#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "tcpclient.h"

#include <QLabel>

LoginWindow::LoginWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    retranslate();

    // Ручное подключение сигналов
    connect(ui->loginButton, &QPushButton::clicked, this, &LoginWindow::onLoginClicked);
    connect(ui->registerButton, &QPushButton::clicked, this, &LoginWindow::onRegisterClicked);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::onLoginClicked()
{
    ui->statusLabel->clear();

    QString login = ui->loginEdit->text();
    QString pass = ui->passwordEdit->text();

    if (login.isEmpty() || pass.isEmpty()) {
        ui->statusLabel->setText("<font color='red'>" + tr("Login and password are required") + "</font>");
        return;
    }

    try {
        TcpClient client;
        std::string cmd = "login " + login.toStdString() + " " + pass.toStdString();
        std::string resp = client.sendCommand(cmd);

        if (resp.find("OK:") != std::string::npos) {
            m_login = login;
            m_password = pass;

            std::string nickCmd = "get_nickname " + login.toStdString();
            std::string nickResp = client.sendCommand(nickCmd);
            if (!nickResp.empty() && nickResp.back() == '\n')
                nickResp.pop_back();
            m_nickname = QString::fromStdString(nickResp);

            accept();
        } else {
            ui->statusLabel->setText("<font color='red'>" + QString::fromStdString(resp).toHtmlEscaped() + "</font>");
        }
    } catch (const std::exception& e) {
        ui->statusLabel->setText("<font color='red'>" + tr("Network error: ") + QString::fromStdString(e.what()).toHtmlEscaped() + "</font>");
    }
}

void LoginWindow::onRegisterClicked()
{
    done(2);
}

QString LoginWindow::login() const { return m_login; }
QString LoginWindow::password() const { return m_password; }
QString LoginWindow::nickname() const { return m_nickname; }

void LoginWindow::retranslate()
{
    ui->retranslateUi(this);
}
