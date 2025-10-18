// GD_QLPhongBan.h

#ifndef GD_QLPHONGBAN_H
#define GD_QLPHONGBAN_H

#include <QWidget>
namespace Ui {
class GD_QLPhongBan;
}

class GD_QLPhongBan : public QWidget
{
    Q_OBJECT

public:
    explicit GD_QLPhongBan(QWidget *parent = nullptr);
    ~GD_QLPhongBan();

private:
    Ui::GD_QLPhongBan *ui;
};

#endif
