#include "GD_QLDuAn.h"
#include "ui_GD_QLDuAn.h"
#include "ClassNhanSu.h"
#include "NhanSuData.h"
#include <QMessageBox>
#include <QHeaderView>

GD_QLDuAn::GD_QLDuAn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GD_QLDuAn)
{
    ui->setupUi(this);

    QHeaderView *header = ui->tableProjects->horizontalHeader();

    header->setSectionResizeMode(0, QHeaderView::ResizeToContents); // Mã DA
    header->setSectionResizeMode(2, QHeaderView::ResizeToContents); // Người Phụ Trách
    header->setSectionResizeMode(3, QHeaderView::ResizeToContents); // Ngày Bắt Đầu
    header->setSectionResizeMode(4, QHeaderView::ResizeToContents); // Trạng Thái
    header->setSectionResizeMode(5, QHeaderView::ResizeToContents); // Số Lượng TV
    header->setSectionResizeMode(1, QHeaderView::Stretch); // Tên Dự Án

    docDuAnTuFile(); // Đọc từ file
    loadProjectsToTable();
}

GD_QLDuAn::~GD_QLDuAn()
{
    delete ui;
}

void GD_QLDuAn::loadProjectsToTable()
{
    ui->tableProjects->setRowCount(0);
    ui->tableProjects->setSortingEnabled(false);

    for (const auto& duAn : g_danhSachDuAn)
    {
        int row = ui->tableProjects->rowCount();
        ui->tableProjects->insertRow(row);

        ui->tableProjects->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(duAn.getMaDuAn())));
        ui->tableProjects->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(duAn.getTenDuAn())));

        auto nguoiPhuTrach = timNhanSuTheoMa(duAn.getNguoiPhuTrach());
        QString tenPhuTrach = "N/A";
        if (nguoiPhuTrach) {
            tenPhuTrach = QString::fromStdString(nguoiPhuTrach->getHoTen());
        }
        ui->tableProjects->setItem(row, 2, new QTableWidgetItem(tenPhuTrach));

        ui->tableProjects->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(duAn.getNgayBatDau().toString())));
        QString trangThai = duAn.isDaHoanThanh() ? "Hoàn thành" : "Đang thực hiện";
        ui->tableProjects->setItem(row, 4, new QTableWidgetItem(trangThai));
        ui->tableProjects->setItem(row, 5, new QTableWidgetItem(QString::number(duAn.getSoLuongThanhVien())));
    }
    ui->tableProjects->setSortingEnabled(true); // Bật lại sắp xếp
}


void GD_QLDuAn::on_btnAddProject_clicked()
{
    // Chưa tạo file dự án riêng nên chưa dùng được
    QMessageBox::information(this, "Thông báo", "Chức năng Thêm Dự Án chưa được lập trình.");
    // Sau khi thêm, bạn cần gọi:
    // luuDuAnVaoFile();
    // loadProjectsToTable();
}

void GD_QLDuAn::on_btnRefresh_clicked()
{
    docDuAnTuFile(); // Đọc lại từ file
    loadProjectsToTable();
    QMessageBox::information(this, "Thông Báo", "Đã làm mới danh sách dự án!");
}
