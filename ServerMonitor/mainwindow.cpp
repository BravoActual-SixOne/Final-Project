// mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tcpclient.h"
#include <QMessageBox>
#include <QTimer>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Server Monitor — Chat Admin");

    ui->messagesTable->setHorizontalHeaderLabels({"ID", "Sender", "Recipient", "Content", "Type", "Time"});
    ui->usersTable->setHorizontalHeaderLabels({"ID", "Login", "Nickname", "Status", "Ban"});

    ui->messagesTable->setSortingEnabled(true);
    ui->usersTable->setSortingEnabled(true);

    connect(ui->kickButton, &QPushButton::clicked, this, &MainWindow::onKickClicked);
    connect(ui->banButton, &QPushButton::clicked, this, &MainWindow::onBanClicked);
    connect(ui->unbanButton, &QPushButton::clicked, this, &MainWindow::onUnbanClicked);

    onReload();

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::onReload);
    timer->start(3000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onReload()
{
    loadUsers();
    loadMessages();
}

void MainWindow::loadUsers()
{
    QString selectedUserId;
    auto selectedItems = ui->usersTable->selectedItems();
    if (!selectedItems.empty()) {
        int row = selectedItems.first()->row();
        if (ui->usersTable->item(row, 0)) {
            selectedUserId = ui->usersTable->item(row, 0)->text();
        }
    }

    // Отключаем сортировку и перерисовку
    ui->usersTable->setSortingEnabled(false);
    ui->usersTable->setUpdatesEnabled(false);
    ui->usersTable->setRowCount(0);

    try {
        TcpClient client("127.0.0.1", 7777);
        std::string resp = client.sendCommand("admin_list_users");

        QStringList lines = QString::fromStdString(resp).split('\n');
        bool inBlock = false;
        for (const QString &line : lines) {
            if (line == "USERS_BEGIN") {
                inBlock = true;
                continue;
            }
            if (line == "USERS_END") {
                break;
            }
            if (inBlock && !line.trimmed().isEmpty()) {
                QStringList parts = line.split(' ');
                if (parts.size() >= 5) {
                    bool valid = true;
                    for (int i = 0; i < 5; ++i) {
                        if (parts[i].isEmpty()) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid) continue;

                    int row = ui->usersTable->rowCount();
                    ui->usersTable->insertRow(row);
                    ui->usersTable->setItem(row, 0, new QTableWidgetItem(parts[0]));
                    ui->usersTable->setItem(row, 1, new QTableWidgetItem(parts[1]));
                    ui->usersTable->setItem(row, 2, new QTableWidgetItem(parts[2]));
                    ui->usersTable->setItem(row, 3, new QTableWidgetItem(parts[3] == "1" ? "Online" : "Offline"));
                    ui->usersTable->setItem(row, 4, new QTableWidgetItem(parts[4] == "1" ? "Banned" : "Active"));
                }
            }
        }
    } catch (const std::exception &e) {
        QMessageBox::warning(this, "Error", e.what());
    }

    // Восстанавливаем выделение
    if (!selectedUserId.isEmpty()) {
        for (int row = 0; row < ui->usersTable->rowCount(); ++row) {
            if (ui->usersTable->item(row, 0) &&
                ui->usersTable->item(row, 0)->text() == selectedUserId) {
                ui->usersTable->selectRow(row);
                break;
            }
        }
    }

    // Включаем обратно
    ui->usersTable->setUpdatesEnabled(true);
    ui->usersTable->setSortingEnabled(true);
}

void MainWindow::loadMessages()
{
    // Отключаем сортировку и перерисовку
    ui->messagesTable->setSortingEnabled(false);
    ui->messagesTable->setUpdatesEnabled(false);
    ui->messagesTable->setRowCount(0);

    try {
        TcpClient client("127.0.0.1", 7777);
        std::string resp = client.sendCommand("admin_show_public");

        QStringList lines = QString::fromStdString(resp).split('\n');
        bool inBlock = false;
        for (const QString &line : lines) {
            if (line == "MESSAGES_BEGIN") {
                inBlock = true;
                continue;
            }
            if (line == "MESSAGES_END") {
                break;
            }
            if (inBlock && !line.trimmed().isEmpty()) {
                QStringList parts = line.split('\t');
                if (parts.size() >= 6) {
                    bool valid = true;
                    for (int i = 0; i < 6; ++i) {
                        if (parts[i].isEmpty()) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid) continue;

                    int row = ui->messagesTable->rowCount();
                    ui->messagesTable->insertRow(row);
                    for (int i = 0; i < 6; ++i) {
                        ui->messagesTable->setItem(row, i, new QTableWidgetItem(parts[i]));
                    }
                }
            }
        }
    } catch (const std::exception &e) {
        QMessageBox::warning(this, "Error", e.what());
    }

    // Включаем обратно
    ui->messagesTable->setUpdatesEnabled(true);
    ui->messagesTable->setSortingEnabled(true);
}

// ===== СЛОТЫ ДЛЯ КНОПОК =====

void MainWindow::onKickClicked()
{
    auto items = ui->usersTable->selectedItems();
    if (items.isEmpty()) {
        QMessageBox::warning(this, "Select User", "Please select a user to kick");
        return;
    }
    int row = items.first()->row();
    QString userId = ui->usersTable->item(row, 0)->text();

    try {
        TcpClient client("127.0.0.1", 7777);
        std::string cmd = "kick " + userId.toStdString();
        std::string resp = client.sendCommand(cmd);
        if (resp.find("OK") != std::string::npos) {
            onReload();
        } else {
            QMessageBox::warning(this, "Error", "Kick failed");
        }
    } catch (const std::exception &e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}

void MainWindow::onBanClicked()
{
    auto items = ui->usersTable->selectedItems();
    if (items.isEmpty()) {
        QMessageBox::warning(this, "Select User", "Please select a user to ban");
        return;
    }
    int row = items.first()->row();
    QString userId = ui->usersTable->item(row, 0)->text();

    try {
        TcpClient client("127.0.0.1", 7777);
        std::string cmd = "ban " + userId.toStdString();
        std::string resp = client.sendCommand(cmd);
        if (resp.find("OK") != std::string::npos) {
            onReload();
        } else {
            QMessageBox::warning(this, "Error", "Ban failed");
        }
    } catch (const std::exception &e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}

void MainWindow::onUnbanClicked()
{
    auto items = ui->usersTable->selectedItems();
    if (items.isEmpty()) {
        QMessageBox::warning(this, "Select User", "Please select a user to unban");
        return;
    }
    int row = items.first()->row();
    QString userId = ui->usersTable->item(row, 0)->text();

    try {
        TcpClient client("127.0.0.1", 7777);
        std::string cmd = "unban " + userId.toStdString();
        std::string resp = client.sendCommand(cmd);
        if (resp.find("OK") != std::string::npos) {
            onReload();
        } else {
            QMessageBox::warning(this, "Error", "Unban failed");
        }
    } catch (const std::exception &e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}
