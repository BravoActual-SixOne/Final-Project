#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tcpclient.h"
#include <QMessageBox>
#include <QLineEdit>
#include <QPushButton>
#include <QTextBrowser>
#include <QTimer>
#include <exception>
#include <sstream>

MainWindow::MainWindow(const QString& login, const QString& nickname, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , currentUserLogin(login)
    , currentUserNickname(nickname)
    , lastChatContent("")
{
    ui->setupUi(this);
    setWindowTitle("Чат — " + nickname);

    // Таймер автообновления
    chatUpdateTimer = new QTimer(this);
    connect(chatUpdateTimer, &QTimer::timeout, this, [this]() {
        if (isPublicChat) {
            loadChatHistory();
        } else {
            loadPrivateChat();
        }
    });
    chatUpdateTimer->start(3000);

    // Таймер проверки статуса
    statusCheckTimer = new QTimer(this);
    connect(statusCheckTimer, &QTimer::timeout, [this]() {
        try {
            TcpClient client;
            std::string cmd = "check_status " + currentUserLogin.toStdString();
            std::string resp = client.sendCommand(cmd);

            if (resp.find("STATUS:BANNED") != std::string::npos) {
                QMessageBox::critical(this, "Доступ запрещён",
                                      "Ваш аккаунт заблокирован. Обратитесь к администратору.");
                this->close();
            }
            else if (resp.find("STATUS:KICKED") != std::string::npos) {
                QMessageBox::warning(this, "Отключено",
                                     "Вы были отключены от сервера. Пожалуйста, войдите снова.");
                this->close();
            }
        } catch (...) {
            // Игнор
        }
    });
    statusCheckTimer->start(3000);

    // Сигналы
    connect(ui->sendButton, &QPushButton::clicked, this, &MainWindow::onSendClicked);
    connect(ui->messageEdit, &QLineEdit::returnPressed, this, &MainWindow::onSendClicked);
    connect(ui->logoutButton, &QPushButton::clicked, this, &MainWindow::onLogoutClicked);

    loadUserList();
    loadChatHistory();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onSendClicked()
{
    QString text = ui->messageEdit->text().trimmed();
    if (text.isEmpty()) return;

    try {
        TcpClient client;
        std::string cmd;
        if (isPublicChat) {
            cmd = "send " + currentUserLogin.toStdString() + " ALL " + text.toStdString();
        } else {
            cmd = "send " + currentUserLogin.toStdString() + " " + currentChatTarget.toStdString() + " " + text.toStdString();
        }

        std::string resp = client.sendCommand(cmd);
        if (resp.find("OK:") != std::string::npos) {
            ui->messageEdit->clear();
            if (isPublicChat) {
                loadChatHistory();
            } else {
                loadPrivateChat();
            }
        }
    } catch (...) {
        // обработка ошибки
    }
}

void MainWindow::onLogoutClicked()
{
    try {
        TcpClient client;
        std::string cmd = "logout " + currentUserLogin.toStdString();
        client.sendCommand(cmd);
    } catch (...) {
        // игнор
    }
    this->close();
}

void MainWindow::onChatSelected(QListWidgetItem* item)
{
    QString text = item->text();

    if (text == "💬 Общий чат") {
        isPublicChat = true;
        currentChatTarget.clear();
        loadChatHistory();
    } else {
        isPublicChat = false;
        // Убираем префикс "📩 ", если он есть
        if (text.startsWith("📩 ")) {
            currentChatTarget = text.mid(3);
        } else {
            currentChatTarget = text;
        }
        loadPrivateChat();
    }
}

void MainWindow::loadUserList()
{
    try {
        TcpClient client;
        std::string resp = client.sendCommand("list_users");

        size_t begin = resp.find("USERS_BEGIN\n");
        size_t end = resp.find("\nUSERS_END");

        ui->chatListWidget->clear();
        ui->chatListWidget->addItem("💬 Общий чат");

        // Добавляем других пользователей (кроме себя)
        if (begin != std::string::npos && end != std::string::npos && end > begin) {
            size_t start = begin + 12;
            size_t len = end - start;
            std::string usersPart = resp.substr(start, len);

            std::istringstream iss(usersPart);
            std::string nick;
            while (std::getline(iss, nick)) {
                if (!nick.empty() && nick != currentUserNickname.toStdString()) {
                    ui->chatListWidget->addItem(QString::fromStdString(nick));
                }
            }
        }

        // ВСЕГДА добавляем "чат с самим собой" (вне if!)
        ui->chatListWidget->addItem("📩 " + currentUserNickname);

        static bool connected = false;
        if (!connected) {
            connect(ui->chatListWidget, &QListWidget::itemClicked,
                    this, &MainWindow::onChatSelected);
            connected = true;
        }
    } catch (...) {
        ui->chatListWidget->addItem("⚠️ Не удалось загрузить пользователей");
    }
}

void MainWindow::loadChatHistory()
{
    try {
        TcpClient client;
        std::string resp = client.sendCommand("show_public " + currentUserLogin.toStdString());

        size_t beginPos = resp.find("MESSAGES_BEGIN\n");
        size_t endPos = resp.find("\nMESSAGES_END");

        QString content;
        if (beginPos != std::string::npos && endPos != std::string::npos && endPos > beginPos) {
            size_t start = beginPos + 14;
            size_t len = endPos - start;
            std::string messagesPart = resp.substr(start, len);
            content = QString::fromStdString(messagesPart);
        } else {
            content = "Общий чат пуст.";
        }

        if (content != lastChatContent) {
            ui->chatTextEdit->setPlainText(content);
            lastChatContent = content;
        }
    } catch (const std::exception& e) {
        QString error = "Ошибка загрузки чата.";
        if (error != lastChatContent) {
            ui->chatTextEdit->setPlainText(error);
            lastChatContent = error;
        }
    }
}

void MainWindow::loadPrivateChat()
{
    try {
        TcpClient client;
        std::string cmd = "show_private "
                          + currentUserLogin.toStdString() + " "
                          + currentChatTarget.toStdString();
        std::string resp = client.sendCommand(cmd);

        size_t beginPos = resp.find("MESSAGES_BEGIN\n");
        size_t endPos = resp.find("\nMESSAGES_END");

        QString content;
        if (beginPos != std::string::npos && endPos != std::string::npos && endPos > beginPos) {
            size_t start = beginPos + 14;
            size_t len = endPos - start;
            std::string messagesPart = resp.substr(start, len);
            content = QString::fromStdString(messagesPart);
        } else {
            content = "Нет личных сообщений.";
        }

        if (content != lastChatContent) {
            ui->chatTextEdit->setPlainText(content);
            lastChatContent = content;
        }
    } catch (const std::exception& e) {
        QString error = "Ошибка загрузки личного чата.";
        if (error != lastChatContent) {
            ui->chatTextEdit->setPlainText(error);
            lastChatContent = error;
        }
    }
}
