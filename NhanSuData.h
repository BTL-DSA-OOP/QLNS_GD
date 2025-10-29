#ifndef NHANSUDATA_H
#define NHANSUDATA_H

#include <vector>
#include <memory>
#include <string>
#include "ClassNhanSu.h" // Đã bao gồm DuAn, ClassNhanSu, PhongBan...
#include <QString>
#include "ClassNghiPhep.h"

// Biến toàn cục cho Nhân Sự
extern std::vector<std::shared_ptr<NhanSu>> g_danhSachNhanSu;
std::shared_ptr<NhanSu> timNhanSuTheoMa(const std::string& maNV);
void docNhanSuTuFile();
void luuNhanSuVaoFile();

// Biến toàn cục cho Dự Án
extern std::vector<DuAn> g_danhSachDuAn;
DuAn* timDuAnTheoMa(const std::string& maDA);
void luuDuAnVaoFile();
void docDuAnTuFile();

// --- THÊM MỚI CHO PHÒNG BAN ---
extern std::vector<PhongBan> g_danhSachPhongBan;
PhongBan* timPhongBanTheoMa(const std::string& maPB);
void docPhongBanTuFile();
void luuPhongBanVaoFile();
// --- KẾT THÚC THÊM MỚI ---

// --- THÊM MỚI CHO NGHỈ PHÉP ---
extern std::vector<YeuCauNghiPhep> g_danhSachYeuCauNghiPhep;
void docYeuCauNghiPhepTuFile();
void luuYeuCauNghiPhepVaoFile();
// --- KẾT THÚC THÊM MỚI ---

// Hàm xử lý tài khoản
bool isUsernameTaken(const QString& username);
void xoaTaiKhoan(const std::string& tenNguoiDung);

#endif // NHANSUDATA_H
