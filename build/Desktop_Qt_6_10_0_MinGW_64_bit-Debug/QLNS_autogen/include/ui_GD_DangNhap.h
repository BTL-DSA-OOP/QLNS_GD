/********************************************************************************
** Form generated from reading UI file 'GD_DangNhap.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GD_DANGNHAP_H
#define UI_GD_DANGNHAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GD_DangNhap
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_1;
    QVBoxLayout *formLayout;
    QSpacerItem *verticalSpacer_1;
    QLabel *lblFormTitle;
    QLineEdit *txtUsername;
    QLineEdit *txtPassword;
    QHBoxLayout *forgotPassLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnForgot;
    QPushButton *btnLogin;
    QLabel *lblStatus;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QMainWindow *GD_DangNhap)
    {
        if (GD_DangNhap->objectName().isEmpty())
            GD_DangNhap->setObjectName("GD_DangNhap");
        GD_DangNhap->resize(400, 420);
        GD_DangNhap->setStyleSheet(QString::fromUtf8("/* --- Main Window Style --- */\n"
"#centralwidget {\n"
"    background-color: #f4f7fc;\n"
"}\n"
"\n"
"/* --- General Font Style --- */\n"
"QWidget {\n"
"    font-family: \"Segoe UI\", Arial, sans-serif;\n"
"}\n"
"\n"
"/* --- Form Title --- */\n"
"#lblFormTitle {\n"
"    font-size: 16pt;\n"
"    font-weight: bold;\n"
"    color: #2c3e50;\n"
"    qproperty-alignment: 'AlignCenter';\n"
"    margin-bottom: 25px;\n"
"}\n"
"\n"
"/* --- Input Fields --- */\n"
"QLineEdit {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #dde1e7;\n"
"    border-radius: 10px;\n"
"    padding: 12px 15px;\n"
"    font-size: 11pt;\n"
"    min-height: 25px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 2px solid #3498db;\n"
"}\n"
"\n"
"/* --- Login Button --- */\n"
"#btnLogin {\n"
"    background-color: #3498db;\n"
"    color: white;\n"
"    font-size: 12pt;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"    border-radius: 20px; /* (height / 2) */\n"
"    min-height: 40px;\n"
"    margin-top: 15px;\n"
"}\n"
"#btnLogin:hove"
                        "r {\n"
"    background-color: #2980b9;\n"
"}\n"
"#btnLogin:pressed {\n"
"    background-color: #1f618d;\n"
"}\n"
"\n"
"/* --- Forgot Password Button --- */\n"
"#btnForgot {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    color: #3498db;\n"
"    font-size: 9pt;\n"
"    text-decoration: none;\n"
"}\n"
"#btnForgot:hover {\n"
"    text-decoration: underline;\n"
"}\n"
"\n"
"/* --- Status/Error Message Label --- */\n"
"#lblStatus {\n"
"    color: #e74c3c; /* Red color for errors */\n"
"    font-size: 9pt;\n"
"    qproperty-alignment: 'AlignCenter';\n"
"    min-height: 20px;\n"
"}\n"
""));
        centralwidget = new QWidget(GD_DangNhap);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(30, 30, 30, 30);
        horizontalSpacer_1 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_1);

        formLayout = new QVBoxLayout();
        formLayout->setSpacing(15);
        formLayout->setObjectName("formLayout");
        verticalSpacer_1 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout->addItem(verticalSpacer_1);

        lblFormTitle = new QLabel(centralwidget);
        lblFormTitle->setObjectName("lblFormTitle");

        formLayout->addWidget(lblFormTitle);

        txtUsername = new QLineEdit(centralwidget);
        txtUsername->setObjectName("txtUsername");

        formLayout->addWidget(txtUsername);

        txtPassword = new QLineEdit(centralwidget);
        txtPassword->setObjectName("txtPassword");
        txtPassword->setEchoMode(QLineEdit::Password);

        formLayout->addWidget(txtPassword);

        forgotPassLayout = new QHBoxLayout();
        forgotPassLayout->setObjectName("forgotPassLayout");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        forgotPassLayout->addItem(horizontalSpacer_3);

        btnForgot = new QPushButton(centralwidget);
        btnForgot->setObjectName("btnForgot");
        btnForgot->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        forgotPassLayout->addWidget(btnForgot);


        formLayout->addLayout(forgotPassLayout);

        btnLogin = new QPushButton(centralwidget);
        btnLogin->setObjectName("btnLogin");
        btnLogin->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        formLayout->addWidget(btnLogin);

        lblStatus = new QLabel(centralwidget);
        lblStatus->setObjectName("lblStatus");

        formLayout->addWidget(lblStatus);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(formLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        GD_DangNhap->setCentralWidget(centralwidget);

        retranslateUi(GD_DangNhap);

        QMetaObject::connectSlotsByName(GD_DangNhap);
    } // setupUi

    void retranslateUi(QMainWindow *GD_DangNhap)
    {
        GD_DangNhap->setWindowTitle(QCoreApplication::translate("GD_DangNhap", "\304\220\304\203ng nh\341\272\255p", nullptr));
        lblFormTitle->setText(QCoreApplication::translate("GD_DangNhap", "\304\220\304\203ng Nh\341\272\255p H\341\273\207 Th\341\273\221ng", nullptr));
        txtUsername->setPlaceholderText(QCoreApplication::translate("GD_DangNhap", "T\303\252n \304\221\304\203ng nh\341\272\255p", nullptr));
        txtPassword->setPlaceholderText(QCoreApplication::translate("GD_DangNhap", "M\341\272\255t kh\341\272\251u", nullptr));
        btnForgot->setText(QCoreApplication::translate("GD_DangNhap", "Qu\303\252n m\341\272\255t kh\341\272\251u?", nullptr));
        btnLogin->setText(QCoreApplication::translate("GD_DangNhap", "\304\220\304\203ng nh\341\272\255p", nullptr));
        lblStatus->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GD_DangNhap: public Ui_GD_DangNhap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GD_DANGNHAP_H
