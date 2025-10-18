#ifndef NHANSUDATA_H
#define NHANSUDATA_H

#include "ClassNhanSu.h"
#include <vector>
#include <memory>
#include <QString>

extern std::vector<std::shared_ptr<NhanSu>> g_danhSachNhanSu;
extern std::vector<DuAn> g_danhSachDuAn;

void docNhanSuTuFile();
void luuNhanSuVaoFile();
void xoaTaiKhoan(const std::string& tenNguoiDung);
std::shared_ptr<NhanSu> timNhanSuTheoMa(const std::string& maNV);
bool isUsernameTaken(const QString& username);

void docDuAnTuFile();
void luuDuAnVaoFile();
DuAn* timDuAnTheoMa(const std::string& maDA);

#endif // NHANSUDATA_H
