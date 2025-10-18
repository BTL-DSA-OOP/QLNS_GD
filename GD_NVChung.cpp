#include "GD_NVChung.h"
#include "ui_GD_NVChung.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDate>
#include <QDir>
#include <QMessageBox>
#include <QDateTime>
#include <QLocale>

// Cập nhật constructor
GD_NVChung::GD_NVChung(const QString &maNV, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GD_NVChung)
    , m_maNV(maNV)
{
    ui->setupUi(this);

    // Kết nối các nút điều hướng
    // connect(ui->btnNavInfo, &QPushButton::clicked, this, &GD_NVChung::on_btnNavInfo_clicked);
    // connect(ui->btnNavSalary, &QPushButton::clicked, this, &GD_NVChung::on_btnNavSalary_clicked);
    // connect(ui->btnNavAttendance, &QPushButton::clicked, this, &GD_NVChung::on_btnNavAttendance_clicked);
    // connect(ui->btnNavProjects, &QPushButton::clicked, this, &GD_NVChung::on_btnNavProjects_clicked);
    // connect(ui->btnNavRelatives, &QPushButton::clicked, this, &GD_NVChung::on_btnNavRelatives_clicked);
    // connect(ui->btnCheckIn, &QPushButton::clicked, this, &GD_NVChung::on_btnCheckIn_clicked);
    // connect(ui->btnCheckOut, &QPushButton::clicked, this, &GD_NVChung::on_btnCheckOut_clicked); // <<< KẾT NỐI NÚT MỚI
    // connect(ui->btnAttendanceHistory, &QPushButton::clicked, this, &GD_NVChung::on_btnAttendanceHistory_clicked);


    ui->btnNavSalary->setVisible(false);
    loadNhanSuData(m_maNV);
    calculateAndDisplaySalary();
    ui->mainStackedWidget->setCurrentIndex(0); // Bắt đầu ở trang thông tin

    // Cài đặt ReadOnly cho trang thông tin
    ui->lineEdit_maNV->setReadOnly(true);
    ui->lineEdit_hoTen->setReadOnly(true);
    ui->lineEdit_cccd->setReadOnly(true);
    ui->dateEdit_ngaySinh->setReadOnly(true);
    ui->comboBox_gioiTinh->setEnabled(false);
    ui->lineEdit_sdt->setReadOnly(true);
    ui->lineEdit_email->setReadOnly(true);
    ui->lineEdit_diaChi->setReadOnly(true);
    ui->lineEdit_viTri->setReadOnly(true);
    ui->lineEdit_phongBan->setReadOnly(true);
    ui->dateEdit_ngayVao->setReadOnly(true);
    ui->lineEdit_thamNien->setReadOnly(true);

    // Tải lịch sử chấm công khi mở
    on_btnAttendanceHistory_clicked();
}

GD_NVChung::~GD_NVChung()
{
    delete ui;
}

void GD_NVChung::loadNhanSuData(const QString &maNV)
{
    ui->tableRelatives->setRowCount(0);
    QFile file("dsns.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning("Không thể mở file dsns.txt!");
        return;
    }

    QTextStream in(&file);
    bool foundUser = false;
    QString line;
    while (!in.atEnd()) {
        line = in.readLine().trimmed();
        if (line.startsWith("MaNV: ") && line.mid(6).trimmed() == maNV) {
            foundUser = true;
            while(!in.atEnd()) {
                line = in.readLine().trimmed();
                if (line.startsWith("---------------------------------")) {
                    break;
                }

                if (line.startsWith("LoaiNhanSu: ")) {
                    m_loaiNhanSu = line.mid(12);
                } else if (line.startsWith("HoTen: ")) {
                    ui->lineEdit_hoTen->setText(line.mid(7));
                } else if (line.startsWith("CCCD: ")) {
                    ui->lineEdit_cccd->setText(line.mid(6));
                } else if (line.startsWith("NgaySinh: ")) {
                    ui->dateEdit_ngaySinh->setDate(QDate::fromString(line.mid(10), "dd/MM/yyyy"));
                } else if (line.startsWith("GioiTinh: ")) {
                    ui->comboBox_gioiTinh->setCurrentText(line.mid(10));
                } else if (line.startsWith("SDT: ")) {
                    ui->lineEdit_sdt->setText(line.mid(5));
                } else if (line.startsWith("Email: ")) {
                    ui->lineEdit_email->setText(line.mid(7));
                } else if (line.startsWith("DiaChi: ")) {
                    ui->lineEdit_diaChi->setText(line.mid(8));
                } else if (line.startsWith("ViTri: ")) {
                    ui->lineEdit_viTri->setText(line.mid(7));
                } else if (line.startsWith("PhongBan: ")) {
                    QString phongBan = line.mid(10);
                    int bracketPos = phongBan.indexOf(" (");
                    if (bracketPos != -1) phongBan = phongBan.left(bracketPos);
                    ui->lineEdit_phongBan->setText(phongBan);
                } else if (line.startsWith("NgayVaoCongTy: ")) {
                    QDate ngayVao = QDate::fromString(line.mid(15), "dd/MM/yyyy");
                    ui->dateEdit_ngayVao->setDate(ngayVao);
                    int years = QDate::currentDate().year() - ngayVao.year();
                    ui->lineEdit_thamNien->setText(QString::number(years) + " năm");
                }
                else if (line.startsWith("PhuCapThucTap: ")) {
                    m_phuCapThucTap = line.mid(15).toDouble();
                } else if (line.startsWith("LuongCoBan: ")) {
                    m_luongCoBan_CT = line.mid(12).toDouble();
                    m_luongCoBan_QL = line.mid(12).toDouble();
                } else if (line.startsWith("PhuCapChucVu: ")) {
                    m_phuCapChucVu = line.mid(14).toDouble();
                } else if (line.startsWith("PhuCapAnTrua: ")) {
                    m_phuCapAnTrua = line.mid(14).toDouble();
                } else if (line.startsWith("PhuCapXangXe: ")) {
                    m_phuCapXangXe = line.mid(14).toDouble();
                } else if (line.startsWith("PhuCapQuanLy: ")) {
                    m_phuCapQuanLy = line.mid(14).toDouble();
                }
                else if (line.startsWith("ThanNhan: ")) {
                    QStringList parts = line.mid(10).trimmed().split(';');
                    if (parts.size() == 3) {
                        int row = ui->tableRelatives->rowCount();
                        ui->tableRelatives->insertRow(row);
                        ui->tableRelatives->setItem(row, 0, new QTableWidgetItem(parts[0])); // Họ Tên
                        ui->tableRelatives->setItem(row, 1, new QTableWidgetItem(parts[1])); // Quan hệ
                        ui->tableRelatives->setItem(row, 2, new QTableWidgetItem(parts[2])); // SĐT
                    }
                }
            }
            break;
        }
    }

    if (foundUser) {
        ui->lineEdit_maNV->setText(maNV);
        ui->lineEdit_maNV->setReadOnly(true);
    } else {
        qWarning() << "Không tìm thấy nhân viên với mã:" << maNV;
    }
    file.close();
}

void GD_NVChung::calculateAndDisplaySalary()
{
    QLocale vietnamese(QLocale::Vietnamese);

    ui->groupBox_luong_TV->setVisible(false);
    ui->groupBox_luong_CT->setVisible(false);
    ui->groupBox_luong_QL->setVisible(false);

    if (m_loaiNhanSu == "Nhân viên thử việc") {
        ui->groupBox_luong_TV->setVisible(true);
        ui->lineEdit_phuCapTT->setText(vietnamese.toString(m_phuCapThucTap) + " VNĐ");
        ui->lineEdit_thucNhan_TV->setText(vietnamese.toString(m_phuCapThucTap) + " VNĐ");
    }
    else if (m_loaiNhanSu == "Nhân viên chính thức") {
        ui->groupBox_luong_CT->setVisible(true);

        double tongPhuCap = m_phuCapChucVu + m_phuCapAnTrua + m_phuCapXangXe;
        double tongThuNhap = m_luongCoBan_CT + tongPhuCap;
        double bhxh = tongThuNhap * 0.105; // Giả định BHXH, BHYT, BHTN là 10.5%
        double thueTNCN = (tongThuNhap > 11000000) ? (tongThuNhap - 11000000) * 0.1 : 0; // Giả định thuế bậc 1
        double giamTru = bhxh + thueTNCN;
        double thucNhan = tongThuNhap - giamTru;

        ui->lineEdit_luongCB_CT->setText(vietnamese.toString(m_luongCoBan_CT) + " VNĐ");
        ui->lineEdit_tongPhuCap_CT->setText(vietnamese.toString(tongPhuCap) + " VNĐ");
        ui->lineEdit_giamTru_CT->setText(vietnamese.toString(giamTru, 'f', 0) + " VNĐ");
        ui->lineEdit_thucNhan_CT->setText(vietnamese.toString(thucNhan, 'f', 0) + " VNĐ");
    }
    else if (m_loaiNhanSu == "Quản lý") {
        ui->groupBox_luong_QL->setVisible(true);

        double tongThuNhap = m_luongCoBan_QL + m_phuCapQuanLy;
        double bhxh = tongThuNhap * 0.105;
        double thueTNCN = (tongThuNhap > 11000000) ? (tongThuNhap - 11000000) * 0.15 : 0; // Giả định thuế bậc cao hơn
        double giamTru = bhxh + thueTNCN;
        double thucNhan = tongThuNhap - giamTru;

        ui->lineEdit_luongCB_QL->setText(vietnamese.toString(m_luongCoBan_QL) + " VNĐ");
        ui->lineEdit_phuCapQL->setText(vietnamese.toString(m_phuCapQuanLy) + " VNĐ");
        ui->lineEdit_giamTru_QL->setText(vietnamese.toString(giamTru, 'f', 0) + " VNĐ");
        ui->lineEdit_thucNhan_QL->setText(vietnamese.toString(thucNhan, 'f', 0) + " VNĐ");
    }
}

// --- CÁC HÀM MỚI CHO CHẤM CÔNG  ---

void GD_NVChung::on_btnCheckIn_clicked()
{
    QDir dir;
    if (!dir.exists("ChamCong")) {
        dir.mkpath("ChamCong"); // Tạo thư mục nếu chưa có
    }

    QString filePath = "ChamCong/" + m_maNV + "_chamcong.txt";
    QFile file(filePath);

    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QMessageBox::critical(this, "Lỗi", "Không thể mở file chấm công.");
        return;
    }

    QDateTime now = QDateTime::currentDateTime();
    QString dateStr = now.toString("dd/MM/yyyy");
    QString timeStr = now.toString("hh:mm:ss");

    QTextStream stream(&file);
    QStringList lines;
    bool foundToday = false;

    // Đọc tất cả nội dung file
    while (!stream.atEnd()) {
        lines.append(stream.readLine());
    }

    // Kiểm tra xem đã check-in chưa
    for (const QString &line : lines) {
        if (line.startsWith(dateStr)) {
            foundToday = true;
            break;
        }
    }

    if (foundToday) {
        QMessageBox::warning(this, "Chấm công", "Bạn đã check-in hôm nay rồi.");
        file.close();
        return;
    }

    // Thêm dòng check-in mới
    lines.append(QString("%1,%2,,%3").arg(dateStr, timeStr, "Đã vào"));
    QMessageBox::information(this, "Chấm công", "Đã check-in thành công!");

    // Ghi lại file
    file.resize(0); // Xóa nội dung cũ
    for (const QString &line : lines) {
        if (!line.isEmpty()) {
            stream << line << "\n";
        }
    }
    file.close();

    // Tải lại bảng lịch sử
    on_btnAttendanceHistory_clicked();
}

void GD_NVChung::on_btnCheckOut_clicked()
{
    QString filePath = "ChamCong/" + m_maNV + "_chamcong.txt";
    QFile file(filePath);

    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QMessageBox::critical(this, "Lỗi", "Không thể mở file chấm công.");
        return;
    }

    QDateTime now = QDateTime::currentDateTime();
    QString dateStr = now.toString("dd/MM/yyyy");
    QString timeStr = now.toString("hh:mm:ss");

    QTextStream stream(&file);
    QStringList lines;
    bool foundToday = false;
    bool alreadyCheckedOut = false;
    int lineIndex = -1; // Vị trí của dòng cần sửa

    // Đọc tất cả nội dung file
    while (!stream.atEnd()) {
        lines.append(stream.readLine());
    }

    // Tìm dòng của ngày hôm nay
    for (int i = 0; i < lines.size(); ++i) {
        if (lines[i].startsWith(dateStr)) {
            foundToday = true;
            lineIndex = i;
            QStringList parts = lines[i].split(',');
            if (parts.size() == 4 && !parts[2].isEmpty()) { // parts[2] là Giờ ra
                alreadyCheckedOut = true;
            }
            break;
        }
    }

    if (!foundToday) {
        QMessageBox::warning(this, "Chấm công", "Bạn chưa check-in. Vui lòng check-in trước.");
        file.close();
        return;
    }

    if (alreadyCheckedOut) {
        QMessageBox::warning(this, "Chấm công", "Bạn đã check-out hôm nay rồi.");
        file.close();
        return;
    }

    // Cập nhật dòng check-out
    QStringList parts = lines[lineIndex].split(',');
    if (parts.size() == 4) {
        parts[2] = timeStr; // Giờ ra
        parts[3] = "Đã ra";
        lines[lineIndex] = parts.join(",");
        QMessageBox::information(this, "Chấm công", "Đã check-out thành công!");
    } else {
        // Xử lý trường hợp file bị lỗi (ít khi xảy ra)
        QMessageBox::critical(this, "Lỗi", "Dữ liệu file chấm công bị lỗi.");
        file.close();
        return;
    }

    // Ghi lại file
    file.resize(0);
    for (const QString &line : lines) {
        if (!line.isEmpty()) {
            stream << line << "\n";
        }
    }
    file.close();

    // Tải lại bảng lịch sử
    on_btnAttendanceHistory_clicked();
}


void GD_NVChung::on_btnAttendanceHistory_clicked()
{
    ui->tableAttendance->setRowCount(0); // Xóa bảng
    QString filePath = "ChamCong/" + m_maNV + "_chamcong.txt";
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return; // Không tìm thấy file (chưa chấm công)
    }

    QTextStream in(&file);
    ui->tableAttendance->setSortingEnabled(false); // Tắt sắp xếp khi thêm
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(',');
        if (parts.size() == 4) {
            int row = ui->tableAttendance->rowCount();
            ui->tableAttendance->insertRow(row);
            ui->tableAttendance->setItem(row, 0, new QTableWidgetItem(parts[0])); // Ngày
            ui->tableAttendance->setItem(row, 1, new QTableWidgetItem(parts[1])); // Giờ vào
            ui->tableAttendance->setItem(row, 2, new QTableWidgetItem(parts[2])); // Giờ ra
            ui->tableAttendance->setItem(row, 3, new QTableWidgetItem(parts[3])); // Trạng thái
        }
    }
    ui->tableAttendance->setSortingEnabled(true); // Bật lại sắp xếp
    file.close();
}


void GD_NVChung::on_btnNavInfo_clicked() { ui->mainStackedWidget->setCurrentIndex(0); }
void GD_NVChung::on_btnNavSalary_clicked() { ui->mainStackedWidget->setCurrentIndex(1); }
void GD_NVChung::on_btnNavAttendance_clicked() { ui->mainStackedWidget->setCurrentIndex(2); }
void GD_NVChung::on_btnNavProjects_clicked() { ui->mainStackedWidget->setCurrentIndex(3); }
void GD_NVChung::on_btnNavRelatives_clicked() { ui->mainStackedWidget->setCurrentIndex(4); }
