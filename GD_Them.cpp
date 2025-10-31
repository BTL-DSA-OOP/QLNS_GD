#include "GD_Them.h"
#include "ui_GD_Them.h"
#include "NhanSuData.h"
#include "ClassNhanSu.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>
#include <QDebug>
#include <QLocale>

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
        spinBox->setDecimals(0);
    }

    // Cài đặt cho hệ số lương
    ui->spinHeSoLuong_CT->setLocale(vnLocale);
    ui->spinHeSoLuong_QL->setLocale(vnLocale);

    ui->cmbLoaiNhanSu->clear();
    ui->cmbLoaiNhanSu->addItem("Nhân viên thử việc", "NhanVienThuViec");
    ui->cmbLoaiNhanSu->addItem("Nhân viên chính thức", "NhanVienChinhThuc");
    ui->cmbLoaiNhanSu->addItem("Quản lý", "QuanLy");

    ui->cmbPhongBan->clear();
    if (g_danhSachPhongBan.empty()) {
        ui->cmbPhongBan->addItem("Chưa có phòng ban", "");
    } else {
        for (const auto& pb : g_danhSachPhongBan) {
            ui->cmbPhongBan->addItem(
                QString::fromStdString(pb.getTenPhongBan()),
                QString::fromStdString(pb.getMaPhongBan())
                );
        }
    }
    connect(ui->cmbLoaiNhanSu, &QComboBox::currentIndexChanged, this, &GD_Them::updateSalaryFields);

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
    updateThanNhanHeight();
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
    updateThanNhanHeight();
}


void capNhatThongTinTaiKhoan(const QString& maNV, const QString& emailMoi, const QString& vaiTroMoi)
{
    QFile inFile("account.txt");
    QFile outFile("account_temp.txt");

    if (!inFile.open(QIODevice::ReadOnly | QIODevice::Text) || !outFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return;
    }

    QTextStream in(&inFile);
    QTextStream out(&outFile);
    bool userFound = false;

    while (!in.atEnd()) {
        QString line = in.readLine();

        if (line.startsWith("Ten nguoi dung: ") && line.mid(16).trimmed() == maNV) {
            userFound = true;
            out << line << "\n"; // Ghi lại dòng Tên người dùng
        } else if (userFound && line.startsWith("Mat khau: ")) {
            out << line << "\n"; // Ghi lại dòng Mật khẩu (không đổi)
        } else if (userFound && line.startsWith("Email: ")) {
            out << "Email: " << emailMoi << "\n"; // Ghi email mới
        } else if (userFound && line.startsWith("Loai nhan su: ")) {
            out << "Loai nhan su: " << vaiTroMoi << "\n"; // Ghi vai trò mới
        } else if (userFound && line.startsWith("---------------------------------")) {
            out << line << "\n";
            userFound = false; // Reset
        } else {
            out << line << "\n";
        }
    }

    inFile.close();
    outFile.close();

    QFile::remove("account.txt");
    QFile::rename("account_temp.txt", "account.txt");
}

void GD_Them::fillCommonDataFromUI(std::shared_ptr<NhanSu> ns)
{
    ns->setHoTen(ui->txtHoTen->text().toStdString());
    ns->setCCCD(ui->txtCCCD->text().toStdString());
    ns->setNgaySinh(NgayThang::fromString(ui->dateNgaySinh->date().toString("dd/MM/yyyy").toStdString()));
    ns->setGioiTinh(ui->cmbGioiTinh->currentText() == "Nam" ? GioiTinh::NAM : GioiTinh::NU);
    ns->setSoDienThoai(ui->txtSoDienThoai->text().toStdString());
    ns->setEmail(ui->txtEmail->text().trimmed().toStdString());
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
}

void GD_Them::fillSalaryDataFromUI(std::shared_ptr<NhanSu> ns)
{
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
}


void GD_Them::on_btnThem_clicked()
{
    ui->lblStatus->clear();

    // --- 1. Lấy và kiểm tra dữ liệu ---
    QString username = ui->txtUsername->text().trimmed();
    QString password = ui->txtPassword->text();
    QString confirmPassword = ui->txtConfirmPassword->text();
    QString email = ui->txtEmail->text().trimmed();
    QString newRoleData = ui->cmbLoaiNhanSu->currentData().toString();

    if (!isEditMode) {
        // Kiểm tra chung cho chế độ "Thêm mới"
        if (username.isEmpty() || password.isEmpty() || confirmPassword.isEmpty() || email.isEmpty()) {
            ui->lblStatus->setText("Vui lòng nhập đầy đủ thông tin tài khoản!");
            return;
        }
        if (username.length() < 5 || username.length() > 30) {
            ui->lblStatus->setText("Tên tài khoản phải có 5–30 ký tự!");
            return;
        }
        if (password.length() < 5 || password.length() > 30) {
            ui->lblStatus->setText("Mật khẩu phải có 5–30 ký tự!");
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

    // Kiểm tra chung cho cả "Thêm" và "Sửa"
    if (!isEmailValid(email)) {
        ui->lblStatus->setText("Địa chỉ Email không hợp lệ!");
        return;
    }
    if (ui->txtHoTen->text().isEmpty() || ui->txtCCCD->text().isEmpty() || ui->txtSoDienThoai->text().isEmpty()) {
        ui->lblStatus->setText("Vui lòng nhập đầy đủ thông tin cơ bản và liên hệ của nhân sự!");
        return;
    }


    // --- 2. Xử lý logic ---
    if (isEditMode)
    {
        // --- CHẾ ĐỘ SỬA ---
        auto ns_cu = timNhanSuTheoMa(m_editMaNV.toStdString());
        if (!ns_cu) {
            QMessageBox::critical(this, "Lỗi", "Không tìm thấy nhân sự để cập nhật.");
            return;
        }

        // Xác định loại nhân sự cũ (dưới dạng Data: "NhanVienChinhThuc")
        QString oldRoleData;
        if (std::dynamic_pointer_cast<NhanVienThuViec>(ns_cu)) oldRoleData = "NhanVienThuViec";
        else if (std::dynamic_pointer_cast<NhanVienChinhThuc>(ns_cu)) oldRoleData = "NhanVienChinhThuc";
        else if (std::dynamic_pointer_cast<QuanLy>(ns_cu)) oldRoleData = "QuanLy";


        if (oldRoleData == newRoleData)
        {
            // Cập nhật dữ liệu trên đối tượng cũ
            fillCommonDataFromUI(ns_cu);
            fillSalaryDataFromUI(ns_cu);

            // Cập nhật file account
            capNhatThongTinTaiKhoan(m_editMaNV, email, newRoleData);
        }
        else
        {
            // 1. Tạo đối tượng mới dựa trên vai trò mới
            std::shared_ptr<NhanSu> ns_moi;
            if (newRoleData == "NhanVienThuViec") {
                ns_moi = std::make_shared<NhanVienThuViec>();
            } else if (newRoleData == "NhanVienChinhThuc") {
                ns_moi = std::make_shared<NhanVienChinhThuc>();
            } else { // QuanLy
                ns_moi = std::make_shared<QuanLy>();
            }

            // 2. Gán Mã NV và điền thông tin chung từ UI
            ns_moi->setMaNhanVien(m_editMaNV.toStdString()); // Giữ nguyên Mã NV
            fillCommonDataFromUI(ns_moi);

            // 3. Điền thông tin lương mới từ UI
            fillSalaryDataFromUI(ns_moi);

            // 4. Thay thế con trỏ CŨ bằng con trỏ mới trong danh sách toàn cục
            for (auto& ns_ptr : g_danhSachNhanSu) {
                if (ns_ptr->getMaNhanVien() == m_editMaNV.toStdString()) {
                    ns_ptr = ns_moi; // Đây là bước "thay thế"
                    break;
                }
            }

            // 5. Cập nhật file account (cả email và vai trò)
            capNhatThongTinTaiKhoan(m_editMaNV, email, newRoleData);
        }

        // Lưu file dsns.txt
        luuNhanSuVaoFile();
        QMessageBox::information(this, "Thành công", "Cập nhật thông tin nhân sự thành công!");

    }
    else
    {
        // --- CHẾ ĐỘ THÊM mới  ---
        std::shared_ptr<NhanSu> ns_moi;
        if (newRoleData == "NhanVienThuViec") {
            ns_moi = std::make_shared<NhanVienThuViec>();
        } else if (newRoleData == "NhanVienChinhThuc") {
            ns_moi = std::make_shared<NhanVienChinhThuc>();
        } else { // QuanLy
            ns_moi = std::make_shared<QuanLy>();
        }

        ns_moi->setMaNhanVien(username.toStdString());
        fillCommonDataFromUI(ns_moi);
        fillSalaryDataFromUI(ns_moi);

        g_danhSachNhanSu.push_back(ns_moi);
        luuNhanSuVaoFile();

        // Ghi file account.txt
        QFile accountFile("account.txt");
        if (!accountFile.open(QIODevice::Append | QIODevice::Text)) {
            ui->lblStatus->setText("Lỗi: Không thể mở file account.txt!");
            return;
        }
        QTextStream accountOut(&accountFile);
        accountOut << "Ten nguoi dung: " << username << "\n";
        accountOut << "Mat khau: " << password << "\n";
        accountOut << "Email: " << email << "\n";
        accountOut << "Loai nhan su: " << newRoleData << "\n";
        accountOut << "---------------------------------\n";
        accountFile.close();

        QMessageBox::information(this, "Thành công", "Thêm tài khoản và hồ sơ nhân sự mới thành công!");
    }

    this->accept();
}


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
    updateThanNhanHeight();
}


void GD_Them::on_btnXoaThanNhan_clicked()
{
    int currentRow = ui->tableThanNhan->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Chưa chọn", "Vui lòng chọn một thân nhân trong danh sách để xóa.");
        return;
    }
    ui->tableThanNhan->removeRow(currentRow);
    updateThanNhanHeight();
}
void GD_Them::updateThanNhanHeight()
{
    int rowCount = ui->tableThanNhan->rowCount();
    int headerHeight = ui->tableThanNhan->horizontalHeader()->height();
    int rowsHeight = 0;

    if (rowCount == 0) {
        ui->tableThanNhan->setMinimumHeight(80);
        ui->tableThanNhan->setMaximumHeight(80);
        return;
    }

    for (int i = 0; i < rowCount; ++i) {
        rowsHeight += ui->tableThanNhan->rowHeight(i);
    }

    int frameWidth = ui->tableThanNhan->frameWidth() * 2;
    int calculatedHeight = headerHeight + rowsHeight + frameWidth;

    int maxHeight = 250;
    if (calculatedHeight > maxHeight) {
        ui->tableThanNhan->setMinimumHeight(maxHeight);
        ui->tableThanNhan->setMaximumHeight(maxHeight);
    } else {
        ui->tableThanNhan->setMinimumHeight(calculatedHeight);
        ui->tableThanNhan->setMaximumHeight(calculatedHeight);
    }
}
