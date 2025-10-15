#ifndef GD_NVCHUNG_H
#define GD_NVCHUNG_H

#include <QMainWindow>
#include <QStackedWidget>

// Forward declaration của lớp giao diện người dùng
namespace Ui {
class GD_NVChung;
}

class GD_NVChung : public QMainWindow
{
    Q_OBJECT

public:
    explicit GD_NVChung(QWidget *parent = nullptr);
    ~GD_NVChung();

private slots:
    void on_btnNavInfo_clicked();
    void on_btnNavSalary_clicked();
    void on_btnNavAttendance_clicked();
    void on_btnNavProjects_clicked();
    void on_btnNavRelatives_clicked();

private:
    Ui::GD_NVChung *ui;
};

#endif // GD_NVCHUNG_H
