/********************************************************************************
** Form generated from reading UI file 'GD_QLDuAn.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GD_QLDUAN_H
#define UI_GD_QLDUAN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GD_QLDuAn
{
public:
    QVBoxLayout *verticalLayout_2;
    QFrame *topBarFrame;
    QHBoxLayout *topBar;
    QLineEdit *lineEditSearch;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnRefresh;
    QFrame *actionFrame;
    QHBoxLayout *actionLayout;
    QPushButton *btnAddProject;
    QPushButton *btnEditProject;
    QPushButton *btnDeleteProject;
    QPushButton *btnDetailProject;
    QPushButton *btnCompleteProject;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *tableProjects;

    void setupUi(QWidget *GD_QLDuAn)
    {
        if (GD_QLDuAn->objectName().isEmpty())
            GD_QLDuAn->setObjectName("GD_QLDuAn");
        GD_QLDuAn->resize(1042, 744);
        verticalLayout_2 = new QVBoxLayout(GD_QLDuAn);
        verticalLayout_2->setSpacing(12);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(12, 12, 12, 12);
        topBarFrame = new QFrame(GD_QLDuAn);
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

        btnRefresh = new QPushButton(topBarFrame);
        btnRefresh->setObjectName("btnRefresh");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/refresh.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnRefresh->setIcon(icon);

        topBar->addWidget(btnRefresh);


        verticalLayout_2->addWidget(topBarFrame);

        actionFrame = new QFrame(GD_QLDuAn);
        actionFrame->setObjectName("actionFrame");
        actionLayout = new QHBoxLayout(actionFrame);
        actionLayout->setObjectName("actionLayout");
        btnAddProject = new QPushButton(actionFrame);
        btnAddProject->setObjectName("btnAddProject");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/add.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnAddProject->setIcon(icon1);

        actionLayout->addWidget(btnAddProject);

        btnEditProject = new QPushButton(actionFrame);
        btnEditProject->setObjectName("btnEditProject");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/edit.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnEditProject->setIcon(icon2);

        actionLayout->addWidget(btnEditProject);

        btnDeleteProject = new QPushButton(actionFrame);
        btnDeleteProject->setObjectName("btnDeleteProject");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/delete.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnDeleteProject->setIcon(icon3);

        actionLayout->addWidget(btnDeleteProject);

        btnDetailProject = new QPushButton(actionFrame);
        btnDetailProject->setObjectName("btnDetailProject");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/detail.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnDetailProject->setIcon(icon4);

        actionLayout->addWidget(btnDetailProject);

        btnCompleteProject = new QPushButton(actionFrame);
        btnCompleteProject->setObjectName("btnCompleteProject");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/check.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnCompleteProject->setIcon(icon5);

        actionLayout->addWidget(btnCompleteProject);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        actionLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(actionFrame);

        tableProjects = new QTableWidget(GD_QLDuAn);
        if (tableProjects->columnCount() < 6)
            tableProjects->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableProjects->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableProjects->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableProjects->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableProjects->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableProjects->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableProjects->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableProjects->setObjectName("tableProjects");
        tableProjects->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableProjects->setAlternatingRowColors(true);
        tableProjects->setSelectionMode(QAbstractItemView::SingleSelection);
        tableProjects->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableProjects->setSortingEnabled(true);
        tableProjects->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_2->addWidget(tableProjects);


        retranslateUi(GD_QLDuAn);

        QMetaObject::connectSlotsByName(GD_QLDuAn);
    } // setupUi

    void retranslateUi(QWidget *GD_QLDuAn)
    {
        GD_QLDuAn->setWindowTitle(QCoreApplication::translate("GD_QLDuAn", "Form", nullptr));
        lineEditSearch->setPlaceholderText(QCoreApplication::translate("GD_QLDuAn", "T\303\254m ki\341\272\277m theo t\303\252n, m\303\243 d\341\273\261 \303\241n...", nullptr));
        btnRefresh->setText(QCoreApplication::translate("GD_QLDuAn", "L\303\240m m\341\273\233i", nullptr));
        btnAddProject->setText(QCoreApplication::translate("GD_QLDuAn", "Th\303\252m D\341\273\261 \303\201n", nullptr));
        btnEditProject->setText(QCoreApplication::translate("GD_QLDuAn", "S\341\273\255a", nullptr));
        btnDeleteProject->setText(QCoreApplication::translate("GD_QLDuAn", "X\303\263a", nullptr));
        btnDetailProject->setText(QCoreApplication::translate("GD_QLDuAn", "Chi Ti\341\272\277t", nullptr));
        btnCompleteProject->setText(QCoreApplication::translate("GD_QLDuAn", "Ho\303\240n Th\303\240nh", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableProjects->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("GD_QLDuAn", "M\303\243 DA", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableProjects->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("GD_QLDuAn", "T\303\252n D\341\273\261 \303\201n", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableProjects->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("GD_QLDuAn", "Ng\306\260\341\273\235i Ph\341\273\245 Tr\303\241ch", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableProjects->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("GD_QLDuAn", "Ng\303\240y B\341\272\257t \304\220\341\272\247u", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableProjects->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("GD_QLDuAn", "Tr\341\272\241ng Th\303\241i", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableProjects->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("GD_QLDuAn", "S\341\273\221 L\306\260\341\273\243ng TV", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GD_QLDuAn: public Ui_GD_QLDuAn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GD_QLDUAN_H
