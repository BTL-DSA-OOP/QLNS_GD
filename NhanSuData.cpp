#include "NhanSuData.h"
#include "ClassNhanSu.h"
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QLocale>

    //Biến toàn cục
std::vector<std::shared_ptr<NhanSu>> g_danhSachNhanSu;
std::vector<DuAn> g_danhSachDuAn;
std::vector<PhongBan> g_danhSachPhongBan;
std::vector<YeuCauNghiPhep> g_danhSachYeuCauNghiPhep;
// --- Hàm tìm kiếm Nhân Sự ---
std::shared_ptr<NhanSu> timNhanSuTheoMa(const std::string& maNV) {
    for (const auto& ns : g_danhSachNhanSu) {
        if (ns->getMaNhanVien() == maNV) {
            return ns;
        }
    }
    return nullptr;
}

// --- Hàm đọc/ghi file "dsns.txt" ---

void docNhanSuTuFile() {
    g_danhSachNhanSu.clear();
    QFile file("dsns.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream in(&file);
    std::shared_ptr<NhanSu> ns = nullptr;

    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.startsWith("LoaiNhanSu: ")) {
            QString loai = line.mid(12).trimmed();
            if (loai == "Nhan vien thu viec") {
                ns = std::make_shared<NhanVienThuViec>();
            } else if (loai == "Nhan vien chinh thuc") {
                ns = std::make_shared<NhanVienChinhThuc>();
            } else if (loai == "Quan ly") {
                ns = std::make_shared<QuanLy>();
            } else {
                ns = nullptr;
                continue;
            }
        } else if (line.startsWith("MaNV: ") && ns) {
            ns->setMaNhanVien(line.mid(6).trimmed().toStdString());
        } else if (line.startsWith("HoTen: ") && ns) {
            ns->setHoTen(line.mid(7).trimmed().toStdString());
        } else if (line.startsWith("CCCD: ") && ns) {
            ns->setCCCD(line.mid(6).trimmed().toStdString());
        } else if (line.startsWith("NgaySinh: ") && ns) {
            ns->setNgaySinh(NgayThang::fromString(line.mid(10).trimmed().toStdString()));
        } else if (line.startsWith("GioiTinh: ") && ns) {
            ns->setGioiTinh(line.mid(10).trimmed() == "Nam" ? GioiTinh::NAM : GioiTinh::NU);
        } else if (line.startsWith("SDT: ") && ns) {
            ns->setSoDienThoai(line.mid(5).trimmed().toStdString());
        } else if (line.startsWith("Email: ") && ns) {
            ns->setEmail(line.mid(7).trimmed().toStdString());
        } else if (line.startsWith("DiaChi: ") && ns) {
            ns->setDiaChi(line.mid(8).trimmed().toStdString());
        } else if (line.startsWith("SoTaiKhoan: ") && ns) {
            ns->setSoTaiKhoan(line.mid(12).trimmed().toStdString());
        } else if (line.startsWith("NganHang: ") && ns) {
            ns->setTenNganHang(line.mid(10).trimmed().toStdString());
        } else if (line.startsWith("NgayVaoCongTy: ") && ns) {
            ns->setNgayVaoCongTy(NgayThang::fromString(line.mid(15).trimmed().toStdString()));
        } else if (line.startsWith("ViTri: ") && ns) {
            ns->setViTriCongViec(line.mid(7).trimmed().toStdString());
        } else if (line.startsWith("PhongBan: ") && ns) {
            QString pbLine = line.mid(10).trimmed();
            QString tenPB = pbLine.section('(', 0, 0).trimmed();
            QString maPB = pbLine.section('(', 1).section(')', 0, 0).trimmed();
            ns->setPhongBan(PhongBan(maPB.toStdString(), tenPB.toStdString()));
        } else if (line.startsWith("TrinhDo: ") && ns) {
            ns->setTrinhDoHocVan(line.mid(9).trimmed().toStdString());
        } else if (line.startsWith("ChuyenNganh: ") && ns) {
            ns->setChuyenNganh(line.mid(12).trimmed().toStdString());
        }
        // Đọc thông tin lương (các hàm này đã được thêm vào ClassNhanSu.h)
        else if (line.startsWith("PhuCapThucTap: ") && ns) {
            if (auto tv = std::dynamic_pointer_cast<NhanVienThuViec>(ns)) {
                tv->setPhuCapThucTap(line.mid(16).trimmed().toDouble());
            }
        } else if (line.startsWith("LuongCoBan: ") && ns) {
            if (auto ct = std::dynamic_pointer_cast<NhanVienChinhThuc>(ns)) {
                ct->setLuongCoBan(line.mid(12).trimmed().toDouble());
            } else if (auto ql = std::dynamic_pointer_cast<QuanLy>(ns)) {
                ql->setLuongCoBan(line.mid(12).trimmed().toDouble());
            }
        } else if (line.startsWith("HeSoLuong: ") && ns) {
            if (auto ct = std::dynamic_pointer_cast<NhanVienChinhThuc>(ns)) {
                ct->setHeSoLuong(line.mid(11).trimmed().toDouble());
            } else if (auto ql = std::dynamic_pointer_cast<QuanLy>(ns)) {
                ql->setHeSoLuong(line.mid(11).trimmed().toDouble());
            }
        } else if (line.startsWith("PhuCapChucVu: ") && ns) {
            if (auto ct = std::dynamic_pointer_cast<NhanVienChinhThuc>(ns)) {
                ct->setPhuCapChucVu(line.mid(15).trimmed().toDouble());
            }
        } else if (line.startsWith("PhuCapAnTrua: ") && ns) {
            if (auto ct = std::dynamic_pointer_cast<NhanVienChinhThuc>(ns)) {
                ct->setPhuCapAnTrua(line.mid(14).trimmed().toDouble());
            }
        } else if (line.startsWith("PhuCapXangXe: ") && ns) {
            if (auto ct = std::dynamic_pointer_cast<NhanVienChinhThuc>(ns)) {
                ct->setPhuCapXangXe(line.mid(14).trimmed().toDouble());
            }
        } else if (line.startsWith("PhuCapQuanLy: ") && ns) {
            if (auto ql = std::dynamic_pointer_cast<QuanLy>(ns)) {
                ql->setPhuCapQuanLy(line.mid(15).trimmed().toDouble());
            }
        } else if (line.startsWith("ThuongHieuQua: ") && ns) {
            if (auto ql = std::dynamic_pointer_cast<QuanLy>(ns)) {
                ql->setThuongHieuQua(line.mid(16).trimmed().toDouble());
            }
        }
        // Đọc thân nhân
        else if (line.startsWith("ThanNhan: ") && ns) {
            QStringList parts = line.mid(10).trimmed().split(';');
            if (parts.size() == 3) {
                ThanNhan tn(parts[0].toStdString(), parts[1].toStdString(), parts[2].toStdString());
                if (auto ct = std::dynamic_pointer_cast<NhanVienChinhThuc>(ns)) {
                    ct->themThanNhan(tn);
                } else if (auto ql = std::dynamic_pointer_cast<QuanLy>(ns)) {
                    ql->themThanNhan(tn);
                }
            }
        }
        else if (line.startsWith("---------------------------------")) {
            if (ns) {
                g_danhSachNhanSu.push_back(ns);
                ns = nullptr;
            }
        }
    }
    file.close();
}


void luuNhanSuVaoFile() {
    QFile file("dsns.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        return;
    }

    QTextStream out(&file);

    for (const auto& ns : g_danhSachNhanSu) {
        out << "LoaiNhanSu: " << QString::fromStdString(ns->getLoaiNhanSu()) << "\n";
        out << "MaNV: " << QString::fromStdString(ns->getMaNhanVien()) << "\n";
        out << "HoTen: " << QString::fromStdString(ns->getHoTen()) << "\n";
        out << "CCCD: " << QString::fromStdString(ns->getCCCD()) << "\n";
        out << "NgaySinh: " << QString::fromStdString(ns->getNgaySinh().toString()) << "\n";
        out << "GioiTinh: " << (ns->getGioiTinh() == GioiTinh::NAM ? "Nam" : "Nu") << "\n";
        out << "SDT: " << QString::fromStdString(ns->getSoDienThoai()) << "\n";
        out << "Email: " << QString::fromStdString(ns->getEmail()) << "\n";
        out << "DiaChi: " << QString::fromStdString(ns->getDiaChi()) << "\n";
        out << "SoTaiKhoan: " << QString::fromStdString(ns->getSoTaiKhoan()) << "\n";
        out << "NganHang: " << QString::fromStdString(ns->getTenNganHang()) << "\n";
        out << "NgayVaoCongTy: " << QString::fromStdString(ns->getNgayVaoCongTy().toString()) << "\n";
        out << "ViTri: " << QString::fromStdString(ns->getViTriCongViec()) << "\n";
        out << "PhongBan: " << QString::fromStdString(ns->getPhongBan().getTenPhongBan()) << " (" << QString::fromStdString(ns->getPhongBan().getMaPhongBan()) << ")\n";
        out << "TrinhDo: " << QString::fromStdString(ns->getTrinhDoHocVan()) << "\n";
        out << "ChuyenNganh: " << QString::fromStdString(ns->getChuyenNganh()) << "\n";

        // Ghi dữ liệu lương
        if (auto tv = std::dynamic_pointer_cast<NhanVienThuViec>(ns)) {
            out << "PhuCapThucTap: " << tv->getPhuCapThucTap() << "\n";
        } else if (auto ct = std::dynamic_pointer_cast<NhanVienChinhThuc>(ns)) {
            out << "LuongCoBan: " << ct->getLuongCoBan() << "\n";
            out << "HeSoLuong: " << ct->getHeSoLuong() << "\n";
            out << "PhuCapChucVu: " << ct->getPhuCapChucVu() << "\n";
            out << "PhuCapAnTrua: " << ct->getPhuCapAnTrua() << "\n";
            out << "PhuCapXangXe: " << ct->getPhuCapXangXe() << "\n";
            for (const auto& tn : ct->getDanhSachThanNhan()) {
                out << "ThanNhan: " << QString::fromStdString(tn.getHoTen()) << ";"
                    << QString::fromStdString(tn.getQuanHe()) << ";"
                    << QString::fromStdString(tn.getSoDienThoai()) << "\n";
            }
        } else if (auto ql = std::dynamic_pointer_cast<QuanLy>(ns)) {
            out << "LuongCoBan: " << ql->getLuongCoBan() << "\n";
            out << "HeSoLuong: " << ql->getHeSoLuong() << "\n";
            out << "PhuCapQuanLy: " << ql->getPhuCapQuanLy() << "\n";
            out << "ThuongHieuQua: " << ql->getThuongHieuQua() << "\n";
            for (const auto& tn : ql->getDanhSachThanNhan()) {
                out << "ThanNhan: " << QString::fromStdString(tn.getHoTen()) << ";"
                    << QString::fromStdString(tn.getQuanHe()) << ";"
                    << QString::fromStdString(tn.getSoDienThoai()) << "\n";
            }
        }
        out << "---------------------------------\n";
    }
    file.close();
}

// Hàm đọc/ghi Yêu cầu nghỉ phép (SỬA LỖI TÊN FILE VÀ DÙNG QLOCALE)
void docYeuCauNghiPhepTuFile() {
    g_danhSachYeuCauNghiPhep.clear();
    QFile file("yeucaughinghep.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream in(&file);
    QLocale locale(QLocale::C); // Dùng QLocale::C để đọc/ghi số thập phân nhất quán

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;

        // Định dạng: MaYC,MaNV,NgayBD,NgayKT,SoNgayNghi,LyDo,TrangThai(0-2),NguoiDuyet
        QStringList parts = line.split(',');
        if (parts.size() == 8) {
            std::string maYC = parts[0].toStdString();
            std::string maNV = parts[1].toStdString();
            NgayThang bd = NgayThang::fromString(parts[2].toStdString());
            NgayThang kt = NgayThang::fromString(parts[3].toStdString());

            double soNgay = locale.toDouble(parts[4]); // Dùng locale để đọc số

            std::string lyDo = parts[5].toStdString();

            // Xử lý trạng thái (0: Chờ duyệt, 1: Đã duyệt, 2: Từ chối)
            TrangThaiDuyet tt;
            int trangThaiInt = parts[6].toInt();
            if (trangThaiInt == 1) tt = TrangThaiDuyet::DA_DUYET;
            else if (trangThaiInt == 2) tt = TrangThaiDuyet::TU_CHOI;
            else tt = TrangThaiDuyet::CHO_DUYET;

            std::string nguoiDuyet = parts[7].toStdString();

            YeuCauNghiPhep yc(maYC, maNV, bd, kt, soNgay, lyDo, tt, nguoiDuyet);
            g_danhSachYeuCauNghiPhep.push_back(yc);
        }
    }
    file.close();
}

void luuYeuCauNghiPhepVaoFile() {
    QFile file("yeucaughinghep.txt"); // <<< TÊN FILE ĐÃ ĐƯỢC CHUẨN HÓA
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        return;
    }
    QTextStream out(&file);
    QLocale locale(QLocale::C); // Dùng QLocale::C để đảm bảo dấu thập phân là '.'

    for (const auto& yc : g_danhSachYeuCauNghiPhep) {
        // Định dạng: MaYC,MaNV,NgayBD,NgayKT,SoNgayNghi,LyDo,TrangThai(0-2),NguoiDuyet
        out << QString::fromStdString(yc.getMaYeuCau()) << ","
            << QString::fromStdString(yc.getMaNhanVien()) << ","
            << QString::fromStdString(yc.getNgayBatDau().toString()) << ","
            << QString::fromStdString(yc.getNgayKetThuc().toString()) << ","
            << locale.toString(yc.getSoNgayNghi(), 'f', 1) << "," // Dùng locale để ghi số
            << QString::fromStdString(yc.getLyDo()) << ","
            << (int)yc.getTrangThai() << "," // 0: Chờ duyệt, 1: Đã duyệt, 2: Từ chối
            << QString::fromStdString(yc.getNguoiDuyet()) << "\n";
    }
    file.close();
}
// HÀM XỬ LÝ TÀI KHOẢN (account.txt)

bool isUsernameTaken(const QString& username) {
    QFile file("account.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (line.startsWith("Ten nguoi dung: ") && line.mid(16).trimmed() == username) {
                file.close();
                return true;
            }
        }
        file.close();
    }
    return false;
}

void xoaTaiKhoan(const std::string& tenNguoiDung) {
    QString qTenNguoiDung = QString::fromStdString(tenNguoiDung);
    QFile inFile("account.txt");
    QFile outFile("account_temp.txt");

    if (!inFile.open(QIODevice::ReadOnly | QIODevice::Text) || !outFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return;
    }

    QTextStream in(&inFile);
    QTextStream out(&outFile);
    bool skipMode = false;

    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.startsWith("Ten nguoi dung: ")) {
            if (line.mid(16).trimmed() == qTenNguoiDung) {
                skipMode = true;
            } else {
                skipMode = false;
            }
        }
        if (line.startsWith("---------------------------------")) {
            if (skipMode) {
                skipMode = false;
                continue;
            }
        }
        if (!skipMode) {
            out << line << "\n";
        }
    }

    inFile.close();
    outFile.close();

    QFile::remove("account.txt");
    QFile::rename("account_temp.txt", "account.txt");
}


// HÀM XỬ LÝ DỰ ÁN (duan.txt)

DuAn* timDuAnTheoMa(const std::string& maDA) {
    for (auto& da : g_danhSachDuAn) {
        if (da.getMaDuAn() == maDA) {
            return &da;
        }
    }
    return nullptr;
}

void luuDuAnVaoFile() {
    QFile file("duan.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        return;
    }

    QTextStream out(&file);

    // Ghi số lượng dự án
    out << g_danhSachDuAn.size() << "\n";

    for (const auto& da : g_danhSachDuAn) {
        out << QString::fromStdString(da.getMaDuAn()) << "\n";
        out << QString::fromStdString(da.getTenDuAn()) << "\n";
        // Ghi ngày tháng (dùng toString() đã sửa)
        out << QString::fromStdString(da.getNgayBatDau().toString()) << "\n";
        out << QString::fromStdString(da.getNgayKetThuc().toString()) << "\n";
        out << QString::fromStdString(da.getNguoiPhuTrach()) << "\n";
        out << da.getKinhPhi() << "\n";
        out << (da.isDaHoanThanh() ? "1" : "0") << "\n";

        // Danh sách thành viên
        const auto& thanhVien = da.getDanhSachThanhVien();
        out << thanhVien.size() << "\n";
        for (const auto& tv : thanhVien) {
            out << QString::fromStdString(tv) << "\n";
        }
    }

    file.close();
}

void docDuAnTuFile() {
    QFile file("duan.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    g_danhSachDuAn.clear();
    QTextStream in(&file);

    int soLuong = in.readLine().toInt();

    for (int i = 0; i < soLuong; ++i) {
        if (in.atEnd()) break;

        std::string maDA = in.readLine().toStdString();
        std::string tenDA = in.readLine().toStdString();
        NgayThang batDau = NgayThang::fromString(in.readLine().toStdString());
        NgayThang ketThuc = NgayThang::fromString(in.readLine().toStdString());
        std::string nguoiPhuTrach = in.readLine().toStdString();
        double kinhPhi = in.readLine().toDouble();
        bool hoanThanh = (in.readLine().toInt() == 1);

        std::vector<std::string> thanhVien;
        int soTV = in.readLine().toInt();
        for (int j = 0; j < soTV; ++j) {
            if (in.atEnd()) break;
            thanhVien.push_back(in.readLine().toStdString());
        }

        DuAn da(maDA, tenDA, batDau, ketThuc, nguoiPhuTrach, thanhVien, kinhPhi, hoanThanh);
        g_danhSachDuAn.push_back(da);
    }

    file.close();
}
PhongBan* timPhongBanTheoMa(const std::string& maPB) {
    for (auto& pb : g_danhSachPhongBan) {
        if (pb.getMaPhongBan() == maPB) {
            return &pb;
        }
    }
    return nullptr;
}
void luuPhongBanVaoFile() {
    QFile file("phongban.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        return;
    }
    QTextStream out(&file);
    for (const auto& pb : g_danhSachPhongBan) {
        // Định dạng: MaPB,TenPB
        out << QString::fromStdString(pb.getMaPhongBan()) << ","
            << QString::fromStdString(pb.getTenPhongBan()) << "\n";
    }
    file.close();
}
void docPhongBanTuFile() {
    g_danhSachPhongBan.clear();
    QFile file("phongban.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;

        QStringList parts = line.split(',');
        if (parts.size() == 2) {
            g_danhSachPhongBan.emplace_back(
                parts[0].toStdString(), // MaPB
                parts[1].toStdString()  // TenPB
                );
        }
    }
    file.close();
}
