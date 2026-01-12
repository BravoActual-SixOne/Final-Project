#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QDialog>

namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = nullptr);
    ~RegisterWindow();

    QString registeredLogin() const;
    QString registeredPassword() const;
    QString registeredNickname() const;

private slots:
    void onRegisterClicked();
    void onBackClicked();

private:
    Ui::RegisterWindow *ui;
    QString m_registeredLogin;
    QString m_registeredPassword;
    QString m_registeredNickname;

    void retranslate();
};

#endif // REGISTERWINDOW_H
