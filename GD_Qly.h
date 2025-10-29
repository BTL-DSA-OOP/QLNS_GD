#ifndef GD_QLY_H
#define GD_QLY_H

#include <QMainWindow>
#include <vector>
#include <memory>
#include "GD_QLPhongBan.h"
#include "GD_QLDuAn.h"
#include "ClassNhanSu.h"
#include "ClassNghiPhep.h"
#include <set> // Cần thiết cho việc thu thập các chức vụ duy nhất

QT_BEGIN_NAMESPACE
namespace Ui {
class GD_Qly;
}
QT_END_NAMESPACE

class GD_Qly : public QMainWindow
{
    Q_OBJECT

public:
    GD_Qly(QWidget *parent = nullptr);
    ~GD_Qly();

private slots:
    void on_btnAdd_clicked();
    void on_btnNavDepartments_clicked();
    void on_btnNavEmployees_clicked();
    void on_btnNavProjects_clicked();
    void on_btnNavAttendance_clicked();
    void on_btnNavLeaveApproval_clicked();
    void on_btnEdit_clicked();
    void on_btnDelete_clicked();
    void on_btnDetail_clicked();
    void on_btnRefresh_clicked();
    void on_lineEditSearch_textChanged(const QString &arg1);

    void on_btnLoadChamCong_clicked();

    // --- THÊM MỚI CHO DUYỆT NGHỈ ---
    void on_btnLoadLeaveRequests_clicked();
    void on_btnApproveLeave_clicked();
    void on_btnRejectLeave_clicked();
    // --- KẾT THÚC THÊM MỚI ---

    // <<< CÁC SLOTS MỚI CHO LỌC VÀ XUẤT CSV
    void on_btnExport_clicked();
    void on_comboFilterPhongBan_currentIndexChanged(int index);
    void on_comboFilterChucVu_currentIndexChanged(int index);
    // KẾT THÚC CÁC SLOTS MỚI >>>

private:
    Ui::GD_Qly *ui;
    GD_QLPhongBan *m_qlpbWidget;
    GD_QLDuAn *m_qlduAnWidget;

    // --- Biến lưu tên quản lý (người duyệt) ---
    QString m_maQuanLy = "QL001";

    // Hàm private
    void loadNhanSuData();
    void displayNhanSuTable(const std::vector<std::shared_ptr<NhanSu>>& list);
    void setupTable();
    void loadNhanVienListToComboBox();

    // --- THÊM MỚI CHO DUYỆT NGHỈ ---
    void loadLeaveRequestsTable();
    YeuCauNghiPhep* timYeuCauTheoMa(const std::string& maYC);
    // --- KẾT THÚC THÊM MỚI ---

    // <<< HÀM LỌC VÀ TẢI COMBOBOX MỚI
    void loadFilterComboBoxes();
    void filterNhanSuTable(); // Hàm lọc chung
    // KẾT THÚC HÀM MỚI >>>
};
#endif
