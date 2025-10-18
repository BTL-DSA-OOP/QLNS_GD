#include "GD_DangNhap.h"
#include "ui_GD_DangNhap.h"
#include "GD_Qly.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QTimer>
#include <QDebug> // Thư viện đã được include
#include "GD_NVChung.h"

GD_DangNhap::GD_DangNhap(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GD_DangNhap)
    , failedAttempts(0)
{
    ui->setupUi(this);
    connect(ui->btnLogin, &QPushButton::clicked, this, &GD_DangNhap::onLoginClicked);
    connect(ui->btnForgot, &QPushButton::clicked, this, &GD_DangNhap::onForgotClicked);
    connect(ui->txtUsername, &QLineEdit::returnPressed, this, &GD_DangNhap::onLoginClicked);
    connect(ui->txtPassword, &QLineEdit::returnPressed, this, &GD_DangNhap::onLoginClicked);
}

GD_DangNhap::~GD_DangNhap()
{
    delete ui;
}

QList<UserData> GD_DangNhap::loadUsersFromFile() {
    QList<UserData> userList;
    QFile file("account.txt");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return userList;
    }

    QTextStream in(&file);
    UserData currentUser;

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;


        if (line.startsWith("Ten nguoi dung: ")) {
            if (!currentUser.username.isEmpty()) {
                userList.append(currentUser);
            }
            currentUser = UserData(); // Reset
            currentUser.username = line.mid(16).trimmed();
        } else if (line.startsWith("Mat khau: ")) {
            currentUser.password = line.mid(10).trimmed();
        } else if (line.startsWith("Loai nhan su: ")) {
            currentUser.role = line.mid(15).trimmed();
        }
    }

    if (!currentUser.username.isEmpty()) {
        userList.append(currentUser);
    }

    file.close();
    return userList;
}

void GD_DangNhap::onLoginClicked()
{
    QString username = ui->txtUsername->text().trimmed();
    QString password = ui->txtPassword->text();
    ui->lblStatus->setText("");

    if (username.isEmpty() || password.isEmpty()) {
        ui->lblStatus->setText("Vui lòng nhập tên đăng nhập và mật khẩu!");
        return;
    }

    bool loginSuccess = false;
    QString userRole = "";

    if (username == "admin" && password == "123") {
        loginSuccess = true;
        userRole = "QuanLy";
    }

    if (!loginSuccess) {
        QList<UserData> userList = loadUsersFromFile();

        for (const auto& user : userList) {
            if (user.username == username && user.password == password) {
                loginSuccess = true;
                userRole = user.role;
                break;
            }
        }
    }

    if (loginSuccess) {
        this->hide();
        if (userRole == "QuanLy") {
            GD_Qly *mainWindow = new GD_Qly();
            mainWindow->show();
        } else if (userRole == "NhanVienChinhThuc" || userRole == "NhanVienThuViec" ||userRole == "hanVienThuViec" || userRole == "hanVienChinhThuc") {
            GD_NVChung *nhanVienWindow = new GD_NVChung(username);
            nhanVienWindow->show();
        } else {
            QMessageBox::warning(this, "Lỗi", "Không xác định được vai trò người dùng!");
            this->show();
        }
        failedAttempts = 0;
        this->close();

    } else {
        failedAttempts++;
        ui->txtPassword->clear();
        ui->txtPassword->setFocus();
        if (failedAttempts >= 3) {
            ui->lblStatus->setText("Đăng nhập thất bại 3 lần. Đã bị khóa 5 giây.");
            ui->btnLogin->setEnabled(false);
            QTimer::singleShot(5000, this, [this](){
                ui->btnLogin->setEnabled(true);
                this->failedAttempts = 0;
                ui->lblStatus->setText("");
            });
        } else {
            ui->lblStatus->setText("Sai tên đăng nhập hoặc mật khẩu! (" + QString::number(3 - failedAttempts) + " lần còn lại)");
        }
    }
}

void GD_DangNhap::onForgotClicked()
{
    QMessageBox::information(this, "Quên mật khẩu",
                             "Vui lòng liên hệ quản trị viên để khôi phục mật khẩu.");
}
