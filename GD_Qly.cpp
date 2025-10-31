#include "GD_Qly.h"
#include "ui_GD_Qly.h"
#include "GD_Them.h"
#include "GD_NVChung.h"
#include "GD_QLPhongBan.h"
#include "GD_QLDuAn.h"
#include "NhanSuData.h"
#include "ClassNhanSu.h"
#include <QMessageBox>
#include <QHeaderView>
#include <QLocale>
#include <QDir>
#include <QDate>
#include <QFile>
#include <QTextStream>
#include <QDateEdit>
#include <QFileDialog>
#include <set>
#include <cmath>
#include <QProgressDialog>
GD_Qly::GD_Qly(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GD_Qly)
{
    ui->setupUi(this);

    // Thêm các widget con vào mainStackedWidget
    m_qlpbWidget = new GD_QLPhongBan(this);
    ui->mainStackedWidget->addWidget(m_qlpbWidget);
    m_qlduAnWidget = new GD_QLDuAn(this);
    ui->mainStackedWidget->addWidget(m_qlduAnWidget);
    ui->btnNavSettings->setVisible(false);

    setupTable();

    // Tải dữ liệu
    loadNhanSuData();
    displayNhanSuTable(g_danhSachNhanSu);
    loadNhanVienListToComboBox();
    docDuAnTuFile();
    docPhongBanTuFile();
    docYeuCauNghiPhepTuFile();

    // Tải dữ liệu cho các ComboBox
    loadFilterComboBoxes();

    // Thiết lập cho trang Chấm công
    ui->dateEditChamCong->setDate(QDate::currentDate());
    ui->tableChamCongTongHop->setColumnCount(6);
    ui->tableChamCongTongHop->setHorizontalHeaderLabels(QStringList()
                                                        << "Ngày"
                                                        << "Mã NV"
                                                        << "Họ và Tên"
                                                        << "Giờ vào"
                                                        << "Giờ ra"
                                                        << "Trạng thái");

    QHeaderView *headerCC = ui->tableChamCongTongHop->horizontalHeader();
    headerCC->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    headerCC->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    headerCC->setSectionResizeMode(2, QHeaderView::Stretch);
    headerCC->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    headerCC->setSectionResizeMode(4, QHeaderView::ResizeToContents);
    headerCC->setSectionResizeMode(5, QHeaderView::ResizeToContents);

    // Thiết lập cho trang Duyệt nghỉ
    ui->tableLeaveRequests->setColumnCount(8);
    QHeaderView *headerLeave = ui->tableLeaveRequests->horizontalHeader();
    headerLeave->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    headerLeave->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    headerLeave->setSectionResizeMode(2, QHeaderView::Stretch);
    headerLeave->setSectionResizeMode(5, QHeaderView::Stretch);
    headerLeave->setSectionResizeMode(6, QHeaderView::ResizeToContents);
    headerLeave->setSectionResizeMode(7, QHeaderView::ResizeToContents);

    // Kết nối các slot
    ui->btnLoadChamCong->setVisible(false);
    connect(ui->comboChamCongNhanVien, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &GD_Qly::on_btnLoadChamCong_clicked);
    connect(ui->dateEditChamCong, &QDateEdit::dateChanged,
            this, &GD_Qly::on_btnLoadChamCong_clicked);


    // Tải dữ liệu ban đầu
    on_btnLoadChamCong_clicked();
    loadLeaveRequestsTable();

    ui->mainStackedWidget->setCurrentIndex(0);
}

GD_Qly::~GD_Qly()
{
    delete ui;
}

// --- CÁC HÀM TẢI DỮ LIỆU GỐC ---
void GD_Qly::setupTable()
{
    QHeaderView *header = ui->tableEmployees->horizontalHeader();
    header->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    header->setSectionResizeMode(1, QHeaderView::Stretch);
    header->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    header->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    header->setSectionResizeMode(4, QHeaderView::ResizeToContents);
    header->setSectionResizeMode(5, QHeaderView::ResizeToContents);
}

void GD_Qly::loadNhanSuData()
{
    docNhanSuTuFile();
}

void GD_Qly::displayNhanSuTable(const std::vector<std::shared_ptr<NhanSu>>& list)
{
    ui->tableEmployees->setSortingEnabled(false);
    ui->tableEmployees->setRowCount(0);
    QLocale vnLocale(QLocale::Vietnamese, QLocale::Vietnam);

    for (const auto& ns : list)
    {
        int row = ui->tableEmployees->rowCount();
        ui->tableEmployees->insertRow(row);
        ui->tableEmployees->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(ns->getMaNhanVien())));
        ui->tableEmployees->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(ns->getHoTen())));
        QString gioiTinh = (ns->getGioiTinh() == GioiTinh::NAM) ? "Nam" : "Nữ";
        ui->tableEmployees->setItem(row, 2, new QTableWidgetItem(gioiTinh));
        ui->tableEmployees->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(ns->getPhongBan().getTenPhongBan())));
        ui->tableEmployees->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(ns->getViTriCongViec())));
        double luong = ns->tinhLuongThucNhan();
        QTableWidgetItem *luongItem = new QTableWidgetItem(vnLocale.toString(luong, 'f', 0) + " VNĐ");
        luongItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        ui->tableEmployees->setItem(row, 5, luongItem);
    }

    ui->tableEmployees->setSortingEnabled(true);
}

// --- HÀM TẢI COMBOBOX LỌC ---
void GD_Qly::loadFilterComboBoxes()
{
    // 1. Tải Phòng ban
    docPhongBanTuFile();
    ui->comboFilterPhongBan->clear();
    ui->comboFilterPhongBan->addItem("Tất cả Phòng ban", "ALL");
    for (const auto& pb : g_danhSachPhongBan) {
        ui->comboFilterPhongBan->addItem(QString::fromStdString(pb.getTenPhongBan()),
                                         QString::fromStdString(pb.getMaPhongBan()));
    }

    // 2. Tải Chức vụ
    ui->comboFilterChucVu->clear();
    ui->comboFilterChucVu->addItem("Tất cả Chức vụ", "ALL");
    std::set<QString> uniqueViTri;
    for (const auto& ns : g_danhSachNhanSu) {
        uniqueViTri.insert(QString::fromStdString(ns->getViTriCongViec()));
    }
    for (const QString& viTri : uniqueViTri) {
        if (!viTri.isEmpty()) {
            ui->comboFilterChucVu->addItem(viTri);
        }
    }
}

// --- HÀM LỌC CHUNG  ---
void GD_Qly::filterNhanSuTable()
{
    QString query = ui->lineEditSearch->text().trimmed().toLower();
    QString maPBSelected = ui->comboFilterPhongBan->currentData().toString();
    QString chucVuSelected = ui->comboFilterChucVu->currentText();

    std::vector<std::shared_ptr<NhanSu>> filteredList;
    for (const auto& ns : g_danhSachNhanSu) {
        // 1. Lọc theo Tìm kiếm (Tên/Mã NV)
        bool matchesSearch = true;
        if (!query.isEmpty()) {
            if (!QString::fromStdString(ns->getHoTen()).toLower().contains(query) &&
                !QString::fromStdString(ns->getMaNhanVien()).toLower().contains(query))
            {
                matchesSearch = false;
            }
        }

        // 2. Lọc theo Phòng ban
        bool matchesPB = true;
        if (maPBSelected != "ALL") {
            if (QString::fromStdString(ns->getPhongBan().getMaPhongBan()) != maPBSelected) {
                matchesPB = false;
            }
        }

        // 3. Lọc theo Chức vụ
        bool matchesChucVu = true;
        if (chucVuSelected != "Tất cả Chức vụ") {
            if (QString::fromStdString(ns->getViTriCongViec()) != chucVuSelected) {
                matchesChucVu = false;
            }
        }

        if (matchesSearch && matchesPB && matchesChucVu) {
            filteredList.push_back(ns);
        }
    }
    displayNhanSuTable(filteredList);
}


//HÀM LỌC CHUNG
void GD_Qly::on_lineEditSearch_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    filterNhanSuTable();
}
void GD_Qly::on_comboFilterPhongBan_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    filterNhanSuTable();
}
void GD_Qly::on_comboFilterChucVu_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    filterNhanSuTable();
}


// --- HÀM CHO TRANG CHẤM CÔNG ---
void GD_Qly::loadNhanVienListToComboBox()
{
    ui->comboChamCongNhanVien->clear();
    ui->comboChamCongNhanVien->addItem("Tất cả nhân viên", "ALL"); // Lựa chọn xem tất cả
    for (const auto& ns : g_danhSachNhanSu)
    {
        ui->comboChamCongNhanVien->addItem(
            QString::fromStdString(ns->getHoTen()),
            QString::fromStdString(ns->getMaNhanVien())
            );
    }
}

void GD_Qly::on_btnLoadChamCong_clicked()
{
    ui->tableChamCongTongHop->setRowCount(0);
    ui->tableChamCongTongHop->setSortingEnabled(false);

    QString maNV_selected = ui->comboChamCongNhanVien->currentData().toString();

    // Lấy ngày, tháng, năm
    QDate selectedDate = ui->dateEditChamCong->date();
    int targetMonth = selectedDate.month();
    int targetYear = selectedDate.year();

    QDir dir("ChamCong");
    if (!dir.exists()) {
        return;
    }

    QStringList fileList;
    if (maNV_selected == "ALL") {
        fileList = dir.entryList(QStringList() << "*_chamcong.txt", QDir::Files);
    } else {
        if (QFile::exists(dir.filePath(maNV_selected + "_chamcong.txt"))) {
            fileList.append(maNV_selected + "_chamcong.txt");
        }
    }

    for (const QString &fileName : fileList) {
        QFile file(dir.filePath(fileName));
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) continue;

        QString maNV = fileName.split("_").first();
        auto ns = timNhanSuTheoMa(maNV.toStdString());
        QString hoTen = ns ? QString::fromStdString(ns->getHoTen()) : "Không rõ";

        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(',');

            if (parts.size() == 4) {
                // Kiểm tra xem ngày trong file có trùng tháng và năm không
                QDate lineDate = QDate::fromString(parts[0], "dd/MM/yyyy");
                if (lineDate.isValid() && lineDate.month() == targetMonth && lineDate.year() == targetYear)
                {
                    int row = ui->tableChamCongTongHop->rowCount();
                    ui->tableChamCongTongHop->insertRow(row);
                    ui->tableChamCongTongHop->setItem(row, 0, new QTableWidgetItem(parts[0])); // Ngày
                    ui->tableChamCongTongHop->setItem(row, 1, new QTableWidgetItem(maNV));
                    ui->tableChamCongTongHop->setItem(row, 2, new QTableWidgetItem(hoTen));
                    ui->tableChamCongTongHop->setItem(row, 3, new QTableWidgetItem(parts[1])); // Giờ vào
                    ui->tableChamCongTongHop->setItem(row, 4, new QTableWidgetItem(parts[2])); // Giờ ra
                    ui->tableChamCongTongHop->setItem(row, 5, new QTableWidgetItem(parts[3])); // Trạng thái
                }
            }
        }
        file.close();
    }

    ui->tableChamCongTongHop->setSortingEnabled(true);
}

// --- HÀM XUẤT CSV ---
void GD_Qly::on_btnExport_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this,
                                                    "Lưu File CSV Nhân Sự",
                                                    QDir::homePath() + "/danh_sach_nhan_su.csv",
                                                    "CSV Files (*.csv);;All Files (*)");

    if (filePath.isEmpty()) {
        return;
    }

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        QMessageBox::critical(this, "Lỗi Ghi File", "Không thể mở file để ghi: " + file.errorString());
        return;
    }

    QByteArray bom;
    bom.append(0xEF);
    bom.append(0xBB);
    bom.append(0xBF);
    file.write(bom);

    QTextStream out(&file);

    #if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
        out.setCodec("UTF-8");  // Qt5
    #else
        out.setEncoding(QStringConverter::Utf8);  // Qt6
    #endif

    // Lọc dữ liệu
    QString query = ui->lineEditSearch->text().trimmed().toLower();
    QString maPBSelected = ui->comboFilterPhongBan->currentData().toString();
    QString chucVuSelected = ui->comboFilterChucVu->currentText();

    std::vector<std::shared_ptr<NhanSu>> listToExport;
    for (const auto& ns : g_danhSachNhanSu) {
        bool matchesSearch = true;
        if (!query.isEmpty()) {
            if (!QString::fromStdString(ns->getHoTen()).toLower().contains(query) &&
                !QString::fromStdString(ns->getMaNhanVien()).toLower().contains(query))
            {
                matchesSearch = false;
            }
        }

        bool matchesPB = true;
        if (maPBSelected != "ALL") {
            if (QString::fromStdString(ns->getPhongBan().getMaPhongBan()) != maPBSelected) {
                matchesPB = false;
            }
        }

        bool matchesChucVu = true;
        if (chucVuSelected != "Tất cả Chức vụ") {
            if (QString::fromStdString(ns->getViTriCongViec()) != chucVuSelected) {
                matchesChucVu = false;
            }
        }

        if (matchesSearch && matchesPB && matchesChucVu) {
            listToExport.push_back(ns);
        }
    }

    if (listToExport.empty()) {
        QMessageBox::information(this, "Xuất CSV", "Không có dữ liệu nhân sự phù hợp với bộ lọc để xuất.");
        file.close();
        return;
    }

    // Hàm helper
    auto escapeCSV = [](const QString& field) -> QString {
        if (field.contains(',') || field.contains('"') || field.contains('\n') || field.contains('\r')) {
            return "\"" + QString(field).replace("\"", "\"\"") + "\"";
        }
        return field;
    };

    // Tiêu đề
    out << "MaNV,HoTen,LoaiNhanSu,PhongBan,MaPhongBan,ViTri,NgaySinh,GioiTinh,CCCD,SDT,Email,DiaChi,NgayVaoCongTy,TrinhDo,ChuyenNganh,LuongThucNhan\n";

    // Ghi dữ liệu
    QLocale cLocale(QLocale::C);

    for (const auto& ns : listToExport) {
        out << escapeCSV(QString::fromStdString(ns->getMaNhanVien())) << ",";
        out << escapeCSV(QString::fromStdString(ns->getHoTen())) << ",";
        out << escapeCSV(QString::fromStdString(ns->getLoaiNhanSu())) << ",";
        out << escapeCSV(QString::fromStdString(ns->getPhongBan().getTenPhongBan())) << ",";
        out << escapeCSV(QString::fromStdString(ns->getPhongBan().getMaPhongBan())) << ",";
        out << escapeCSV(QString::fromStdString(ns->getViTriCongViec())) << ",";
        out << escapeCSV(QString::fromStdString(ns->getNgaySinh().toString())) << ",";
        out << escapeCSV(ns->getGioiTinh() == GioiTinh::NAM ? "Nam" : "Nữ") << ",";
        out << escapeCSV(QString::fromStdString(ns->getCCCD())) << ",";
        out << escapeCSV(QString::fromStdString(ns->getSoDienThoai())) << ",";
        out << escapeCSV(QString::fromStdString(ns->getEmail())) << ",";
        out << escapeCSV(QString::fromStdString(ns->getDiaChi())) << ",";
        out << escapeCSV(QString::fromStdString(ns->getNgayVaoCongTy().toString())) << ",";
        out << escapeCSV(QString::fromStdString(ns->getTrinhDoHocVan())) << ",";
        out << escapeCSV(QString::fromStdString(ns->getChuyenNganh())) << ",";
        out << escapeCSV(cLocale.toString(ns->tinhLuongThucNhan(), 'f', 0));
        out << "\n";
    }

    file.close();

    QMessageBox::information(this, "Xuất CSV",
                             QString("Đã xuất thành công %1 hồ sơ nhân sự vào:\n%2")
                                 .arg(listToExport.size())
                                 .arg(filePath));
}


// --- HÀM CHO TRANG DUYỆT NGHỈ PHÉP ---

YeuCauNghiPhep* GD_Qly::timYeuCauTheoMa(const std::string& maYC) {
    for (auto& yc : g_danhSachYeuCauNghiPhep) {
        if (yc.getMaYeuCau() == maYC) {
            return &yc;
        }
    }
    return nullptr;
}

void GD_Qly::loadLeaveRequestsTable() {
    ui->tableLeaveRequests->setRowCount(0);
    ui->tableLeaveRequests->setSortingEnabled(false);

    int row = 0;
    for (const auto& yc : g_danhSachYeuCauNghiPhep) {
        // Chỉ hiển thị các yêu cầu CHỜ DUYỆT
        if (yc.getTrangThai() != TrangThaiDuyet::CHO_DUYET) continue;

        auto ns = timNhanSuTheoMa(yc.getMaNhanVien());
        QString hoTen = ns ? QString::fromStdString(ns->getHoTen()) : "Không rõ";
        int phepConLai = 0;

        // Lấy số ngày phép còn lại
        if (auto ct = std::dynamic_pointer_cast<NhanVienChinhThuc>(ns)) {
            phepConLai = ct->getSoNgayPhepConLai();
        } else if (auto ql = std::dynamic_pointer_cast<QuanLy>(ns)) {
            phepConLai = ql->getSoNgayPhepConLai();
        }

        ui->tableLeaveRequests->insertRow(row);

        // Mã YC (Cột 0)
        ui->tableLeaveRequests->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(yc.getMaYeuCau())));
        // Mã NV (Cột 1)
        ui->tableLeaveRequests->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(yc.getMaNhanVien())));
        // Họ và Tên (Cột 2)
        ui->tableLeaveRequests->setItem(row, 2, new QTableWidgetItem(hoTen));
        // Ngày bắt đầu (Cột 3)
        ui->tableLeaveRequests->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(yc.getNgayBatDau().toString())));
        // Số ngày (Cột 4)
        ui->tableLeaveRequests->setItem(row, 4, new QTableWidgetItem(QString::number(yc.getSoNgayNghi(), 'f', 1)));
        // Lý do (Cột 5)
        ui->tableLeaveRequests->setItem(row, 5, new QTableWidgetItem(QString::fromStdString(yc.getLyDo())));
        // Phép còn (Cột 6)
        QTableWidgetItem *phepItem = new QTableWidgetItem(QString::number(phepConLai));
        // Trạng thái (Cột 7)
        QTableWidgetItem *statusItem = new QTableWidgetItem(yc.getTrangThaiText());

        // --- Logic tô màu đỏ nếu phép còn lại không đủ ---
        if (phepConLai < yc.getSoNgayNghi()) {
            QBrush redBrush(QColor(255, 192, 192)); // Màu đỏ nhạt
            for (int col = 0; col < ui->tableLeaveRequests->columnCount(); ++col) {
                if (col == 6) { // Riêng cột Phép còn tô chữ đỏ đậm
                    phepItem->setForeground(QBrush(Qt::red));
                }
                ui->tableLeaveRequests->item(row, col)->setBackground(redBrush);
            }
        }

        phepItem->setTextAlignment(Qt::AlignCenter);
        statusItem->setForeground(QBrush(QColor(255, 165, 0))); // Màu Cam cho Chờ duyệt

        ui->tableLeaveRequests->setItem(row, 6, phepItem);
        ui->tableLeaveRequests->setItem(row, 7, statusItem);

        row++;
    }

    ui->tableLeaveRequests->setSortingEnabled(true);
}

void GD_Qly::on_btnLoadLeaveRequests_clicked() {
    docYeuCauNghiPhepTuFile();
    loadLeaveRequestsTable();
}

void GD_Qly::on_btnApproveLeave_clicked() {
    int currentRow = ui->tableLeaveRequests->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Chọn yêu cầu", "Vui lòng chọn yêu cầu nghỉ phép cần duyệt.");
        return;
    }

    QString maYC_q = ui->tableLeaveRequests->item(currentRow, 0)->text();
    std::string maYC = maYC_q.toStdString();

    YeuCauNghiPhep* yc = timYeuCauTheoMa(maYC);
    if (!yc) {
        QMessageBox::critical(this, "Lỗi", "Không tìm thấy yêu cầu.");
        return;
    }

    // Kiểm tra đủ phép không
    auto ns = timNhanSuTheoMa(yc->getMaNhanVien());
    double soNgayNghi = yc->getSoNgayNghi();
    int phepConLai = 0;

    if (auto ct = std::dynamic_pointer_cast<NhanVienChinhThuc>(ns)) {
        phepConLai = ct->getSoNgayPhepConLai();
    } else if (auto ql = std::dynamic_pointer_cast<QuanLy>(ns)) {
        phepConLai = ql->getSoNgayPhepConLai();
    }

    if (phepConLai < soNgayNghi) {
        QMessageBox::critical(this, "Lỗi Duyệt", QString("Nhân viên này chỉ còn %1 ngày phép. Không đủ để duyệt %2 ngày.")
                                                         .arg(phepConLai)
                                                         .arg(soNgayNghi));
        return;
    }

    // Tiến hành duyệt
    yc->setTrangThai(TrangThaiDuyet::DA_DUYET);
    yc->setNguoiDuyet(m_maQuanLy.toStdString());

    // Cập nhật số ngày phép còn lại cho nhân viên
    if (auto ct = std::dynamic_pointer_cast<NhanVienChinhThuc>(ns)) {
        ct->capNhatPhep(phepConLai - qCeil(soNgayNghi));
    } else if (auto ql = std::dynamic_pointer_cast<QuanLy>(ns)) {
        ql->capNhatPhep(phepConLai - qCeil(soNgayNghi));
    }

    luuYeuCauNghiPhepVaoFile();
    luuNhanSuVaoFile();
    loadNhanSuData(); // Tải lại data để cập nhật phép còn
    loadFilterComboBoxes(); // Cập nhật lại list lọc

    QMessageBox::information(this, "Thành công", "Yêu cầu nghỉ phép đã được DUYỆT thành công!");
    loadLeaveRequestsTable();
}

void GD_Qly::on_btnRejectLeave_clicked() {
    int currentRow = ui->tableLeaveRequests->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Chọn yêu cầu", "Vui lòng chọn yêu cầu nghỉ phép cần từ chối.");
        return;
    }

    QString maYC_q = ui->tableLeaveRequests->item(currentRow, 0)->text();
    std::string maYC = maYC_q.toStdString();

    YeuCauNghiPhep* yc = timYeuCauTheoMa(maYC);
    if (!yc) {
        QMessageBox::critical(this, "Lỗi", "Không tìm thấy yêu cầu.");
        return;
    }

    auto reply = QMessageBox::question(this, "Xác nhận Từ chối",
                                       QString("Bạn có chắc chắn muốn TỪ CHỐI yêu cầu '%1' này?")
                                           .arg(maYC_q),
                                       QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        yc->setTrangThai(TrangThaiDuyet::TU_CHOI);
        yc->setNguoiDuyet(m_maQuanLy.toStdString());

        luuYeuCauNghiPhepVaoFile();

        QMessageBox::information(this, "Thành công", "Yêu cầu nghỉ phép đã bị TỪ CHỐI.");
        loadLeaveRequestsTable();
    }
}

// --- SLOTS CHỨC NĂNG KHÁC ---

void GD_Qly::on_btnAdd_clicked()
{
    GD_Them *formThem = new GD_Them(this);
    formThem->setWindowFlags(formThem->windowFlags() | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);

    if (formThem->exec() == QDialog::Accepted)
    {
        loadNhanSuData();
        displayNhanSuTable(g_danhSachNhanSu);
        loadNhanVienListToComboBox();
        loadFilterComboBoxes(); // Cập nhật combobox lọc
    }
    delete formThem;
}

void GD_Qly::on_btnEdit_clicked()
{
    int currentRow = ui->tableEmployees->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Chưa chọn", "Vui lòng chọn nhân sự cần sửa.");
        return;
    }

    QString maNV = ui->tableEmployees->item(currentRow, 0)->text();
    auto ns = timNhanSuTheoMa(maNV.toStdString());
    if (!ns) {
        QMessageBox::critical(this, "Lỗi", "Không tìm thấy nhân sự.");
        return;
    }

    GD_Them *formSua = new GD_Them(this);
    formSua->loadDataForEdit(ns);

    if (formSua->exec() == QDialog::Accepted)
    {
        loadNhanSuData();
        displayNhanSuTable(g_danhSachNhanSu);
        loadNhanVienListToComboBox();
        loadFilterComboBoxes(); // Cập nhật combobox lọc
        loadLeaveRequestsTable();
    }
    delete formSua;
}

void GD_Qly::on_btnDelete_clicked()
{
    int currentRow = ui->tableEmployees->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Chưa chọn", "Vui lòng chọn nhân sự cần xóa.");
        return;
    }

    QString maNV = ui->tableEmployees->item(currentRow, 0)->text();
    QString hoTen = ui->tableEmployees->item(currentRow, 1)->text();

    auto reply = QMessageBox::question(this, "Xác nhận xóa",
                                       QString("Bạn có chắc chắn muốn xóa nhân sự '%1' (Mã: %2)?\nHành động này không thể hoàn tác.")
                                           .arg(hoTen, maNV),
                                       QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes)
    {
        g_danhSachNhanSu.erase(
            std::remove_if(g_danhSachNhanSu.begin(), g_danhSachNhanSu.end(),
                           [&](const std::shared_ptr<NhanSu>& ns) {
                               return ns->getMaNhanVien() == maNV.toStdString();
                           }),
            g_danhSachNhanSu.end()
            );

        luuNhanSuVaoFile();
        xoaTaiKhoan(maNV.toStdString());

        QFile::remove("ChamCong/" + maNV + "_chamcong.txt");

        ui->tableEmployees->removeRow(currentRow);
        loadNhanVienListToComboBox();
        loadFilterComboBoxes(); // Cập nhật combobox lọc
        loadLeaveRequestsTable();
        QMessageBox::information(this, "Thành công", "Đã xóa nhân sự thành công.");
    }
}

void GD_Qly::on_btnDetail_clicked()
{
    int currentRow = ui->tableEmployees->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Chưa chọn", "Vui lòng chọn nhân sự để xem chi tiết.");
        return;
    }

    QString maNV = ui->tableEmployees->item(currentRow, 0)->text();

    GD_NVChung *formChiTiet = new GD_NVChung(maNV, this);
    formChiTiet->setAttribute(Qt::WA_DeleteOnClose);
    formChiTiet->show();
}

void GD_Qly::on_btnRefresh_clicked()
{
    loadNhanSuData();
    docYeuCauNghiPhepTuFile();
    loadFilterComboBoxes(); // GỌI LẠI HÀM NÀY
    displayNhanSuTable(g_danhSachNhanSu);
    loadNhanVienListToComboBox();
    ui->lineEditSearch->clear();
    on_btnLoadChamCong_clicked();
    loadLeaveRequestsTable();
    QMessageBox::information(this, "Làm mới", "Đã tải lại toàn bộ dữ liệu.");
}


// --- ĐIỀU HƯỚNG ---
void GD_Qly::on_btnNavEmployees_clicked()
{
    ui->mainStackedWidget->setCurrentIndex(0);
}
void GD_Qly::on_btnNavAttendance_clicked()
{
    ui->mainStackedWidget->setCurrentIndex(1);
    on_btnLoadChamCong_clicked();
}
void GD_Qly::on_btnNavLeaveApproval_clicked()
{
    ui->mainStackedWidget->setCurrentIndex(2);
    loadLeaveRequestsTable();
}
void GD_Qly::on_btnNavProjects_clicked()
{
    ui->mainStackedWidget->setCurrentIndex(5);
}
void GD_Qly::on_btnNavDepartments_clicked()
{
    ui->mainStackedWidget->setCurrentIndex(4);
}
