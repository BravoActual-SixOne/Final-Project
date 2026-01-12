#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "tcpclient.h"

#include <QLabel>

RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    retranslate();

    // Ручное подключение сигналов
    connect(ui->registerButton, &QPushButton::clicked, this, &RegisterWindow::onRegisterClicked);
    connect(ui->backButton, &QPushButton::clicked, this, &RegisterWindow::onBackClicked);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::onRegisterClicked()
{
    ui->statusLabel->clear();

    QString login = ui->loginEdit->text();
    QString pass = ui->passwordEdit->text();
    QString confirm = ui->confirmEdit->text();
    QString nick = ui->nicknameEdit->text();

    if (login.isEmpty() || pass.isEmpty() || nick.isEmpty()) {
        ui->statusLabel->setText("<font color='red'>" + tr("All fields are required") + "</font>");
        return;
    }
    if (pass != confirm) {
        ui->statusLabel->setText("<font color='red'>" + tr("Passwords do not match") + "</font>");
        return;
    }

    try {
        TcpClient client;
        std::string cmd = "register " + login.toStdString() + " " +
                          pass.toStdString() + " " + nick.toStdString();
        std::string resp = client.sendCommand(cmd);

        if (resp.find("OK:") != std::string::npos) {
            m_registeredLogin = login;
            m_registeredPassword = pass;
            m_registeredNickname = nick;
            accept();
        } else {
            ui->statusLabel->setText("<font color='red'>" + QString::fromStdString(resp).toHtmlEscaped() + "</font>");
        }
    } catch (const std::exception& e) {
        ui->statusLabel->setText("<font color='red'>" + tr("Network error: ") + QString::fromStdString(e.what()).toHtmlEscaped() + "</font>");
    }
}

void RegisterWindow::onBackClicked()
{
    reject();
}

void RegisterWindow::retranslate()
{
    ui->retranslateUi(this);
}

QString RegisterWindow::registeredLogin() const { return m_registeredLogin; }
QString RegisterWindow::registeredPassword() const { return m_registeredPassword; }
QString RegisterWindow::registeredNickname() const { return m_registeredNickname; }
