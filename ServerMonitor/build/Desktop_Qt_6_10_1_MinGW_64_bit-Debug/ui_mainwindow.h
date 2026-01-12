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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *kickButton;
    QPushButton *banButton;
    QLabel *label;
    QPushButton *unbanButton;
    QTableWidget *usersTable;
    QTableWidget *messagesTable;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1102, 672);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
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
"QTableWidget {\n"
"    background-color: #252525;\n"
"    border: none;\n"
"    gridline-color: #333;\n"
"    alternate-background-color: #282828;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #2D2D2D;\n"
"    color: #CCCCCC;\n"
"    padding: 6px;\n"
"    border: none;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: #3A3A3A;\n"
"    color: #FFFFFF;\n"
"}\n"
"\n"
"QLineEdit {\n"
"    background-color: #2D2D2D;\n"
"    color: #E0E0E0;\n"
"    border: 1px solid #333;\n"
"    border-radius: 6px;\n"
"    padding: 6px;\n"
"}\n"
"\n"
"#kickButton {\n"
"    background-color: #FF5252;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 6px 16px;\n"
"    font-weight: bold;\n"
"}\n"
"#kickButton:hover {\n"
"    background-col"
                        "or: #FF3B3B;\n"
"}\n"
"\n"
"#banButton {\n"
"    background-color: #FF9800;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 6px 16px;\n"
"    font-weight: bold;\n"
"}\n"
"#banButton:hover {\n"
"    background-color: #FF8A00;\n"
"}\n"
"\n"
"#unbanButton {\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 6px 16px;\n"
"    font-weight: bold;\n"
"}\n"
"#unbanButton:hover {\n"
"    background-color: #43A047;\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: #34495E;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 6px 16px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #2C3E50;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setEnabled(true);
        kickButton = new QPushButton(centralwidget);
        kickButton->setObjectName("kickButton");
        kickButton->setGeometry(QRect(150, 580, 91, 28));
        banButton = new QPushButton(centralwidget);
        banButton->setObjectName("banButton");
        banButton->setGeometry(QRect(20, 580, 111, 28));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 540, 789, 16));
        unbanButton = new QPushButton(centralwidget);
        unbanButton->setObjectName("unbanButton");
        unbanButton->setGeometry(QRect(20, 620, 111, 28));
        usersTable = new QTableWidget(centralwidget);
        if (usersTable->columnCount() < 5)
            usersTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        usersTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        usersTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        usersTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        usersTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        usersTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        usersTable->setObjectName("usersTable");
        usersTable->setGeometry(QRect(10, 20, 1081, 201));
        usersTable->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        usersTable->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContents);
        messagesTable = new QTableWidget(centralwidget);
        if (messagesTable->columnCount() < 6)
            messagesTable->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        messagesTable->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        messagesTable->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        messagesTable->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        messagesTable->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        messagesTable->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        messagesTable->setHorizontalHeaderItem(5, __qtablewidgetitem10);
        messagesTable->setObjectName("messagesTable");
        messagesTable->setGeometry(QRect(10, 250, 1081, 271));
        messagesTable->setMaximumSize(QSize(16777215, 16777215));
        messagesTable->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        kickButton->setText(QCoreApplication::translate("MainWindow", "\320\232\320\270\320\272", nullptr));
        banButton->setText(QCoreApplication::translate("MainWindow", "\320\221\320\260\320\275", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\321\200\320\276 \320\277\320\276\320\266\320\260\320\273\320\276\320\262\320\260\321\202\321\214 \320\262 \320\274\320\276\320\275\320\270\321\202\320\276\321\200\320\270\320\275\320\263 \321\201\320\265\321\200\320\262\320\265\321\200\320\275\320\276\320\271 \321\207\320\260\321\201\321\202\320\270! \320\222\320\276\321\202 \320\262\321\201\321\221 \320\262\320\260\320\274 \320\275\320\265\320\276\320\261\321\205\320\276\320\264\320\270\320\274\320\276\320\265, \321\207\321\202\320\276\320\261\321\213 \321\201\320\266\320\270\320\263\320\260\321\202\321\214 \320\265\321\200\320\265\321\202\320\270\320\272\320\276\320\262:", nullptr));
        unbanButton->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\320\261\320\260\320\275", nullptr));
        QTableWidgetItem *___qtablewidgetitem = usersTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = usersTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = usersTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Nickname", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = usersTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = usersTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Ban", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = messagesTable->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = messagesTable->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = messagesTable->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Sender", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = messagesTable->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Recipient", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = messagesTable->horizontalHeaderItem(4);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Content", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = messagesTable->horizontalHeaderItem(5);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
