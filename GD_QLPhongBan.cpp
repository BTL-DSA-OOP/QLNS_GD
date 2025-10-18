// GD_QLPhongBan.cpp

#include "GD_QLPhongBan.h"
#include "ui_GD_QLPhongBan.h"

GD_QLPhongBan::GD_QLPhongBan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GD_QLPhongBan)
{
    ui->setupUi(this);
    QHeaderView *header = ui->tableDepartments->horizontalHeader();
    header->setSectionResizeMode(0, QHeaderView::ResizeToContents);

    header->setSectionResizeMode(1, QHeaderView::ResizeToContents);

    header->setSectionResizeMode(2, QHeaderView::ResizeToContents);

    header->setSectionResizeMode(3, QHeaderView::Stretch);

}

GD_QLPhongBan::~GD_QLPhongBan()
{
    delete ui;
}
