/********************************************************************************
** Form generated from reading UI file 'GD_NVChung.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GD_NVCHUNG_H
#define UI_GD_NVCHUNG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GD_NVChung
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_main;
    QFrame *navFrame;
    QVBoxLayout *verticalLayout;
    QLabel *headerLabel;
    QPushButton *btnNavInfo;
    QPushButton *btnNavSalary;
    QPushButton *btnNavAttendance;
    QPushButton *btnNavProjects;
    QPushButton *btnNavRelatives;
    QSpacerItem *verticalSpacer;
    QStackedWidget *mainStackedWidget;
    QWidget *page_info;
    QVBoxLayout *verticalLayout_info_page;
    QLabel *label_page_info;
    QGroupBox *groupBox_basic_info;
    QFormLayout *formLayout_basic;
    QLabel *label_maNV;
    QLineEdit *lineEdit_maNV;
    QLabel *label_hoTen;
    QLineEdit *lineEdit_hoTen;
    QLabel *label_cccd;
    QLineEdit *lineEdit_cccd;
    QLabel *label_ngaySinh;
    QDateEdit *dateEdit_ngaySinh;
    QLabel *label_gioiTinh;
    QComboBox *comboBox_gioiTinh;
    QGroupBox *groupBox_contact;
    QFormLayout *formLayout_contact;
    QLabel *label_sdt;
    QLineEdit *lineEdit_sdt;
    QLabel *label_email;
    QLineEdit *lineEdit_email;
    QLabel *label_diaChi;
    QLineEdit *lineEdit_diaChi;
    QGroupBox *groupBox_work;
    QFormLayout *formLayout_work;
    QLabel *label_viTri;
    QLineEdit *lineEdit_viTri;
    QLabel *label_phongBan;
    QLineEdit *lineEdit_phongBan;
    QLabel *label_ngayVao;
    QDateEdit *dateEdit_ngayVao;
    QSpacerItem *verticalSpacer_info;
    QWidget *page_salary;
    QVBoxLayout *verticalLayout_salary_page;
    QLabel *label_page_salary;
    QLabel *label_luong_info;
    QSpacerItem *verticalSpacer_salary;
    QWidget *page_attendance;
    QVBoxLayout *verticalLayout_attendance_page;
    QLabel *label_page_attendance;
    QGroupBox *groupBox_attendance_actions;
    QHBoxLayout *horizontalLayout_attendance_actions;
    QPushButton *btnCheckIn;
    QPushButton *btnAttendanceHistory;
    QSpacerItem *horizontalSpacer_attendance_actions;
    QGroupBox *groupBox_attendance_history;
    QVBoxLayout *verticalLayout_attendance_history;
    QTableWidget *tableAttendance;
    QSpacerItem *verticalSpacer_attendance;
    QWidget *page_projects;
    QVBoxLayout *verticalLayout_projects_page;
    QLabel *label_page_projects;
    QTableWidget *tableProjects;
    QWidget *page_relatives;
    QVBoxLayout *verticalLayout_relatives_page;
    QLabel *label_page_relatives;
    QTableWidget *tableRelatives;
    QSpacerItem *verticalSpacer_relatives;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GD_NVChung)
    {
        if (GD_NVChung->objectName().isEmpty())
            GD_NVChung->setObjectName("GD_NVChung");
        GD_NVChung->resize(1280, 800);
        GD_NVChung->setStyleSheet(QString::fromUtf8("/* --- Global Styles --- */\n"
"QWidget {\n"
"	font-family: \"Segoe UI\", Arial, sans-serif;\n"
"	font-size: 10pt;\n"
"	color: #333;\n"
"}\n"
"\n"
"QMainWindow {\n"
"	background-color: #f0f2f5;\n"
"}\n"
"\n"
"/* --- Navigation Sidebar --- */\n"
"#navFrame {\n"
"	background-color: #ffffff;\n"
"	border-right: 1px solid #e0e0e0;\n"
"}\n"
"\n"
"#navFrame QPushButton {\n"
"	text-align: left;\n"
"	padding: 12px 20px;\n"
"	border: none;\n"
"	border-radius: 8px;\n"
"	background-color: transparent;\n"
"	font-weight: 500;\n"
"}\n"
"\n"
"#navFrame QPushButton:hover {\n"
"	background-color: #f0f2f5;\n"
"}\n"
"\n"
"#navFrame QPushButton:checked {\n"
"	background-color: #e6f2ff;\n"
"	color: #005a9e;\n"
"	font-weight: bold;\n"
"}\n"
"\n"
"#headerLabel {\n"
"	font-size: 14pt;\n"
"	font-weight: bold;\n"
"	color: #005a9e;\n"
"	padding: 10px;\n"
"}\n"
"\n"
"/* --- Content Area --- */\n"
"#page_info, #page_salary, #page_projects, #page_relatives, #page_attendance {\n"
"	background-color: #f0f2f5;\n"
"}\n"
"\n"
"QGroupBox {\n"
"	f"
                        "ont-weight: bold;\n"
"	background-color: #ffffff;\n"
"	border: 1px solid #dcdcdc;\n"
"	border-radius: 8px;\n"
"	margin-top: 10px;\n"
"}\n"
"QGroupBox::title {\n"
"	subcontrol-origin: margin;\n"
"	subcontrol-position: top left;\n"
"	padding: 0 10px;\n"
"	left: 10px;\n"
"}\n"
"\n"
"/* --- General Widgets --- */\n"
"QLineEdit, QComboBox, QTextEdit, QDateEdit {\n"
"	border: 1px solid #dcdcdc;\n"
"	border-radius: 8px;\n"
"	padding: 8px 12px;\n"
"	background-color: white;\n"
"}\n"
"QLineEdit:focus, QComboBox:focus, QTextEdit:focus, QDateEdit:focus {\n"
"	border: 1px solid #0078d7;\n"
"}\n"
"\n"
"QLabel {\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* --- Buttons --- */\n"
"QPushButton {\n"
"	padding: 8px 18px;\n"
"	border: 1px solid #dcdcdc;\n"
"	border-radius: 8px;\n"
"	background-color: white;\n"
"	min-width: 80px;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: #f5f5f5;\n"
"	border-color: #c0c0c0;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: #e0e0e0;\n"
"}\n"
"\n"
"/* --- Table --- */\n"
"QTableWidget {\n"
""
                        "	border: 1px solid #dcdcdc;\n"
"	border-radius: 8px;\n"
"	gridline-color: #e0e0e0;\n"
"	background-color: white;\n"
"}\n"
"QHeaderView::section {\n"
"	background-color: #f8f9fa;\n"
"	padding: 10px;\n"
"	border: none;\n"
"	border-bottom: 1px solid #dcdcdc;\n"
"	font-weight: bold;\n"
"}\n"
"QTableWidget::item {\n"
"	padding: 10px;\n"
"}\n"
"QTableWidget::item:selected {\n"
"	background-color: #cfe2ff;\n"
"	color: #000;\n"
"}\n"
"\n"
"/* --- ScrollBar --- */\n"
"QScrollBar:vertical {\n"
"	border: none;\n"
"	background: #f0f2f5;\n"
"	width: 10px;\n"
"	margin: 0px 0px 0px 0px;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"	background: #c0c0c0;\n"
"	min-height: 20px;\n"
"	border-radius: 5px;\n"
"}\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"	height: 0px;\n"
"}\n"
""));
        centralwidget = new QWidget(GD_NVChung);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_main = new QHBoxLayout(centralwidget);
        horizontalLayout_main->setSpacing(0);
        horizontalLayout_main->setObjectName("horizontalLayout_main");
        horizontalLayout_main->setContentsMargins(0, 0, 0, 0);
        navFrame = new QFrame(centralwidget);
        navFrame->setObjectName("navFrame");
        navFrame->setMinimumSize(QSize(220, 0));
        navFrame->setMaximumSize(QSize(220, 16777215));
        navFrame->setFrameShape(QFrame::StyledPanel);
        navFrame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(navFrame);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        headerLabel = new QLabel(navFrame);
        headerLabel->setObjectName("headerLabel");
        headerLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(headerLabel);

        btnNavInfo = new QPushButton(navFrame);
        btnNavInfo->setObjectName("btnNavInfo");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/user.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnNavInfo->setIcon(icon);
        btnNavInfo->setCheckable(true);
        btnNavInfo->setChecked(true);
        btnNavInfo->setAutoExclusive(true);

        verticalLayout->addWidget(btnNavInfo);

        btnNavSalary = new QPushButton(navFrame);
        btnNavSalary->setObjectName("btnNavSalary");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/dollar-sign.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnNavSalary->setIcon(icon1);
        btnNavSalary->setCheckable(true);
        btnNavSalary->setAutoExclusive(true);

        verticalLayout->addWidget(btnNavSalary);

        btnNavAttendance = new QPushButton(navFrame);
        btnNavAttendance->setObjectName("btnNavAttendance");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/calendar.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnNavAttendance->setIcon(icon2);
        btnNavAttendance->setCheckable(true);
        btnNavAttendance->setAutoExclusive(true);

        verticalLayout->addWidget(btnNavAttendance);

        btnNavProjects = new QPushButton(navFrame);
        btnNavProjects->setObjectName("btnNavProjects");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/briefcase.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnNavProjects->setIcon(icon3);
        btnNavProjects->setCheckable(true);
        btnNavProjects->setAutoExclusive(true);

        verticalLayout->addWidget(btnNavProjects);

        btnNavRelatives = new QPushButton(navFrame);
        btnNavRelatives->setObjectName("btnNavRelatives");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/family.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnNavRelatives->setIcon(icon4);
        btnNavRelatives->setCheckable(true);
        btnNavRelatives->setAutoExclusive(true);

        verticalLayout->addWidget(btnNavRelatives);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_main->addWidget(navFrame);

        mainStackedWidget = new QStackedWidget(centralwidget);
        mainStackedWidget->setObjectName("mainStackedWidget");
        page_info = new QWidget();
        page_info->setObjectName("page_info");
        verticalLayout_info_page = new QVBoxLayout(page_info);
        verticalLayout_info_page->setObjectName("verticalLayout_info_page");
        label_page_info = new QLabel(page_info);
        label_page_info->setObjectName("label_page_info");
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label_page_info->setFont(font);

        verticalLayout_info_page->addWidget(label_page_info);

        groupBox_basic_info = new QGroupBox(page_info);
        groupBox_basic_info->setObjectName("groupBox_basic_info");
        formLayout_basic = new QFormLayout(groupBox_basic_info);
        formLayout_basic->setObjectName("formLayout_basic");
        label_maNV = new QLabel(groupBox_basic_info);
        label_maNV->setObjectName("label_maNV");

        formLayout_basic->setWidget(0, QFormLayout::ItemRole::LabelRole, label_maNV);

        lineEdit_maNV = new QLineEdit(groupBox_basic_info);
        lineEdit_maNV->setObjectName("lineEdit_maNV");

        formLayout_basic->setWidget(0, QFormLayout::ItemRole::FieldRole, lineEdit_maNV);

        label_hoTen = new QLabel(groupBox_basic_info);
        label_hoTen->setObjectName("label_hoTen");

        formLayout_basic->setWidget(1, QFormLayout::ItemRole::LabelRole, label_hoTen);

        lineEdit_hoTen = new QLineEdit(groupBox_basic_info);
        lineEdit_hoTen->setObjectName("lineEdit_hoTen");

        formLayout_basic->setWidget(1, QFormLayout::ItemRole::FieldRole, lineEdit_hoTen);

        label_cccd = new QLabel(groupBox_basic_info);
        label_cccd->setObjectName("label_cccd");

        formLayout_basic->setWidget(2, QFormLayout::ItemRole::LabelRole, label_cccd);

        lineEdit_cccd = new QLineEdit(groupBox_basic_info);
        lineEdit_cccd->setObjectName("lineEdit_cccd");

        formLayout_basic->setWidget(2, QFormLayout::ItemRole::FieldRole, lineEdit_cccd);

        label_ngaySinh = new QLabel(groupBox_basic_info);
        label_ngaySinh->setObjectName("label_ngaySinh");

        formLayout_basic->setWidget(3, QFormLayout::ItemRole::LabelRole, label_ngaySinh);

        dateEdit_ngaySinh = new QDateEdit(groupBox_basic_info);
        dateEdit_ngaySinh->setObjectName("dateEdit_ngaySinh");

        formLayout_basic->setWidget(3, QFormLayout::ItemRole::FieldRole, dateEdit_ngaySinh);

        label_gioiTinh = new QLabel(groupBox_basic_info);
        label_gioiTinh->setObjectName("label_gioiTinh");

        formLayout_basic->setWidget(4, QFormLayout::ItemRole::LabelRole, label_gioiTinh);

        comboBox_gioiTinh = new QComboBox(groupBox_basic_info);
        comboBox_gioiTinh->addItem(QString());
        comboBox_gioiTinh->addItem(QString());
        comboBox_gioiTinh->setObjectName("comboBox_gioiTinh");

        formLayout_basic->setWidget(4, QFormLayout::ItemRole::FieldRole, comboBox_gioiTinh);


        verticalLayout_info_page->addWidget(groupBox_basic_info);

        groupBox_contact = new QGroupBox(page_info);
        groupBox_contact->setObjectName("groupBox_contact");
        formLayout_contact = new QFormLayout(groupBox_contact);
        formLayout_contact->setObjectName("formLayout_contact");
        label_sdt = new QLabel(groupBox_contact);
        label_sdt->setObjectName("label_sdt");

        formLayout_contact->setWidget(0, QFormLayout::ItemRole::LabelRole, label_sdt);

        lineEdit_sdt = new QLineEdit(groupBox_contact);
        lineEdit_sdt->setObjectName("lineEdit_sdt");

        formLayout_contact->setWidget(0, QFormLayout::ItemRole::FieldRole, lineEdit_sdt);

        label_email = new QLabel(groupBox_contact);
        label_email->setObjectName("label_email");

        formLayout_contact->setWidget(1, QFormLayout::ItemRole::LabelRole, label_email);

        lineEdit_email = new QLineEdit(groupBox_contact);
        lineEdit_email->setObjectName("lineEdit_email");

        formLayout_contact->setWidget(1, QFormLayout::ItemRole::FieldRole, lineEdit_email);

        label_diaChi = new QLabel(groupBox_contact);
        label_diaChi->setObjectName("label_diaChi");

        formLayout_contact->setWidget(2, QFormLayout::ItemRole::LabelRole, label_diaChi);

        lineEdit_diaChi = new QLineEdit(groupBox_contact);
        lineEdit_diaChi->setObjectName("lineEdit_diaChi");

        formLayout_contact->setWidget(2, QFormLayout::ItemRole::FieldRole, lineEdit_diaChi);


        verticalLayout_info_page->addWidget(groupBox_contact);

        groupBox_work = new QGroupBox(page_info);
        groupBox_work->setObjectName("groupBox_work");
        formLayout_work = new QFormLayout(groupBox_work);
        formLayout_work->setObjectName("formLayout_work");
        label_viTri = new QLabel(groupBox_work);
        label_viTri->setObjectName("label_viTri");

        formLayout_work->setWidget(0, QFormLayout::ItemRole::LabelRole, label_viTri);

        lineEdit_viTri = new QLineEdit(groupBox_work);
        lineEdit_viTri->setObjectName("lineEdit_viTri");

        formLayout_work->setWidget(0, QFormLayout::ItemRole::FieldRole, lineEdit_viTri);

        label_phongBan = new QLabel(groupBox_work);
        label_phongBan->setObjectName("label_phongBan");

        formLayout_work->setWidget(1, QFormLayout::ItemRole::LabelRole, label_phongBan);

        lineEdit_phongBan = new QLineEdit(groupBox_work);
        lineEdit_phongBan->setObjectName("lineEdit_phongBan");

        formLayout_work->setWidget(1, QFormLayout::ItemRole::FieldRole, lineEdit_phongBan);

        label_ngayVao = new QLabel(groupBox_work);
        label_ngayVao->setObjectName("label_ngayVao");

        formLayout_work->setWidget(2, QFormLayout::ItemRole::LabelRole, label_ngayVao);

        dateEdit_ngayVao = new QDateEdit(groupBox_work);
        dateEdit_ngayVao->setObjectName("dateEdit_ngayVao");

        formLayout_work->setWidget(2, QFormLayout::ItemRole::FieldRole, dateEdit_ngayVao);


        verticalLayout_info_page->addWidget(groupBox_work);

        verticalSpacer_info = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_info_page->addItem(verticalSpacer_info);

        mainStackedWidget->addWidget(page_info);
        page_salary = new QWidget();
        page_salary->setObjectName("page_salary");
        verticalLayout_salary_page = new QVBoxLayout(page_salary);
        verticalLayout_salary_page->setObjectName("verticalLayout_salary_page");
        label_page_salary = new QLabel(page_salary);
        label_page_salary->setObjectName("label_page_salary");
        label_page_salary->setFont(font);

        verticalLayout_salary_page->addWidget(label_page_salary);

        label_luong_info = new QLabel(page_salary);
        label_luong_info->setObjectName("label_luong_info");
        label_luong_info->setAlignment(Qt::AlignCenter);

        verticalLayout_salary_page->addWidget(label_luong_info);

        verticalSpacer_salary = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_salary_page->addItem(verticalSpacer_salary);

        mainStackedWidget->addWidget(page_salary);
        page_attendance = new QWidget();
        page_attendance->setObjectName("page_attendance");
        verticalLayout_attendance_page = new QVBoxLayout(page_attendance);
        verticalLayout_attendance_page->setObjectName("verticalLayout_attendance_page");
        label_page_attendance = new QLabel(page_attendance);
        label_page_attendance->setObjectName("label_page_attendance");
        label_page_attendance->setFont(font);

        verticalLayout_attendance_page->addWidget(label_page_attendance);

        groupBox_attendance_actions = new QGroupBox(page_attendance);
        groupBox_attendance_actions->setObjectName("groupBox_attendance_actions");
        horizontalLayout_attendance_actions = new QHBoxLayout(groupBox_attendance_actions);
        horizontalLayout_attendance_actions->setObjectName("horizontalLayout_attendance_actions");
        btnCheckIn = new QPushButton(groupBox_attendance_actions);
        btnCheckIn->setObjectName("btnCheckIn");

        horizontalLayout_attendance_actions->addWidget(btnCheckIn);

        btnAttendanceHistory = new QPushButton(groupBox_attendance_actions);
        btnAttendanceHistory->setObjectName("btnAttendanceHistory");

        horizontalLayout_attendance_actions->addWidget(btnAttendanceHistory);

        horizontalSpacer_attendance_actions = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_attendance_actions->addItem(horizontalSpacer_attendance_actions);


        verticalLayout_attendance_page->addWidget(groupBox_attendance_actions);

        groupBox_attendance_history = new QGroupBox(page_attendance);
        groupBox_attendance_history->setObjectName("groupBox_attendance_history");
        verticalLayout_attendance_history = new QVBoxLayout(groupBox_attendance_history);
        verticalLayout_attendance_history->setObjectName("verticalLayout_attendance_history");
        tableAttendance = new QTableWidget(groupBox_attendance_history);
        if (tableAttendance->columnCount() < 4)
            tableAttendance->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableAttendance->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableAttendance->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableAttendance->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableAttendance->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableAttendance->setObjectName("tableAttendance");
        tableAttendance->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableAttendance->setAlternatingRowColors(true);
        tableAttendance->setSelectionMode(QAbstractItemView::SingleSelection);
        tableAttendance->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableAttendance->setSortingEnabled(true);
        tableAttendance->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_attendance_history->addWidget(tableAttendance);


        verticalLayout_attendance_page->addWidget(groupBox_attendance_history);

        verticalSpacer_attendance = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_attendance_page->addItem(verticalSpacer_attendance);

        mainStackedWidget->addWidget(page_attendance);
        page_projects = new QWidget();
        page_projects->setObjectName("page_projects");
        verticalLayout_projects_page = new QVBoxLayout(page_projects);
        verticalLayout_projects_page->setObjectName("verticalLayout_projects_page");
        label_page_projects = new QLabel(page_projects);
        label_page_projects->setObjectName("label_page_projects");
        label_page_projects->setFont(font);

        verticalLayout_projects_page->addWidget(label_page_projects);

        tableProjects = new QTableWidget(page_projects);
        if (tableProjects->columnCount() < 4)
            tableProjects->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableProjects->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableProjects->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableProjects->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableProjects->setHorizontalHeaderItem(3, __qtablewidgetitem7);
        tableProjects->setObjectName("tableProjects");
        tableProjects->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_projects_page->addWidget(tableProjects);

        mainStackedWidget->addWidget(page_projects);
        page_relatives = new QWidget();
        page_relatives->setObjectName("page_relatives");
        verticalLayout_relatives_page = new QVBoxLayout(page_relatives);
        verticalLayout_relatives_page->setObjectName("verticalLayout_relatives_page");
        label_page_relatives = new QLabel(page_relatives);
        label_page_relatives->setObjectName("label_page_relatives");
        label_page_relatives->setFont(font);

        verticalLayout_relatives_page->addWidget(label_page_relatives);

        tableRelatives = new QTableWidget(page_relatives);
        if (tableRelatives->columnCount() < 3)
            tableRelatives->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableRelatives->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableRelatives->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableRelatives->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        tableRelatives->setObjectName("tableRelatives");
        tableRelatives->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_relatives_page->addWidget(tableRelatives);

        verticalSpacer_relatives = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_relatives_page->addItem(verticalSpacer_relatives);

        mainStackedWidget->addWidget(page_relatives);

        horizontalLayout_main->addWidget(mainStackedWidget);

        GD_NVChung->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GD_NVChung);
        menubar->setObjectName("menubar");
        GD_NVChung->setMenuBar(menubar);
        statusbar = new QStatusBar(GD_NVChung);
        statusbar->setObjectName("statusbar");
        GD_NVChung->setStatusBar(statusbar);

        retranslateUi(GD_NVChung);

        mainStackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(GD_NVChung);
    } // setupUi

    void retranslateUi(QMainWindow *GD_NVChung)
    {
        GD_NVChung->setWindowTitle(QCoreApplication::translate("GD_NVChung", "Th\303\264ng tin Nh\303\242n s\341\273\261", nullptr));
        headerLabel->setText(QCoreApplication::translate("GD_NVChung", "TH\303\224NG TIN NH\303\202N VI\303\212N", nullptr));
        btnNavInfo->setText(QCoreApplication::translate("GD_NVChung", "Th\303\264ng tin c\303\241 nh\303\242n", nullptr));
        btnNavSalary->setText(QCoreApplication::translate("GD_NVChung", "L\306\260\306\241ng v\303\240 Thu nh\341\272\255p", nullptr));
        btnNavAttendance->setText(QCoreApplication::translate("GD_NVChung", "Ch\341\272\245m c\303\264ng", nullptr));
        btnNavProjects->setText(QCoreApplication::translate("GD_NVChung", "D\341\273\261 \303\241n", nullptr));
        btnNavRelatives->setText(QCoreApplication::translate("GD_NVChung", "Th\303\242n nh\303\242n", nullptr));
        label_page_info->setText(QCoreApplication::translate("GD_NVChung", "Th\303\264ng tin c\303\241 nh\303\242n", nullptr));
        groupBox_basic_info->setTitle(QCoreApplication::translate("GD_NVChung", "Th\303\264ng tin c\306\241 b\341\272\243n", nullptr));
        label_maNV->setText(QCoreApplication::translate("GD_NVChung", "M\303\243 nh\303\242n vi\303\252n:", nullptr));
        label_hoTen->setText(QCoreApplication::translate("GD_NVChung", "H\341\273\215 v\303\240 t\303\252n:", nullptr));
        label_cccd->setText(QCoreApplication::translate("GD_NVChung", "CCCD/CMND:", nullptr));
        label_ngaySinh->setText(QCoreApplication::translate("GD_NVChung", "Ng\303\240y sinh:", nullptr));
        label_gioiTinh->setText(QCoreApplication::translate("GD_NVChung", "Gi\341\273\233i t\303\255nh:", nullptr));
        comboBox_gioiTinh->setItemText(0, QCoreApplication::translate("GD_NVChung", "Nam", nullptr));
        comboBox_gioiTinh->setItemText(1, QCoreApplication::translate("GD_NVChung", "N\341\273\257", nullptr));

        groupBox_contact->setTitle(QCoreApplication::translate("GD_NVChung", "Li\303\252n h\341\273\207", nullptr));
        label_sdt->setText(QCoreApplication::translate("GD_NVChung", "S\341\273\221 \304\221i\341\273\207n tho\341\272\241i:", nullptr));
        label_email->setText(QCoreApplication::translate("GD_NVChung", "Email:", nullptr));
        label_diaChi->setText(QCoreApplication::translate("GD_NVChung", "\304\220\341\273\213a ch\341\273\211:", nullptr));
        groupBox_work->setTitle(QCoreApplication::translate("GD_NVChung", "C\303\264ng vi\341\273\207c", nullptr));
        label_viTri->setText(QCoreApplication::translate("GD_NVChung", "V\341\273\213 tr\303\255:", nullptr));
        label_phongBan->setText(QCoreApplication::translate("GD_NVChung", "Ph\303\262ng ban:", nullptr));
        label_ngayVao->setText(QCoreApplication::translate("GD_NVChung", "Ng\303\240y v\303\240o:", nullptr));
        label_page_salary->setText(QCoreApplication::translate("GD_NVChung", "L\306\260\306\241ng v\303\240 Thu nh\341\272\255p", nullptr));
        label_luong_info->setText(QCoreApplication::translate("GD_NVChung", "Chi ti\341\272\277t l\306\260\306\241ng s\341\272\275 hi\341\273\203n th\341\273\213 t\341\272\241i \304\221\303\242y.", nullptr));
        label_page_attendance->setText(QCoreApplication::translate("GD_NVChung", "Ch\341\272\245m c\303\264ng", nullptr));
        groupBox_attendance_actions->setTitle(QCoreApplication::translate("GD_NVChung", "T\303\241c v\341\273\245", nullptr));
        btnCheckIn->setText(QCoreApplication::translate("GD_NVChung", "Ch\341\272\245m c\303\264ng", nullptr));
        btnAttendanceHistory->setText(QCoreApplication::translate("GD_NVChung", "Xem l\341\273\213ch s\341\273\255", nullptr));
        groupBox_attendance_history->setTitle(QCoreApplication::translate("GD_NVChung", "L\341\273\213ch s\341\273\255 Ch\341\272\245m c\303\264ng", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableAttendance->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("GD_NVChung", "Ng\303\240y", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableAttendance->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("GD_NVChung", "Gi\341\273\235 v\303\240o", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableAttendance->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("GD_NVChung", "Gi\341\273\235 ra", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableAttendance->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("GD_NVChung", "Tr\341\272\241ng th\303\241i", nullptr));
        label_page_projects->setText(QCoreApplication::translate("GD_NVChung", "D\341\273\261 \303\241n \304\221ang tham gia", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableProjects->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("GD_NVChung", "M\303\243 D\341\273\261 \303\241n", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableProjects->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("GD_NVChung", "T\303\252n D\341\273\261 \303\241n", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableProjects->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("GD_NVChung", "Tr\341\272\241ng th\303\241i", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableProjects->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("GD_NVChung", "Ng\306\260\341\273\235i ph\341\273\245 tr\303\241ch", nullptr));
        label_page_relatives->setText(QCoreApplication::translate("GD_NVChung", "Th\303\264ng tin Th\303\242n nh\303\242n", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableRelatives->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("GD_NVChung", "H\341\273\215 v\303\240 T\303\252n", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableRelatives->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("GD_NVChung", "Quan h\341\273\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableRelatives->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("GD_NVChung", "S\341\273\221 \304\221i\341\273\207n tho\341\272\241i", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GD_NVChung: public Ui_GD_NVChung {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GD_NVCHUNG_H
