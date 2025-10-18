#include <QApplication>
#include "GD_DangNhap.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GD_DangNhap loginWindow;
    loginWindow.show();

    return a.exec();
}
