#include <QApplication>
#include "GD_NVChung.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GD_NVChung window;
    window.show();

    return a.exec();
}
