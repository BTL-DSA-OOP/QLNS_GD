#ifndef GD_QLDUAN_H
#define GD_QLDUAN_H

#include <QWidget>
#include <vector>
#include <string>
#include "ClassNhanSu.h"
#include <QDateEdit>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <QGroupBox>
#include <QListWidget>
#include <QDialog>

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
    void on_btnSelectMembers_clicked();
    void on_lineEditSearch_textChanged(const QString &arg1);

    // Slots cho form nhập liệu
    void on_btnSaveChanges_clicked();
    void on_btnCancelChanges_clicked();
    void on_tableProjects_itemSelectionChanged();


private:
    Ui::GD_QLDuAn *ui;
    bool isEditMode; // Biến cờ để biết đang Thêm (false) hay Sửa (true)
    QString currentEditMaDA; // Lưu mã DA khi đang sửa

    std::vector<std::string> currentSelectedMembers;

    void displayProjectsTable(const std::vector<DuAn>& list);
    void setupTable();

    void loadNguoiPhuTrachComboBox();
    void clearInputFields();
    void setInputMode(bool isEditing);

    void updateMembersDisplay();
};

#endif // GD_QLDUAN_H
