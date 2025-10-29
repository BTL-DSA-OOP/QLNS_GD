#ifndef GD_THEM_H
#define GD_THEM_H

#include <QDialog>
#include <memory>
class NhanSu;
namespace Ui {
class GD_Them;
}
// ---

class GD_Them : public QDialog
{
    Q_OBJECT

public:
    explicit GD_Them(QWidget *parent = nullptr);
    ~GD_Them();

    void loadDataForEdit(std::shared_ptr<NhanSu> ns);

private slots:
    void on_btnThem_clicked();
    void updateSalaryFields();

    void on_btnThemThanNhan_clicked();
    void on_btnXoaThanNhan_clicked();

private:
    Ui::GD_Them *ui;
    void setupThanNhanTable();

    // --- THAY ĐỔI: Thêm 2 hàm hỗ trợ ---
    void fillCommonDataFromUI(std::shared_ptr<NhanSu> ns);
    void fillSalaryDataFromUI(std::shared_ptr<NhanSu> ns);
    // --- KẾT THÚC THAY ĐỔI ---
    void updateThanNhanHeight();
    bool isEditMode = false;
    QString m_editMaNV;
};

#endif
