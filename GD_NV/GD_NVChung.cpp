#include "GD_NVChung.h"
#include "ui_GD_NVChung.h"

GD_NVChung::GD_NVChung(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GD_NVChung)
{
    ui->setupUi(this);

    // Connect buttons to their slots to switch pages
    connect(ui->btnNavInfo, &QPushButton::clicked, this, &GD_NVChung::on_btnNavInfo_clicked);
    connect(ui->btnNavSalary, &QPushButton::clicked, this, &GD_NVChung::on_btnNavSalary_clicked);
    connect(ui->btnNavAttendance, &QPushButton::clicked, this, &GD_NVChung::on_btnNavAttendance_clicked);
    connect(ui->btnNavProjects, &QPushButton::clicked, this, &GD_NVChung::on_btnNavProjects_clicked);
    connect(ui->btnNavRelatives, &QPushButton::clicked, this, &GD_NVChung::on_btnNavRelatives_clicked);

    // Show the first page when the application starts
    ui->mainStackedWidget->setCurrentIndex(0);
}

GD_NVChung::~GD_NVChung()
{
    delete ui;
}

void GD_NVChung::on_btnNavInfo_clicked()
{
    ui->mainStackedWidget->setCurrentIndex(0);
}

void GD_NVChung::on_btnNavSalary_clicked()
{
    ui->mainStackedWidget->setCurrentIndex(1);
}

void GD_NVChung::on_btnNavAttendance_clicked()
{
    ui->mainStackedWidget->setCurrentIndex(2);
}

void GD_NVChung::on_btnNavProjects_clicked()
{
    ui->mainStackedWidget->setCurrentIndex(3);
}

void GD_NVChung::on_btnNavRelatives_clicked()
{
    ui->mainStackedWidget->setCurrentIndex(4);
}
