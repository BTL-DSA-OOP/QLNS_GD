#include "GD_Them.h"
#include "ui_GD_Them.h"
#include "NhanSuData.h"
#include "ClassNhanSu.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>
#include <QDebug>
#include <QLocale> // <<< THÊM THƯ VIỆN NÀY

bool isUsernameTaken(const QString& username);

GD_Them::GD_Them(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GD_Them),
    isEditMode(false)
{
    ui->setupUi(this);

    QLocale vnLocale(QLocale::Vietnamese, QLocale::Vietnam);

    QList<QDoubleSpinBox*> currencySpinBoxes = {
        ui->spinPhuCapThucTap,
        ui->spinLuongCoBan_CT,
        ui->spinPhuCapChucVu_CT,
        ui->spinPhuCapAnTrua,
        ui->spinPhuCapXangXe,
        ui->spinLuongCoBan_QL,
        ui->spinPhuCapQuanLy,
        ui->spinThuongHieuQua
    };

    for (auto spinBox : currencySpinBoxes)
    {
        spinBox->setLocale(vnLocale); // Dùng locale VN
        spinBox->setGroupSeparatorShown(true); // Hiển thị dấu phân cách (VD: 1.000.000)
        spinBox->setDecimals(0); // Tiền VNĐ không cần số thập phân
    }

    // Cài đặt riêng cho spinbox "Hệ số lương" (cần 2 số thập phân)
    ui->spinHeSoLuong_CT->setLocale(vnLocale);
    ui->spinHeSoLuong_QL->setLocale(vnLocale);

    ui->cmbLoaiNhanSu->clear();
    ui->cmbLoaiNhanSu->addItem("Nhân viên thử việc", "NhanVienThuViec");
    ui->cmbLoaiNhanSu->addItem("Nhân viên chính thức", "NhanVienChinhThuc");
    ui->cmbLoaiNhanSu->addItem("Quản lý", "QuanLy");

    ui->cmbPhongBan->addItem("Phòng Kỹ thuật", "TECH");
    ui->cmbPhongBan->addItem("Phòng Nhân sự", "HR");
    ui->cmbPhongBan->addItem("Phòng Kinh doanh", "SALES");

    connect(ui->cmbLoaiNhanSu, &QComboBox::currentIndexChanged, this, &GD_Them::updateSalaryFields);
    // connect(ui->btnThem, &QPushButton::clicked, this, &GD_Them::on_btnThem_clicked);
    // connect(ui->btnThemThanNhan, &QPushButton::clicked, this, &GD_Them::on_btnThemThanNhan_clicked);
    // connect(ui->btnXoaThanNhan, &QPushButton::clicked, this, &GD_Them::on_btnXoaThanNhan_clicked);

    connect(ui->txtUsername, &QLineEdit::textChanged, ui->txtMaNhanVien, &QLineEdit::setText);
    ui->txtMaNhanVien->setReadOnly(true);

    setupThanNhanTable();
    updateSalaryFields();
}

GD_Them::~GD_Them()
{
    delete ui;
}

void GD_Them::setupThanNhanTable()
{
    ui->tableThanNhan->setColumnCount(3);
    ui->tableThanNhan->setHorizontalHeaderLabels({"Họ và Tên", "Quan hệ", "Số điện thoại"});
    ui->tableThanNhan->horizontalHeader()->setStretchLastSection(true);
}

void GD_Them::updateSalaryFields()
{
    QString selectedType = ui->cmbLoaiNhanSu->currentText();

    ui->groupThuViec->setVisible(selectedType == "Nhân viên thử việc");
    ui->groupChinhThuc->setVisible(selectedType == "Nhân viên chính thức");
    ui->groupQuanLy->setVisible(selectedType == "Quản lý");

    bool showThanNhan = (selectedType == "Nhân viên chính thức" || selectedType == "Quản lý");
    ui->groupThanNhan->setVisible(showThanNhan);
}

bool isEmailValid(const QString &email) {
    static const QRegularExpression re("^[\\w.-]+@[\\w.-]+\\.[a-zA-Z]{2,}$");
    return re.match(email).hasMatch();
}


// --- HÀM Tải dữ liệu lên form ---
void GD_Them::loadDataForEdit(std::shared_ptr<NhanSu> ns)
{
    isEditMode = true;
    m_editMaNV = QString::fromStdString(ns->getMaNhanVien());
    ui->lblFormTitle->setText("Cập nhật thông tin nhân sự");
    this->setWindowTitle("Cập nhật thông tin nhân sự");
    ui->btnThem->setText("Cập nhật");

    ui->txtUsername->setText(m_editMaNV);
    ui->txtUsername->setReadOnly(true);
    ui->txtPassword->setText("********");
    ui->txtConfirmPassword->setText("********");
    ui->txtEmail->setText(QString::fromStdString(ns->getEmail()));

    ui->txtMaNhanVien->setText(m_editMaNV);
    ui->txtHoTen->setText(QString::fromStdString(ns->getHoTen()));
    ui->txtCCCD->setText(QString::fromStdString(ns->getCCCD()));
    ui->dateNgaySinh->setDate(QDate::fromString(QString::fromStdString(ns->getNgaySinh().toString()), "dd/MM/yyyy"));
    ui->cmbGioiTinh->setCurrentText(ns->getGioiTinh() == GioiTinh::NAM ? "Nam" : "Nữ");

    ui->txtSoDienThoai->setText(QString::fromStdString(ns->getSoDienThoai()));
    ui->txtDiaChi->setText(QString::fromStdString(ns->getDiaChi()));
    ui->txtSoTaiKhoan->setText(QString::fromStdString(ns->getSoTaiKhoan()));
    ui->txtTenNganHang->setText(QString::fromStdString(ns->getTenNganHang()));

    ui->dateNgayVaoCongTy->setDate(QDate::fromString(QString::fromStdString(ns->getNgayVaoCongTy().toString()), "dd/MM/yyyy"));
    ui->txtViTriCongViec->setText(QString::fromStdString(ns->getViTriCongViec()));
    ui->cmbPhongBan->setCurrentText(QString::fromStdString(ns->getPhongBan().getTenPhongBan()));
    ui->txtTrinhDoHocVan->setText(QString::fromStdString(ns->getTrinhDoHocVan()));
    ui->txtChuyenNganh->setText(QString::fromStdString(ns->getChuyenNganh()));

    ui->cmbLoaiNhanSu->setCurrentText(QString::fromStdString(ns->getLoaiNhanSu()));
    ui->cmbLoaiNhanSu->setEnabled(false);

    // Tải dữ liệu lương
    if (auto tv = std::dynamic_pointer_cast<NhanVienThuViec>(ns)) {
        ui->spinPhuCapThucTap->setValue(tv->getPhuCapThucTap());
    } else if (auto ct = std::dynamic_pointer_cast<NhanVienChinhThuc>(ns)) {
        ui->spinLuongCoBan_CT->setValue(ct->getLuongCoBan());
        ui->spinHeSoLuong_CT->setValue(ct->getHeSoLuong());
        ui->spinPhuCapChucVu_CT->setValue(ct->getPhuCapChucVu());
        ui->spinPhuCapAnTrua->setValue(ct->getPhuCapAnTrua());
        ui->spinPhuCapXangXe->setValue(ct->getPhuCapXangXe());
        // Tải thân nhân
        for(const auto& tn : ct->getDanhSachThanNhan()) {
            int row = ui->tableThanNhan->rowCount();
            ui->tableThanNhan->insertRow(row);
            ui->tableThanNhan->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(tn.getHoTen())));
            ui->tableThanNhan->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(tn.getQuanHe())));
            ui->tableThanNhan->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(tn.getSoDienThoai())));
        }
    } else if (auto ql = std::dynamic_pointer_cast<QuanLy>(ns)) {
        ui->spinLuongCoBan_QL->setValue(ql->getLuongCoBan());
        ui->spinHeSoLuong_QL->setValue(ql->getHeSoLuong());
        ui->spinPhuCapQuanLy->setValue(ql->getPhuCapQuanLy());
        ui->spinThuongHieuQua->setValue(ql->getThuongHieuQua());
        // Tải thân nhân
        for(const auto& tn : ql->getDanhSachThanNhan()) {
            int row = ui->tableThanNhan->rowCount();
            ui->tableThanNhan->insertRow(row);
            ui->tableThanNhan->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(tn.getHoTen())));
            ui->tableThanNhan->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(tn.getQuanHe())));
            ui->tableThanNhan->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(tn.getSoDienThoai())));
        }
    }
}


// --- Xử lý sự kiện "Thêm"/"Cập nhật" ---
void GD_Them::on_btnThem_clicked()
{
    ui->lblStatus->clear();

    QString username = ui->txtUsername->text().trimmed();
    QString password = ui->txtPassword->text();
    QString confirmPassword = ui->txtConfirmPassword->text();
    QString email = ui->txtEmail->text().trimmed();
    QString role = ui->cmbLoaiNhanSu->currentData().toString();
    QString loaiNhanSu = ui->cmbLoaiNhanSu->currentText();

    if (!isEditMode) {
        if (username.isEmpty() || password.isEmpty() || confirmPassword.isEmpty() || email.isEmpty()) {
            ui->lblStatus->setText("Vui lòng nhập đầy đủ thông tin tài khoản!");
            return;
        }
        if (username.length() < 8 || username.length() > 30) {
            ui->lblStatus->setText("Tên tài khoản phải có 8–30 ký tự!");
            return;
        }
        if (password.length() < 8 || password.length() > 30) {
            ui->lblStatus->setText("Mật khẩu phải có 8–30 ký tự!");
            return;
        }
        if (password != confirmPassword) {
            ui->lblStatus->setText("Mật khẩu xác nhận không khớp!");
            return;
        }
        if (isUsernameTaken(username)) {
            ui->lblStatus->setText("Tài khoản này đã tồn tại!");
            return;
        }
    }
    if (!isEmailValid(email)) {
        ui->lblStatus->setText("Địa chỉ Email không hợp lệ!");
        return;
    }
    if (ui->txtHoTen->text().isEmpty() || ui->txtCCCD->text().isEmpty() || ui->txtSoDienThoai->text().isEmpty()) {
        ui->lblStatus->setText("Vui lòng nhập đầy đủ thông tin cơ bản và liên hệ của nhân sự!");
        return;
    }


    std::shared_ptr<NhanSu> ns;
    if (isEditMode) {
        ns = timNhanSuTheoMa(m_editMaNV.toStdString());
        if (!ns) {
            QMessageBox::critical(this, "Lỗi", "Không tìm thấy nhân sự để cập nhật.");
            return;
        }
    } else {
        if (loaiNhanSu == "Nhân viên thử việc") {
            ns = std::make_shared<NhanVienThuViec>();
        } else if (loaiNhanSu == "Nhân viên chính thức") {
            ns = std::make_shared<NhanVienChinhThuc>();
        } else {
            ns = std::make_shared<QuanLy>();
        }
        ns->setMaNhanVien(username.toStdString());
    }

    // --- 4. Cập nhật dữ liệu từ UI vào đối tượng ns ---
    ns->setHoTen(ui->txtHoTen->text().toStdString());
    ns->setCCCD(ui->txtCCCD->text().toStdString());
    ns->setNgaySinh(NgayThang::fromString(ui->dateNgaySinh->date().toString("dd/MM/yyyy").toStdString()));
    ns->setGioiTinh(ui->cmbGioiTinh->currentText() == "Nam" ? GioiTinh::NAM : GioiTinh::NU);
    ns->setSoDienThoai(ui->txtSoDienThoai->text().toStdString());
    ns->setEmail(email.toStdString());
    ns->setDiaChi(ui->txtDiaChi->text().toStdString());
    ns->setSoTaiKhoan(ui->txtSoTaiKhoan->text().toStdString());
    ns->setTenNganHang(ui->txtTenNganHang->text().toStdString());
    ns->setNgayVaoCongTy(NgayThang::fromString(ui->dateNgayVaoCongTy->date().toString("dd/MM/yyyy").toStdString()));
    ns->setViTriCongViec(ui->txtViTriCongViec->text().toStdString());

    QString tenPB = ui->cmbPhongBan->currentText();
    QString maPB = ui->cmbPhongBan->currentData().toString();
    ns->setPhongBan(PhongBan(maPB.toStdString(), tenPB.toStdString()));

    ns->setTrinhDoHocVan(ui->txtTrinhDoHocVan->text().toStdString());
    ns->setChuyenNganh(ui->txtChuyenNganh->text().toStdString());

    // Cập nhật lương
    if (auto tv = std::dynamic_pointer_cast<NhanVienThuViec>(ns)) {
        tv->setPhuCapThucTap(ui->spinPhuCapThucTap->value());
    } else if (auto ct = std::dynamic_pointer_cast<NhanVienChinhThuc>(ns)) {
        ct->setLuongCoBan(ui->spinLuongCoBan_CT->value());
        ct->setHeSoLuong(ui->spinHeSoLuong_CT->value());
        ct->setPhuCapChucVu(ui->spinPhuCapChucVu_CT->value());
        ct->setPhuCapAnTrua(ui->spinPhuCapAnTrua->value());
        ct->setPhuCapXangXe(ui->spinPhuCapXangXe->value());

        ct->xoaTatCaThanNhan();
        for (int i = 0; i < ui->tableThanNhan->rowCount(); ++i) {
            ct->themThanNhan(ThanNhan(
                ui->tableThanNhan->item(i, 0)->text().toStdString(), // Tên
                ui->tableThanNhan->item(i, 1)->text().toStdString(), // Quan hệ
                ui->tableThanNhan->item(i, 2)->text().toStdString()  // SĐT
                ));
        }
    } else if (auto ql = std::dynamic_pointer_cast<QuanLy>(ns)) {
        ql->setLuongCoBan(ui->spinLuongCoBan_QL->value());
        ql->setHeSoLuong(ui->spinHeSoLuong_QL->value());
        ql->setPhuCapQuanLy(ui->spinPhuCapQuanLy->value());
        ql->setThuongHieuQua(ui->spinThuongHieuQua->value());

        ql->xoaTatCaThanNhan();
        for (int i = 0; i < ui->tableThanNhan->rowCount(); ++i) {
            ql->themThanNhan(ThanNhan(
                ui->tableThanNhan->item(i, 0)->text().toStdString(), // Tên
                ui->tableThanNhan->item(i, 1)->text().toStdString(), // Quan hệ
                ui->tableThanNhan->item(i, 2)->text().toStdString()  // SĐT
                ));
        }
    }

    // --- 5. Lưu dữ liệu ---
    if (isEditMode) {
        luuNhanSuVaoFile();
        QMessageBox::information(this, "Thành công", "Cập nhật thông tin nhân sự thành công!");

    } else {
        g_danhSachNhanSu.push_back(ns);
        luuNhanSuVaoFile();

        QFile accountFile("account.txt");
        if (!accountFile.open(QIODevice::Append | QIODevice::Text)) {
            ui->lblStatus->setText("Lỗi: Không thể mở file account.txt!");
            return;
        }
        QTextStream accountOut(&accountFile);
        accountOut << "Ten nguoi dung: " << username << "\n";
        accountOut << "Mat khau: " << password << "\n";
        accountOut << "Email: " << email << "\n";
        accountOut << "Loai nhan su: " << role << "\n";
        accountOut << "---------------------------------\n";
        accountFile.close();

        QMessageBox::information(this, "Thành công", "Thêm tài khoản và hồ sơ nhân sự mới thành công!");
    }

    this->accept();
}

// --- Xử lý sự kiện thêm một thân nhân vào bảng ---
void GD_Them::on_btnThemThanNhan_clicked()
{
    QString hoTen = ui->txtTenThanNhan->text().trimmed();
    QString quanHe = ui->txtQuanHe->text().trimmed();
    QString sdt = ui->txtSdtThanNhan->text().trimmed();

    if (hoTen.isEmpty() || quanHe.isEmpty() || sdt.isEmpty()) {
        QMessageBox::warning(this, "Thiếu thông tin", "Vui lòng nhập đủ thông tin thân nhân.");
        return;
    }

    int newRow = ui->tableThanNhan->rowCount();
    ui->tableThanNhan->insertRow(newRow);

    ui->tableThanNhan->setItem(newRow, 0, new QTableWidgetItem(hoTen));
    ui->tableThanNhan->setItem(newRow, 1, new QTableWidgetItem(quanHe));
    ui->tableThanNhan->setItem(newRow, 2, new QTableWidgetItem(sdt));

    ui->txtTenThanNhan->clear();
    ui->txtQuanHe->clear();
    ui->txtSdtThanNhan->clear();
}


// --- Xử lý sự kiện xóa một thân nhân khỏi bảng ---
void GD_Them::on_btnXoaThanNhan_clicked()
{
    int currentRow = ui->tableThanNhan->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Chưa chọn", "Vui lòng chọn một thân nhân trong danh sách để xóa.");
        return;
    }
    ui->tableThanNhan->removeRow(currentRow);
}
