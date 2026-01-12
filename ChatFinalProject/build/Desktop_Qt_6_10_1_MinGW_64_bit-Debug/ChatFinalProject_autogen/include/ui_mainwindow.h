/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QListWidget *chatListWidget;
    QVBoxLayout *verticalLayout_7;
    QTextBrowser *chatTextEdit;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *messageEdit;
    QPushButton *sendButton;
    QPushButton *logoutButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(982, 671);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background-color: #1E1E1E;\n"
"}\n"
"\n"
"/* \320\222\321\201\320\265 \320\262\320\273\320\276\320\266\320\265\320\275\320\275\321\213\320\265 \320\262\320\270\320\264\320\266\320\265\321\202\321\213 \320\277\320\276 \321\203\320\274\320\276\320\273\321\207\320\260\320\275\320\270\321\216 */\n"
"QWidget {\n"
"    background-color: #252525;\n"
"    color: #E0E0E0;\n"
"}\n"
"\n"
"/* \320\230\321\201\320\272\320\273\321\216\321\207\320\265\320\275\320\270\321\217 */\n"
"QLineEdit {\n"
"    background-color: #2D2D2D;\n"
"    border: 1px solid #333;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: #2C5AA0;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 24px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #0B78CC;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #0966B3;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 50, 981, 561));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        chatListWidget = new QListWidget(verticalLayoutWidget);
        chatListWidget->setObjectName("chatListWidget");
        chatListWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(chatListWidget->sizePolicy().hasHeightForWidth());
        chatListWidget->setSizePolicy(sizePolicy);
        chatListWidget->setMinimumSize(QSize(200, 0));
        chatListWidget->setMaximumSize(QSize(250, 16777215));
        chatListWidget->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"    background-color: #252525;\n"
"    border: none;\n"
"    outline: none; \n"
"}\n"
"\n"
"QListWidget::item {\n"
"    padding: 8px 12px;\n"
"    margin: 4px 0px; \n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QListWidget::item:hover {\n"
"    background-color: #2D2D2D;\n"
"}\n"
"\n"
"QListWidget::item:selected {\n"
"    background-color: #3A3A3A;\n"
"    color: #FFFFFF;\n"
"}"));

        horizontalLayout_3->addWidget(chatListWidget);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        chatTextEdit = new QTextBrowser(verticalLayoutWidget);
        chatTextEdit->setObjectName("chatTextEdit");

        verticalLayout_7->addWidget(chatTextEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        messageEdit = new QLineEdit(verticalLayoutWidget);
        messageEdit->setObjectName("messageEdit");

        horizontalLayout_2->addWidget(messageEdit);

        sendButton = new QPushButton(verticalLayoutWidget);
        sendButton->setObjectName("sendButton");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sendButton->sizePolicy().hasHeightForWidth());
        sendButton->setSizePolicy(sizePolicy1);
        sendButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(sendButton);


        verticalLayout_7->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_7);


        verticalLayout->addLayout(horizontalLayout_3);

        logoutButton = new QPushButton(centralwidget);
        logoutButton->setObjectName("logoutButton");
        logoutButton->setGeometry(QRect(810, 10, 161, 29));
        logoutButton->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 982, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        sendButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
        logoutButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\277\321\203\321\201\321\202\320\270\321\202\320\265 \320\274\320\265\320\275\321\217!!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
