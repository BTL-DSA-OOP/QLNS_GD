/********************************************************************************
** Form generated from reading UI file 'GD_Them.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GD_THEM_H
#define UI_GD_THEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GD_Them
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *mainLayout;
    QLabel *lblFormTitle;
    QLabel *lblSectionAccountInfo;
    QFormLayout *formLayoutAccount;
    QLabel *lblUsername;
    QLineEdit *txtUsername;
    QLabel *lblPassword;
    QLineEdit *txtPassword;
    QLabel *lblConfirmPassword;
    QLineEdit *txtConfirmPassword;
    QLabel *lblSectionBasicInfo;
    QFormLayout *formLayoutBasic;
    QLabel *lblMaNhanVien;
    QLineEdit *txtMaNhanVien;
    QLabel *lblHoTen;
    QLineEdit *txtHoTen;
    QLabel *lblCCCD;
    QLineEdit *txtCCCD;
    QLabel *lblNgaySinh;
    QDateEdit *dateNgaySinh;
    QLabel *lblGioiTinh;
    QComboBox *cmbGioiTinh;
    QLabel *lblSectionContact;
    QFormLayout *formLayoutContact;
    QLabel *lblSoDienThoai;
    QLineEdit *txtSoDienThoai;
    QLabel *lblEmail;
    QLineEdit *txtEmail;
    QLabel *lblDiaChi;
    QLineEdit *txtDiaChi;
    QLabel *lblSoTaiKhoan;
    QLineEdit *txtSoTaiKhoan;
    QLabel *lblTenNganHang;
    QLineEdit *txtTenNganHang;
    QLabel *lblSectionJobInfo;
    QFormLayout *formLayoutJob;
    QLabel *lblNgayVaoCongTy;
    QDateEdit *dateNgayVaoCongTy;
    QLabel *lblViTriCongViec;
    QLineEdit *txtViTriCongViec;
    QLabel *lblPhongBan;
    QComboBox *cmbPhongBan;
    QLabel *lblTrinhDoHocVan;
    QLineEdit *txtTrinhDoHocVan;
    QLabel *lblChuyenNganh;
    QLineEdit *txtChuyenNganh;
    QLabel *lblSectionSalary;
    QFormLayout *formLayoutType;
    QLabel *lblLoaiNhanSu;
    QComboBox *cmbLoaiNhanSu;
    QWidget *groupThuViec;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayoutThuViec;
    QLabel *lblPhuCapThucTap;
    QDoubleSpinBox *spinPhuCapThucTap;
    QWidget *groupChinhThuc;
    QVBoxLayout *verticalLayout_4;
    QFormLayout *formLayoutChinhThuc;
    QLabel *lblLuongCoBan_CT;
    QDoubleSpinBox *spinLuongCoBan_CT;
    QLabel *lblHeSoLuong_CT;
    QDoubleSpinBox *spinHeSoLuong_CT;
    QLabel *lblPhuCapChucVu_CT;
    QDoubleSpinBox *spinPhuCapChucVu_CT;
    QLabel *lblPhuCapAnTrua;
    QDoubleSpinBox *spinPhuCapAnTrua;
    QLabel *lblPhuCapXangXe;
    QDoubleSpinBox *spinPhuCapXangXe;
    QWidget *groupQuanLy;
    QVBoxLayout *verticalLayout_5;
    QFormLayout *formLayoutQuanLy;
    QLabel *lblLuongCoBan_QL;
    QDoubleSpinBox *spinLuongCoBan_QL;
    QLabel *lblHeSoLuong_QL;
    QDoubleSpinBox *spinHeSoLuong_QL;
    QLabel *lblPhuCapQuanLy;
    QDoubleSpinBox *spinPhuCapQuanLy;
    QLabel *lblThuongHieuQua;
    QDoubleSpinBox *spinThuongHieuQua;
    QGroupBox *groupThanNhan;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableThanNhan;
    QFormLayout *formLayoutThanNhan;
    QLabel *lblTenThanNhan;
    QLineEdit *txtTenThanNhan;
    QLabel *lblQuanHe;
    QLineEdit *txtQuanHe;
    QLabel *lblSdtThanNhan;
    QLineEdit *txtSdtThanNhan;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnThemThanNhan;
    QPushButton *btnXoaThanNhan;
    QSpacerItem *verticalSpacer;
    QLabel *lblStatus;
    QPushButton *btnThem;

    void setupUi(QDialog *GD_Them)
    {
        if (GD_Them->objectName().isEmpty())
            GD_Them->setObjectName("GD_Them");
        GD_Them->resize(1280, 800);
        GD_Them->setStyleSheet(QString::fromUtf8("/* --- Main Window Style --- */\n"
"#centralwidget {\n"
"	background-color: #f4f7fc;\n"
"}\n"
"\n"
"QWidget {\n"
"	font-family: \"Segoe UI\", Arial, sans-serif;\n"
"	font-size: 11pt;\n"
"}\n"
"\n"
"/* --- ScrollArea --- */\n"
"QScrollArea {\n"
"	border: none;\n"
"}\n"
"\n"
"/* --- Form Title --- */\n"
"#lblFormTitle {\n"
"	font-size: 20pt;\n"
"	font-weight: bold;\n"
"	color: #2c3e50;\n"
"	qproperty-alignment: 'AlignCenter';\n"
"	margin-bottom: 25px;\n"
"	margin-top: 15px;\n"
"}\n"
"\n"
"/* --- Section Labels --- */\n"
".SectionLabel {\n"
"    font-size: 13pt;\n"
"    font-weight: bold;\n"
"    color: #34495e;\n"
"    margin-top: 20px;\n"
"    margin-bottom: 5px;\n"
"    border-bottom: 2px solid #bdc3c7;\n"
"    padding-bottom: 5px;\n"
"}\n"
"\n"
"\n"
"/* --- Input Fields --- */\n"
"QLineEdit, QComboBox, QDateEdit, QDoubleSpinBox {\n"
"	background-color: #ffffff;\n"
"	border: 1px solid #dde1e7;\n"
"	border-radius: 8px;\n"
"	padding: 10px 15px;\n"
"	font-size: 11pt;\n"
"	min-height: 28px;\n"
"}\n"
"QLineEdit:foc"
                        "us, QComboBox:focus, QDateEdit:focus, QDoubleSpinBox:focus {\n"
"	border: 2px solid #27ae60;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 20px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: #dde1e7;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/qt-project.org/styles/commonstyle/images/down-arrow-16.png);\n"
"}\n"
"\n"
"\n"
"/* --- Add Button --- */\n"
"#btnThem {\n"
"	background-color: #27ae60;\n"
"	color: white;\n"
"	font-size: 14pt;\n"
"	font-weight: bold;\n"
"	border: none;\n"
"	border-radius: 20px;\n"
"	min-height: 50px;\n"
"	min-width: 250px;\n"
"	margin-top: 25px;\n"
"}\n"
"#btnThem:hover {\n"
"	background-color: #229954;\n"
"}\n"
"#btnThem:pressed {\n"
"	background-color: #1e8449;\n"
"}\n"
"\n"
"/* --- Status/Error Message Label --- */\n"
"#lblStatus {\n"
"	color: #e74c3c;\n"
"	font-"
                        "size: 11pt;\n"
"	qproperty-alignment: 'AlignCenter';\n"
"	min-height: 25px;\n"
"}\n"
"\n"
"/* --- Table Widget --- */\n"
"QTableWidget {\n"
"    border: 1px solid #dde1e7;\n"
"    border-radius: 8px;\n"
"    gridline-color: #e0e0e0;\n"
"}\n"
"QHeaderView::section {\n"
"    background-color: #f8f9fa;\n"
"    padding: 8px;\n"
"    border: none;\n"
"    border-bottom: 1px solid #dde1e7;\n"
"    font-weight: bold;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(GD_Them);
        verticalLayout->setObjectName("verticalLayout");
        scrollArea = new QScrollArea(GD_Them);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        mainLayout = new QVBoxLayout(scrollAreaWidgetContents);
        mainLayout->setSpacing(15);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(150, 20, 150, 50);
        lblFormTitle = new QLabel(scrollAreaWidgetContents);
        lblFormTitle->setObjectName("lblFormTitle");

        mainLayout->addWidget(lblFormTitle);

        lblSectionAccountInfo = new QLabel(scrollAreaWidgetContents);
        lblSectionAccountInfo->setObjectName("lblSectionAccountInfo");

        mainLayout->addWidget(lblSectionAccountInfo);

        formLayoutAccount = new QFormLayout();
        formLayoutAccount->setObjectName("formLayoutAccount");
        formLayoutAccount->setHorizontalSpacing(20);
        formLayoutAccount->setVerticalSpacing(12);
        lblUsername = new QLabel(scrollAreaWidgetContents);
        lblUsername->setObjectName("lblUsername");

        formLayoutAccount->setWidget(0, QFormLayout::ItemRole::LabelRole, lblUsername);

        txtUsername = new QLineEdit(scrollAreaWidgetContents);
        txtUsername->setObjectName("txtUsername");

        formLayoutAccount->setWidget(0, QFormLayout::ItemRole::FieldRole, txtUsername);

        lblPassword = new QLabel(scrollAreaWidgetContents);
        lblPassword->setObjectName("lblPassword");

        formLayoutAccount->setWidget(1, QFormLayout::ItemRole::LabelRole, lblPassword);

        txtPassword = new QLineEdit(scrollAreaWidgetContents);
        txtPassword->setObjectName("txtPassword");
        txtPassword->setEchoMode(QLineEdit::EchoMode::Password);

        formLayoutAccount->setWidget(1, QFormLayout::ItemRole::FieldRole, txtPassword);

        lblConfirmPassword = new QLabel(scrollAreaWidgetContents);
        lblConfirmPassword->setObjectName("lblConfirmPassword");

        formLayoutAccount->setWidget(2, QFormLayout::ItemRole::LabelRole, lblConfirmPassword);

        txtConfirmPassword = new QLineEdit(scrollAreaWidgetContents);
        txtConfirmPassword->setObjectName("txtConfirmPassword");
        txtConfirmPassword->setEchoMode(QLineEdit::EchoMode::Password);

        formLayoutAccount->setWidget(2, QFormLayout::ItemRole::FieldRole, txtConfirmPassword);


        mainLayout->addLayout(formLayoutAccount);

        lblSectionBasicInfo = new QLabel(scrollAreaWidgetContents);
        lblSectionBasicInfo->setObjectName("lblSectionBasicInfo");

        mainLayout->addWidget(lblSectionBasicInfo);

        formLayoutBasic = new QFormLayout();
        formLayoutBasic->setObjectName("formLayoutBasic");
        formLayoutBasic->setHorizontalSpacing(20);
        formLayoutBasic->setVerticalSpacing(12);
        lblMaNhanVien = new QLabel(scrollAreaWidgetContents);
        lblMaNhanVien->setObjectName("lblMaNhanVien");

        formLayoutBasic->setWidget(0, QFormLayout::ItemRole::LabelRole, lblMaNhanVien);

        txtMaNhanVien = new QLineEdit(scrollAreaWidgetContents);
        txtMaNhanVien->setObjectName("txtMaNhanVien");

        formLayoutBasic->setWidget(0, QFormLayout::ItemRole::FieldRole, txtMaNhanVien);

        lblHoTen = new QLabel(scrollAreaWidgetContents);
        lblHoTen->setObjectName("lblHoTen");

        formLayoutBasic->setWidget(1, QFormLayout::ItemRole::LabelRole, lblHoTen);

        txtHoTen = new QLineEdit(scrollAreaWidgetContents);
        txtHoTen->setObjectName("txtHoTen");

        formLayoutBasic->setWidget(1, QFormLayout::ItemRole::FieldRole, txtHoTen);

        lblCCCD = new QLabel(scrollAreaWidgetContents);
        lblCCCD->setObjectName("lblCCCD");

        formLayoutBasic->setWidget(2, QFormLayout::ItemRole::LabelRole, lblCCCD);

        txtCCCD = new QLineEdit(scrollAreaWidgetContents);
        txtCCCD->setObjectName("txtCCCD");

        formLayoutBasic->setWidget(2, QFormLayout::ItemRole::FieldRole, txtCCCD);

        lblNgaySinh = new QLabel(scrollAreaWidgetContents);
        lblNgaySinh->setObjectName("lblNgaySinh");

        formLayoutBasic->setWidget(3, QFormLayout::ItemRole::LabelRole, lblNgaySinh);

        dateNgaySinh = new QDateEdit(scrollAreaWidgetContents);
        dateNgaySinh->setObjectName("dateNgaySinh");
        dateNgaySinh->setCalendarPopup(true);

        formLayoutBasic->setWidget(3, QFormLayout::ItemRole::FieldRole, dateNgaySinh);

        lblGioiTinh = new QLabel(scrollAreaWidgetContents);
        lblGioiTinh->setObjectName("lblGioiTinh");

        formLayoutBasic->setWidget(4, QFormLayout::ItemRole::LabelRole, lblGioiTinh);

        cmbGioiTinh = new QComboBox(scrollAreaWidgetContents);
        cmbGioiTinh->addItem(QString());
        cmbGioiTinh->addItem(QString());
        cmbGioiTinh->setObjectName("cmbGioiTinh");

        formLayoutBasic->setWidget(4, QFormLayout::ItemRole::FieldRole, cmbGioiTinh);


        mainLayout->addLayout(formLayoutBasic);

        lblSectionContact = new QLabel(scrollAreaWidgetContents);
        lblSectionContact->setObjectName("lblSectionContact");

        mainLayout->addWidget(lblSectionContact);

        formLayoutContact = new QFormLayout();
        formLayoutContact->setObjectName("formLayoutContact");
        formLayoutContact->setHorizontalSpacing(20);
        formLayoutContact->setVerticalSpacing(12);
        lblSoDienThoai = new QLabel(scrollAreaWidgetContents);
        lblSoDienThoai->setObjectName("lblSoDienThoai");

        formLayoutContact->setWidget(0, QFormLayout::ItemRole::LabelRole, lblSoDienThoai);

        txtSoDienThoai = new QLineEdit(scrollAreaWidgetContents);
        txtSoDienThoai->setObjectName("txtSoDienThoai");

        formLayoutContact->setWidget(0, QFormLayout::ItemRole::FieldRole, txtSoDienThoai);

        lblEmail = new QLabel(scrollAreaWidgetContents);
        lblEmail->setObjectName("lblEmail");

        formLayoutContact->setWidget(1, QFormLayout::ItemRole::LabelRole, lblEmail);

        txtEmail = new QLineEdit(scrollAreaWidgetContents);
        txtEmail->setObjectName("txtEmail");

        formLayoutContact->setWidget(1, QFormLayout::ItemRole::FieldRole, txtEmail);

        lblDiaChi = new QLabel(scrollAreaWidgetContents);
        lblDiaChi->setObjectName("lblDiaChi");

        formLayoutContact->setWidget(2, QFormLayout::ItemRole::LabelRole, lblDiaChi);

        txtDiaChi = new QLineEdit(scrollAreaWidgetContents);
        txtDiaChi->setObjectName("txtDiaChi");

        formLayoutContact->setWidget(2, QFormLayout::ItemRole::FieldRole, txtDiaChi);

        lblSoTaiKhoan = new QLabel(scrollAreaWidgetContents);
        lblSoTaiKhoan->setObjectName("lblSoTaiKhoan");

        formLayoutContact->setWidget(3, QFormLayout::ItemRole::LabelRole, lblSoTaiKhoan);

        txtSoTaiKhoan = new QLineEdit(scrollAreaWidgetContents);
        txtSoTaiKhoan->setObjectName("txtSoTaiKhoan");

        formLayoutContact->setWidget(3, QFormLayout::ItemRole::FieldRole, txtSoTaiKhoan);

        lblTenNganHang = new QLabel(scrollAreaWidgetContents);
        lblTenNganHang->setObjectName("lblTenNganHang");

        formLayoutContact->setWidget(4, QFormLayout::ItemRole::LabelRole, lblTenNganHang);

        txtTenNganHang = new QLineEdit(scrollAreaWidgetContents);
        txtTenNganHang->setObjectName("txtTenNganHang");

        formLayoutContact->setWidget(4, QFormLayout::ItemRole::FieldRole, txtTenNganHang);


        mainLayout->addLayout(formLayoutContact);

        lblSectionJobInfo = new QLabel(scrollAreaWidgetContents);
        lblSectionJobInfo->setObjectName("lblSectionJobInfo");

        mainLayout->addWidget(lblSectionJobInfo);

        formLayoutJob = new QFormLayout();
        formLayoutJob->setObjectName("formLayoutJob");
        formLayoutJob->setHorizontalSpacing(20);
        formLayoutJob->setVerticalSpacing(12);
        lblNgayVaoCongTy = new QLabel(scrollAreaWidgetContents);
        lblNgayVaoCongTy->setObjectName("lblNgayVaoCongTy");

        formLayoutJob->setWidget(0, QFormLayout::ItemRole::LabelRole, lblNgayVaoCongTy);

        dateNgayVaoCongTy = new QDateEdit(scrollAreaWidgetContents);
        dateNgayVaoCongTy->setObjectName("dateNgayVaoCongTy");
        dateNgayVaoCongTy->setCalendarPopup(true);

        formLayoutJob->setWidget(0, QFormLayout::ItemRole::FieldRole, dateNgayVaoCongTy);

        lblViTriCongViec = new QLabel(scrollAreaWidgetContents);
        lblViTriCongViec->setObjectName("lblViTriCongViec");

        formLayoutJob->setWidget(1, QFormLayout::ItemRole::LabelRole, lblViTriCongViec);

        txtViTriCongViec = new QLineEdit(scrollAreaWidgetContents);
        txtViTriCongViec->setObjectName("txtViTriCongViec");

        formLayoutJob->setWidget(1, QFormLayout::ItemRole::FieldRole, txtViTriCongViec);

        lblPhongBan = new QLabel(scrollAreaWidgetContents);
        lblPhongBan->setObjectName("lblPhongBan");

        formLayoutJob->setWidget(2, QFormLayout::ItemRole::LabelRole, lblPhongBan);

        cmbPhongBan = new QComboBox(scrollAreaWidgetContents);
        cmbPhongBan->setObjectName("cmbPhongBan");

        formLayoutJob->setWidget(2, QFormLayout::ItemRole::FieldRole, cmbPhongBan);

        lblTrinhDoHocVan = new QLabel(scrollAreaWidgetContents);
        lblTrinhDoHocVan->setObjectName("lblTrinhDoHocVan");

        formLayoutJob->setWidget(3, QFormLayout::ItemRole::LabelRole, lblTrinhDoHocVan);

        txtTrinhDoHocVan = new QLineEdit(scrollAreaWidgetContents);
        txtTrinhDoHocVan->setObjectName("txtTrinhDoHocVan");

        formLayoutJob->setWidget(3, QFormLayout::ItemRole::FieldRole, txtTrinhDoHocVan);

        lblChuyenNganh = new QLabel(scrollAreaWidgetContents);
        lblChuyenNganh->setObjectName("lblChuyenNganh");

        formLayoutJob->setWidget(4, QFormLayout::ItemRole::LabelRole, lblChuyenNganh);

        txtChuyenNganh = new QLineEdit(scrollAreaWidgetContents);
        txtChuyenNganh->setObjectName("txtChuyenNganh");

        formLayoutJob->setWidget(4, QFormLayout::ItemRole::FieldRole, txtChuyenNganh);


        mainLayout->addLayout(formLayoutJob);

        lblSectionSalary = new QLabel(scrollAreaWidgetContents);
        lblSectionSalary->setObjectName("lblSectionSalary");

        mainLayout->addWidget(lblSectionSalary);

        formLayoutType = new QFormLayout();
        formLayoutType->setObjectName("formLayoutType");
        formLayoutType->setHorizontalSpacing(20);
        formLayoutType->setVerticalSpacing(12);
        lblLoaiNhanSu = new QLabel(scrollAreaWidgetContents);
        lblLoaiNhanSu->setObjectName("lblLoaiNhanSu");

        formLayoutType->setWidget(0, QFormLayout::ItemRole::LabelRole, lblLoaiNhanSu);

        cmbLoaiNhanSu = new QComboBox(scrollAreaWidgetContents);
        cmbLoaiNhanSu->addItem(QString());
        cmbLoaiNhanSu->addItem(QString());
        cmbLoaiNhanSu->addItem(QString());
        cmbLoaiNhanSu->setObjectName("cmbLoaiNhanSu");

        formLayoutType->setWidget(0, QFormLayout::ItemRole::FieldRole, cmbLoaiNhanSu);


        mainLayout->addLayout(formLayoutType);

        groupThuViec = new QWidget(scrollAreaWidgetContents);
        groupThuViec->setObjectName("groupThuViec");
        verticalLayout_3 = new QVBoxLayout(groupThuViec);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        formLayoutThuViec = new QFormLayout();
        formLayoutThuViec->setObjectName("formLayoutThuViec");
        formLayoutThuViec->setHorizontalSpacing(20);
        formLayoutThuViec->setVerticalSpacing(12);
        lblPhuCapThucTap = new QLabel(groupThuViec);
        lblPhuCapThucTap->setObjectName("lblPhuCapThucTap");

        formLayoutThuViec->setWidget(0, QFormLayout::ItemRole::LabelRole, lblPhuCapThucTap);

        spinPhuCapThucTap = new QDoubleSpinBox(groupThuViec);
        spinPhuCapThucTap->setObjectName("spinPhuCapThucTap");
        spinPhuCapThucTap->setMaximum(999999999.989999890327454);

        formLayoutThuViec->setWidget(0, QFormLayout::ItemRole::FieldRole, spinPhuCapThucTap);


        verticalLayout_3->addLayout(formLayoutThuViec);


        mainLayout->addWidget(groupThuViec);

        groupChinhThuc = new QWidget(scrollAreaWidgetContents);
        groupChinhThuc->setObjectName("groupChinhThuc");
        verticalLayout_4 = new QVBoxLayout(groupChinhThuc);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        formLayoutChinhThuc = new QFormLayout();
        formLayoutChinhThuc->setObjectName("formLayoutChinhThuc");
        formLayoutChinhThuc->setHorizontalSpacing(20);
        formLayoutChinhThuc->setVerticalSpacing(12);
        lblLuongCoBan_CT = new QLabel(groupChinhThuc);
        lblLuongCoBan_CT->setObjectName("lblLuongCoBan_CT");

        formLayoutChinhThuc->setWidget(0, QFormLayout::ItemRole::LabelRole, lblLuongCoBan_CT);

        spinLuongCoBan_CT = new QDoubleSpinBox(groupChinhThuc);
        spinLuongCoBan_CT->setObjectName("spinLuongCoBan_CT");
        spinLuongCoBan_CT->setMaximum(999999999.989999890327454);

        formLayoutChinhThuc->setWidget(0, QFormLayout::ItemRole::FieldRole, spinLuongCoBan_CT);

        lblHeSoLuong_CT = new QLabel(groupChinhThuc);
        lblHeSoLuong_CT->setObjectName("lblHeSoLuong_CT");

        formLayoutChinhThuc->setWidget(1, QFormLayout::ItemRole::LabelRole, lblHeSoLuong_CT);

        spinHeSoLuong_CT = new QDoubleSpinBox(groupChinhThuc);
        spinHeSoLuong_CT->setObjectName("spinHeSoLuong_CT");
        spinHeSoLuong_CT->setDecimals(2);
        spinHeSoLuong_CT->setMinimum(1.000000000000000);
        spinHeSoLuong_CT->setMaximum(10.000000000000000);
        spinHeSoLuong_CT->setSingleStep(0.010000000000000);

        formLayoutChinhThuc->setWidget(1, QFormLayout::ItemRole::FieldRole, spinHeSoLuong_CT);

        lblPhuCapChucVu_CT = new QLabel(groupChinhThuc);
        lblPhuCapChucVu_CT->setObjectName("lblPhuCapChucVu_CT");

        formLayoutChinhThuc->setWidget(2, QFormLayout::ItemRole::LabelRole, lblPhuCapChucVu_CT);

        spinPhuCapChucVu_CT = new QDoubleSpinBox(groupChinhThuc);
        spinPhuCapChucVu_CT->setObjectName("spinPhuCapChucVu_CT");
        spinPhuCapChucVu_CT->setMaximum(999999999.989999890327454);

        formLayoutChinhThuc->setWidget(2, QFormLayout::ItemRole::FieldRole, spinPhuCapChucVu_CT);

        lblPhuCapAnTrua = new QLabel(groupChinhThuc);
        lblPhuCapAnTrua->setObjectName("lblPhuCapAnTrua");

        formLayoutChinhThuc->setWidget(3, QFormLayout::ItemRole::LabelRole, lblPhuCapAnTrua);

        spinPhuCapAnTrua = new QDoubleSpinBox(groupChinhThuc);
        spinPhuCapAnTrua->setObjectName("spinPhuCapAnTrua");
        spinPhuCapAnTrua->setMaximum(999999999.989999890327454);

        formLayoutChinhThuc->setWidget(3, QFormLayout::ItemRole::FieldRole, spinPhuCapAnTrua);

        lblPhuCapXangXe = new QLabel(groupChinhThuc);
        lblPhuCapXangXe->setObjectName("lblPhuCapXangXe");

        formLayoutChinhThuc->setWidget(4, QFormLayout::ItemRole::LabelRole, lblPhuCapXangXe);

        spinPhuCapXangXe = new QDoubleSpinBox(groupChinhThuc);
        spinPhuCapXangXe->setObjectName("spinPhuCapXangXe");
        spinPhuCapXangXe->setMaximum(999999999.989999890327454);

        formLayoutChinhThuc->setWidget(4, QFormLayout::ItemRole::FieldRole, spinPhuCapXangXe);


        verticalLayout_4->addLayout(formLayoutChinhThuc);


        mainLayout->addWidget(groupChinhThuc);

        groupQuanLy = new QWidget(scrollAreaWidgetContents);
        groupQuanLy->setObjectName("groupQuanLy");
        verticalLayout_5 = new QVBoxLayout(groupQuanLy);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        formLayoutQuanLy = new QFormLayout();
        formLayoutQuanLy->setObjectName("formLayoutQuanLy");
        formLayoutQuanLy->setHorizontalSpacing(20);
        formLayoutQuanLy->setVerticalSpacing(12);
        lblLuongCoBan_QL = new QLabel(groupQuanLy);
        lblLuongCoBan_QL->setObjectName("lblLuongCoBan_QL");

        formLayoutQuanLy->setWidget(0, QFormLayout::ItemRole::LabelRole, lblLuongCoBan_QL);

        spinLuongCoBan_QL = new QDoubleSpinBox(groupQuanLy);
        spinLuongCoBan_QL->setObjectName("spinLuongCoBan_QL");
        spinLuongCoBan_QL->setMaximum(999999999.989999890327454);

        formLayoutQuanLy->setWidget(0, QFormLayout::ItemRole::FieldRole, spinLuongCoBan_QL);

        lblHeSoLuong_QL = new QLabel(groupQuanLy);
        lblHeSoLuong_QL->setObjectName("lblHeSoLuong_QL");

        formLayoutQuanLy->setWidget(1, QFormLayout::ItemRole::LabelRole, lblHeSoLuong_QL);

        spinHeSoLuong_QL = new QDoubleSpinBox(groupQuanLy);
        spinHeSoLuong_QL->setObjectName("spinHeSoLuong_QL");
        spinHeSoLuong_QL->setDecimals(2);
        spinHeSoLuong_QL->setMinimum(1.000000000000000);
        spinHeSoLuong_QL->setMaximum(10.000000000000000);
        spinHeSoLuong_QL->setSingleStep(0.010000000000000);

        formLayoutQuanLy->setWidget(1, QFormLayout::ItemRole::FieldRole, spinHeSoLuong_QL);

        lblPhuCapQuanLy = new QLabel(groupQuanLy);
        lblPhuCapQuanLy->setObjectName("lblPhuCapQuanLy");

        formLayoutQuanLy->setWidget(2, QFormLayout::ItemRole::LabelRole, lblPhuCapQuanLy);

        spinPhuCapQuanLy = new QDoubleSpinBox(groupQuanLy);
        spinPhuCapQuanLy->setObjectName("spinPhuCapQuanLy");
        spinPhuCapQuanLy->setMaximum(999999999.989999890327454);

        formLayoutQuanLy->setWidget(2, QFormLayout::ItemRole::FieldRole, spinPhuCapQuanLy);

        lblThuongHieuQua = new QLabel(groupQuanLy);
        lblThuongHieuQua->setObjectName("lblThuongHieuQua");

        formLayoutQuanLy->setWidget(3, QFormLayout::ItemRole::LabelRole, lblThuongHieuQua);

        spinThuongHieuQua = new QDoubleSpinBox(groupQuanLy);
        spinThuongHieuQua->setObjectName("spinThuongHieuQua");
        spinThuongHieuQua->setMaximum(999999999.989999890327454);

        formLayoutQuanLy->setWidget(3, QFormLayout::ItemRole::FieldRole, spinThuongHieuQua);


        verticalLayout_5->addLayout(formLayoutQuanLy);


        mainLayout->addWidget(groupQuanLy);

        groupThanNhan = new QGroupBox(scrollAreaWidgetContents);
        groupThanNhan->setObjectName("groupThanNhan");
        verticalLayout_2 = new QVBoxLayout(groupThanNhan);
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setObjectName("verticalLayout_2");
        tableThanNhan = new QTableWidget(groupThanNhan);
        if (tableThanNhan->columnCount() < 3)
            tableThanNhan->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableThanNhan->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableThanNhan->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableThanNhan->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableThanNhan->setObjectName("tableThanNhan");
        tableThanNhan->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableThanNhan->setSelectionMode(QAbstractItemView::SingleSelection);
        tableThanNhan->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableThanNhan->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_2->addWidget(tableThanNhan);

        formLayoutThanNhan = new QFormLayout();
        formLayoutThanNhan->setObjectName("formLayoutThanNhan");
        lblTenThanNhan = new QLabel(groupThanNhan);
        lblTenThanNhan->setObjectName("lblTenThanNhan");

        formLayoutThanNhan->setWidget(0, QFormLayout::ItemRole::LabelRole, lblTenThanNhan);

        txtTenThanNhan = new QLineEdit(groupThanNhan);
        txtTenThanNhan->setObjectName("txtTenThanNhan");

        formLayoutThanNhan->setWidget(0, QFormLayout::ItemRole::FieldRole, txtTenThanNhan);

        lblQuanHe = new QLabel(groupThanNhan);
        lblQuanHe->setObjectName("lblQuanHe");

        formLayoutThanNhan->setWidget(1, QFormLayout::ItemRole::LabelRole, lblQuanHe);

        txtQuanHe = new QLineEdit(groupThanNhan);
        txtQuanHe->setObjectName("txtQuanHe");

        formLayoutThanNhan->setWidget(1, QFormLayout::ItemRole::FieldRole, txtQuanHe);

        lblSdtThanNhan = new QLabel(groupThanNhan);
        lblSdtThanNhan->setObjectName("lblSdtThanNhan");

        formLayoutThanNhan->setWidget(2, QFormLayout::ItemRole::LabelRole, lblSdtThanNhan);

        txtSdtThanNhan = new QLineEdit(groupThanNhan);
        txtSdtThanNhan->setObjectName("txtSdtThanNhan");

        formLayoutThanNhan->setWidget(2, QFormLayout::ItemRole::FieldRole, txtSdtThanNhan);


        verticalLayout_2->addLayout(formLayoutThanNhan);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnThemThanNhan = new QPushButton(groupThanNhan);
        btnThemThanNhan->setObjectName("btnThemThanNhan");

        horizontalLayout->addWidget(btnThemThanNhan);

        btnXoaThanNhan = new QPushButton(groupThanNhan);
        btnXoaThanNhan->setObjectName("btnXoaThanNhan");

        horizontalLayout->addWidget(btnXoaThanNhan);


        verticalLayout_2->addLayout(horizontalLayout);


        mainLayout->addWidget(groupThanNhan);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        mainLayout->addItem(verticalSpacer);

        lblStatus = new QLabel(scrollAreaWidgetContents);
        lblStatus->setObjectName("lblStatus");

        mainLayout->addWidget(lblStatus, 0, Qt::AlignHCenter);

        btnThem = new QPushButton(scrollAreaWidgetContents);
        btnThem->setObjectName("btnThem");

        mainLayout->addWidget(btnThem, 0, Qt::AlignHCenter);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(GD_Them);

        QMetaObject::connectSlotsByName(GD_Them);
    } // setupUi

    void retranslateUi(QDialog *GD_Them)
    {
        GD_Them->setWindowTitle(QCoreApplication::translate("GD_Them", "Th\303\252m nh\303\242n s\341\273\261", nullptr));
        lblFormTitle->setText(QCoreApplication::translate("GD_Them", "Th\303\252m Nh\303\242n S\341\273\261 M\341\273\233i", nullptr));
        lblSectionAccountInfo->setText(QCoreApplication::translate("GD_Them", "Th\303\264ng tin t\303\240i kho\341\272\243n", nullptr));
        lblSectionAccountInfo->setProperty("class", QVariant(QCoreApplication::translate("GD_Them", "SectionLabel", nullptr)));
        lblUsername->setText(QCoreApplication::translate("GD_Them", "T\303\252n t\303\240i kho\341\272\243n:", nullptr));
        txtUsername->setPlaceholderText(QCoreApplication::translate("GD_Them", "Nh\341\272\255p t\303\252n t\303\240i kho\341\272\243n \304\221\341\273\203 \304\221\304\203ng nh\341\272\255p", nullptr));
        lblPassword->setText(QCoreApplication::translate("GD_Them", "M\341\272\255t kh\341\272\251u:", nullptr));
        txtPassword->setPlaceholderText(QCoreApplication::translate("GD_Them", "Nh\341\272\255p m\341\272\255t kh\341\272\251u", nullptr));
        lblConfirmPassword->setText(QCoreApplication::translate("GD_Them", "X\303\241c nh\341\272\255n m\341\272\255t kh\341\272\251u:", nullptr));
        txtConfirmPassword->setPlaceholderText(QCoreApplication::translate("GD_Them", "Nh\341\272\255p l\341\272\241i m\341\272\255t kh\341\272\251u", nullptr));
        lblSectionBasicInfo->setText(QCoreApplication::translate("GD_Them", "Th\303\264ng tin c\306\241 b\341\272\243n c\341\273\247a nh\303\242n s\341\273\261", nullptr));
        lblSectionBasicInfo->setProperty("class", QVariant(QCoreApplication::translate("GD_Them", "SectionLabel", nullptr)));
        lblMaNhanVien->setText(QCoreApplication::translate("GD_Them", "M\303\243 nh\303\242n vi\303\252n:", nullptr));
        txtMaNhanVien->setPlaceholderText(QCoreApplication::translate("GD_Them", "M\303\243 nh\303\242n vi\303\252n s\341\272\275 \304\221\306\260\341\273\243c t\341\273\261 \304\221\341\273\231ng \304\221i\341\273\201n", nullptr));
        lblHoTen->setText(QCoreApplication::translate("GD_Them", "H\341\273\215 v\303\240 t\303\252n:", nullptr));
        txtHoTen->setPlaceholderText(QCoreApplication::translate("GD_Them", "Nh\341\272\255p h\341\273\215 v\303\240 t\303\252n \304\221\341\272\247y \304\221\341\273\247", nullptr));
        lblCCCD->setText(QCoreApplication::translate("GD_Them", "S\341\273\221 CCCD:", nullptr));
        txtCCCD->setPlaceholderText(QCoreApplication::translate("GD_Them", "Nh\341\272\255p s\341\273\221 C\304\203n c\306\260\341\273\233c c\303\264ng d\303\242n", nullptr));
        lblNgaySinh->setText(QCoreApplication::translate("GD_Them", "Ng\303\240y sinh:", nullptr));
        dateNgaySinh->setDisplayFormat(QCoreApplication::translate("GD_Them", "dd/MM/yyyy", nullptr));
        lblGioiTinh->setText(QCoreApplication::translate("GD_Them", "Gi\341\273\233i t\303\255nh:", nullptr));
        cmbGioiTinh->setItemText(0, QCoreApplication::translate("GD_Them", "Nam", nullptr));
        cmbGioiTinh->setItemText(1, QCoreApplication::translate("GD_Them", "N\341\273\257", nullptr));

        lblSectionContact->setText(QCoreApplication::translate("GD_Them", "Th\303\264ng tin li\303\252n h\341\273\207 & Ng\303\242n h\303\240ng", nullptr));
        lblSectionContact->setProperty("class", QVariant(QCoreApplication::translate("GD_Them", "SectionLabel", nullptr)));
        lblSoDienThoai->setText(QCoreApplication::translate("GD_Them", "S\341\273\221 \304\221i\341\273\207n tho\341\272\241i:", nullptr));
        txtSoDienThoai->setPlaceholderText(QCoreApplication::translate("GD_Them", "Nh\341\272\255p s\341\273\221 \304\221i\341\273\207n tho\341\272\241i", nullptr));
        lblEmail->setText(QCoreApplication::translate("GD_Them", "Email:", nullptr));
        txtEmail->setPlaceholderText(QCoreApplication::translate("GD_Them", "Nh\341\272\255p \304\221\341\273\213a ch\341\273\211 email", nullptr));
        lblDiaChi->setText(QCoreApplication::translate("GD_Them", "\304\220\341\273\213a ch\341\273\211:", nullptr));
        txtDiaChi->setPlaceholderText(QCoreApplication::translate("GD_Them", "Nh\341\272\255p \304\221\341\273\213a ch\341\273\211 hi\341\273\207n t\341\272\241i", nullptr));
        lblSoTaiKhoan->setText(QCoreApplication::translate("GD_Them", "S\341\273\221 t\303\240i kho\341\272\243n:", nullptr));
        txtSoTaiKhoan->setPlaceholderText(QCoreApplication::translate("GD_Them", "Nh\341\272\255p s\341\273\221 t\303\240i kho\341\272\243n ng\303\242n h\303\240ng", nullptr));
        lblTenNganHang->setText(QCoreApplication::translate("GD_Them", "T\303\252n ng\303\242n h\303\240ng:", nullptr));
        txtTenNganHang->setPlaceholderText(QCoreApplication::translate("GD_Them", "Nh\341\272\255p t\303\252n ng\303\242n h\303\240ng", nullptr));
        lblSectionJobInfo->setText(QCoreApplication::translate("GD_Them", "Th\303\264ng tin c\303\264ng vi\341\273\207c & H\341\273\215c v\341\272\245n", nullptr));
        lblSectionJobInfo->setProperty("class", QVariant(QCoreApplication::translate("GD_Them", "SectionLabel", nullptr)));
        lblNgayVaoCongTy->setText(QCoreApplication::translate("GD_Them", "Ng\303\240y v\303\240o c\303\264ng ty:", nullptr));
        dateNgayVaoCongTy->setDisplayFormat(QCoreApplication::translate("GD_Them", "dd/MM/yyyy", nullptr));
        lblViTriCongViec->setText(QCoreApplication::translate("GD_Them", "V\341\273\213 tr\303\255 c\303\264ng vi\341\273\207c:", nullptr));
        txtViTriCongViec->setPlaceholderText(QCoreApplication::translate("GD_Them", "Nh\341\272\255p v\341\273\213 tr\303\255 c\303\264ng vi\341\273\207c", nullptr));
        lblPhongBan->setText(QCoreApplication::translate("GD_Them", "Ph\303\262ng ban:", nullptr));
        lblTrinhDoHocVan->setText(QCoreApplication::translate("GD_Them", "Tr\303\254nh \304\221\341\273\231 h\341\273\215c v\341\272\245n:", nullptr));
        txtTrinhDoHocVan->setPlaceholderText(QCoreApplication::translate("GD_Them", "V\303\255 d\341\273\245: C\341\273\255 nh\303\242n, K\341\273\271 s\306\260,...", nullptr));
        lblChuyenNganh->setText(QCoreApplication::translate("GD_Them", "Chuy\303\252n ng\303\240nh:", nullptr));
        txtChuyenNganh->setPlaceholderText(QCoreApplication::translate("GD_Them", "V\303\255 d\341\273\245: C\303\264ng ngh\341\273\207 th\303\264ng tin, K\341\272\277 to\303\241n,...", nullptr));
        lblSectionSalary->setText(QCoreApplication::translate("GD_Them", "Th\303\264ng tin L\306\260\306\241ng & Lo\341\272\241i nh\303\242n s\341\273\261", nullptr));
        lblSectionSalary->setProperty("class", QVariant(QCoreApplication::translate("GD_Them", "SectionLabel", nullptr)));
        lblLoaiNhanSu->setText(QCoreApplication::translate("GD_Them", "Lo\341\272\241i nh\303\242n s\341\273\261:", nullptr));
        cmbLoaiNhanSu->setItemText(0, QCoreApplication::translate("GD_Them", "Nh\303\242n vi\303\252n th\341\273\255 vi\341\273\207c", nullptr));
        cmbLoaiNhanSu->setItemText(1, QCoreApplication::translate("GD_Them", "Nh\303\242n vi\303\252n ch\303\255nh th\341\273\251c", nullptr));
        cmbLoaiNhanSu->setItemText(2, QCoreApplication::translate("GD_Them", "Qu\341\272\243n l\303\275", nullptr));

        lblPhuCapThucTap->setText(QCoreApplication::translate("GD_Them", "Ph\341\273\245 c\341\272\245p th\341\273\261c t\341\272\255p:", nullptr));
        spinPhuCapThucTap->setSuffix(QCoreApplication::translate("GD_Them", " VN\304\220", nullptr));
        lblLuongCoBan_CT->setText(QCoreApplication::translate("GD_Them", "L\306\260\306\241ng c\306\241 b\341\272\243n:", nullptr));
        spinLuongCoBan_CT->setSuffix(QCoreApplication::translate("GD_Them", " VN\304\220", nullptr));
        lblHeSoLuong_CT->setText(QCoreApplication::translate("GD_Them", "H\341\273\207 s\341\273\221 l\306\260\306\241ng:", nullptr));
        lblPhuCapChucVu_CT->setText(QCoreApplication::translate("GD_Them", "Ph\341\273\245 c\341\272\245p ch\341\273\251c v\341\273\245:", nullptr));
        spinPhuCapChucVu_CT->setSuffix(QCoreApplication::translate("GD_Them", " VN\304\220", nullptr));
        lblPhuCapAnTrua->setText(QCoreApplication::translate("GD_Them", "Ph\341\273\245 c\341\272\245p \304\203n tr\306\260a:", nullptr));
        spinPhuCapAnTrua->setSuffix(QCoreApplication::translate("GD_Them", " VN\304\220", nullptr));
        lblPhuCapXangXe->setText(QCoreApplication::translate("GD_Them", "Ph\341\273\245 c\341\272\245p x\304\203ng xe:", nullptr));
        spinPhuCapXangXe->setSuffix(QCoreApplication::translate("GD_Them", " VN\304\220", nullptr));
        lblLuongCoBan_QL->setText(QCoreApplication::translate("GD_Them", "L\306\260\306\241ng c\306\241 b\341\272\243n:", nullptr));
        spinLuongCoBan_QL->setSuffix(QCoreApplication::translate("GD_Them", " VN\304\220", nullptr));
        lblHeSoLuong_QL->setText(QCoreApplication::translate("GD_Them", "H\341\273\207 s\341\273\221 l\306\260\306\241ng:", nullptr));
        lblPhuCapQuanLy->setText(QCoreApplication::translate("GD_Them", "Ph\341\273\245 c\341\272\245p qu\341\272\243n l\303\275:", nullptr));
        spinPhuCapQuanLy->setSuffix(QCoreApplication::translate("GD_Them", " VN\304\220", nullptr));
        lblThuongHieuQua->setText(QCoreApplication::translate("GD_Them", "Th\306\260\341\273\237ng hi\341\273\207u qu\341\272\243:", nullptr));
        spinThuongHieuQua->setSuffix(QCoreApplication::translate("GD_Them", " VN\304\220", nullptr));
        groupThanNhan->setTitle(QCoreApplication::translate("GD_Them", "Th\303\264ng tin th\303\242n nh\303\242n", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableThanNhan->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("GD_Them", "H\341\273\215 v\303\240 T\303\252n", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableThanNhan->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("GD_Them", "Quan h\341\273\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableThanNhan->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("GD_Them", "S\341\273\221 \304\221i\341\273\207n tho\341\272\241i", nullptr));
        lblTenThanNhan->setText(QCoreApplication::translate("GD_Them", "H\341\273\215 v\303\240 t\303\252n:", nullptr));
        txtTenThanNhan->setPlaceholderText(QCoreApplication::translate("GD_Them", "Nh\341\272\255p h\341\273\215 t\303\252n th\303\242n nh\303\242n", nullptr));
        lblQuanHe->setText(QCoreApplication::translate("GD_Them", "Quan h\341\273\207:", nullptr));
        txtQuanHe->setPlaceholderText(QCoreApplication::translate("GD_Them", "V\303\255 d\341\273\245: V\341\273\243, Ch\341\273\223ng, Con,...", nullptr));
        lblSdtThanNhan->setText(QCoreApplication::translate("GD_Them", "S\341\273\221 \304\221i\341\273\207n tho\341\272\241i:", nullptr));
        txtSdtThanNhan->setPlaceholderText(QCoreApplication::translate("GD_Them", "Nh\341\272\255p S\304\220T th\303\242n nh\303\242n", nullptr));
        btnThemThanNhan->setText(QCoreApplication::translate("GD_Them", "Th\303\252m Th\303\242n nh\303\242n", nullptr));
        btnXoaThanNhan->setText(QCoreApplication::translate("GD_Them", "X\303\263a Th\303\242n nh\303\242n", nullptr));
        btnThem->setText(QCoreApplication::translate("GD_Them", "Th\303\252m Nh\303\242n S\341\273\261", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GD_Them: public Ui_GD_Them {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GD_THEM_H
