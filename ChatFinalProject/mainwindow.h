#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>  // ← обязательно для onChatSelected

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(const QString& login, const QString& nickname, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onSendClicked();
    void onChatSelected(QListWidgetItem* item);  // ← обработчик клика по чату
    void onLogoutClicked();

private:
    Ui::MainWindow *ui;
    QString currentUserLogin;
    QString currentUserNickname;
    QString currentChatTarget;
    bool isPublicChat = true;  // true = общий чат, false = личный
    QTimer* chatUpdateTimer;
    QTimer* statusCheckTimer = nullptr;
    QString lastChatContent; // чтобы не обновлять, если ничего не изменилось

    // Методы загрузки данных
    void loadUserList();       // список пользователей
    void loadChatHistory();    // публичный чат
    void loadPrivateChat();    // личные сообщения
};

#endif // MAINWINDOW_H
