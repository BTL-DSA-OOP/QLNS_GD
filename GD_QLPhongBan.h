#ifndef GD_QLPHONGBAN_H
#define GD_QLPHONGBAN_H

#include <QWidget>
#include <map>
#include <string>

namespace Ui {
class GD_QLPhongBan;
}

// Cấu trúc để lưu trữ thông tin thống kê
struct PhongBanStats {
    std::string tenPB;
    int soLuongNV = 0;
    int nvThuViec = 0;
    int nvChinhThuc = 0;
    int quanLy = 0;
};

class GD_QLPhongBan : public QWidget
{
    Q_OBJECT

public:
    explicit GD_QLPhongBan(QWidget *parent = nullptr);
    ~GD_QLPhongBan();

protected:
    void showEvent(QShowEvent *event) override;

private slots:
    // --- THÊM SLOT NÀY ---
    void on_btnThemPB_clicked();

    void on_btnSuaPB_clicked();
    void on_btnXoaPB_clicked();
    void on_btnRefresh_clicked();

    // Slots cho form nhập liệu
    void on_btnLuu_clicked();
    void on_btnHuy_clicked();

    // Slot cho bảng
    void on_tablePhongBan_itemSelectionChanged();

private:
    Ui::GD_QLPhongBan *ui;
    std::map<std::string, PhongBanStats> m_phongBanData;

    // Biến trạng thái để biết đang Thêm hay Sửa
    enum class EditMode { None, Add, Edit };
    EditMode m_currentMode = EditMode::None;
    QString m_editingMaPB; // Lưu lại mã PB đang sửa

    // Các hàm private helper
    void setupTables();
    void refreshData();
    void displayPhongBanDetails(const std::string& maPB);
    void clearChiTiet();
    void setEditMode(bool isEditing);
};

#endif // GD_QLPHONGBAN_H
