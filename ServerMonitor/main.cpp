// main.cpp
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QFont font;
    font.setFamily("Segoe UI");
    font.setPointSize(10);
    font.setWeight(QFont::Normal);
    app.setFont(font);

    MainWindow w;
    w.show();

    return app.exec();
}
