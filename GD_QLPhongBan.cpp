#include "GD_QLPhongBan.h"
#include "ui_GD_QLPhongBan.h"
#include "NhanSuData.h"
#include <QHeaderView>
#include <QTableWidgetItem>
#include <QShowEvent>
#include <QMessageBox>

GD_QLPhongBan::GD_QLPhongBan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GD_QLPhongBan)
{
    ui->setupUi(this);
    setupTables();
    clearChiTiet();
    setEditMode(false);
    ui->splitter->setSizes(QList<int>() << 400 << 600);
}

GD_QLPhongBan::~GD_QLPhongBan()
{
    delete ui;
}

void GD_QLPhongBan::setupTables()
{
    ui->tablePhongBan->setColumnCount(3);
    ui->tablePhongBan->setHorizontalHeaderLabels({"Mã PB", "Tên Phòng Ban", "Số Lượng NV"});
    ui->tablePhongBan->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->tablePhongBan->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tablePhongBan->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui->tablePhongBan->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tablePhongBan->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableChiTietNV->setColumnCount(3);
    ui->tableChiTietNV->setHorizontalHeaderLabels({"Mã NV", "Họ và Tên", "Vị trí"});
    ui->tableChiTietNV->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->tableChiTietNV->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableChiTietNV->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui->tableChiTietNV->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

// Tự động tải lại dữ liệu
void GD_QLPhongBan::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    if (m_currentMode == EditMode::Add) {
        refreshData();
    }
}
void GD_QLPhongBan::setEditMode(bool isEditing)
{
    ui->frameControls->setEnabled(!isEditing); // Khung chứa nút Sửa/Xóa
    ui->groupBox_DanhSach->setEnabled(!isEditing);
    ui->groupBox_ChiTiet->setEnabled(!isEditing);

    ui->btnSuaPB->setEnabled(!isEditing);
    ui->btnXoaPB->setEnabled(!isEditing);
    ui->btnRefresh->setEnabled(!isEditing);
    ui->btnThemPB->setEnabled(!isEditing);


    if (isEditing) {
        // Chuyển sang chế độ SỬA
        m_currentMode = EditMode::Edit;
        ui->groupNhapLieu->setTitle("Sửa Tên Phòng Ban");
        ui->txtMaPB->setReadOnly(true); // Khóa Mã PB khi Sửa
        ui->txtTenPB->setFocus();
    } else {
        // Reset sang chế độ THÊM
        m_currentMode = EditMode::Add;
        ui->groupNhapLieu->setTitle("Thêm Phòng Ban Mới");
        ui->txtMaPB->clear();
        ui->txtTenPB->clear();
        ui->txtMaPB->setReadOnly(false);
        ui->txtMaPB->setFocus();

        // Kích hoạt lại các nút sau khi Hủy
        ui->frameControls->setEnabled(true);
        ui->groupBox_DanhSach->setEnabled(true);
        ui->groupBox_ChiTiet->setEnabled(true);
        ui->btnSuaPB->setEnabled(true);
        ui->btnXoaPB->setEnabled(true);
        ui->btnRefresh->setEnabled(true);
        ui->btnThemPB->setEnabled(true);
    }
}


// NÚT LÀM MỚI
void GD_QLPhongBan::on_btnRefresh_clicked()
{
    docPhongBanTuFile();
    docNhanSuTuFile();
    refreshData();
    QMessageBox::information(this, "Làm mới", "Đã tải lại dữ liệu phòng ban và nhân sự.");
}

void GD_QLPhongBan::refreshData()
{
    m_phongBanData.clear();
    ui->tablePhongBan->setRowCount(0);
    ui->tablePhongBan->setSortingEnabled(false);
    clearChiTiet();

    for (const auto& pb : g_danhSachPhongBan) {
        m_phongBanData[pb.getMaPhongBan()].tenPB = pb.getTenPhongBan();
    }

    for (const auto& ns : g_danhSachNhanSu) {
        std::string maPB = ns->getPhongBan().getMaPhongBan();
        if (!maPB.empty() && m_phongBanData.count(maPB)) {
            m_phongBanData[maPB].soLuongNV++;
            if (dynamic_cast<QuanLy*>(ns.get())) m_phongBanData[maPB].quanLy++;
            else if (dynamic_cast<NhanVienChinhThuc*>(ns.get())) m_phongBanData[maPB].nvChinhThuc++;
            else if (dynamic_cast<NhanVienThuViec*>(ns.get())) m_phongBanData[maPB].nvThuViec++;
        }
    }

    for (const auto& pair : m_phongBanData) {
        int row = ui->tablePhongBan->rowCount();
        ui->tablePhongBan->insertRow(row);
        QString maPB = QString::fromStdString(pair.first);
        QTableWidgetItem *itemMaPB = new QTableWidgetItem(maPB);
        itemMaPB->setData(Qt::UserRole, maPB);
        ui->tablePhongBan->setItem(row, 0, itemMaPB);
        ui->tablePhongBan->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(pair.second.tenPB)));
        ui->tablePhongBan->setItem(row, 2, new QTableWidgetItem(QString::number(pair.second.soLuongNV)));
    }

    ui->tablePhongBan->setSortingEnabled(true);
}

void GD_QLPhongBan::on_tablePhongBan_itemSelectionChanged()
{
    int currentRow = ui->tablePhongBan->currentRow();
    if (currentRow < 0) {
        clearChiTiet();
        return;
    }
    QString maPB = ui->tablePhongBan->item(currentRow, 0)->data(Qt::UserRole).toString();
    displayPhongBanDetails(maPB.toStdString());
}

void GD_QLPhongBan::displayPhongBanDetails(const std::string &maPB)
{
    if (!m_phongBanData.count(maPB)) {
        clearChiTiet();
        return;
    }
    const auto& stats = m_phongBanData.at(maPB);
    ui->lblTenPhongBan->setText(QString::fromStdString(stats.tenPB));
    ui->lblTongSoNV->setText(QString::number(stats.soLuongNV));
    ui->lblSoQuanLy->setText(QString::number(stats.quanLy));
    ui->lblSoChinhThuc->setText(QString::number(stats.nvChinhThuc));
    ui->lblSoThuViec->setText(QString::number(stats.nvThuViec));

    ui->tableChiTietNV->setRowCount(0);
    ui->tableChiTietNV->setSortingEnabled(false);
    for (const auto& ns : g_danhSachNhanSu) {
        if (ns->getPhongBan().getMaPhongBan() == maPB) {
            int row = ui->tableChiTietNV->rowCount();
            ui->tableChiTietNV->insertRow(row);
            ui->tableChiTietNV->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(ns->getMaNhanVien())));
            ui->tableChiTietNV->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(ns->getHoTen())));
            ui->tableChiTietNV->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(ns->getViTriCongViec())));
        }
    }
    ui->tableChiTietNV->setSortingEnabled(true);
}

void GD_QLPhongBan::clearChiTiet()
{
    ui->lblTenPhongBan->setText("Chưa chọn phòng ban");
    ui->lblTongSoNV->setText("0");
    ui->lblSoQuanLy->setText("0");
    ui->lblSoChinhThuc->setText("0");
    ui->lblSoThuViec->setText("0");
    ui->tableChiTietNV->setRowCount(0);
}


void GD_QLPhongBan::on_btnThemPB_clicked()
{
    setEditMode(false);
}
// -------------------------


void GD_QLPhongBan::on_btnSuaPB_clicked()
{
    int currentRow = ui->tablePhongBan->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Chưa chọn", "Vui lòng chọn một phòng ban để sửa.");
        return;
    }

    m_editingMaPB = ui->tablePhongBan->item(currentRow, 0)->data(Qt::UserRole).toString();
    QString tenPB = ui->tablePhongBan->item(currentRow, 1)->text();

    setEditMode(true); // Chuyển sang chế độ Sửa

    ui->txtMaPB->setText(m_editingMaPB);
    ui->txtTenPB->setText(tenPB);
    ui->txtMaPB->setFocus();
}

void GD_QLPhongBan::on_btnLuu_clicked()
{
    QString maPB = ui->txtMaPB->text().trimmed();
    QString tenPB = ui->txtTenPB->text().trimmed();

    if (maPB.isEmpty() || tenPB.isEmpty()) {
        QMessageBox::warning(this, "Thiếu thông tin", "Mã và Tên phòng ban không được để trống.");
        ui->btnLuu->setEnabled(true); // Kích hoạt lại nút nếu lỗi
        return;
    }

    if (m_currentMode == EditMode::Add) {
        if (timPhongBanTheoMa(maPB.toStdString())) {
            QMessageBox::critical(this, "Lỗi", "Mã phòng ban đã tồn tại. Vui lòng chọn mã khác.");
            ui->btnLuu->setEnabled(true); // Kích hoạt lại nút nếu lỗi
            return;
        }
        g_danhSachPhongBan.emplace_back(maPB.toStdString(), tenPB.toStdString());
    }
    else if (m_currentMode == EditMode::Edit) {
        PhongBan* pb = timPhongBanTheoMa(m_editingMaPB.toStdString());
        if (pb) {
            pb->setTenPhongBan(tenPB.toStdString());
            bool hasChanged = false;
            for (auto& ns : g_danhSachNhanSu) {
                if (ns->getPhongBan().getMaPhongBan() == m_editingMaPB.toStdString()) {
                    ns->setPhongBan(PhongBan(m_editingMaPB.toStdString(), tenPB.toStdString()));
                    hasChanged = true;
                }
            }
            if(hasChanged) luuNhanSuVaoFile();
        }
    }
    luuPhongBanVaoFile();
    refreshData();
    setEditMode(false);
}

void GD_QLPhongBan::on_btnHuy_clicked()
{
    setEditMode(false);
}

void GD_QLPhongBan::on_btnXoaPB_clicked()
{
    int currentRow = ui->tablePhongBan->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Chưa chọn", "Vui lòng chọn phòng ban cần xóa.");
        return;
    }

    QString maPB = ui->tablePhongBan->item(currentRow, 0)->data(Qt::UserRole).toString();
    QString tenPB = ui->tablePhongBan->item(currentRow, 1)->text();

    for (const auto& ns : g_danhSachNhanSu) {
        if (ns->getPhongBan().getMaPhongBan() == maPB.toStdString()) {
            QMessageBox::critical(this, "Không thể xóa", QString("Không thể xóa phòng ban '%1' vì vẫn còn nhân viên.").arg(tenPB));
            return;
        }
    }

    auto reply = QMessageBox::question(this, "Xác nhận xóa", QString("Bạn có chắc chắn muốn xóa phòng ban '%1'?").arg(tenPB), QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        g_danhSachPhongBan.erase(
            std::remove_if(g_danhSachPhongBan.begin(), g_danhSachPhongBan.end(),
                           [&](const PhongBan& pb) { return pb.getMaPhongBan() == maPB.toStdString(); }),
            g_danhSachPhongBan.end()
            );
        luuPhongBanVaoFile();
        refreshData();
        QMessageBox::information(this, "Thành công", "Đã xóa phòng ban.");
    }
}
