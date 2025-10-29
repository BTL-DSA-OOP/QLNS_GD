#ifndef GD_QLDUAN_H
#define GD_QLDUAN_H

#include <QWidget>
#include <vector>
#include "ClassNhanSu.h" // Đảm bảo đã include DuAn

// Thêm các include cho widget mới
#include <QDateEdit>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <QGroupBox>


namespace Ui {
class GD_QLDuAn;
}

class GD_QLDuAn : public QWidget
{
    Q_OBJECT

public:
    explicit GD_QLDuAn(QWidget *parent = nullptr);
    ~GD_QLDuAn();

private slots:
    // Slots cho các nút
    void on_btnAddProject_clicked();
    void on_btnEditProject_clicked();
    void on_btnDeleteProject_clicked();
    void on_btnCompleteProject_clicked();
    void on_btnRefresh_clicked();

    void on_lineEditSearch_textChanged(const QString &arg1);

    // Slots mới cho form tích hợp
    void on_btnSaveChanges_clicked();
    void on_btnCancelChanges_clicked();
    void on_tableProjects_itemSelectionChanged();


private:
    Ui::GD_QLDuAn *ui;
    bool isEditMode; // Biến cờ để biết đang Thêm (false) hay Sửa (true)
    QString currentEditMaDA; // Lưu mã DA khi đang sửa

    void displayProjectsTable(const std::vector<DuAn>& list);
    void setupTable();

    // Hàm private mới
    void loadNguoiPhuTrachComboBox();
    void clearInputFields();
    void setInputMode(bool isEditing); // Hàm gộp để quản lý UI
};

#endif // GD_QLDUAN_H
