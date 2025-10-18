#ifndef GD_NVCHUNG_H
#define GD_NVCHUNG_H

#include <QMainWindow>
#include <QString>
#include <QDateTime>

// Forward declaration
namespace Ui {
class GD_NVChung;
}

class GD_NVChung : public QMainWindow
{
    Q_OBJECT

public:
    explicit GD_NVChung(const QString &maNV, QWidget *parent = nullptr);
    ~GD_NVChung();

private slots:
    void on_btnNavInfo_clicked();
    void on_btnNavSalary_clicked();
    void on_btnNavAttendance_clicked();
    void on_btnNavProjects_clicked();
    void on_btnNavRelatives_clicked();
    void on_btnCheckIn_clicked();
    void on_btnCheckOut_clicked();
    void on_btnAttendanceHistory_clicked();

private:
    Ui::GD_NVChung *ui;
    QString m_maNV; // Mã nhân viên đang đăng nhập

    // --- Biến lưu thông tin lương ---
    QString m_loaiNhanSu;
    // Lương thử việc
    double m_phuCapThucTap = 0.0;
    // Lương chính thức
    double m_luongCoBan_CT = 0.0;
    double m_phuCapChucVu = 0.0;
    double m_phuCapAnTrua = 0.0;
    double m_phuCapXangXe = 0.0;
    // Lương quản lý
    double m_luongCoBan_QL = 0.0;
    double m_phuCapQuanLy = 0.0;

    // --- Hàm xử lý ---
    void loadNhanSuData(const QString &maNV);
    void calculateAndDisplaySalary();
};

#endif
