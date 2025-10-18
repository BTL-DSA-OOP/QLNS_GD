/********************************************************************************
** Form generated from reading UI file 'GD_Qly.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GD_QLY_H
#define UI_GD_QLY_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
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

class Ui_GD_Qly
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_main;
    QFrame *navFrame;
    QVBoxLayout *verticalLayout;
    QLabel *headerLabel;
    QPushButton *btnNavEmployees;
    QPushButton *btnNavAttendance;
    QPushButton *btnNavProjects;
    QPushButton *btnNavDepartments;
    QSpacerItem *verticalSpacer;
    QPushButton *btnNavSettings;
    QStackedWidget *mainStackedWidget;
    QWidget *page_employees;
    QVBoxLayout *verticalLayout_2;
    QFrame *topBarFrame;
    QHBoxLayout *topBar;
    QLineEdit *lineEditSearch;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnExport;
    QPushButton *btnRefresh;
    QFrame *actionFrame;
    QHBoxLayout *actionLayout;
    QPushButton *btnAdd;
    QPushButton *btnEdit;
    QPushButton *btnDelete;
    QPushButton *btnDetail;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *tableEmployees;
    QWidget *page_attendance;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_filter_chamcong;
    QHBoxLayout *horizontalLayout;
    QLabel *label_chonNV;
    QComboBox *comboChamCongNhanVien;
    QLabel *label_chonNgay;
    QCalendarWidget *calendarChamCong;
    QPushButton *btnLoadChamCong;
    QSpacerItem *horizontalSpacer_3;
    QTableWidget *tableChamCongTongHop;
    QWidget *page_projects;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GD_Qly)
    {
        if (GD_Qly->objectName().isEmpty())
            GD_Qly->setObjectName("GD_Qly");
        GD_Qly->resize(1280, 800);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/app-icon.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        GD_Qly->setWindowIcon(icon);
        GD_Qly->setStyleSheet(QString::fromUtf8("/* --- Global Styles --- */\n"
"QWidget {\n"
"    font-family: \"Segoe UI\", Arial, sans-serif;\n"
"font-size: 10pt;\n"
"    color: #333;\n"
"}\n"
"\n"
"QMainWindow {\n"
"    background-color: #f0f2f5;\n"
"}\n"
"\n"
"/* --- Navigation Sidebar --- */\n"
"#navFrame {\n"
"    background-color: #ffffff;\n"
"    border-right: 1px solid #e0e0e0;\n"
"}\n"
"\n"
"#navFrame QPushButton {\n"
"    text-align: left;\n"
"    padding: 12px 20px;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    background-color: transparent;\n"
"    font-weight: 500;\n"
"}\n"
"\n"
"#navFrame QPushButton:hover {\n"
"    background-color: #f0f2f5;\n"
"}\n"
"\n"
"#navFrame QPushButton:checked {\n"
"    background-color: #e6f2ff;\n"
"    color: #005a9e;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#headerLabel {\n"
"    font-size: 14pt;\n"
"    font-weight: bold;\n"
"    color: #005a9e;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"\n"
"/* --- Content Area --- */\n"
"#page_employees, #page_attendance, #page_projects {\n"
"    background-color: #f0f"
                        "2f5;\n"
"}\n"
"\n"
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
"QLineEdit, QComboBox {\n"
"    border: 1px solid #dcdcdc;\n"
"    border-radius: 8px;\n"
"    padding: 8px 12px;\n"
"background-color: white;\n"
"}\n"
"QLineEdit:focus, QComboBox:focus {\n"
"    border: 1px solid #0078d7;\n"
"}\n"
"\n"
"QPushButton {\n"
"    padding: 8px 18px;\n"
"border: 1px solid #dcdcdc;\n"
"    border-radius: 8px;\n"
"    background-color: white;\n"
"    min-width: 80px;\n"
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
"    "
                        "background-color: #0078d7;\n"
"color: white;\n"
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
"    border-bottom: 1px solid #dcdcdc;\n"
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
""
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
        centralwidget = new QWidget(GD_Qly);
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

        btnNavEmployees = new QPushButton(navFrame);
        btnNavEmployees->setObjectName("btnNavEmployees");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/users.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnNavEmployees->setIcon(icon1);
        btnNavEmployees->setCheckable(true);
        btnNavEmployees->setChecked(true);
        btnNavEmployees->setAutoExclusive(true);

        verticalLayout->addWidget(btnNavEmployees);

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

        btnNavDepartments = new QPushButton(navFrame);
        btnNavDepartments->setObjectName("btnNavDepartments");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/office.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnNavDepartments->setIcon(icon4);
        btnNavDepartments->setCheckable(true);
        btnNavDepartments->setAutoExclusive(true);

        verticalLayout->addWidget(btnNavDepartments);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btnNavSettings = new QPushButton(navFrame);
        btnNavSettings->setObjectName("btnNavSettings");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/settings.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnNavSettings->setIcon(icon5);
        btnNavSettings->setCheckable(true);
        btnNavSettings->setAutoExclusive(true);

        verticalLayout->addWidget(btnNavSettings);


        horizontalLayout_main->addWidget(navFrame);

        mainStackedWidget = new QStackedWidget(centralwidget);
        mainStackedWidget->setObjectName("mainStackedWidget");
        page_employees = new QWidget();
        page_employees->setObjectName("page_employees");
        verticalLayout_2 = new QVBoxLayout(page_employees);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(12, 12, 12, 12);
        topBarFrame = new QFrame(page_employees);
        topBarFrame->setObjectName("topBarFrame");
        topBar = new QHBoxLayout(topBarFrame);
        topBar->setObjectName("topBar");
        lineEditSearch = new QLineEdit(topBarFrame);
        lineEditSearch->setObjectName("lineEditSearch");
        lineEditSearch->setMinimumSize(QSize(350, 0));
        lineEditSearch->setClearButtonEnabled(true);

        topBar->addWidget(lineEditSearch);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        topBar->addItem(horizontalSpacer);

        btnExport = new QPushButton(topBarFrame);
        btnExport->setObjectName("btnExport");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/export.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnExport->setIcon(icon6);

        topBar->addWidget(btnExport);

        btnRefresh = new QPushButton(topBarFrame);
        btnRefresh->setObjectName("btnRefresh");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/refresh.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnRefresh->setIcon(icon7);

        topBar->addWidget(btnRefresh);


        verticalLayout_2->addWidget(topBarFrame);

        actionFrame = new QFrame(page_employees);
        actionFrame->setObjectName("actionFrame");
        actionLayout = new QHBoxLayout(actionFrame);
        actionLayout->setObjectName("actionLayout");
        btnAdd = new QPushButton(actionFrame);
        btnAdd->setObjectName("btnAdd");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/add.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnAdd->setIcon(icon8);

        actionLayout->addWidget(btnAdd);

        btnEdit = new QPushButton(actionFrame);
        btnEdit->setObjectName("btnEdit");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons/edit.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnEdit->setIcon(icon9);

        actionLayout->addWidget(btnEdit);

        btnDelete = new QPushButton(actionFrame);
        btnDelete->setObjectName("btnDelete");
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icons/delete.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnDelete->setIcon(icon10);

        actionLayout->addWidget(btnDelete);

        btnDetail = new QPushButton(actionFrame);
        btnDetail->setObjectName("btnDetail");
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icons/detail.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnDetail->setIcon(icon11);

        actionLayout->addWidget(btnDetail);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        actionLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(actionFrame);

        tableEmployees = new QTableWidget(page_employees);
        if (tableEmployees->columnCount() < 6)
            tableEmployees->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableEmployees->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableEmployees->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableEmployees->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableEmployees->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableEmployees->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableEmployees->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableEmployees->setObjectName("tableEmployees");
        tableEmployees->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableEmployees->setAlternatingRowColors(true);
        tableEmployees->setSelectionMode(QAbstractItemView::SingleSelection);
        tableEmployees->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableEmployees->setSortingEnabled(true);
        tableEmployees->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_2->addWidget(tableEmployees);

        mainStackedWidget->addWidget(page_employees);
        page_attendance = new QWidget();
        page_attendance->setObjectName("page_attendance");
        verticalLayout_3 = new QVBoxLayout(page_attendance);
        verticalLayout_3->setSpacing(10);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(12, 12, 12, 12);
        frame_filter_chamcong = new QFrame(page_attendance);
        frame_filter_chamcong->setObjectName("frame_filter_chamcong");
        frame_filter_chamcong->setFrameShape(QFrame::NoFrame);
        frame_filter_chamcong->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_filter_chamcong);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_chonNV = new QLabel(frame_filter_chamcong);
        label_chonNV->setObjectName("label_chonNV");

        horizontalLayout->addWidget(label_chonNV);

        comboChamCongNhanVien = new QComboBox(frame_filter_chamcong);
        comboChamCongNhanVien->setObjectName("comboChamCongNhanVien");
        comboChamCongNhanVien->setMinimumSize(QSize(250, 0));

        horizontalLayout->addWidget(comboChamCongNhanVien);

        label_chonNgay = new QLabel(frame_filter_chamcong);
        label_chonNgay->setObjectName("label_chonNgay");

        horizontalLayout->addWidget(label_chonNgay);

        calendarChamCong = new QCalendarWidget(frame_filter_chamcong);
        calendarChamCong->setObjectName("calendarChamCong");
        calendarChamCong->setMaximumSize(QSize(400, 300));

        horizontalLayout->addWidget(calendarChamCong);

        btnLoadChamCong = new QPushButton(frame_filter_chamcong);
        btnLoadChamCong->setObjectName("btnLoadChamCong");

        horizontalLayout->addWidget(btnLoadChamCong);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout_3->addWidget(frame_filter_chamcong);

        tableChamCongTongHop = new QTableWidget(page_attendance);
        if (tableChamCongTongHop->columnCount() < 5)
            tableChamCongTongHop->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableChamCongTongHop->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableChamCongTongHop->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableChamCongTongHop->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableChamCongTongHop->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableChamCongTongHop->setHorizontalHeaderItem(4, __qtablewidgetitem10);
        tableChamCongTongHop->setObjectName("tableChamCongTongHop");
        tableChamCongTongHop->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableChamCongTongHop->setSelectionMode(QAbstractItemView::SingleSelection);
        tableChamCongTongHop->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableChamCongTongHop->setSortingEnabled(true);
        tableChamCongTongHop->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_3->addWidget(tableChamCongTongHop);

        mainStackedWidget->addWidget(page_attendance);
        page_projects = new QWidget();
        page_projects->setObjectName("page_projects");
        verticalLayout_4 = new QVBoxLayout(page_projects);
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_2 = new QLabel(page_projects);
        label_2->setObjectName("label_2");
        QFont font;
        font.setPointSize(16);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_2);

        mainStackedWidget->addWidget(page_projects);

        horizontalLayout_main->addWidget(mainStackedWidget);

        GD_Qly->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GD_Qly);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1280, 23));
        GD_Qly->setMenuBar(menubar);
        statusbar = new QStatusBar(GD_Qly);
        statusbar->setObjectName("statusbar");
        GD_Qly->setStatusBar(statusbar);

        retranslateUi(GD_Qly);

        mainStackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(GD_Qly);
    } // setupUi

    void retranslateUi(QMainWindow *GD_Qly)
    {
        GD_Qly->setWindowTitle(QCoreApplication::translate("GD_Qly", "QU\341\272\242N L\303\235 NH\303\202N S\341\273\260", nullptr));
        headerLabel->setText(QCoreApplication::translate("GD_Qly", "QU\341\272\242N L\303\235", nullptr));
        btnNavEmployees->setText(QCoreApplication::translate("GD_Qly", "Qu\341\272\243n l\303\275 Nh\303\242n vi\303\252n", nullptr));
#if QT_CONFIG(tooltip)
        btnNavEmployees->setToolTip(QCoreApplication::translate("GD_Qly", "Qu\341\272\243n l\303\275 h\341\273\223 s\306\241 v\303\240 th\303\264ng tin nh\303\242n vi\303\252n", nullptr));
#endif // QT_CONFIG(tooltip)
        btnNavAttendance->setText(QCoreApplication::translate("GD_Qly", "Ki\341\273\203m so\303\241t Ch\341\272\245m c\303\264ng", nullptr));
#if QT_CONFIG(tooltip)
        btnNavAttendance->setToolTip(QCoreApplication::translate("GD_Qly", "Theo d\303\265i v\303\240 qu\341\272\243n l\303\275 d\341\273\257 li\341\273\207u ch\341\272\245m c\303\264ng", nullptr));
#endif // QT_CONFIG(tooltip)
        btnNavProjects->setText(QCoreApplication::translate("GD_Qly", "Qu\341\272\243n l\303\275 D\341\273\261 \303\241n", nullptr));
#if QT_CONFIG(tooltip)
        btnNavProjects->setToolTip(QCoreApplication::translate("GD_Qly", "Ph\303\242n c\303\264ng v\303\240 theo d\303\265i ti\341\272\277n \304\221\341\273\231 c\303\241c d\341\273\261 \303\241n", nullptr));
#endif // QT_CONFIG(tooltip)
        btnNavDepartments->setText(QCoreApplication::translate("GD_Qly", "Qu\341\272\243n l\303\275 Ph\303\262ng ban", nullptr));
#if QT_CONFIG(tooltip)
        btnNavDepartments->setToolTip(QCoreApplication::translate("GD_Qly", "Qu\341\272\243n l\303\275 th\303\264ng tin v\303\240 danh s\303\241ch ph\303\262ng ban", nullptr));
#endif // QT_CONFIG(tooltip)
        btnNavSettings->setText(QCoreApplication::translate("GD_Qly", "C\303\240i \304\221\341\272\267t", nullptr));
        lineEditSearch->setPlaceholderText(QCoreApplication::translate("GD_Qly", "T\303\254m ki\341\272\277m theo t\303\252n, m\303\243 nh\303\242n vi\303\252n...", nullptr));
        btnExport->setText(QCoreApplication::translate("GD_Qly", "Xu\341\272\245t Excel", nullptr));
        btnRefresh->setText(QCoreApplication::translate("GD_Qly", "L\303\240m m\341\273\233i", nullptr));
        btnAdd->setText(QCoreApplication::translate("GD_Qly", "Th\303\252m M\341\273\233i", nullptr));
        btnEdit->setText(QCoreApplication::translate("GD_Qly", "S\341\273\255a", nullptr));
        btnDelete->setText(QCoreApplication::translate("GD_Qly", "X\303\263a", nullptr));
        btnDetail->setText(QCoreApplication::translate("GD_Qly", "Chi Ti\341\272\277t", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableEmployees->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("GD_Qly", "M\303\243 NV", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableEmployees->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("GD_Qly", "H\341\273\215 v\303\240 T\303\252n", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableEmployees->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("GD_Qly", "Gi\341\273\233i T\303\255nh", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableEmployees->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("GD_Qly", "Ph\303\262ng Ban", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableEmployees->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("GD_Qly", "Ch\341\273\251c V\341\273\245", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableEmployees->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("GD_Qly", "M\341\273\251c L\306\260\306\241ng", nullptr));
        label_chonNV->setText(QCoreApplication::translate("GD_Qly", "Ch\341\273\215n nh\303\242n vi\303\252n:", nullptr));
        label_chonNgay->setText(QCoreApplication::translate("GD_Qly", "Ch\341\273\215n ng\303\240y:", nullptr));
        btnLoadChamCong->setText(QCoreApplication::translate("GD_Qly", "T\341\272\243i d\341\273\257 li\341\273\207u", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableChamCongTongHop->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("GD_Qly", "M\303\243 NV", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableChamCongTongHop->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("GD_Qly", "H\341\273\215 v\303\240 T\303\252n", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableChamCongTongHop->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("GD_Qly", "Gi\341\273\235 v\303\240o", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableChamCongTongHop->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("GD_Qly", "Gi\341\273\235 ra", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableChamCongTongHop->horizontalHeaderItem(4);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("GD_Qly", "Tr\341\272\241ng th\303\241i", nullptr));
        label_2->setText(QCoreApplication::translate("GD_Qly", "N\341\273\231i dung cho trang Qu\341\272\243n l\303\275 D\341\273\261 \303\241n", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GD_Qly: public Ui_GD_Qly {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GD_QLY_H
