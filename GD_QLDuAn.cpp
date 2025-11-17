#include "GD_QLDuAn.h"
#include "ui_GD_QLDuAn.h"
#include "ClassNhanSu.h"
#include "NhanSuData.h"
#include <QMessageBox>
#include <QHeaderView>
#include <algorithm>
#include <QDate>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QListWidgetItem>

GD_QLDuAn::GD_QLDuAn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GD_QLDuAn),
    isEditMode(false)
{
    ui->setupUi(this);

    setupTable();

    ui->groupBox_Input->setVisible(false);

    // Vô hiệu hóa các nút chức năng khi chưa chọn
    ui->btnEditProject->setEnabled(false);
    ui->btnDeleteProject->setEnabled(false);
    ui->btnDetailProject->setEnabled(false);
    ui->btnCompleteProject->setEnabled(false);

    // Đọc dữ liệu từ file
    docNhanSuTuFile();
    docDuAnTuFile();

    loadNguoiPhuTrachComboBox(); // Tải danh sách người phụ trách
    displayProjectsTable(g_danhSachDuAn);
}

GD_QLDuAn::~GD_QLDuAn()
{
    delete ui;
}

void GD_QLDuAn::setupTable()
{
    QHeaderView *header = ui->tableProjects->horizontalHeader();
    header->setSectionResizeMode(0, QHeaderView::ResizeToContents); // Mã DA
    header->setSectionResizeMode(2, QHeaderView::ResizeToContents); // Người Phụ Trách
    header->setSectionResizeMode(3, QHeaderView::ResizeToContents); // Ngày Bắt Đầu
    header->setSectionResizeMode(4, QHeaderView::ResizeToContents); // Trạng Thái
    header->setSectionResizeMode(5, QHeaderView::ResizeToContents); // Số Lượng TV
    header->setSectionResizeMode(1, QHeaderView::Stretch); // Tên Dự Án
}

void GD_QLDuAn::displayProjectsTable(const std::vector<DuAn>& list)
{
    ui->tableProjects->setRowCount(0);
    ui->tableProjects->setSortingEnabled(false);

    for (const auto& duAn : list)
    {
        int row = ui->tableProjects->rowCount();
        ui->tableProjects->insertRow(row);

        ui->tableProjects->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(duAn.getMaDuAn())));
        ui->tableProjects->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(duAn.getTenDuAn())));

        // Tìm tên người phụ trách từ mã
        auto nguoiPhuTrach = timNhanSuTheoMa(duAn.getNguoiPhuTrach());
        QString tenPhuTrach = "N/A";
        if (nguoiPhuTrach) {
            tenPhuTrach = QString::fromStdString(nguoiPhuTrach->getHoTen());
        }
        ui->tableProjects->setItem(row, 2, new QTableWidgetItem(tenPhuTrach));

        ui->tableProjects->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(duAn.getNgayBatDau().toString())));

        QString trangThai = duAn.isDaHoanThanh() ? "Hoàn thành" : "Đang thực hiện";
        QTableWidgetItem *trangThaiItem = new QTableWidgetItem(trangThai);
        if(duAn.isDaHoanThanh()) {
            trangThaiItem->setForeground(QBrush(Qt::darkGreen));
        }
        ui->tableProjects->setItem(row, 4, trangThaiItem);

        ui->tableProjects->setItem(row, 5, new QTableWidgetItem(QString::number(duAn.getSoLuongThanhVien())));
    }
    ui->tableProjects->setSortingEnabled(true);
}

// Chỉ load Nhân viên chính thức hoặc Quản lý
void GD_QLDuAn::loadNguoiPhuTrachComboBox()
{
    ui->comboNguoiPT->clear();
    ui->comboNguoiPT->addItem("Chọn người phụ trách", QVariant(""));

    for(const auto& ns : g_danhSachNhanSu)
    {
        if(ns->getTrangThai() == TrangThaiNhanVien::DANG_LAM)
        {
            // Kiểm tra kiểu đối tượng
            bool isOfficial = (std::dynamic_pointer_cast<NhanVienChinhThuc>(ns) != nullptr);
            bool isManager = (std::dynamic_pointer_cast<QuanLy>(ns) != nullptr);

            if (isOfficial || isManager) {
                QString displayText = QString::fromStdString(ns->getHoTen() + " (" + ns->getMaNhanVien() + ")");
                ui->comboNguoiPT->addItem(displayText, QVariant(QString::fromStdString(ns->getMaNhanVien())));
            }
        }
    }
}

void GD_QLDuAn::clearInputFields()
{
    ui->txtMaDA->clear();
    ui->txtTenDA->clear();
    ui->dateNgayBD->setDate(QDate::currentDate());
    ui->dateNgayKT->setDate(QDate::currentDate().addMonths(6));
    ui->comboNguoiPT->setCurrentIndex(0);
    ui->spinKinhPhi->setValue(0.0);

    //Xóa danh sách thành viên tạm
    currentSelectedMembers.clear();
    ui->txtMembers->clear();
}

void GD_QLDuAn::setInputMode(bool isEditing)
{
    isEditMode = isEditing;
    ui->txtMaDA->setReadOnly(isEditing);
    ui->groupBox_Input->setVisible(true);
}

void GD_QLDuAn::updateMembersDisplay()
{
    QStringList names;
    for (const std::string& id : currentSelectedMembers) {
        auto ns = timNhanSuTheoMa(id);
        if (ns) {
            names << QString::fromStdString(ns->getHoTen());
        } else {
            names << QString::fromStdString(id);
        }
    }
    ui->txtMembers->setText(names.join(", "));
    ui->txtMembers->setToolTip(ui->txtMembers->text());
}

void GD_QLDuAn::on_tableProjects_itemSelectionChanged()
{
    bool selected = ui->tableProjects->selectionModel()->hasSelection();
    ui->btnEditProject->setEnabled(selected);
    ui->btnDeleteProject->setEnabled(selected);
    ui->btnDetailProject->setEnabled(selected);
    ui->btnCompleteProject->setEnabled(selected);
}

void GD_QLDuAn::on_btnAddProject_clicked()
{
    clearInputFields();
    setInputMode(false);
    ui->txtMaDA->setFocus();
}

// Sửa dự án: Load thêm danh sách thành viên
void GD_QLDuAn::on_btnEditProject_clicked()
{
    int currentRow = ui->tableProjects->currentRow();
    if (currentRow < 0) return;

    QString maDA = ui->tableProjects->item(currentRow, 0)->text();
    DuAn* da = timDuAnTheoMa(maDA.toStdString());
    if (!da) {
        QMessageBox::critical(this, "Lỗi", "Không tìm thấy dự án trong dữ liệu.");
        return;
    }

    // Tải dữ liệu vào form
    ui->txtMaDA->setText(QString::fromStdString(da->getMaDuAn()));
    ui->txtTenDA->setText(QString::fromStdString(da->getTenDuAn()));
    ui->spinKinhPhi->setValue(da->getKinhPhi());

    NgayThang bd = da->getNgayBatDau();
    NgayThang kt = da->getNgayKetThuc();
    ui->dateNgayBD->setDate(QDate(bd.getNam(), bd.getThang(), bd.getNgay()));
    ui->dateNgayKT->setDate(QDate(kt.getNam(), kt.getThang(), kt.getNgay()));

    QString maPT = QString::fromStdString(da->getNguoiPhuTrach());
    int index = ui->comboNguoiPT->findData(QVariant(maPT));
    if (index != -1) ui->comboNguoiPT->setCurrentIndex(index);
    else ui->comboNguoiPT->setCurrentIndex(0);

    // [MỚI] Load thành viên
    currentSelectedMembers = da->getDanhSachThanhVien();
    updateMembersDisplay();

    currentEditMaDA = maDA;
    setInputMode(true);
}

// Xử lý chọn thành viên qua Dialog
void GD_QLDuAn::on_btnSelectMembers_clicked()
{
    QDialog dialog(this);
    dialog.setWindowTitle("Chọn thành viên dự án");
    dialog.resize(400, 500);
    QVBoxLayout layout(&dialog);

    QListWidget listWidget;
    QString maPT = ui->comboNguoiPT->currentData().toString(); // Lấy mã người PT để loại trừ

    for (const auto& ns : g_danhSachNhanSu) {
        if (ns->getTrangThai() != TrangThaiNhanVien::DANG_LAM) continue;

        // Không cho chọn người đang làm Quản lý dự án vào danh sách thành viên
        if (ns->getMaNhanVien() == maPT.toStdString()) continue;

        QListWidgetItem* item = new QListWidgetItem(
            QString::fromStdString(ns->getHoTen() + " (" + ns->getMaNhanVien() + ")"),
            &listWidget
            );
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setData(Qt::UserRole, QString::fromStdString(ns->getMaNhanVien()));

        // Kiểm tra đã chọn trước đó chưa
        bool isSelected = false;
        for (const std::string& selectedID : currentSelectedMembers) {
            if (selectedID == ns->getMaNhanVien()) {
                isSelected = true;
                break;
            }
        }
        item->setCheckState(isSelected ? Qt::Checked : Qt::Unchecked);
    }

    layout.addWidget(&listWidget);

    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    connect(&buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(&buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);
    layout.addWidget(&buttonBox);

    if (dialog.exec() == QDialog::Accepted) {
        currentSelectedMembers.clear();
        for (int i = 0; i < listWidget.count(); ++i) {
            QListWidgetItem* item = listWidget.item(i);
            if (item->checkState() == Qt::Checked) {
                currentSelectedMembers.push_back(item->data(Qt::UserRole).toString().toStdString());
            }
        }
        updateMembersDisplay();
    }
}

// Lưu dự án kèm danh sách thành viên
void GD_QLDuAn::on_btnSaveChanges_clicked()
{
    QString maDA = ui->txtMaDA->text().trimmed();
    QString tenDA = ui->txtTenDA->text().trimmed();
    QString maPT = ui->comboNguoiPT->currentData().toString();
    double kinhPhi = ui->spinKinhPhi->value();
    QDate ngayBD_Q = ui->dateNgayBD->date();
    QDate ngayKT_Q = ui->dateNgayKT->date();

    NgayThang ngayBD(ngayBD_Q.day(), ngayBD_Q.month(), ngayBD_Q.year());
    NgayThang ngayKT(ngayKT_Q.day(), ngayKT_Q.month(), ngayKT_Q.year());

    if (maDA.isEmpty() || tenDA.isEmpty()) {
        QMessageBox::warning(this, "Thiếu thông tin", "Mã dự án và Tên dự án không được để trống.");
        return;
    }
    if (maPT.isEmpty()) {
        QMessageBox::warning(this, "Thiếu thông tin", "Vui lòng chọn người phụ trách.");
        return;
    }

    if (isEditMode)
    {
        DuAn* da = timDuAnTheoMa(currentEditMaDA.toStdString());
        if (!da) {
            QMessageBox::critical(this, "Lỗi", "Không tìm thấy dự án để cập nhật.");
            return;
        }
        da->setTenDuAn(tenDA.toStdString());
        da->setNguoiPhuTrach(maPT.toStdString());
        da->setKinhPhi(kinhPhi);
        da->setNgayBatDau(ngayBD);
        da->setNgayKetThuc(ngayKT);

        // Cập nhật thành viên
        da->setDanhSachThanhVien(currentSelectedMembers);

        QMessageBox::information(this, "Thành công", "Đã cập nhật thông tin dự án.");
    }
    else
    {
        if (timDuAnTheoMa(maDA.toStdString())) {
            QMessageBox::warning(this, "Trùng lặp", "Mã dự án này đã tồn tại.");
            return;
        }

        // Tạo dự án mới với danh sách thành viên đã chọn
        DuAn duAnMoi(maDA.toStdString(), tenDA.toStdString(), ngayBD, ngayKT, maPT.toStdString(), currentSelectedMembers, kinhPhi);
        g_danhSachDuAn.push_back(duAnMoi);

        QMessageBox::information(this, "Thành công", "Đã thêm dự án mới thành công.");
    }

    luuDuAnVaoFile();
    displayProjectsTable(g_danhSachDuAn);
    ui->groupBox_Input->setVisible(false);
    clearInputFields();
    isEditMode = false;
}

void GD_QLDuAn::on_btnCancelChanges_clicked()
{
    ui->groupBox_Input->setVisible(false);
    clearInputFields();
    isEditMode = false;
}

void GD_QLDuAn::on_btnDeleteProject_clicked()
{
    int currentRow = ui->tableProjects->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Chưa chọn", "Vui lòng chọn dự án cần xóa.");
        return;
    }

    QString maDA = ui->tableProjects->item(currentRow, 0)->text();
    QString tenDA = ui->tableProjects->item(currentRow, 1)->text();

    auto reply = QMessageBox::question(this, "Xác nhận xóa",
                                       QString("Bạn có chắc chắn muốn xóa dự án '%1' (Mã: %2)?\nViệc này sẽ xóa dự án vĩnh viễn.")
                                           .arg(tenDA, maDA),
                                       QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes)
    {
        g_danhSachDuAn.erase(
            std::remove_if(g_danhSachDuAn.begin(), g_danhSachDuAn.end(),
                           [&](const DuAn& da) {
                               return da.getMaDuAn() == maDA.toStdString();
                           }),
            g_danhSachDuAn.end()
            );

        luuDuAnVaoFile();
        displayProjectsTable(g_danhSachDuAn);
        QMessageBox::information(this, "Thành công", "Đã xóa dự án thành công.");
    }
}

void GD_QLDuAn::on_btnCompleteProject_clicked()
{
    int currentRow = ui->tableProjects->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Chưa chọn", "Vui lòng chọn dự án để đánh dấu hoàn thành.");
        return;
    }

    QString maDA = ui->tableProjects->item(currentRow, 0)->text();
    DuAn* da = timDuAnTheoMa(maDA.toStdString());
    if (!da) {
        QMessageBox::critical(this, "Lỗi", "Không tìm thấy dự án trong dữ liệu.");
        return;
    }

    if (da->isDaHoanThanh()) {
        QMessageBox::information(this, "Thông báo", "Dự án này đã được đánh dấu hoàn thành từ trước.");
        return;
    }

    auto reply = QMessageBox::question(this, "Xác nhận",
                                       QString("Bạn có muốn đánh dấu dự án '%1' là 'Hoàn thành' không?")
                                           .arg(QString::fromStdString(da->getTenDuAn())),
                                       QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes)
    {
        da->setDaHoanThanh(true);
        luuDuAnVaoFile();
        displayProjectsTable(g_danhSachDuAn);
        QMessageBox::information(this, "Thành công", "Đã cập nhật trạng thái dự án.");
    }
}

void GD_QLDuAn::on_btnRefresh_clicked()
{
    docNhanSuTuFile();
    docDuAnTuFile();
    loadNguoiPhuTrachComboBox();
    displayProjectsTable(g_danhSachDuAn);
    ui->lineEditSearch->clear();
    QMessageBox::information(this, "Thông Báo", "Đã làm mới danh sách dự án!");
}

void GD_QLDuAn::on_lineEditSearch_textChanged(const QString &arg1)
{
    QString query = arg1.trimmed().toLower();
    if (query.isEmpty()) {
        displayProjectsTable(g_danhSachDuAn);
        return;
    }

    std::vector<DuAn> filteredList;
    for (const auto& da : g_danhSachDuAn) {
        QString tenPT = "N/A";
        auto ns = timNhanSuTheoMa(da.getNguoiPhuTrach());
        if(ns) tenPT = QString::fromStdString(ns->getHoTen());

        if (QString::fromStdString(da.getTenDuAn()).toLower().contains(query) ||
            QString::fromStdString(da.getMaDuAn()).toLower().contains(query) ||
            tenPT.toLower().contains(query))
        {
            filteredList.push_back(da);
        }
    }
    displayProjectsTable(filteredList);
}
