/********************************************************************************
** Form generated from reading UI file 'FlameDate.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLAMEDATE_H
#define UI_FLAMEDATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FlameDateClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonAddMinus;
    QFrame *line_2;
    QPushButton *pushButtonImport;
    QPushButton *pushButtonExport;
    QFrame *line_3;
    QPushButton *pushButtonRefresh;
    QFrame *line_4;
    QPushButton *pushButtonSetting;
    QTreeWidget *treeWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FlameDateClass)
    {
        if (FlameDateClass->objectName().isEmpty())
            FlameDateClass->setObjectName(QString::fromUtf8("FlameDateClass"));
        FlameDateClass->resize(1195, 623);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FlameDateClass->sizePolicy().hasHeightForWidth());
        FlameDateClass->setSizePolicy(sizePolicy);
        FlameDateClass->setFocusPolicy(Qt::NoFocus);
        centralWidget = new QWidget(FlameDateClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setEnabled(true);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy1);
        splitter->setMaximumSize(QSize(75, 214));
        splitter->setOrientation(Qt::Vertical);
        pushButtonAdd = new QPushButton(splitter);
        pushButtonAdd->setObjectName(QString::fromUtf8("pushButtonAdd"));
        sizePolicy1.setHeightForWidth(pushButtonAdd->sizePolicy().hasHeightForWidth());
        pushButtonAdd->setSizePolicy(sizePolicy1);
        splitter->addWidget(pushButtonAdd);
        pushButtonAddMinus = new QPushButton(splitter);
        pushButtonAddMinus->setObjectName(QString::fromUtf8("pushButtonAddMinus"));
        sizePolicy1.setHeightForWidth(pushButtonAddMinus->sizePolicy().hasHeightForWidth());
        pushButtonAddMinus->setSizePolicy(sizePolicy1);
        splitter->addWidget(pushButtonAddMinus);
        line_2 = new QFrame(splitter);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        sizePolicy1.setHeightForWidth(line_2->sizePolicy().hasHeightForWidth());
        line_2->setSizePolicy(sizePolicy1);
        line_2->setMinimumSize(QSize(0, 10));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        splitter->addWidget(line_2);
        pushButtonImport = new QPushButton(splitter);
        pushButtonImport->setObjectName(QString::fromUtf8("pushButtonImport"));
        sizePolicy1.setHeightForWidth(pushButtonImport->sizePolicy().hasHeightForWidth());
        pushButtonImport->setSizePolicy(sizePolicy1);
        splitter->addWidget(pushButtonImport);
        pushButtonExport = new QPushButton(splitter);
        pushButtonExport->setObjectName(QString::fromUtf8("pushButtonExport"));
        sizePolicy1.setHeightForWidth(pushButtonExport->sizePolicy().hasHeightForWidth());
        pushButtonExport->setSizePolicy(sizePolicy1);
        splitter->addWidget(pushButtonExport);
        line_3 = new QFrame(splitter);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        sizePolicy1.setHeightForWidth(line_3->sizePolicy().hasHeightForWidth());
        line_3->setSizePolicy(sizePolicy1);
        line_3->setMinimumSize(QSize(0, 10));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        splitter->addWidget(line_3);
        pushButtonRefresh = new QPushButton(splitter);
        pushButtonRefresh->setObjectName(QString::fromUtf8("pushButtonRefresh"));
        sizePolicy1.setHeightForWidth(pushButtonRefresh->sizePolicy().hasHeightForWidth());
        pushButtonRefresh->setSizePolicy(sizePolicy1);
        splitter->addWidget(pushButtonRefresh);
        line_4 = new QFrame(splitter);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        sizePolicy1.setHeightForWidth(line_4->sizePolicy().hasHeightForWidth());
        line_4->setSizePolicy(sizePolicy1);
        line_4->setMinimumSize(QSize(0, 10));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        splitter->addWidget(line_4);
        pushButtonSetting = new QPushButton(splitter);
        pushButtonSetting->setObjectName(QString::fromUtf8("pushButtonSetting"));
        sizePolicy1.setHeightForWidth(pushButtonSetting->sizePolicy().hasHeightForWidth());
        pushButtonSetting->setSizePolicy(sizePolicy1);
        splitter->addWidget(pushButtonSetting);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);

        treeWidget = new QTreeWidget(centralWidget);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(10);
        sizePolicy2.setVerticalStretch(10);
        sizePolicy2.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy2);
        treeWidget->setMinimumSize(QSize(300, 300));
        treeWidget->setFocusPolicy(Qt::NoFocus);
        treeWidget->setLayoutDirection(Qt::LeftToRight);
        treeWidget->setAutoFillBackground(false);
        treeWidget->setSortingEnabled(false);

        gridLayout->addWidget(treeWidget, 0, 1, 1, 1);

        FlameDateClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(FlameDateClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1195, 22));
        FlameDateClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(FlameDateClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        FlameDateClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(FlameDateClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        FlameDateClass->setStatusBar(statusBar);

        retranslateUi(FlameDateClass);

        QMetaObject::connectSlotsByName(FlameDateClass);
    } // setupUi

    void retranslateUi(QMainWindow *FlameDateClass)
    {
        FlameDateClass->setWindowTitle(QCoreApplication::translate("FlameDateClass", "FlameDate", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonAdd->setToolTip(QCoreApplication::translate("FlameDateClass", "Add new control object", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButtonAdd->setText(QCoreApplication::translate("FlameDateClass", "+", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonAddMinus->setToolTip(QCoreApplication::translate("FlameDateClass", "Delete choised control object", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButtonAddMinus->setText(QCoreApplication::translate("FlameDateClass", "-", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonImport->setToolTip(QCoreApplication::translate("FlameDateClass", "Imports an object tree into XML", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButtonImport->setText(QCoreApplication::translate("FlameDateClass", "\320\230\320\274\320\277\320\276\321\200\321\202", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonExport->setToolTip(QCoreApplication::translate("FlameDateClass", "Exports an object tree from XML", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButtonExport->setText(QCoreApplication::translate("FlameDateClass", "\320\255\320\272\321\201\320\277\320\276\321\200\321\202", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonRefresh->setToolTip(QCoreApplication::translate("FlameDateClass", "Refresh control parameters for control object", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButtonRefresh->setText(QCoreApplication::translate("FlameDateClass", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonSetting->setToolTip(QCoreApplication::translate("FlameDateClass", "Set general default parameters.", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButtonSetting->setText(QCoreApplication::translate("FlameDateClass", "\320\241\320\262\320\276\320\271\321\201\321\202\320\262\320\260", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(10, QCoreApplication::translate("FlameDateClass", "\320\241\321\202\321\200\320\276\320\272\320\260 \320\267\320\260\320\263\320\276\320\273\320\276\320\262\320\272\320\260", nullptr));
        ___qtreewidgetitem->setText(9, QCoreApplication::translate("FlameDateClass", "\320\233\320\270\321\201\321\202 \320\262 \321\204\320\260\320\271\320\273\320\265", nullptr));
        ___qtreewidgetitem->setText(8, QCoreApplication::translate("FlameDateClass", "Telegram Id", nullptr));
        ___qtreewidgetitem->setText(7, QCoreApplication::translate("FlameDateClass", "\320\241\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
        ___qtreewidgetitem->setText(6, QCoreApplication::translate("FlameDateClass", "\320\241\321\202\321\200\320\276\320\272\320\260", nullptr));
        ___qtreewidgetitem->setText(5, QCoreApplication::translate("FlameDateClass", "\320\222\321\200\320\265\320\274\321\217 \320\277\321\200\320\276\320\262\320\265\321\200\320\272\320\270 \320\264\320\260\321\202", nullptr));
        ___qtreewidgetitem->setText(4, QCoreApplication::translate("FlameDateClass", "\320\236\321\202\320\277\321\200\320\260\320\262\320\272\320\260 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\271", nullptr));
        ___qtreewidgetitem->setText(3, QCoreApplication::translate("FlameDateClass", "\320\237\321\200\320\276\320\262\320\265\321\200\320\272\320\260 \320\264\320\260\321\202", nullptr));
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("FlameDateClass", "\320\241\321\200\320\276\320\272\320\270 \321\203\320\262\320\265\320\264\320\276\320\274\320\273\320\265\320\275\320\270\320\271", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("FlameDateClass", "\320\240\320\260\321\201\320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("FlameDateClass", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265/\320\230\320\274\321\217", nullptr));
#if QT_CONFIG(tooltip)
        treeWidget->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class FlameDateClass: public Ui_FlameDateClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLAMEDATE_H
