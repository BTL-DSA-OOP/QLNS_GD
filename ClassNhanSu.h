#ifndef CLASSNHANSU_H
#define CLASSNHANSU_H

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <stdio.h>

// --- ENUMS ---
enum class GioiTinh
{
    NAM,
    NU
};

enum class TrangThaiNhanVien
{
    DANG_LAM,
    NGHI_VIEC
};

class NgayThang
{
private:
    int ngay, thang, nam;

public:
    NgayThang(int d = 1, int m = 1, int y = 1111) : ngay(d), thang(m), nam(y) {}
    int getNgay() const { return ngay; }
    int getThang() const { return thang; }
    int getNam() const { return nam; }
    void setNgay(int d) { ngay = d; }
    void setThang(int m) { thang = m; }
    void setNam(int y) { nam = y; }
    std::string toString() const
    {
        // dạng "dd/mm/yyyy"
        std::stringstream ss;
        ss << std::setfill('0') << std::setw(2) << ngay << "/"
           << std::setw(2) << thang << "/" << nam;
        return ss.str();
    }

    // Hàm static để đọc từ chuỗi
    static NgayThang fromString(const std::string& str) {
        int d = 1, m = 1, y = 2000;
        if (str.length() >= 8) { // Chấp nhận "d/m/yyyy" hoặc "dd/mm/yyyy"
            sscanf(str.c_str(), "%d/%d/%d", &d, &m, &y);
        }
        if (y < 1900) y = 2000; // Đặt giá trị mặc định nếu năm không hợp lệ
        if (m < 1 || m > 12) m = 1;
        if (d < 1 || d > 31) d = 1;
        return NgayThang(d, m, y);
    }
};

// --- CLASS PHONGBAN ---
class PhongBan
{
private:
    std::string maPhongBan;
    std::string tenPhongBan;

public:
    PhongBan(const std::string &ma = "", const std::string &ten = "")
        : maPhongBan(ma), tenPhongBan(ten) {}

    // Getters
    std::string getMaPhongBan() const { return maPhongBan; }
    std::string getTenPhongBan() const { return tenPhongBan; }

    // Setters
    void setMaPhongBan(const std::string &ma) { maPhongBan = ma; }
    void setTenPhongBan(const std::string &ten) { tenPhongBan = ten; }
};

// --- CLASS THANNHAN ---
class ThanNhan
{
private:
    std::string hoTen;
    std::string soDienThoai;
    std::string quanHe;

public:
    ThanNhan(const std::string &ht = "", const std::string &qh = "", const std::string &sdt = "")
        : hoTen(ht), soDienThoai(sdt), quanHe(qh) {}

    // Getters
    std::string getHoTen() const { return hoTen; }
    std::string getSoDienThoai() const { return soDienThoai; }
    std::string getQuanHe() const { return quanHe; }

    // Setters
    void setHoTen(const std::string &ht) { hoTen = ht; }
    void setSoDienThoai(const std::string &sdt) { soDienThoai = sdt; }
    void setQuanHe(const std::string &qh) { quanHe = qh; }

    void hienThi() const
    {
        std::cout << "  - Ho ten: " << hoTen
                  << ", Quan he: " << quanHe
                  << ", SDT: " << soDienThoai << std::endl;
    }
};

// --- CLASS NHANSU ---
class NhanSu
{
protected:
    // Thông tin cơ bản
    std::string maNhanVien;
    std::string hoTen;
    std::string CCCD;
    NgayThang ngaySinh;
    GioiTinh gioiTinh;

    // Liên hệ
    std::string soDienThoai;
    std::string email;
    std::string diaChi;

    // Ngân hàng
    std::string soTaiKhoan;
    std::string tenNganHang;

    // Công việc
    NgayThang ngayVaoCongTy;
    std::string viTriCongViec;
    PhongBan phongBan;
    TrangThaiNhanVien trangThai;

    // Học vấn
    std::string trinhDoHocVan;
    std::string chuyenNganh;

    // <<< MỚI: Thêm hàm protected để các lớp con gọi (Refactor 1)
    void hienThiThongTinCoBan() const
    {
        std::cout << "Ma NV: " << maNhanVien << std::endl;
        std::cout << "Ho ten: " << hoTen << std::endl;
        std::cout << "CCCD: " << CCCD << std::endl;
        std::cout << "Ngay sinh: " << ngaySinh.toString() << std::endl;
        std::cout << "Gioi tinh: " << (gioiTinh == GioiTinh::NAM ? "Nam" : "Nu") << std::endl;
        std::cout << "So dien thoai: " << soDienThoai << std::endl;
        std::cout << "Email: " << email << std::endl;
        std::cout << "Dia chi: " << diaChi << std::endl;
        std::cout << "Thong tin ngan hang: " << thongTinChiTra() << std::endl;
        std::cout << "Vi tri: " << viTriCongViec << std::endl;
        std::cout << "Phong ban: " << phongBan.getTenPhongBan() << std::endl;
        std::cout << "Ngay vao cong ty: " << ngayVaoCongTy.toString() << std::endl;
    }

public:
    NhanSu() : gioiTinh(GioiTinh::NAM), trangThai(TrangThaiNhanVien::DANG_LAM) {}

    NhanSu(const std::string &ma, const std::string &ht, const std::string &cccd,
           const NgayThang &ns, GioiTinh gt, const std::string &sdt = "",
           const std::string &em = "", const std::string &dc = "",
           const std::string &stk = "", const std::string &nganHang = "",
           const NgayThang &ngayVao = NgayThang(), const std::string &viTri = "",
           const PhongBan &pb = PhongBan(), const std::string &trinhDo = "",
           const std::string &nganh = "", TrangThaiNhanVien tt = TrangThaiNhanVien::DANG_LAM)
        : maNhanVien(ma), hoTen(ht), CCCD(cccd), ngaySinh(ns), gioiTinh(gt),
        soDienThoai(sdt), email(em), diaChi(dc), soTaiKhoan(stk), tenNganHang(nganHang),
        ngayVaoCongTy(ngayVao), viTriCongViec(viTri), phongBan(pb),
        trinhDoHocVan(trinhDo), chuyenNganh(nganh), trangThai(tt) {}

    // Destructor ảo
    virtual ~NhanSu() = default;
    virtual double tinhLuongThucNhan() const = 0;
    virtual std::string getLoaiNhanSu() const = 0;
    virtual void hienThiThongTin() const = 0;
    // Hàm ảo để xóa thân nhân khi sửa
    virtual void xoaTatCaThanNhan() {}

    // --- Thông tin cơ bản ---
    std::string getMaNhanVien() const { return maNhanVien; }
    std::string getHoTen() const { return hoTen; }
    std::string getCCCD() const { return CCCD; }
    GioiTinh getGioiTinh() const { return gioiTinh; }
    NgayThang getNgaySinh() const { return ngaySinh; }

    void setMaNhanVien(const std::string &ma) { maNhanVien = ma; }
    void setHoTen(const std::string &ht) { hoTen = ht; }
    void setCCCD(const std::string &cccd) { CCCD = cccd; }
    void setNgaySinh(const NgayThang &ns) { ngaySinh = ns; }
    void setGioiTinh(GioiTinh gt) { gioiTinh = gt; }
    int tinhTuoi() const { return 2025 - ngaySinh.getNam(); }

    // --- Liên hệ ---
    std::string getSoDienThoai() const { return soDienThoai; }
    std::string getEmail() const { return email; }
    std::string getDiaChi() const { return diaChi; }
    void capNhatLienHe(const std::string &sdt, const std::string &em, const std::string &dc)
    {
        soDienThoai = sdt;
        email = em;
        diaChi = dc;
    }
    void setSoDienThoai(const std::string &sdt) { soDienThoai = sdt; }
    void setEmail(const std::string &em) { email = em; }
    void setDiaChi(const std::string &dc) { diaChi = dc; }


    // --- Ngân hàng ---
    std::string getSoTaiKhoan() const { return soTaiKhoan; }
    std::string getTenNganHang() const { return tenNganHang; }
    void capNhatNganHang(const std::string &stk, const std::string &nganHang)
    {
        soTaiKhoan = stk;
        tenNganHang = nganHang;
    }
    void setSoTaiKhoan(const std::string &stk) { soTaiKhoan = stk; }
    void setTenNganHang(const std::string &nh) { tenNganHang = nh; }

    std::string thongTinChiTra() const
    {
        if (soTaiKhoan.empty())
        {
            return "Chua cap nhat thong tin ngan hang";
        }
        return "Chuyen khoan: " + soTaiKhoan + " - " + tenNganHang;
    }

    // --- Công việc ---
    std::string getViTriCongViec() const { return viTriCongViec; }
    NgayThang getNgayVaoCongTy() const { return ngayVaoCongTy; }
    const PhongBan &getPhongBan() const { return phongBan; }
    TrangThaiNhanVien getTrangThai() const { return trangThai; }

    void capNhatCongViec(const std::string &viTri, const PhongBan &pb, const NgayThang &ngayVao)
    {
        viTriCongViec = viTri;
        phongBan = pb;
        ngayVaoCongTy = ngayVao;
    }
    void setViTriCongViec(const std::string &vt) { viTriCongViec = vt; }
    void setPhongBan(const PhongBan &pb) { phongBan = pb; }
    void setNgayVaoCongTy(const NgayThang &ngay) { ngayVaoCongTy = ngay; }

    void setTrangThai(TrangThaiNhanVien tt) { trangThai = tt; }
    float tinhThamNien() const { return static_cast<float>(2025 - ngayVaoCongTy.getNam()); }

    // --- Học vấn ---
    std::string getTrinhDoHocVan() const { return trinhDoHocVan; }
    std::string getChuyenNganh() const { return chuyenNganh; }
    void capNhatHocVan(const std::string &trinhDo, const std::string &nganh)
    {
        trinhDoHocVan = trinhDo;
        chuyenNganh = nganh;
    }
    void setTrinhDoHocVan(const std::string &td) { trinhDoHocVan = td; }
    void setChuyenNganh(const std::string &cn) { chuyenNganh = cn; }


    // --- Hiển thị tóm tắt ---
    std::string getThongTinTomTat() const
    {
        return maNhanVien + " - " + hoTen + " (" + getLoaiNhanSu() + ")";
    }
};

// --- CLASS NHANVIENTHUVIEC ---
class NhanVienThuViec : public NhanSu
{
private:
    double phuCapThucTap;
    std::string danhGia;

public:
    NhanVienThuViec() : NhanSu(), phuCapThucTap(0.0) {}

    NhanVienThuViec(const std::string &ma, const std::string &ht, const std::string &cccd,
                    const NgayThang &ns, GioiTinh gt, double phuCap,
                    const std::string &sdt = "", const std::string &em = "",
                    const std::string &dc = "", const std::string &stk = "",
                    const std::string &nganHang = "", const NgayThang &ngayVao = NgayThang(),
                    const std::string &viTri = "", const PhongBan &pb = PhongBan(),
                    const std::string &trinhDo = "", const std::string &nganh = "",
                    const std::string &dg = "")
        : NhanSu(ma, ht, cccd, ns, gt, sdt, em, dc, stk, nganHang, ngayVao, viTri, pb, trinhDo, nganh),
        phuCapThucTap(phuCap), danhGia(dg) {}

    // Override các phương thức ảo
    double tinhLuongThucNhan() const override { return phuCapThucTap; }
    std::string getLoaiNhanSu() const override { return "Nhan vien thu viec"; }

    void hienThiThongTin() const override
    {
        std::cout << "=== NHAN VIEN THU VIEC ===" << std::endl;
        hienThiThongTinCoBan(); // <<< SỬA: Gọi hàm của lớp cha
        std::cout << "Phu cap: " << tinhLuongThucNhan() << " VND" << std::endl;
        std::cout << "Danh gia: " << (danhGia.empty() ? "Chua co" : danhGia) << std::endl;
    }

    // Getters & Setters riêng
    void setDanhGia(const std::string &dg) { danhGia = dg; }
    std::string getDanhGia() const { return danhGia; }
    double getPhuCapThucTap() const { return phuCapThucTap; }
    void setPhuCapThucTap(double pc) { phuCapThucTap = pc; }
};

// =========================================================================
// <<< MỚI: CLASS NhanVienTrungGian (LỚP TRUNG GIAN) >>>
// =========================================================================
class NhanVienTrungGian : public NhanSu
{
protected:
    // --- CÁC THUỘC TÍNH CHUNG ĐƯỢC CHUYỂN LÊN TỪ 2 LỚP CON ---
    double luongCoBan;
    double heSoLuong;
    int soNgayPhepConLai;
    std::vector<ThanNhan> danhSachThanNhan;

    // <<< MỚI: Thêm hàm protected để các lớp con gọi (Refactor 2)
    void hienThiThongTinCoHuu() const
    {
        hienThiThongTinCoBan(); // Gọi hàm của NhanSu
        std::cout << "Luong co ban: " << luongCoBan << " VND" << std::endl;
        std::cout << "He so: " << heSoLuong << std::endl;
        std::cout << "So ngay phep con lai: " << soNgayPhepConLai << std::endl;
    }

public:
    // Constructor mặc định
    NhanVienTrungGian() : NhanSu(), luongCoBan(0.0), heSoLuong(1.0), soNgayPhepConLai(12) {}

    // Constructor đầy đủ
    NhanVienTrungGian(const std::string &ma, const std::string &ht, const std::string &cccd,
                  const NgayThang &ns, GioiTinh gt, double luong, double heSo, int phep,
                  const std::string &sdt, const std::string &em, const std::string &dc,
                  const std::string &stk, const std::string &nganHang,
                  const NgayThang &ngayVao, const std::string &viTri,
                  const PhongBan &pb, const std::string &trinhDo,
                  const std::string &nganh, TrangThaiNhanVien tt = TrangThaiNhanVien::DANG_LAM)
        : NhanSu(ma, ht, cccd, ns, gt, sdt, em, dc, stk, nganHang, ngayVao, viTri, pb, trinhDo, nganh, tt),
        luongCoBan(luong), heSoLuong(heSo), soNgayPhepConLai(phep)
    {
        // Thân nhân sẽ được thêm qua hàm themThanNhan()
    }

    // Destructor ảo
    virtual ~NhanVienTrungGian() = default;

    // --- CÁC HÀM CHUNG ĐƯỢC CHUYỂN LÊN TỪ 2 LỚP CON ---

    // Lương
    double getLuongCoBan() const { return luongCoBan; }
    double getHeSoLuong() const { return heSoLuong; }
    void setLuongCoBan(double lcb) { luongCoBan = lcb; }
    void setHeSoLuong(double hsl) { heSoLuong = hsl; }
    void capNhatLuong(double luong, double heSo)
    {
        luongCoBan = luong;
        heSoLuong = heSo;
    }

    // Nghỉ phép
    int getSoNgayPhepConLai() const { return soNgayPhepConLai; }
    void nghiPhep(int soNgay) { soNgayPhepConLai -= soNgay; }
    void capNhatPhep(int soNgay) { soNgayPhepConLai = soNgay; }

    // Thân nhân
    void themThanNhan(const ThanNhan &tn) { danhSachThanNhan.push_back(tn); }
    const std::vector<ThanNhan> &getDanhSachThanNhan() const { return danhSachThanNhan; }

    // Override hàm ảo từ NhanSu
    void xoaTatCaThanNhan() override { danhSachThanNhan.clear(); }

    void hienThiThanNhan() const
    {
        if (danhSachThanNhan.empty())
        {
            std::cout << "Chua co thong tin than nhan." << std::endl;
            return;
        }
        for (const auto &tn : danhSachThanNhan)
        {
            tn.hienThi();
        }
    }

    // Các hàm ảo thuần túy từ NhanSu vẫn chưa được implement,
    // nên lớp này vẫn là lớp trừu tượng (abstract).
    // virtual double tinhLuongThucNhan() const = 0;
    // virtual std::string getLoaiNhanSu() const = 0;
    // virtual void hienThiThongTin() const = 0;
};

// =========================================================================
// --- CLASS NHANVIENCHINHTHUC (ĐÃ SỬA) ---
// =========================================================================
class NhanVienChinhThuc : public NhanVienTrungGian // <<< SỬA: Kế thừa từ NhanVienTrungGian
{
private:
    // <<< XÓA: luongCoBan, heSoLuong, soNgayPhepConLai, danhSachThanNhan (đã chuyển lên NhanVienTrungGian)

    // Các thuộc tính riêng
    double phuCapChucVu;
    double phuCapAnTrua;
    double phuCapXangXe;
    std::vector<std::string> khenThuong;
    std::vector<std::string> kyLuat;

public:
    // Constructor mặc định
    NhanVienChinhThuc() : NhanVienTrungGian(), phuCapChucVu(0.0), phuCapAnTrua(0.0), phuCapXangXe(0.0) {}

    // Constructor đầy đủ (Sửa lại)
    NhanVienChinhThuc(const std::string &ma, const std::string &ht, const std::string &cccd,
                      const NgayThang &ns, GioiTinh gt, double luong, double heSo = 1.0,
                      double pcChucVu = 0, double pcAnTrua = 0, double pcXangXe = 0,
                      int phep = 12, const std::string &sdt = "", const std::string &em = "",
                      const std::string &dc = "", const std::string &stk = "",
                      const std::string &nganHang = "", const NgayThang &ngayVao = NgayThang(),
                      const std::string &viTri = "", const PhongBan &pb = PhongBan(),
                      const std::string &trinhDo = "", const std::string &nganh = "")
        // <<< SỬA: Gọi constructor của NhanVienTrungGian
        : NhanVienTrungGian(ma, ht, cccd, ns, gt, luong, heSo, phep, sdt, em, dc, stk, nganHang, ngayVao, viTri, pb, trinhDo, nganh),
        phuCapChucVu(pcChucVu), phuCapAnTrua(pcAnTrua), phuCapXangXe(pcXangXe) {}

    // Override các phương thức ảo
    double tinhLuongThucNhan() const override
    {
        // luongCoBan và heSoLuong vẫn truy cập được vì là protected
        double tongThuNhap = luongCoBan * heSoLuong + phuCapChucVu + phuCapAnTrua + phuCapXangXe;
        double bhxh = tongThuNhap * 0.105; // BHXH + BHYT + BHTN
        double thue = tongThuNhap > 11000000 ? (tongThuNhap - 11000000) * 0.1 : 0;
        return tongThuNhap - bhxh - thue;
    }

    std::string getLoaiNhanSu() const override { return "Nhan vien chinh thuc"; }

    void hienThiThongTin() const override
    {
        std::cout << "=== NHAN VIEN CHINH THUC ===" << std::endl;
        hienThiThongTinCoHuu(); // <<< SỬA: Gọi hàm của NhanVienTrungGian

        // Chỉ hiển thị thông tin riêng
        std::cout << "Phu cap chuc vu: " << phuCapChucVu << " VND" << std::endl;
        std::cout << "Phu cap an trua: " << phuCapAnTrua << " VND" << std::endl;
        std::cout << "Phu cap xang xe: " << phuCapXangXe << " VND" << std::endl;
        std::cout << "Luong thuc nhan: " << tinhLuongThucNhan() << " VND" << std::endl;
        std::cout << "Tham nien: " << tinhThamNien() << " nam" << std::endl;
        std::cout << "\n--- THAN NHAN ---" << std::endl;
        hienThiThanNhan(); // Hàm này đã được kế thừa từ NhanVienTrungGian
    }

    // Getters & Setters riêng (Các hàm chung đã bị xóa)
    double getPhuCapChucVu() const { return phuCapChucVu; }
    double getPhuCapAnTrua() const { return phuCapAnTrua; }
    double getPhuCapXangXe() const { return phuCapXangXe; }

    void setPhuCapChucVu(double pc) { phuCapChucVu = pc; }
    void setPhuCapAnTrua(double pc) { phuCapAnTrua = pc; }
    void setPhuCapXangXe(double pc) { phuCapXangXe = pc; }

    // <<< XÓA: getLuongCoBan, getHeSoLuong, capNhatLuong, setLuongCoBan, setHeSoLuong
    // <<< XÓA: getSoNgayPhepConLai, nghiPhep, capNhatPhep
    // <<< XÓA: themThanNhan, getDanhSachThanNhan, xoaTatCaThanNhan, hienThiThanNhan

    // Getters/Setters riêng cho Khen thưởng/Kỷ luật
    void themKhenThuong(const std::string &kt) { khenThuong.push_back(kt); }
    void themKyLuat(const std::string &kl) { kyLuat.push_back(kl); }
    const std::vector<std::string> &getKhenThuong() const { return khenThuong; }
    const std::vector<std::string> &getKyLuat() const { return kyLuat; }
};

// =========================================================================
// --- CLASS QUANLY (ĐÃ SỬA) ---
// =========================================================================
class QuanLy : public NhanVienTrungGian // <<< SỬA: Kế thừa từ NhanVienTrungGian
{
private:
    // <<< XÓA: luongCoBan, heSoLuong, soNgayPhepConLai, danhSachThanNhan (đã chuyển lên NhanVienTrungGian)

    // Các thuộc tính riêng
    double phuCapQuanLy;
    double thuongHieuQua;
    std::vector<std::string> phongBanQuanLy;
    std::vector<std::string> duAnPhuTrach;
    int soLuongNhanVienQuanLy;

public:
    // Constructor mặc định
    QuanLy() : NhanVienTrungGian(), phuCapQuanLy(0.0), thuongHieuQua(0.0), soLuongNhanVienQuanLy(0)
    {
        heSoLuong = 1.5; // Ghi đè hệ số lương mặc định
    }

    // Constructor đầy đủ (Sửa lại)
    QuanLy(const std::string &ma, const std::string &ht, const std::string &cccd,
           const NgayThang &ns, GioiTinh gt, double luong, double heSo = 1.5,
           double pcQuanLy = 0, double thuong = 0, int soNVQuanLy = 0,
           const std::string &sdt = "", const std::string &em = "",
           const std::string &dc = "", const std::string &stk = "",
           const std::string &nganHang = "", const NgayThang &ngayVao = NgayThang(),
           const std::string &viTri = "", const PhongBan &pb = PhongBan(),
           const std::string &trinhDo = "", const std::string &nganh = "",
           int phep = 12)
        // <<< SỬA: Gọi constructor của NhanVienTrungGian
        : NhanVienTrungGian(ma, ht, cccd, ns, gt, luong, heSo, phep, sdt, em, dc, stk, nganHang, ngayVao, viTri, pb, trinhDo, nganh),
        phuCapQuanLy(pcQuanLy), thuongHieuQua(thuong), soLuongNhanVienQuanLy(soNVQuanLy) {}

    // Override các phương thức ảo
    double tinhLuongThucNhan() const override
    {
        // luongCoBan và heSoLuong vẫn truy cập được vì là protected
        double tongThuNhap = luongCoBan * heSoLuong + phuCapQuanLy + thuongHieuQua;
        double bhxh = tongThuNhap * 0.105;
        double thue = tongThuNhap > 11000000 ? (tongThuNhap - 11000000) * 0.15 : 0;
        return tongThuNhap - bhxh - thue;
    }

    std::string getLoaiNhanSu() const override { return "Quan ly"; }

    void hienThiThongTin() const override
    {
        std::cout << "=== QUAN LY ===" << std::endl;
        hienThiThongTinCoHuu(); // <<< SỬA: Gọi hàm của NhanVienTrungGian

        // Chỉ hiển thị thông tin riêng
        std::cout << "Phu cap quan ly: " << phuCapQuanLy << " VND" << std::endl;
        std::cout << "Thuong hieu qua: " << thuongHieuQua << " VND" << std::endl;
        std::cout << "Luong thuc nhan: " << tinhLuongThucNhan() << " VND" << std::endl;
        std::cout << "So luong nhan vien quan ly: " << soLuongNhanVienQuanLy << std::endl;
        std::cout << "So du an phu trach: " << duAnPhuTrach.size() << std::endl;
        std::cout << "\n--- THAN NHAN ---" << std::endl;
        hienThiThanNhan(); // Hàm này đã được kế thừa từ NhanVienTrungGian
    }

    // Getters & Setters riêng
    double getPhuCapQuanLy() const { return phuCapQuanLy; }
    void setPhuCapQuanLy(double pc) { phuCapQuanLy = pc; }
    void setThuongHieuQua(double thuong) { thuongHieuQua = thuong; }
    void setSoLuongNhanVienQuanLy(int soLuong) { soLuongNhanVienQuanLy = soLuong; }

    // <<< XÓA: getLuongCoBan, getHeSoLuong, capNhatLuong, setLuongCoBan, setHeSoLuong
    // <<< XÓA: getSoNgayPhepConLai, nghiPhep, capNhatPhep
    // <<< XÓA: themThanNhan, getDanhSachThanNhan, xoaTatCaThanNhan, hienThiThanNhan

    // Getters/Setters riêng cho Dự án/Phòng ban
    void themPhongBanQuanLy(const std::string &maPB) { phongBanQuanLy.push_back(maPB); }
    void themDuAnPhuTrach(const std::string &maDuAn) { duAnPhuTrach.push_back(maDuAn); }
    const std::vector<std::string> &getPhongBanQuanLy() const { return phongBanQuanLy; }
    const std::vector<std::string> &getDuAnPhuTrach() const { return duAnPhuTrach; }
    double getThuongHieuQua() const { return thuongHieuQua; }
    int getSoLuongNhanVienQuanLy() const { return soLuongNhanVienQuanLy; }
};

// --- CLASS DUAN ---
class DuAn
{
private:
    std::string maDuAn;
    std::string tenDuAn;
    NgayThang ngayBatDau;
    NgayThang ngayKetThuc;
    std::string nguoiPhuTrach;
    std::vector<std::string> danhSachThanhVien;
    double kinhPhi;
    bool daHoanThanh;

public:
    DuAn(const std::string &ma = "", const std::string &ten = "", const NgayThang &batDau = NgayThang(),
         const NgayThang &ketThuc = NgayThang(1, 1, 1970), const std::string &phuTrach = "",
         const std::vector<std::string> &thanhVien = {}, double phi = 0.0, bool hoanThanh = false)
        : maDuAn(ma), tenDuAn(ten), ngayBatDau(batDau), ngayKetThuc(ketThuc),
        nguoiPhuTrach(phuTrach), danhSachThanhVien(thanhVien), kinhPhi(phi), daHoanThanh(hoanThanh) {}

    // Getters
    std::string getMaDuAn() const { return maDuAn; }
    std::string getTenDuAn() const { return tenDuAn; }
    NgayThang getNgayBatDau() const { return ngayBatDau; }
    NgayThang getNgayKetThuc() const { return ngayKetThuc; }
    std::string getNguoiPhuTrach() const { return nguoiPhuTrach; }
    const std::vector<std::string> &getDanhSachThanhVien() const { return danhSachThanhVien; }
    double getKinhPhi() const { return kinhPhi; }
    bool isDaHoanThanh() const { return daHoanThanh; }
    int getSoLuongThanhVien() const { return danhSachThanhVien.size(); }

    // Setters
    void setMaDuAn(const std::string &ma) { maDuAn = ma; }
    void setTenDuAn(const std::string &ten) { tenDuAn = ten; }
    void setNgayBatDau(const NgayThang &ngay) { ngayBatDau = ngay; }
    void setNgayKetThuc(const NgayThang &ngay) { ngayKetThuc = ngay; }
    void setNguoiPhuTrach(const std::string &maNV) { nguoiPhuTrach = maNV; }
    void setKinhPhi(double phi) { kinhPhi = phi; }
    void setDaHoanThanh(bool hoanThanh) { daHoanThanh = hoanThanh; }

    // Quản lý danh sách thành viên
    void themThanhVien(const std::string &maNV) { danhSachThanhVien.push_back(maNV); }
    void xoaThanhVien(const std::string &maNV)
    {
        for (auto it = danhSachThanhVien.begin(); it != danhSachThanhVien.end();)
        {
            if (*it == maNV)
            {
                it = danhSachThanhVien.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }

    void hoanThanh() { daHoanThanh = true; }
    void hienThi() const
    {
        std::cout << "Ma du an: " << maDuAn << std::endl;
        std::cout << "Ten du an: " << tenDuAn << std::endl;
        std::cout << "Ngay bat dau: " << ngayBatDau.toString() << std::endl;
        std::cout << "Ngay ket thuc: " << (daHoanThanh ? ngayKetThuc.toString() : "Chua ket thuc") << std::endl;
        std::cout << "Nguoi phu trach: " << (nguoiPhuTrach.empty() ? "Chua co" : nguoiPhuTrach) << std::endl;
        std::cout << "Kinh phi: " << kinhPhi << " VND" << std::endl;
        std::cout << "Trang thai: " << (daHoanThanh ? "Hoan thanh" : "Dang thuc hien") << std::endl;
        std::cout << "Danh sach thanh vien (" << danhSachThanhVien.size() << "):" << std::endl;
        if (danhSachThanhVien.empty())
        {
            std::cout << "  - Khong co thanh vien" << std::endl;
        }
        else
        {
            for (const auto &maNV : danhSachThanhVien)
            {
                std::cout << "  - " << maNV << std::endl;
            }
        }
    }
};

#endif
