// GD_DangNhap.h

#ifndef GD_DANGNHAP_H
#define GD_DANGNHAP_H

#include <QMainWindow>
#include <QList>
#include <QString>

struct UserData {
    QString username;
    QString password;
    QString Email;
    QString role;
};

namespace Ui {
class GD_DangNhap;
}

class GD_DangNhap : public QMainWindow
{
    Q_OBJECT

public:
    explicit GD_DangNhap(QWidget *parent = nullptr);
    ~GD_DangNhap();

private slots:
    void onLoginClicked();
    void onForgotClicked();

private:
    Ui::GD_DangNhap *ui;
    int failedAttempts;
    QList<UserData> loadUsersFromFile();
};

#endif
