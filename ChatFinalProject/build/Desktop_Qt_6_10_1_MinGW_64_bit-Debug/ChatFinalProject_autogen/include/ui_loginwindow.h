/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QLineEdit *passwordEdit;
    QPushButton *loginButton;
    QPushButton *registerButton;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *loginEdit;
    QLabel *statusLabel;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(743, 440);
        LoginWindow->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background-color: #1E1E1E;\n"
"}\n"
"\n"
"QWidget {\n"
"    background-color: #252525;\n"
"    color: #E0E0E0;\n"
"}\n"
"\n"
"QLabel {\n"
"    color: #E0E0E0;\n"
"}\n"
"\n"
"QLineEdit {\n"
"    background-color: #2D2D2D;\n"
"    color: #E0E0E0;\n"
"    border: 1px solid #333;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: #34495E;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 24px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2C3E50;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1F2B38;\n"
"}"));
        passwordEdit = new QLineEdit(LoginWindow);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setGeometry(QRect(40, 150, 251, 31));
        loginButton = new QPushButton(LoginWindow);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(40, 200, 241, 29));
        loginButton->setCheckable(false);
        registerButton = new QPushButton(LoginWindow);
        registerButton->setObjectName("registerButton");
        registerButton->setGeometry(QRect(40, 290, 201, 29));
        label = new QLabel(LoginWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 70, 221, 20));
        label_2 = new QLabel(LoginWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 240, 341, 31));
        loginEdit = new QLineEdit(LoginWindow);
        loginEdit->setObjectName("loginEdit");
        loginEdit->setGeometry(QRect(40, 100, 251, 31));
        statusLabel = new QLabel(LoginWindow);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setGeometry(QRect(50, 350, 201, 20));

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Dialog", nullptr));
        passwordEdit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\262\320\260\321\210 \320\277\320\260\321\200\320\276\320\273\321\214:", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginWindow", "\320\241\320\277\320\276\320\272\320\276\320\271\320\275\320\276, \320\262\321\201\321\221 \320\276\320\272\320\265\320\271, \320\267\320\260\321\205\320\276\320\264\320\270\320\274!", nullptr));
        registerButton->setText(QCoreApplication::translate("LoginWindow", "\320\237\320\276\320\263\320\275\320\260\320\273\320\270, \321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217!", nullptr));
        label->setText(QCoreApplication::translate("LoginWindow", "\320\224\320\273\321\217 \320\262\321\205\320\276\320\264\320\260 \320\262\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\260\320\275\320\275\321\213\320\265:", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWindow", "\320\225\321\211\321\221 \320\275\320\265\321\202 \321\203\321\207\321\221\321\202\320\275\320\276\320\271 \320\267\320\260\320\277\320\270\321\201\320\270? \320\241\320\260\320\274\320\276\320\265 \320\262\321\200\320\265\320\274\321\217 \320\267\320\260\320\262\320\265\321\201\321\202\320\270!", nullptr));
        loginEdit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\273\320\276\320\263\320\270\320\275:", nullptr));
        statusLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
