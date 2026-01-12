#include "loginwindow.h"
#include "registerwindow.h"
#include "mainwindow.h"
#include <QApplication>
#include <QFont>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QFont font;
    font.setFamily("Segoe UI");
    font.setPointSize(10);
    font.setWeight(QFont::Normal);
    app.setFont(font);

    LoginWindow login;
    int result = login.exec();

    if (result == QDialog::Accepted) {
        MainWindow w(login.login(), login.nickname());
        w.show();
        return app.exec();
    }
    else if (result == 2) { // Код регистрации
        RegisterWindow reg;
        int regResult = reg.exec();
        if (regResult == QDialog::Accepted) {
            MainWindow w(reg.registeredLogin(), reg.registeredNickname());
            w.show();
            return app.exec();
        }
    }

    return 0; // Завершение приложения
}
