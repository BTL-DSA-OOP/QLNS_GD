#include "GD_QLDuAn.h"
#include "ui_GD_QLDuAn.h"
#include "ClassNhanSu.h"
#include "NhanSuData.h"
#include <QMessageBox>
#include <QHeaderView>
#include <algorithm>
#include <QDate>

GD_QLDuAn::GD_QLDuAn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GD_QLDuAn),
    isEditMode(false)
{
    ui->setupUi(this);

    setupTable();

    // Ẩn khung nhập liệu khi mới vào
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

        ui->tableProjects->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(duAn.getNgayBatDau().toString()))); // Giả định NgayThang::toString()

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

void GD_QLDuAn::loadNguoiPhuTrachComboBox()
{
    ui->comboNguoiPT->clear();
    ui->comboNguoiPT->addItem("Chọn người phụ trách", QVariant("")); // Thêm mục trống

    // Tải danh sách từ g_danhSachNhanSu
    for(const auto& ns : g_danhSachNhanSu)
    {
        if(ns->getTrangThai() == TrangThaiNhanVien::DANG_LAM)
        {
            QString displayText = QString::fromStdString(ns->getHoTen() + " (" + ns->getMaNhanVien() + ")");
            ui->comboNguoiPT->addItem(displayText, QVariant(QString::fromStdString(ns->getMaNhanVien())));
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
}

void GD_QLDuAn::setInputMode(bool isEditing)
{
    isEditMode = isEditing;
    ui->txtMaDA->setReadOnly(isEditing);
    ui->groupBox_Input->setVisible(true);
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

void GD_QLDuAn::on_btnEditProject_clicked()
{
    int currentRow = ui->tableProjects->currentRow();
    if (currentRow < 0) {
        return;
    }

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

    // Chuyển NgayThang sang QDate
    NgayThang bd = da->getNgayBatDau();
    NgayThang kt = da->getNgayKetThuc();
    ui->dateNgayBD->setDate(QDate(bd.getNam(), bd.getThang(), bd.getNgay()));
    ui->dateNgayKT->setDate(QDate(kt.getNam(), kt.getThang(), kt.getNgay()));

    // Tìm người phụ trách trong combobox
    QString maPT = QString::fromStdString(da->getNguoiPhuTrach());
    int index = ui->comboNguoiPT->findData(QVariant(maPT));
    if (index != -1) {
        ui->comboNguoiPT->setCurrentIndex(index);
    } else {
        ui->comboNguoiPT->setCurrentIndex(0); // Không tìm thấy
    }

    // Lưu mã DA hiện tại và chuyển chế độ
    currentEditMaDA = maDA;
    setInputMode(true); // Chuyển sang chế độ Sửa
}

void GD_QLDuAn::on_btnSaveChanges_clicked()
{
    // Lấy dữ liệu từ form
    QString maDA = ui->txtMaDA->text().trimmed();
    QString tenDA = ui->txtTenDA->text().trimmed();
    QString maPT = ui->comboNguoiPT->currentData().toString();
    double kinhPhi = ui->spinKinhPhi->value();
    QDate ngayBD_Q = ui->dateNgayBD->date();
    QDate ngayKT_Q = ui->dateNgayKT->date();

    // Chuyển QDate sang NgayThang
    NgayThang ngayBD(ngayBD_Q.day(), ngayBD_Q.month(), ngayBD_Q.year());
    NgayThang ngayKT(ngayKT_Q.day(), ngayKT_Q.month(), ngayKT_Q.year());

    // --- Validation (Giống logic console) ---
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

        QMessageBox::information(this, "Thành công", "Đã cập nhật thông tin dự án.");
    }
    else
    {
        if (timDuAnTheoMa(maDA.toStdString())) {
            QMessageBox::warning(this, "Trùng lặp", "Mã dự án này đã tồn tại.");
            return;
        }
        std::vector<std::string> thanhVien; // Thêm mới thì ds thành viên trống
        DuAn duAnMoi(maDA.toStdString(), tenDA.toStdString(), ngayBD, ngayKT, maPT.toStdString(), thanhVien, kinhPhi);
        g_danhSachDuAn.push_back(duAnMoi);

        QMessageBox::information(this, "Thành công", "Đã thêm dự án mới thành công.");
    }

    luuDuAnVaoFile(); // Lưu thay đổi ra file
    displayProjectsTable(g_danhSachDuAn); // Tải lại bảng
    ui->groupBox_Input->setVisible(false); // Ẩn form
    clearInputFields(); // Xóa sạch form
    isEditMode = false; // Reset chế độ
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

        luuDuAnVaoFile(); // Lưu lại file
        displayProjectsTable(g_danhSachDuAn); // Tải lại bảng
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
    docNhanSuTuFile(); // Đọc lại cả nhân sự
    docDuAnTuFile(); // Đọc lại từ file
    loadNguoiPhuTrachComboBox(); // Tải lại combobox
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
        // Tìm theo cả người phụ trách
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
