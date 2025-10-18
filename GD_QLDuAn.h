#ifndef GD_QLDUAN_H
#define GD_QLDUAN_H

#include <QWidget>

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
    void on_btnAddProject_clicked();
    void on_btnRefresh_clicked();

private:
    Ui::GD_QLDuAn *ui;
    void loadProjectsToTable();
};

#endif
