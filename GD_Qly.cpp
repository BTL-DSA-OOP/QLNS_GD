#include "GD_Qly.h"
#include "ui_GD_Qly.h"
#include "GD_Them.h"
#include "GD_NVChung.h"
#include "GD_QLPhongBan.h"
#include "GD_QLDuAn.h"
#include "NhanSuData.h"
#include "ClassNhanSu.h"
#include <QMessageBox>
#include <QHeaderView>
#include <QDebug>
#include <QLocale>
#include <QDir>
#include <QDate>
#include <QFile>
#include <QTextStream>

GD_Qly::GD_Qly(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GD_Qly)
{
    ui->setupUi(this);

    m_qlpbWidget = new GD_QLPhongBan(this);
    ui->mainStackedWidget->addWidget(m_qlpbWidget);
    m_qlduAnWidget = new GD_QLDuAn(this);
    ui->mainStackedWidget->addWidget(m_qlduAnWidget);

    setupTable();

    // connect(ui->btnEdit, &QPushButton::clicked, this, &GD_Qly::on_btnEdit_clicked);
    // connect(ui->btnDelete, &QPushButton::clicked, this, &GD_Qly::on_btnDelete_clicked);
    // connect(ui->btnDetail, &QPushButton::clicked, this, &GD_Qly::on_btnDetail_clicked);
    // connect(ui->btnRefresh, &QPushButton::clicked, this, &GD_Qly::on_btnRefresh_clicked);
    // connect(ui->lineEditSearch, &QLineEdit::textChanged, this, &GD_Qly::on_lineEditSearch_textChanged);
    // connect(ui->btnAdd, &QPushButton::clicked, this, &GD_Qly::on_btnAdd_clicked);
    // connect(ui->btnNavEmployees, &QPushButton::clicked, this, &GD_Qly::on_btnNavEmployees_clicked);
    // connect(ui->btnNavDepartments, &QPushButton::clicked, this, &GD_Qly::on_btnNavDepartments_clicked);
    // connect(ui->btnNavProjects, &QPushButton::clicked, this, &GD_Qly::on_btnNavProjects_clicked);
    // connect(ui->btnNavAttendance, &QPushButton::clicked, this, &GD_Qly::on_btnNavAttendance_clicked);
    // connect(ui->btnLoadChamCong, &QPushButton::clicked, this, &GD_Qly::on_btnLoadChamCong_clicked);

    // Tải dữ liệu
    loadNhanSuData();
    displayNhanSuTable(g_danhSachNhanSu);
    loadNhanVienListToComboBox(); // Tải ds nhân viên vào combobox

    // Cài đặt trang chấm công
    ui->calendarChamCong->setSelectedDate(QDate::currentDate());
    // Thiết lập header cho bảng chấm công
    QHeaderView *headerCC = ui->tableChamCongTongHop->horizontalHeader();
    headerCC->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    headerCC->setSectionResizeMode(1, QHeaderView::Stretch);
    headerCC->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    headerCC->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    headerCC->setSectionResizeMode(4, QHeaderView::ResizeToContents);
}

GD_Qly::~GD_Qly()
{
    delete ui;
}

// --- CÁC HÀM TẢI DỮ LIỆU GỐC ---
void GD_Qly::setupTable()
{
    QHeaderView *header = ui->tableEmployees->horizontalHeader();
    header->setSectionResizeMode(0, QHeaderView::ResizeToContents); // Mã NV
    header->setSectionResizeMode(1, QHeaderView::Stretch); // Họ và Tên
    header->setSectionResizeMode(2, QHeaderView::ResizeToContents); // Giới Tính
    header->setSectionResizeMode(3, QHeaderView::ResizeToContents); // Phòng Ban
    header->setSectionResizeMode(4, QHeaderView::ResizeToContents); // Chức Vụ
    header->setSectionResizeMode(5, QHeaderView::ResizeToContents); // Mức Lương
}

void GD_Qly::loadNhanSuData()
{
    docNhanSuTuFile();
}

void GD_Qly::displayNhanSuTable(const std::vector<std::shared_ptr<NhanSu>>& list)
{
    ui->tableEmployees->setSortingEnabled(false);
    ui->tableEmployees->setRowCount(0);
    QLocale vnLocale(QLocale::Vietnamese, QLocale::Vietnam);

    for (const auto& ns : list)
    {
        int row = ui->tableEmployees->rowCount();
        ui->tableEmployees->insertRow(row);
        ui->tableEmployees->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(ns->getMaNhanVien()))); // <<< SỬA
        ui->tableEmployees->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(ns->getHoTen())));
        QString gioiTinh = (ns->getGioiTinh() == GioiTinh::NAM) ? "Nam" : "Nữ";
        ui->tableEmployees->setItem(row, 2, new QTableWidgetItem(gioiTinh));
        ui->tableEmployees->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(ns->getPhongBan().getTenPhongBan()))); // <<< SỬA
        ui->tableEmployees->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(ns->getViTriCongViec()))); // <<< SỬA
        double luong = ns->tinhLuongThucNhan();
        QTableWidgetItem *luongItem = new QTableWidgetItem(vnLocale.toString(luong, 'f', 0) + " VNĐ");
        luongItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        ui->tableEmployees->setItem(row, 5, luongItem);
    }

    ui->tableEmployees->setSortingEnabled(true);
}


// --- HÀM MỚI ---
void GD_Qly::loadNhanVienListToComboBox()
{
    ui->comboChamCongNhanVien->clear();
    ui->comboChamCongNhanVien->addItem("Tất cả nhân viên", "ALL"); // Lựa chọn xem tất cả
    for (const auto& ns : g_danhSachNhanSu)
    {
        ui->comboChamCongNhanVien->addItem(
            QString::fromStdString(ns->getHoTen()),
            QString::fromStdString(ns->getMaNhanVien())
            );
    }
}

// --- SLOTS MỚI ---
void GD_Qly::on_btnLoadChamCong_clicked()
{
    ui->tableChamCongTongHop->setRowCount(0); // Xóa bảng
    ui->tableChamCongTongHop->setSortingEnabled(false);

    QString maNV_selected = ui->comboChamCongNhanVien->currentData().toString();
    QDate selectedDate = ui->calendarChamCong->selectedDate();
    QString dateStr = selectedDate.toString("dd/MM/yyyy");

    QDir dir("ChamCong");
    if (!dir.exists()) {
        QMessageBox::warning(this, "Lỗi", "Thư mục ChamCong không tồn tại.");
        return;
    }

    QStringList fileList;
    if (maNV_selected == "ALL") {
        fileList = dir.entryList(QStringList() << "*_chamcong.txt", QDir::Files);
    } else {
        if (QFile::exists(dir.filePath(maNV_selected + "_chamcong.txt"))) {
            fileList.append(maNV_selected + "_chamcong.txt");
        }
    }

    for (const QString &fileName : fileList) {
        QFile file(dir.filePath(fileName));
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) continue;

        QString maNV = fileName.split("_").first();
        auto ns = timNhanSuTheoMa(maNV.toStdString());
        QString hoTen = ns ? QString::fromStdString(ns->getHoTen()) : "Không rõ";

        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (line.startsWith(dateStr)) { // Nếu là ngày được chọn
                QStringList parts = line.split(',');
                if (parts.size() == 4) {
                    int row = ui->tableChamCongTongHop->rowCount();
                    ui->tableChamCongTongHop->insertRow(row);
                    ui->tableChamCongTongHop->setItem(row, 0, new QTableWidgetItem(maNV));
                    ui->tableChamCongTongHop->setItem(row, 1, new QTableWidgetItem(hoTen));
                    ui->tableChamCongTongHop->setItem(row, 2, new QTableWidgetItem(parts[1]));
                    ui->tableChamCongTongHop->setItem(row, 3, new QTableWidgetItem(parts[2]));
                    ui->tableChamCongTongHop->setItem(row, 4, new QTableWidgetItem(parts[3]));
                }
                break;
            }
        }
        file.close();
    }

    if(ui->tableChamCongTongHop->rowCount() == 0) {
        QMessageBox::information(this, "Thông báo", "Không tìm thấy dữ liệu chấm công cho ngày đã chọn.");
    }

    ui->tableChamCongTongHop->setSortingEnabled(true);
}


void GD_Qly::on_btnAdd_clicked()
{
    GD_Them *formThem = new GD_Them(this);
    formThem->setWindowFlags(formThem->windowFlags() | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);

    if (formThem->exec() == QDialog::Accepted)
    {
        loadNhanSuData();
        displayNhanSuTable(g_danhSachNhanSu);
        loadNhanVienListToComboBox(); // <-- Cập nhật combobox
    }
    delete formThem;
}

void GD_Qly::on_btnEdit_clicked()
{
    int currentRow = ui->tableEmployees->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Chưa chọn", "Vui lòng chọn nhân sự cần sửa.");
        return;
    }

    QString maNV = ui->tableEmployees->item(currentRow, 0)->text();
    auto ns = timNhanSuTheoMa(maNV.toStdString());
    if (!ns) {
        QMessageBox::critical(this, "Lỗi", "Không tìm thấy nhân sự.");
        return;
    }

    GD_Them *formSua = new GD_Them(this);
    formSua->loadDataForEdit(ns);

    if (formSua->exec() == QDialog::Accepted)
    {
        loadNhanSuData();
        displayNhanSuTable(g_danhSachNhanSu);
        loadNhanVienListToComboBox();
    }
    delete formSua;
}

void GD_Qly::on_btnDelete_clicked()
{
    int currentRow = ui->tableEmployees->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Chưa chọn", "Vui lòng chọn nhân sự cần xóa.");
        return;
    }

    QString maNV = ui->tableEmployees->item(currentRow, 0)->text();
    QString hoTen = ui->tableEmployees->item(currentRow, 1)->text();

    auto reply = QMessageBox::question(this, "Xác nhận xóa",
                                       QString("Bạn có chắc chắn muốn xóa nhân sự '%1' (Mã: %2)?\nHành động này không thể hoàn tác.")
                                           .arg(hoTen, maNV),
                                       QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes)
    {
        g_danhSachNhanSu.erase(
            std::remove_if(g_danhSachNhanSu.begin(), g_danhSachNhanSu.end(),
                           [&](const std::shared_ptr<NhanSu>& ns) {
                               return ns->getMaNhanVien() == maNV.toStdString(); // <<< SỬA
                           }),
            g_danhSachNhanSu.end()
            );

        luuNhanSuVaoFile();
        xoaTaiKhoan(maNV.toStdString());

        QFile::remove("ChamCong/" + maNV + "_chamcong.txt");

        ui->tableEmployees->removeRow(currentRow);
        loadNhanVienListToComboBox(); // <-- Cập nhật combobox
        QMessageBox::information(this, "Thành công", "Đã xóa nhân sự thành công.");
    }
}

void GD_Qly::on_btnDetail_clicked()
{
    int currentRow = ui->tableEmployees->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Chưa chọn", "Vui lòng chọn nhân sự để xem chi tiết.");
        return;
    }

    QString maNV = ui->tableEmployees->item(currentRow, 0)->text();

    GD_NVChung *formChiTiet = new GD_NVChung(maNV, this);
    formChiTiet->setAttribute(Qt::WA_DeleteOnClose);
    formChiTiet->show();
}

void GD_Qly::on_btnRefresh_clicked()
{
    loadNhanSuData();
    displayNhanSuTable(g_danhSachNhanSu);
    loadNhanVienListToComboBox();
    ui->lineEditSearch->clear();
    QMessageBox::information(this, "Làm mới", "Đã tải lại danh sách nhân sự.");
}

void GD_Qly::on_lineEditSearch_textChanged(const QString &arg1)
{
    QString query = arg1.trimmed().toLower();
    if (query.isEmpty()) {
        displayNhanSuTable(g_danhSachNhanSu);
        return;
    }

    std::vector<std::shared_ptr<NhanSu>> filteredList;
    for (const auto& ns : g_danhSachNhanSu) {
        if (QString::fromStdString(ns->getHoTen()).toLower().contains(query) ||
            QString::fromStdString(ns->getMaNhanVien()).toLower().contains(query)) // <<< SỬA
        {
            filteredList.push_back(ns);
        }
    }
    displayNhanSuTable(filteredList);
}


// --- SLOTS ĐIỀU HƯỚNG ---
void GD_Qly::on_btnNavDepartments_clicked()
{
    ui->mainStackedWidget->setCurrentWidget(m_qlpbWidget);
}
void GD_Qly::on_btnNavEmployees_clicked()
{
    ui->mainStackedWidget->setCurrentWidget(ui->page_employees);
}
void GD_Qly::on_btnNavProjects_clicked()
{
    ui->mainStackedWidget->setCurrentWidget(m_qlduAnWidget);
}
void GD_Qly::on_btnNavAttendance_clicked()
{
    ui->mainStackedWidget->setCurrentWidget(ui->page_attendance);
    loadNhanVienListToComboBox();
}
