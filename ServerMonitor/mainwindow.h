// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onReload();
    void onKickClicked();
    void onBanClicked();
    void onUnbanClicked();

private:
    Ui::MainWindow *ui;
    void loadMessages();
    void loadUsers();
};

#endif // MAINWINDOW_H
