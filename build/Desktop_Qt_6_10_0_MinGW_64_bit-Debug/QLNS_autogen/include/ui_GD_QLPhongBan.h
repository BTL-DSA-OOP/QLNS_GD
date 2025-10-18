/********************************************************************************
** Form generated from reading UI file 'GD_QLPhongBan.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GD_QLPHONGBAN_H
#define UI_GD_QLPHONGBAN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GD_QLPhongBan
{
public:
    QVBoxLayout *verticalLayout_main;
    QGroupBox *groupFilter;
    QHBoxLayout *horizontalLayout_filter;
    QLabel *labelSelectGroup;
    QComboBox *comboGroups;
    QSpacerItem *horizontalSpacerFilter;
    QPushButton *btnRefresh;
    QGroupBox *groupDetails;
    QFormLayout *formLayout;
    QLabel *labelDeptID;
    QLineEdit *lineDeptID;
    QLabel *labelDeptName;
    QLineEdit *lineDeptName;
    QLabel *labelLeader;
    QLineEdit *lineLeader;
    QLabel *labelNote;
    QTextEdit *textNote;
    QFrame *frameButtons;
    QHBoxLayout *horizontalLayout_buttons;
    QPushButton *btnAdd;
    QPushButton *btnEdit;
    QPushButton *btnDelete;
    QSpacerItem *horizontalSpacerButtons;
    QGroupBox *groupList;
    QVBoxLayout *verticalLayout_table;
    QTableWidget *tableDepartments;

    void setupUi(QWidget *GD_QLPhongBan)
    {
        if (GD_QLPhongBan->objectName().isEmpty())
            GD_QLPhongBan->setObjectName("GD_QLPhongBan");
        GD_QLPhongBan->resize(700, 550);
        GD_QLPhongBan->setStyleSheet(QString::fromUtf8("/* --- Global Styles --- */\n"
"QWidget {\n"
"    font-family: \"Segoe UI\", Arial, sans-serif;\n"
"    font-size: 10pt;\n"
"    color: #333;\n"
"}\n"
"\n"
"QDialog {\n"
"    background-color: #f0f2f5;\n"
"}\n"
"\n"
"/* --- Content Area --- */\n"
"QGroupBox {\n"
"    font-weight: bold;\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #dcdcdc;\n"
"    border-radius: 8px;\n"
"    margin-top: 10px;\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 0 10px;\n"
"    left: 10px;\n"
"}\n"
"\n"
"/* --- General Widgets --- */\n"
"QLineEdit, QComboBox, QTextEdit {\n"
"    border: 1px solid #dcdcdc;\n"
"    border-radius: 8px;\n"
"    padding: 8px 12px;\n"
"    background-color: white;\n"
"}\n"
"QLineEdit:focus, QComboBox:focus, QTextEdit:focus {\n"
"    border: 1px solid #0078d7;\n"
"}\n"
"\n"
"QPushButton {\n"
"    padding: 8px 18px;\n"
"    border: 1px solid #dcdcdc;\n"
"    border-radius: 8px;\n"
"    background-color: white;\n"
"    min"
                        "-width: 80px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #f5f5f5;\n"
"    border-color: #c0c0c0;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #e0e0e0;\n"
"}\n"
"\n"
"\n"
"/* --- Specialized Buttons --- */\n"
"QPushButton#btnAdd {\n"
"    background-color: #0078d7;\n"
"    color: white;\n"
"    border-color: #0078d7;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton#btnAdd:hover {\n"
"    background-color: #005a9e;\n"
"    border-color: #004578;\n"
"}\n"
"\n"
"QPushButton#btnDelete {\n"
"    background-color: #d9534f;\n"
"    color: white;\n"
"    border-color: #d9534f;\n"
"}\n"
"QPushButton#btnDelete:hover {\n"
"    background-color: #c9302c;\n"
"    border-color: #ac2925;\n"
"}\n"
"\n"
"\n"
"/* --- Table --- */\n"
"QTableWidget {\n"
"    border: 1px solid #dcdcdc;\n"
"    border-radius: 8px;\n"
"    gridline-color: #e0e0e0;\n"
"    background-color: white;\n"
"}\n"
"QHeaderView::section {\n"
"    background-color: #f8f9fa;\n"
"    padding: 10px;\n"
"    border: none;\n"
"    border-bo"
                        "ttom: 1px solid #dcdcdc;\n"
"    font-weight: bold;\n"
"}\n"
"QTableWidget::item {\n"
"    padding: 10px;\n"
"}\n"
"QTableWidget::item:selected {\n"
"    background-color: #cfe2ff;\n"
"    color: #000;\n"
"}\n"
"\n"
"/* --- ScrollBar --- */\n"
"QScrollBar:vertical {\n"
"    border: none;\n"
"    background: #f0f2f5;\n"
"    width: 10px;\n"
"    margin: 0px 0px 0px 0px;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"    background: #c0c0c0;\n"
"    min-height: 20px;\n"
"    border-radius: 5px;\n"
"}\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"}\n"
""));
        verticalLayout_main = new QVBoxLayout(GD_QLPhongBan);
        verticalLayout_main->setObjectName("verticalLayout_main");
        groupFilter = new QGroupBox(GD_QLPhongBan);
        groupFilter->setObjectName("groupFilter");
        horizontalLayout_filter = new QHBoxLayout(groupFilter);
        horizontalLayout_filter->setObjectName("horizontalLayout_filter");
        labelSelectGroup = new QLabel(groupFilter);
        labelSelectGroup->setObjectName("labelSelectGroup");

        horizontalLayout_filter->addWidget(labelSelectGroup);

        comboGroups = new QComboBox(groupFilter);
        comboGroups->addItem(QString());
        comboGroups->addItem(QString());
        comboGroups->addItem(QString());
        comboGroups->addItem(QString());
        comboGroups->setObjectName("comboGroups");
        comboGroups->setMinimumSize(QSize(200, 0));

        horizontalLayout_filter->addWidget(comboGroups);

        horizontalSpacerFilter = new QSpacerItem(20, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_filter->addItem(horizontalSpacerFilter);

        btnRefresh = new QPushButton(groupFilter);
        btnRefresh->setObjectName("btnRefresh");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/refresh.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnRefresh->setIcon(icon);

        horizontalLayout_filter->addWidget(btnRefresh);


        verticalLayout_main->addWidget(groupFilter);

        groupDetails = new QGroupBox(GD_QLPhongBan);
        groupDetails->setObjectName("groupDetails");
        formLayout = new QFormLayout(groupDetails);
        formLayout->setObjectName("formLayout");
        labelDeptID = new QLabel(groupDetails);
        labelDeptID->setObjectName("labelDeptID");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelDeptID);

        lineDeptID = new QLineEdit(groupDetails);
        lineDeptID->setObjectName("lineDeptID");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, lineDeptID);

        labelDeptName = new QLabel(groupDetails);
        labelDeptName->setObjectName("labelDeptName");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelDeptName);

        lineDeptName = new QLineEdit(groupDetails);
        lineDeptName->setObjectName("lineDeptName");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, lineDeptName);

        labelLeader = new QLabel(groupDetails);
        labelLeader->setObjectName("labelLeader");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, labelLeader);

        lineLeader = new QLineEdit(groupDetails);
        lineLeader->setObjectName("lineLeader");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, lineLeader);

        labelNote = new QLabel(groupDetails);
        labelNote->setObjectName("labelNote");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, labelNote);

        textNote = new QTextEdit(groupDetails);
        textNote->setObjectName("textNote");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, textNote);


        verticalLayout_main->addWidget(groupDetails);

        frameButtons = new QFrame(GD_QLPhongBan);
        frameButtons->setObjectName("frameButtons");
        horizontalLayout_buttons = new QHBoxLayout(frameButtons);
        horizontalLayout_buttons->setObjectName("horizontalLayout_buttons");
        btnAdd = new QPushButton(frameButtons);
        btnAdd->setObjectName("btnAdd");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/add.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnAdd->setIcon(icon1);

        horizontalLayout_buttons->addWidget(btnAdd);

        btnEdit = new QPushButton(frameButtons);
        btnEdit->setObjectName("btnEdit");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/edit.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnEdit->setIcon(icon2);

        horizontalLayout_buttons->addWidget(btnEdit);

        btnDelete = new QPushButton(frameButtons);
        btnDelete->setObjectName("btnDelete");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/delete.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnDelete->setIcon(icon3);

        horizontalLayout_buttons->addWidget(btnDelete);

        horizontalSpacerButtons = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_buttons->addItem(horizontalSpacerButtons);


        verticalLayout_main->addWidget(frameButtons);

        groupList = new QGroupBox(GD_QLPhongBan);
        groupList->setObjectName("groupList");
        verticalLayout_table = new QVBoxLayout(groupList);
        verticalLayout_table->setObjectName("verticalLayout_table");
        tableDepartments = new QTableWidget(groupList);
        if (tableDepartments->columnCount() < 4)
            tableDepartments->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableDepartments->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableDepartments->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableDepartments->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableDepartments->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableDepartments->setObjectName("tableDepartments");
        tableDepartments->setAlternatingRowColors(true);
        tableDepartments->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_table->addWidget(tableDepartments);


        verticalLayout_main->addWidget(groupList);


        retranslateUi(GD_QLPhongBan);

        QMetaObject::connectSlotsByName(GD_QLPhongBan);
    } // setupUi

    void retranslateUi(QWidget *GD_QLPhongBan)
    {
        GD_QLPhongBan->setWindowTitle(QCoreApplication::translate("GD_QLPhongBan", "Qu\341\272\243n l\303\275 Ph\303\262ng ban", nullptr));
        groupFilter->setTitle(QCoreApplication::translate("GD_QLPhongBan", "B\341\273\231 l\341\273\215c / Ch\341\273\215n nh\303\263m", nullptr));
        labelSelectGroup->setText(QCoreApplication::translate("GD_QLPhongBan", "Ch\341\273\215n nh\303\263m:", nullptr));
        comboGroups->setItemText(0, QCoreApplication::translate("GD_QLPhongBan", "T\341\272\245t c\341\272\243", nullptr));
        comboGroups->setItemText(1, QCoreApplication::translate("GD_QLPhongBan", "Kh\341\273\221i K\341\273\271 thu\341\272\255t", nullptr));
        comboGroups->setItemText(2, QCoreApplication::translate("GD_QLPhongBan", "Kh\341\273\221i Kinh doanh", nullptr));
        comboGroups->setItemText(3, QCoreApplication::translate("GD_QLPhongBan", "Kh\341\273\221i H\303\240nh ch\303\255nh", nullptr));

        btnRefresh->setText(QCoreApplication::translate("GD_QLPhongBan", "L\303\240m m\341\273\233i", nullptr));
        groupDetails->setTitle(QCoreApplication::translate("GD_QLPhongBan", "Th\303\264ng tin Ph\303\262ng ban", nullptr));
        labelDeptID->setText(QCoreApplication::translate("GD_QLPhongBan", "M\303\243 ph\303\262ng ban:", nullptr));
        labelDeptName->setText(QCoreApplication::translate("GD_QLPhongBan", "T\303\252n ph\303\262ng ban:", nullptr));
        labelLeader->setText(QCoreApplication::translate("GD_QLPhongBan", "Tr\306\260\341\273\237ng ph\303\262ng:", nullptr));
        labelNote->setText(QCoreApplication::translate("GD_QLPhongBan", "M\303\264 t\341\272\243 / Ghi ch\303\272:", nullptr));
        btnAdd->setText(QCoreApplication::translate("GD_QLPhongBan", "Th\303\252m", nullptr));
        btnEdit->setText(QCoreApplication::translate("GD_QLPhongBan", "S\341\273\255a", nullptr));
        btnDelete->setText(QCoreApplication::translate("GD_QLPhongBan", "X\303\263a", nullptr));
        groupList->setTitle(QCoreApplication::translate("GD_QLPhongBan", "Danh s\303\241ch Ph\303\262ng ban", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableDepartments->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("GD_QLPhongBan", "M\303\243 PB", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableDepartments->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("GD_QLPhongBan", "T\303\252n Ph\303\262ng ban", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableDepartments->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("GD_QLPhongBan", "Tr\306\260\341\273\237ng ph\303\262ng", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableDepartments->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("GD_QLPhongBan", "Ghi ch\303\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GD_QLPhongBan: public Ui_GD_QLPhongBan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GD_QLPHONGBAN_H
