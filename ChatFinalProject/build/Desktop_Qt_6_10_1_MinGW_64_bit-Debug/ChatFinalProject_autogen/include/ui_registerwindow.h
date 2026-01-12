/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RegisterWindow
{
public:
    QLineEdit *passwordEdit;
    QLabel *label;
    QLineEdit *loginEdit;
    QPushButton *registerButton;
    QLineEdit *confirmEdit;
    QLineEdit *nicknameEdit;
    QLabel *statusLabel;
    QPushButton *backButton;

    void setupUi(QDialog *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName("RegisterWindow");
        RegisterWindow->resize(720, 421);
        RegisterWindow->setStyleSheet(QString::fromUtf8("QDialog {\n"
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
        passwordEdit = new QLineEdit(RegisterWindow);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setGeometry(QRect(40, 110, 251, 31));
        label = new QLabel(RegisterWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 30, 271, 20));
        loginEdit = new QLineEdit(RegisterWindow);
        loginEdit->setObjectName("loginEdit");
        loginEdit->setGeometry(QRect(40, 60, 251, 31));
        registerButton = new QPushButton(RegisterWindow);
        registerButton->setObjectName("registerButton");
        registerButton->setGeometry(QRect(40, 260, 221, 29));
        confirmEdit = new QLineEdit(RegisterWindow);
        confirmEdit->setObjectName("confirmEdit");
        confirmEdit->setGeometry(QRect(40, 160, 251, 31));
        nicknameEdit = new QLineEdit(RegisterWindow);
        nicknameEdit->setObjectName("nicknameEdit");
        nicknameEdit->setGeometry(QRect(40, 210, 251, 31));
        statusLabel = new QLabel(RegisterWindow);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setGeometry(QRect(40, 340, 211, 20));
        backButton = new QPushButton(RegisterWindow);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(40, 300, 111, 29));

        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QDialog *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "Dialog", nullptr));
        passwordEdit->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "\320\237\321\200\320\270\320\264\321\203\320\274\320\260\320\271\321\202\320\265 \320\275\320\260\320\264\321\221\320\266\320\275\321\213\320\271 (!) \320\277\320\260\321\200\320\276\320\273\321\214: ", nullptr));
        label->setText(QCoreApplication::translate("RegisterWindow", "\320\224\320\273\321\217 \321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\320\270 \320\262\320\262\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\260\320\275\320\275\321\213\320\265:", nullptr));
        loginEdit->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "\320\237\321\200\320\270\320\264\321\203\320\274\320\260\320\271\321\202\320\265 \320\273\320\276\320\263\320\270\320\275:", nullptr));
        registerButton->setText(QCoreApplication::translate("RegisterWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217, \320\262\320\277\320\265\321\200\321\221\320\264!", nullptr));
        confirmEdit->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\320\265 \320\262\320\260\321\210 \320\277\320\260\321\200\320\276\320\273\321\214:", nullptr));
        nicknameEdit->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "\320\237\321\200\320\270\320\264\321\203\320\274\320\260\320\271\321\202\320\265 \320\276\321\202\320\276\320\261\321\200\320\276\320\266\320\260\320\265\320\274\320\276\320\265 \320\270\320\274\321\217:", nullptr));
        statusLabel->setText(QString());
        backButton->setText(QCoreApplication::translate("RegisterWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
