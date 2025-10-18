#ifndef GD_QLY_H
#define GD_QLY_H

#include <QMainWindow>
#include <vector>
#include <memory>
#include "GD_QLPhongBan.h"
#include "GD_QLDuAn.h"
#include "ClassNhanSu.h"

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

    void on_btnEdit_clicked();
    void on_btnDelete_clicked();
    void on_btnDetail_clicked();
    void on_btnRefresh_clicked();
    void on_lineEditSearch_textChanged(const QString &arg1);

    void on_btnLoadChamCong_clicked();

private:
    Ui::GD_Qly *ui;
    GD_QLPhongBan *m_qlpbWidget;
    GD_QLDuAn *m_qlduAnWidget;

    // Hàm private
    void loadNhanSuData();
    void displayNhanSuTable(const std::vector<std::shared_ptr<NhanSu>>& list);
    void setupTable();
    void loadNhanVienListToComboBox();
};
#endif
