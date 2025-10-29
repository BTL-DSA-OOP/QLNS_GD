#ifndef CLASSNGHIPHEP_H
#define CLASSNGHIPHEP_H

#include "ClassNhanSu.h"
#include <QString>

enum class TrangThaiDuyet
{
    CHO_DUYET,
    DA_DUYET,
    TU_CHOI
};

class YeuCauNghiPhep
{
private:
    std::string maYeuCau;
    std::string maNhanVien;
    NgayThang ngayBatDau;
    NgayThang ngayKetThuc;
    double soNgayNghi;
    std::string lyDo;
    TrangThaiDuyet trangThai;
    std::string nguoiDuyet;

public:
    YeuCauNghiPhep(const std::string &maYC = "", const std::string &maNV = "",
                   const NgayThang &bd = NgayThang(), const NgayThang &kt = NgayThang(),
                   double soNgay = 0.0, const std::string &ld = "",
                   TrangThaiDuyet tt = TrangThaiDuyet::CHO_DUYET, const std::string &nd = "")
        : maYeuCau(maYC), maNhanVien(maNV), ngayBatDau(bd), ngayKetThuc(kt),
        soNgayNghi(soNgay), lyDo(ld), trangThai(tt), nguoiDuyet(nd) {}

    // Getters
    std::string getMaYeuCau() const { return maYeuCau; }
    std::string getMaNhanVien() const { return maNhanVien; }
    NgayThang getNgayBatDau() const { return ngayBatDau; }
    NgayThang getNgayKetThuc() const { return ngayKetThuc; }
    double getSoNgayNghi() const { return soNgayNghi; }
    std::string getLyDo() const { return lyDo; }
    TrangThaiDuyet getTrangThai() const { return trangThai; }
    std::string getNguoiDuyet() const { return nguoiDuyet; }

    // Setters
    void setTrangThai(TrangThaiDuyet tt) { trangThai = tt; }
    void setNguoiDuyet(const std::string &nd) { nguoiDuyet = nd; }

    // Hàm tiện ích
    QString getTrangThaiText() const {
        if (trangThai == TrangThaiDuyet::DA_DUYET) return "Đã duyệt";
        if (trangThai == TrangThaiDuyet::TU_CHOI) return "Từ chối";
        return "Chờ duyệt";
    }

    // Tạo ID mới (giả lập)
    static std::string generateNewID(int count) {
        return "YC" + std::to_string(count + 1);
    }
};

#endif
