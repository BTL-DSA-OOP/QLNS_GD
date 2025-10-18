#include "ClassNhanSu.h"
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <memory>
#include <string>

// Khai báo biến toàn cục cho ds nhân sự, dự án
std::vector<std::shared_ptr<NhanSu>> danhSachNhanSu;
std::vector<DuAn> danhSachDuAn;

// File lưu trữ nhân sự, dự án
const std::string FILE_NHANSU = "nhansu.txt";
const std::string FILE_DUAN = "duan.txt";

std::string gioiTinhToString(GioiTinh gt) {
    return (gt == GioiTinh::NAM) ? "NAM" : "NU";
}

GioiTinh stringToGioiTinh(const std::string& str) {
    return (str == "NAM") ? GioiTinh::NAM : GioiTinh::NU;
}

std::string trangThaiToString(TrangThaiNhanVien tt) {
    return (tt == TrangThaiNhanVien::DANG_LAM) ? "DANG_LAM" : "NGHI_VIEC";
}

TrangThaiNhanVien stringToTrangThai(const std::string& str) {
    return (str == "DANG_LAM") ? TrangThaiNhanVien::DANG_LAM : TrangThaiNhanVien::NGHI_VIEC;
}

//TÌM KIẾM
int timViTriNhanSu(const std::string& maNV) {
    for (size_t i = 0; i < danhSachNhanSu.size(); ++i) {
        if (danhSachNhanSu[i]->getMaNhanVien() == maNV) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

std::shared_ptr<NhanSu> timNhanSuTheoMa(const std::string& maNV) {
    for (const auto& ns : danhSachNhanSu) {
        if (ns->getMaNhanVien() == maNV) {
            return ns;
        }
    }
    return nullptr;
}

DuAn* timDuAnTheoMa(const std::string& maDA) {
    for (auto& da : danhSachDuAn) {
        if (da.getMaDuAn() == maDA) {
            return &da;
        }
    }
    return nullptr;
}

//LƯU DỮ LIỆU NHÂN SỰ
void luuNhanSuVaoFile() {
    std::ofstream file(FILE_NHANSU);
    if (!file.is_open()) {
        std::cout << "Khong the mo file de ghi!" << std::endl;
        return;
    }

    file << danhSachNhanSu.size() << "\n";

    for (const auto& ns : danhSachNhanSu) {
        // Loại nhân sự
        file << ns->getLoaiNhanSu() << "\n";

        // Thông tin cơ bản
        file << ns->getMaNhanVien() << "\n";
        file << ns->getHoTen() << "\n";
        file << ns->getCCCD() << "\n";
        file << ns->getNgaySinh().getNgay() << " "
             << ns->getNgaySinh().getThang() << " "
             << ns->getNgaySinh().getNam() << "\n";
        file << gioiTinhToString(ns->getGioiTinh()) << "\n";

        // Liên hệ
        file << ns->getSoDienThoai() << "\n";
        file << ns->getEmail() << "\n";
        file << ns->getDiaChi() << "\n";

        // Ngân hàng
        file << ns->getSoTaiKhoan() << "\n";
        file << ns->getTenNganHang() << "\n";

        // Công việc
        file << ns->getViTriCongViec() << "\n";
        file << ns->getPhongBan().getMaPhongBan() << "\n";
        file << ns->getPhongBan().getTenPhongBan() << "\n";
        file << ns->getNgayVaoCongTy().getNgay() << " "
             << ns->getNgayVaoCongTy().getThang() << " "
             << ns->getNgayVaoCongTy().getNam() << "\n";
        file << trangThaiToString(ns->getTrangThai()) << "\n";

        // Học vấn
        file << ns->getTrinhDoHocVan() << "\n";
        file << ns->getChuyenNganh() << "\n";

        // Thông tin đặc thù theo loại
        if (auto nvtv = std::dynamic_pointer_cast<NhanVienThuViec>(ns)) {
            file << nvtv->getPhuCapThucTap() << "\n";
            file << nvtv->getDanhGia() << "\n";
        } else if (auto nvct = std::dynamic_pointer_cast<NhanVienChinhThuc>(ns)) {
            file << nvct->getLuongCoBan() << "\n";
            file << nvct->getHeSoLuong() << "\n";
            file << nvct->getSoNgayPhepConLai() << "\n";

            // Khen thưởng
            const auto& kt = nvct->getKhenThuong();
            file << kt.size() << "\n";
            for (const auto& k : kt) {
                file << k << "\n";
            }

            // Kỷ luật
            const auto& kl = nvct->getKyLuat();
            file << kl.size() << "\n";
            for (const auto& k : kl) {
                file << k << "\n";
            }

            // Thân nhân
            const auto& tn = nvct->getDanhSachThanNhan();
            file << tn.size() << "\n";
            for (const auto& t : tn) {
                file << t.getHoTen() << "\n";
                file << t.getSoDienThoai() << "\n";
                file << t.getQuanHe() << "\n";
            }
        } else if (auto ql = std::dynamic_pointer_cast<QuanLy>(ns)) {
            file << ql->getLuongCoBan() << "\n";
            file << ql->getHeSoLuong() << "\n";
            file << ql->getPhuCapQuanLy() << "\n";
            file << ql->getThuongHieuQua() << "\n";
            file << ql->getSoLuongNhanVienQuanLy() << "\n";

            // Phòng ban quản lý
            const auto& pb = ql->getPhongBanQuanLy();
            file << pb.size() << "\n";
            for (const auto& p : pb) {
                file << p << "\n";
            }

            // Dự án phụ trách
            const auto& da = ql->getDuAnPhuTrach();
            file << da.size() << "\n";
            for (const auto& d : da) {
                file << d << "\n";
            }

            // Thân nhân
            const auto& tn = ql->getDanhSachThanNhan();
            file << tn.size() << "\n";
            for (const auto& t : tn) {
                file << t.getHoTen() << "\n";
                file << t.getSoDienThoai() << "\n";
                file << t.getQuanHe() << "\n";
            }
        }
    }
    file.close();
    std::cout << "Da luu " << danhSachNhanSu.size() << " nhan su vao file!" << std::endl;
}

//ĐỌC DỮ LIỆU NHÂN SỰ
void docNhanSuTuFile() {
    std::ifstream file(FILE_NHANSU);
    if (!file.is_open()) {
        std::cout << "Chua co file du lieu nhan su. Bat dau voi danh sach trong." << std::endl;
        return;
    }

    danhSachNhanSu.clear();

    int soLuong;
    file >> soLuong;
    file.ignore();

    for (int i = 0; i < soLuong; ++i) {
        std::string loaiNS;
        std::getline(file, loaiNS);

        // Đọc thông tin cơ bản
        std::string maNV, hoTen, cccd;
        int ngay, thang, nam;
        std::string gioiTinhStr;

        std::getline(file, maNV);
        std::getline(file, hoTen);
        std::getline(file, cccd);
        file >> ngay >> thang >> nam;
        file.ignore();
        std::getline(file, gioiTinhStr);

        NgayThang ngaySinh(ngay, thang, nam);
        GioiTinh gioiTinh = stringToGioiTinh(gioiTinhStr);

        // Đọc liên hệ
        std::string sdt, email, diaChi;
        std::getline(file, sdt);
        std::getline(file, email);
        std::getline(file, diaChi);

        // Đọc ngân hàng
        std::string stk, nganHang;
        std::getline(file, stk);
        std::getline(file, nganHang);

        // Đọc công việc
        std::string viTri, maPB, tenPB;
        std::string trangThaiStr;
        int ngayVao, thangVao, namVao;

        std::getline(file, viTri);
        std::getline(file, maPB);
        std::getline(file, tenPB);
        file >> ngayVao >> thangVao >> namVao;
        file.ignore();
        std::getline(file, trangThaiStr);

        NgayThang ngayVaoCty(ngayVao, thangVao, namVao);
        TrangThaiNhanVien trangThai = stringToTrangThai(trangThaiStr);

        // Đọc học vấn
        std::string trinhDo, chuyenNganh;
        std::getline(file, trinhDo);
        std::getline(file, chuyenNganh);

        std::shared_ptr<NhanSu> ns;

        // Tạo đối tượng theo loại
        if (loaiNS == "Nhan vien thu viec") {
            double phuCap;
            std::string danhGia;
            file >> phuCap;
            file.ignore();
            std::getline(file, danhGia);

            ns = std::make_shared<NhanVienThuViec>(maNV, hoTen, cccd, ngaySinh, gioiTinh, phuCap,
                                                   sdt, email, diaChi, stk, nganHang, ngayVaoCty,
                                                   viTri, PhongBan(maPB, tenPB), trinhDo, chuyenNganh, danhGia);
        } else if (loaiNS == "Nhan vien chinh thuc") {
            double luong, heSo;
            int ngayPhep;
            file >> luong >> heSo >> ngayPhep;
            file.ignore();

            ns = std::make_shared<NhanVienChinhThuc>(maNV, hoTen, cccd, ngaySinh, gioiTinh, luong, heSo,
                                                     0, 0, 0, ngayPhep, sdt, email, diaChi, stk, nganHang,
                                                     ngayVaoCty, viTri, PhongBan(maPB, tenPB), trinhDo, chuyenNganh);

            auto nvct = std::dynamic_pointer_cast<NhanVienChinhThuc>(ns);

            // Đọc khen thưởng
            int soKT;
            file >> soKT;
            file.ignore();
            for (int j = 0; j < soKT; ++j) {
                std::string kt;
                std::getline(file, kt);
                nvct->themKhenThuong(kt);
            }

            // Đọc kỷ luật
            int soKL;
            file >> soKL;
            file.ignore();
            for (int j = 0; j < soKL; ++j) {
                std::string kl;
                std::getline(file, kl);
                nvct->themKyLuat(kl);
            }

            // Đọc thân nhân
            int soTN;
            file >> soTN;
            file.ignore();
            for (int j = 0; j < soTN; ++j) {
                std::string ht, sdt_tn, qh;
                std::getline(file, ht);
                std::getline(file, sdt_tn);
                std::getline(file, qh);
                nvct->themThanNhan(ThanNhan(ht, sdt_tn, qh));
            }
        } else if (loaiNS == "Quan ly") {
            double luong, heSo, pcQL, thuong;
            int soNV;
            file >> luong >> heSo >> pcQL >> thuong >> soNV;
            file.ignore();

            ns = std::make_shared<QuanLy>(maNV, hoTen, cccd, ngaySinh, gioiTinh, luong, heSo,
                                          pcQL, thuong, soNV, sdt, email, diaChi, stk, nganHang,
                                          ngayVaoCty, viTri, PhongBan(maPB, tenPB), trinhDo, chuyenNganh);

            auto ql = std::dynamic_pointer_cast<QuanLy>(ns);

            // Đọc phòng ban quản lý
            int soPB;
            file >> soPB;
            file.ignore();
            for (int j = 0; j < soPB; ++j) {
                std::string pb;
                std::getline(file, pb);
                ql->themPhongBanQuanLy(pb);
            }

            // Đọc dự án
            int soDA;
            file >> soDA;
            file.ignore();
            for (int j = 0; j < soDA; ++j) {
                std::string da;
                std::getline(file, da);
                ql->themDuAnPhuTrach(da);
            }

            // Đọc thân nhân
            int soTN;
            file >> soTN;
            file.ignore();
            for (int j = 0; j < soTN; ++j) {
                std::string ht, sdt_tn, qh;
                std::getline(file, ht);
                std::getline(file, sdt_tn);
                std::getline(file, qh);
                ql->themThanNhan(ThanNhan(ht, sdt_tn, qh));
            }
        }

        // Cập nhật trạng thái
        if (ns) {
            ns->setTrangThai(trangThai);
            danhSachNhanSu.push_back(ns);
        }
    }

    file.close();
    std::cout << "Da doc " << danhSachNhanSu.size() << " nhan su tu file!" << std::endl;
}

// LƯU DỮ LIỆU DỰ ÁN
void luuDuAnVaoFile() {
    std::ofstream file(FILE_DUAN);
    if (!file.is_open()) {
        std::cout << "Khong the mo file du an de ghi!" << std::endl;
        return;
    }

    file << danhSachDuAn.size() << "\n";

    for (const auto& da : danhSachDuAn) {
        file << da.getMaDuAn() << "\n";
        file << da.getTenDuAn() << "\n";
        file << da.getNgayBatDau().getNgay() << " "
             << da.getNgayBatDau().getThang() << " "
             << da.getNgayBatDau().getNam() << "\n";
        file << da.getNgayKetThuc().getNgay() << " "
             << da.getNgayKetThuc().getThang() << " "
             << da.getNgayKetThuc().getNam() << "\n";
        file << da.getNguoiPhuTrach() << "\n";
        file << da.getKinhPhi() << "\n";
        file << (da.isDaHoanThanh() ? "1" : "0") << "\n";

        // Danh sách thành viên
        const auto& thanhVien = da.getDanhSachThanhVien();
        file << thanhVien.size() << "\n";
        for (const auto& tv : thanhVien) {
            file << tv << "\n";
        }
    }

    file.close();
    std::cout << "Da luu " << danhSachDuAn.size() << " du an vao file!" << std::endl;
}

//ĐỌC DỮ LIỆU DỰ ÁN
void docDuAnTuFile() {
    std::ifstream file(FILE_DUAN);
    if (!file.is_open()) {
        std::cout << "Chua co file du lieu du an. Bat dau voi danh sach trong." << std::endl;
        return;
    }

    danhSachDuAn.clear();

    int soLuong;
    file >> soLuong;
    file.ignore();

    for (int i = 0; i < soLuong; ++i) {
        std::string maDA, tenDA, nguoiPhuTrach;
        int ngayBD, thangBD, namBD;
        int ngayKT, thangKT, namKT;
        double kinhPhi;
        int hoanThanh;

        std::getline(file, maDA);
        std::getline(file, tenDA);
        file >> ngayBD >> thangBD >> namBD;
        file >> ngayKT >> thangKT >> namKT;
        file.ignore();
        std::getline(file, nguoiPhuTrach);
        file >> kinhPhi >> hoanThanh;
        file.ignore();

        NgayThang batDau(ngayBD, thangBD, namBD);
        NgayThang ketThuc(ngayKT, thangKT, namKT);

        std::vector<std::string> thanhVien;
        int soTV;
        file >> soTV;
        file.ignore();
        for (int j = 0; j < soTV; ++j) {
            std::string tv;
            std::getline(file, tv);
            thanhVien.push_back(tv);
        }

        DuAn da(maDA, tenDA, batDau, ketThuc, nguoiPhuTrach, thanhVien, kinhPhi, static_cast<bool>(hoanThanh));
        danhSachDuAn.push_back(da);
    }

    file.close();
    std::cout << "Da doc " << danhSachDuAn.size() << " du an tu file!" << std::endl;
}

//THÊM NHÂN SỰ
void themNhanSu() {
    int loai;
    std::cout << "Chon loai nhan su (1: Thu viec, 2: Chinh thuc, 3: Quan ly): ";
    std::cin >> loai;
    std::cin.ignore();

    // Nhập thông tin chung
    std::string maNV, hoTen, cccd, sdt, email, diaChi, stk, nganHang, viTri, maPB, tenPB, trinhDo, chuyenNganh;
    int ngaySinhD, thangSinhM, namSinhY, ngayVaoD, thangVaoM, namVaoY;
    std::string gioiTinhStr;

    std::cout << "Ma nhan vien: ";
    std::getline(std::cin, maNV);
    if (timNhanSuTheoMa(maNV)) {
        std::cout << "Ma da ton tai!" << std::endl;
        return;
    }

    std::cout << "Ho ten: ";
    std::getline(std::cin, hoTen);
    std::cout << "CCCD: ";
    std::getline(std::cin, cccd);
    std::cout << "Ngay sinh (dd mm yyyy): ";
    std::cin >> ngaySinhD >> thangSinhM >> namSinhY;
    std::cin.ignore();
    std::cout << "Gioi tinh (NAM/NU): ";
    std::getline(std::cin, gioiTinhStr);
    std::cout << "So dien thoai: ";
    std::getline(std::cin, sdt);
    std::cout << "Email: ";
    std::getline(std::cin, email);
    std::cout << "Dia chi: ";
    std::getline(std::cin, diaChi);
    std::cout << "So tai khoan: ";
    std::getline(std::cin, stk);
    std::cout << "Ten ngan hang: ";
    std::getline(std::cin, nganHang);
    std::cout << "Vi tri cong viec: ";
    std::getline(std::cin, viTri);
    std::cout << "Ma phong ban: ";
    std::getline(std::cin, maPB);
    std::cout << "Ten phong ban: ";
    std::getline(std::cin, tenPB);
    std::cout << "Ngay vao cong ty (dd mm yyyy): ";
    std::cin >> ngayVaoD >> thangVaoM >> namVaoY;
    std::cin.ignore();
    std::cout << "Trinh do hoc van: ";
    std::getline(std::cin, trinhDo);
    std::cout << "Chuyen nganh: ";
    std::getline(std::cin, chuyenNganh);

    NgayThang ngaySinh(ngaySinhD, thangSinhM, namSinhY);
    GioiTinh gt = stringToGioiTinh(gioiTinhStr);
    NgayThang ngayVao(ngayVaoD, thangVaoM, namVaoY);
    PhongBan pb(maPB, tenPB);
    TrangThaiNhanVien tt = TrangThaiNhanVien::DANG_LAM; // Mặc định trạng thái là DANG_LAM

    std::shared_ptr<NhanSu> ns;

    if (loai == 1) { // Thu viec
        double phuCap;
        std::string danhGia;
        std::cout << "Phu cap thuc tap: ";
        std::cin >> phuCap;
        std::cin.ignore();
        std::cout << "Danh gia: ";
        std::getline(std::cin, danhGia);

        ns = std::make_shared<NhanVienThuViec>(maNV, hoTen, cccd, ngaySinh, gt, phuCap,
                                               sdt, email, diaChi, stk, nganHang, ngayVao,
                                               viTri, pb, trinhDo, chuyenNganh, danhGia);
    } else if (loai == 2) { // Chinh thuc
        double luong, heSo, pcChucVu, pcAnTrua, pcXangXe;
        int phep;
        std::cout << "Luong co ban: ";
        std::cin >> luong;
        std::cout << "He so luong: ";
        std::cin >> heSo;
        std::cout << "Phu cap chuc vu: ";
        std::cin >> pcChucVu;
        std::cout << "Phu cap an trua: ";
        std::cin >> pcAnTrua;
        std::cout << "Phu cap xang xe: ";
        std::cin >> pcXangXe;
        std::cout << "So ngay phep con lai: ";
        std::cin >> phep;
        std::cin.ignore();

        ns = std::make_shared<NhanVienChinhThuc>(maNV, hoTen, cccd, ngaySinh, gt, luong, heSo,
                                                 pcChucVu, pcAnTrua, pcXangXe, phep,
                                                 sdt, email, diaChi, stk, nganHang, ngayVao,
                                                 viTri, pb, trinhDo, chuyenNganh);
    } else if (loai == 3) { // Quan ly
        double luong, heSo, pcQuanLy, thuong;
        int soNVQuanLy;
        std::cout << "Luong co ban: ";
        std::cin >> luong;
        std::cout << "He so luong: ";
        std::cin >> heSo;
        std::cout << "Phu cap quan ly: ";
        std::cin >> pcQuanLy;
        std::cout << "Thuong hieu qua: ";
        std::cin >> thuong;
        std::cout << "So luong nhan vien quan ly: ";
        std::cin >> soNVQuanLy;
        std::cin.ignore();

        ns = std::make_shared<QuanLy>(maNV, hoTen, cccd, ngaySinh, gt, luong, heSo,
                                      pcQuanLy, thuong, soNVQuanLy, sdt, email, diaChi,
                                      stk, nganHang, ngayVao, viTri, pb, trinhDo, chuyenNganh);
    } else {
        std::cout << "Loai khong hop le!" << std::endl;
        return;
    }

    danhSachNhanSu.push_back(ns);
    std::cout << "Them nhan su thanh cong!" << std::endl;
    luuNhanSuVaoFile();
}

//SỬA THÔNG TIN
void suaThongTinLienHe(std::shared_ptr<NhanSu> ns) {
    std::string sdt, email, diaChi;
    std::cout << "So dien thoai moi: ";
    std::getline(std::cin, sdt);
    std::cout << "Email moi: ";
    std::getline(std::cin, email);
    std::cout << "Dia chi moi: ";
    std::getline(std::cin, diaChi);

    ns->capNhatLienHe(sdt, email, diaChi);
    std::cout << "Cap nhat lien he thanh cong!" << std::endl;
}

void suaThongTinNganHang(std::shared_ptr<NhanSu> ns) {
    std::string stk, nganHang;
    std::cout << "So tai khoan moi: ";
    std::getline(std::cin, stk);
    std::cout << "Ten ngan hang moi: ";
    std::getline(std::cin, nganHang);

    ns->capNhatNganHang(stk, nganHang);
    std::cout << "Cap nhat thong tin ngan hang thanh cong!" << std::endl;
}

void suaThongTinHocVan(std::shared_ptr<NhanSu> ns) {
    std::string trinhDo, chuyenNganh;
    std::cout << "Trinh do hoc van moi: ";
    std::getline(std::cin, trinhDo);
    std::cout << "Chuyen nganh moi: ";
    std::getline(std::cin, chuyenNganh);

    ns->capNhatHocVan(trinhDo, chuyenNganh);
    std::cout << "Cap nhat hoc van thanh cong!" << std::endl;
}

void suaLuongNhanVienChinhThuc(std::shared_ptr<NhanVienChinhThuc> nv) {
    double luong, heSo, pcChucVu, pcAnTrua, pcXangXe;
    std::cout << "Luong co ban moi: ";
    std::cin >> luong;
    std::cout << "He so luong moi: ";
    std::cin >> heSo;
    std::cin.ignore();

    nv->capNhatLuong(luong, heSo);

    std::cout << "Phu cap chuc vu moi: ";
    std::cin >> pcChucVu;
    std::cout << "Phu cap an trua moi: ";
    std::cin >> pcAnTrua;
    std::cout << "Phu cap xang xe moi: ";
    std::cin >> pcXangXe;
    std::cin.ignore();

    nv->setPhuCapChucVu(pcChucVu);
    nv->setPhuCapAnTrua(pcAnTrua);
    nv->setPhuCapXangXe(pcXangXe);

    std::cout << "Cap nhat luong thanh cong!" << std::endl;
}

void suaThongTinQuanLy(std::shared_ptr<QuanLy> ql) {
    double luong, heSo, pcQL, thuong;
    std::cout << "Luong co ban moi: ";
    std::cin >> luong;
    std::cout << "He so luong moi: ";
    std::cin >> heSo;
    std::cout << "Phu cap quan ly moi: ";
    std::cin >> pcQL;
    std::cout << "Thuong hieu qua moi: ";
    std::cin >> thuong;
    std::cin.ignore();

    ql->capNhatLuong(luong, heSo);
    ql->setPhuCapQuanLy(pcQL);
    ql->setThuongHieuQua(thuong);
    std::cout << "Cap nhat thong tin quan ly thanh cong!" << std::endl;
}

void suaThongTinNhanSu() {
    std::string maNV;
    std::cout << "Nhap ma nhan vien can sua: ";
    std::getline(std::cin, maNV);

    auto ns = timNhanSuTheoMa(maNV);
    if (ns == nullptr) {
        std::cout << "Khong tim thay nhan vien!" << std::endl;
        return;
    }

    std::cout << "\n--- CHON THONG TIN CAN SUA ---" << std::endl;
    std::cout << "1. Thong tin lien he" << std::endl;
    std::cout << "2. Thong tin ngan hang" << std::endl;
    std::cout << "3. Thong tin hoc van" << std::endl;
    std::cout << "4. Luong va phu cap (chi NVCT va QL)" << std::endl;
    std::cout << "5. Trang thai lam viec" << std::endl;
    int chon;
    std::cin >> chon;
    std::cin.ignore();

    switch (chon) {
    case 1:
        suaThongTinLienHe(ns);
        break;
    case 2:
        suaThongTinNganHang(ns);
        break;
    case 3:
        suaThongTinHocVan(ns);
        break;
    case 4: {
        if (auto nv = std::dynamic_pointer_cast<NhanVienChinhThuc>(ns)) {
            suaLuongNhanVienChinhThuc(nv);
        } else if (auto ql = std::dynamic_pointer_cast<QuanLy>(ns)) {
            suaThongTinQuanLy(ql);
        } else {
            std::cout << "Nhan vien thu viec khong co chuc nang nay!" << std::endl;
        }
        break;
    }
    case 5: {
        std::string ttStr;
        std::cout << "Trang thai moi (DANG_LAM/NGHI_VIEC): ";
        std::getline(std::cin, ttStr);
        TrangThaiNhanVien tt = stringToTrangThai(ttStr);
        ns->setTrangThai(tt);
        std::cout << "Cap nhat trang thai thanh cong!" << std::endl;
        break;
    }
    default:
        std::cout << "Lua chon khong hop le!" << std::endl;
    }

    luuNhanSuVaoFile();
}

//XÓA NHÂN SỰ
void xoaNhanSu() {
    std::string maNV;
    std::cout << "Nhap ma nhan vien can xoa: ";
    std::getline(std::cin, maNV);

    auto ns = timNhanSuTheoMa(maNV);
    if (ns == nullptr) {
        std::cout << "Khong tim thay nhan vien!" << std::endl;
        return;
    }

    // Kiểm tra nếu là quản lý dự án hoặc thành viên dự án
    bool coLienQuanDuAn = false;
    for (auto& da : danhSachDuAn) {
        if (da.getNguoiPhuTrach() == maNV) {
            std::cout << "Nhan vien nay dang phu trach du an " << da.getMaDuAn() << ". Khong the xoa!" << std::endl;
            coLienQuanDuAn = true;
            break;
        }
        da.xoaThanhVien(maNV);
        std::cout << "Da xoa nhan vien khoi du an " << da.getMaDuAn() << "." << std::endl;
    }

    if (coLienQuanDuAn) return;

    int viTri = timViTriNhanSu(maNV);
    if (viTri != -1) {
        danhSachNhanSu.erase(danhSachNhanSu.begin() + viTri);
        std::cout << "Xoa nhan vien thanh cong!" << std::endl;
    }
    luuNhanSuVaoFile();
    luuDuAnVaoFile();
}

// TÌM KIẾM NHÂN SỰ - Khi đưa vào giao diện thì sẽ nâng cấp lên, không chỉ search dựa trên các thông tin cơ bản như này nữa
void timKiemNhanSu() {
    std::cout << "\n--- TIM KIEM NHAN SU ---" << std::endl;
    std::cout << "1. Theo ma" << std::endl;
    std::cout << "2. Theo ten" << std::endl;
    std::cout << "3. Theo phong ban" << std::endl;
    int chon;
    std::cin >> chon;
    std::cin.ignore();

    if (chon == 1) {
        std::string ma;
        std::cout << "Nhap ma: ";
        std::getline(std::cin, ma);
        auto ns = timNhanSuTheoMa(ma);
        if (ns) ns->hienThiThongTin();
        else std::cout << "Khong tim thay!" << std::endl;
    } else if (chon == 2) {
        std::string ten;
        std::cout << "Nhap ten: ";
        std::getline(std::cin, ten);
        bool found = false;
        for (const auto& ns : danhSachNhanSu) {
            if (ns->getHoTen().find(ten) != std::string::npos) {
                ns->hienThiThongTin();
                found = true;
            }
        }
        if (!found) std::cout << "Khong tim thay!" << std::endl;
    } else if (chon == 3) {
        std::string maPB;
        std::cout << "Nhap ma phong ban: ";
        std::getline(std::cin, maPB);
        bool found = false;
        for (const auto& ns : danhSachNhanSu) {
            if (ns->getPhongBan().getMaPhongBan() == maPB) {
                ns->hienThiThongTin();
                found = true;
            }
        }
        if (!found) std::cout << "Khong tim thay!" << std::endl;
    }
}

//  HIỂN THỊ DANH SÁCH NHÂN SỰ
void hienThiDanhSachNhanSu() {
    if (danhSachNhanSu.empty()) {
        std::cout << "Danh sach trong!" << std::endl;
        return;
    }

    for (const auto& ns : danhSachNhanSu) {
        ns->hienThiThongTin();
        std::cout << std::endl;
    }
}

//  THÊM THÂN NHÂN
void themThanNhanChoNhanSu() {
    std::string maNV;
    std::cout << "Nhap ma nhan vien: ";
    std::getline(std::cin, maNV);

    auto ns = timNhanSuTheoMa(maNV);
    if (!ns) {
        std::cout << "Khong tim thay!" << std::endl;
        return;
    }

    auto nvct = std::dynamic_pointer_cast<NhanVienChinhThuc>(ns);
    auto ql = std::dynamic_pointer_cast<QuanLy>(ns);

    if (!nvct && !ql) {
        std::cout << "Chi NVCT va QL co than nhan!" << std::endl;
        return;
    }

    std::string hoTen, sdt, quanHe;
    std::cout << "Ho ten than nhan: ";
    std::getline(std::cin, hoTen);
    std::cout << "So dien thoai: ";
    std::getline(std::cin, sdt);
    std::cout << "Quan he: ";
    std::getline(std::cin, quanHe);

    ThanNhan tn(hoTen, sdt, quanHe);

    if (nvct) nvct->themThanNhan(tn);
    else ql->themThanNhan(tn);

    std::cout << "Them than nhan thanh cong!" << std::endl;
    luuNhanSuVaoFile();
}

// QUẢN LÝ DỰ ÁN
void themDuAn() {
    std::string maDA, tenDA, nguoiPhuTrach;
    double kinhPhi;
    int ngayBD, thangBD, namBD;

    std::cout << "Nhap ma du an: ";
    std::getline(std::cin, maDA);

    if (timDuAnTheoMa(maDA)) {
        std::cout << "Ma du an da ton tai!" << std::endl;
        return;
    }

    std::cout << "Nhap ten du an: ";
    std::getline(std::cin, tenDA);

    std::cout << "Ngay bat dau (dd mm yyyy): ";
    std::cin >> ngayBD >> thangBD >> namBD;
    std::cin.ignore();

    std::cout << "Kinh phi: ";
    std::cin >> kinhPhi;
    std::cin.ignore();

    std::cout << "Nhap ma quan ly phu trach: ";
    std::getline(std::cin, nguoiPhuTrach);

    auto ql = std::dynamic_pointer_cast<QuanLy>(timNhanSuTheoMa(nguoiPhuTrach));
    if (!ql) {
        std::cout << "Khong tim thay quan ly hoac khong phai quan ly!" << std::endl;
        return;
    }

    NgayThang batDau(ngayBD, thangBD, namBD);
    DuAn da(maDA, tenDA, batDau, NgayThang(0, 0, 0), nguoiPhuTrach, {}, kinhPhi, false);

    ql->themDuAnPhuTrach(maDA);

    danhSachDuAn.push_back(da);
    std::cout << "Them du an thanh cong!" << std::endl;
    luuDuAnVaoFile();
    luuNhanSuVaoFile();
}

void themThanhVienVaoDuAn() {
    std::string maDA;
    std::cout << "Nhap ma du an: ";
    std::getline(std::cin, maDA);

    auto da = timDuAnTheoMa(maDA);
    if (!da) {
        std::cout << "Khong tim thay du an!" << std::endl;
        return;
    }

    std::string maNV;
    std::cout << "Nhap ma nhan vien them vao: ";
    std::getline(std::cin, maNV);

    auto ns = timNhanSuTheoMa(maNV);
    if (!ns) {
        std::cout << "Khong tim thay nhan vien!" << std::endl;
        return;
    }

    da->themThanhVien(maNV);
    std::cout << "Them thanh vien thanh cong!" << std::endl;
    luuDuAnVaoFile();
}

void hoanThanhDuAn() {
    std::string maDA;
    std::cout << "Nhap ma du an hoan thanh: ";
    std::getline(std::cin, maDA);

    auto da = timDuAnTheoMa(maDA);
    if (!da) {
        std::cout << "Khong tim thay!" << std::endl;
        return;
    }

    int ngayKT, thangKT, namKT;
    std::cout << "Ngay ket thuc (dd mm yyyy): ";
    std::cin >> ngayKT >> thangKT >> namKT;
    std::cin.ignore();

    NgayThang ketThuc(ngayKT, thangKT, namKT);
    da->setNgayKetThuc(ketThuc);
    da->setDaHoanThanh(true);

    std::cout << "Du an da hoan thanh!" << std::endl;
    luuDuAnVaoFile();
}

void hienThiDanhSachDuAn() {
    if (danhSachDuAn.empty()) {
        std::cout << "Danh sach du an trong!" << std::endl;
        return;
    }

    for (const auto& da : danhSachDuAn) {
        da.hienThi();
        std::cout << std::endl;
    }
}

// BÁO CÁO LƯƠNG
void baoCaoLuong() {
    double tongLuong = 0;
    for (const auto& ns : danhSachNhanSu) {
        tongLuong += ns->tinhLuongThucNhan();
    }
    std::cout << "Tong luong: " << tongLuong << std::endl;
}

// THỐNG KÊ
void thongKeNhanSu() {
    int thuViec = 0, chinhThuc = 0, quanLy = 0;
    for (const auto& ns : danhSachNhanSu) {
        if (std::dynamic_pointer_cast<NhanVienThuViec>(ns)) thuViec++;
        else if (std::dynamic_pointer_cast<NhanVienChinhThuc>(ns)) chinhThuc++;
        else quanLy++;
    }
    std::cout << "Thu viec: " << thuViec << ", Chinh thuc: " << chinhThuc << ", Quan ly: " << quanLy << std::endl;
}

// // MENU
// void hienThiMenu() {
//     std::cout << "\n=== MENU ===" << std::endl;
//     std::cout << "1. Them nhan su" << std::endl;
//     std::cout << "2. Sua thong tin nhan su" << std::endl;
//     std::cout << "3. Xoa nhan su" << std::endl;
//     std::cout << "4. Tim kiem nhan su" << std::endl;
//     std::cout << "5. Hien thi danh sach nhan su" << std::endl;
//     std::cout << "6. Them than nhan" << std::endl;
//     std::cout << "7. Bao cao luong" << std::endl;
//     std::cout << "8. Thong ke nhan su" << std::endl;
//     std::cout << "9. Luu du lieu" << std::endl;
//     std::cout << "10. Them du an" << std::endl;
//     std::cout << "11. Them thanh vien vao du an" << std::endl;
//     std::cout << "12. Hoan thanh du an" << std::endl;
//     std::cout << "13. Hien thi danh sach du an" << std::endl;
//     std::cout << "0. Thoat" << std::endl;
//     std::cout << "Chon: ";
// }
