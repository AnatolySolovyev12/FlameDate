/********************************************************************************
** Form generated from reading UI file 'GeneralParam.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERALPARAM_H
#define UI_GENERALPARAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GeneralParamClass
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QWidget *layoutWidget_2;
    QFormLayout *formLayout_4;
    QLabel *label_19;
    QLineEdit *nameLine;
    QLabel *label_13;
    QLineEdit *directoryLine;
    QLabel *label_14;
    QLineEdit *deadlineLine;
    QLabel *label_15;
    QLineEdit *timeLine;
    QLabel *label_16;
    QLineEdit *rowLine;
    QLabel *label_17;
    QLineEdit *columnLine;
    QLabel *label_18;
    QLineEdit *telegramLine;
    QLabel *label_20;
    QLineEdit *listLine;
    QLabel *label_21;
    QLineEdit *rowHeadLine;
    QCheckBox *checkBoxNameCounter;
    QWidget *tab;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QCheckBox *checkMon;
    QCheckBox *checkTue;
    QCheckBox *checkWed;
    QCheckBox *checkThurs;
    QCheckBox *checkFri;
    QFrame *line;
    QCheckBox *checkSat;
    QCheckBox *checkSun;
    QFrame *line_2;
    QCheckBox *checkSendCrit;
    QPushButton *exitBtn;
    QPushButton *saveAllBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GeneralParamClass)
    {
        if (GeneralParamClass->objectName().isEmpty())
            GeneralParamClass->setObjectName(QString::fromUtf8("GeneralParamClass"));
        GeneralParamClass->resize(365, 430);
        GeneralParamClass->setMinimumSize(QSize(365, 430));
        GeneralParamClass->setMaximumSize(QSize(365, 430));
        centralWidget = new QWidget(GeneralParamClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 351, 351));
        tabWidget->setMinimumSize(QSize(200, 200));
        tabWidget->setBaseSize(QSize(50, 0));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        layoutWidget_2 = new QWidget(tab_3);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 40, 331, 515));
        formLayout_4 = new QFormLayout(layoutWidget_2);
        formLayout_4->setSpacing(6);
        formLayout_4->setContentsMargins(11, 11, 11, 11);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        formLayout_4->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        formLayout_4->setRowWrapPolicy(QFormLayout::WrapLongRows);
        formLayout_4->setVerticalSpacing(9);
        formLayout_4->setContentsMargins(0, 0, 0, 0);
        label_19 = new QLabel(layoutWidget_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_19);

        nameLine = new QLineEdit(layoutWidget_2);
        nameLine->setObjectName(QString::fromUtf8("nameLine"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, nameLine);

        label_13 = new QLabel(layoutWidget_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_13);

        directoryLine = new QLineEdit(layoutWidget_2);
        directoryLine->setObjectName(QString::fromUtf8("directoryLine"));
        directoryLine->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(directoryLine->sizePolicy().hasHeightForWidth());
        directoryLine->setSizePolicy(sizePolicy);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, directoryLine);

        label_14 = new QLabel(layoutWidget_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label_14);

        deadlineLine = new QLineEdit(layoutWidget_2);
        deadlineLine->setObjectName(QString::fromUtf8("deadlineLine"));

        formLayout_4->setWidget(2, QFormLayout::FieldRole, deadlineLine);

        label_15 = new QLabel(layoutWidget_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        formLayout_4->setWidget(3, QFormLayout::LabelRole, label_15);

        timeLine = new QLineEdit(layoutWidget_2);
        timeLine->setObjectName(QString::fromUtf8("timeLine"));

        formLayout_4->setWidget(3, QFormLayout::FieldRole, timeLine);

        label_16 = new QLabel(layoutWidget_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        formLayout_4->setWidget(4, QFormLayout::LabelRole, label_16);

        rowLine = new QLineEdit(layoutWidget_2);
        rowLine->setObjectName(QString::fromUtf8("rowLine"));
        rowLine->setEchoMode(QLineEdit::Normal);

        formLayout_4->setWidget(4, QFormLayout::FieldRole, rowLine);

        label_17 = new QLabel(layoutWidget_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        formLayout_4->setWidget(5, QFormLayout::LabelRole, label_17);

        columnLine = new QLineEdit(layoutWidget_2);
        columnLine->setObjectName(QString::fromUtf8("columnLine"));

        formLayout_4->setWidget(5, QFormLayout::FieldRole, columnLine);

        label_18 = new QLabel(layoutWidget_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        formLayout_4->setWidget(6, QFormLayout::LabelRole, label_18);

        telegramLine = new QLineEdit(layoutWidget_2);
        telegramLine->setObjectName(QString::fromUtf8("telegramLine"));

        formLayout_4->setWidget(6, QFormLayout::FieldRole, telegramLine);

        label_20 = new QLabel(layoutWidget_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        formLayout_4->setWidget(7, QFormLayout::LabelRole, label_20);

        listLine = new QLineEdit(layoutWidget_2);
        listLine->setObjectName(QString::fromUtf8("listLine"));

        formLayout_4->setWidget(7, QFormLayout::FieldRole, listLine);

        label_21 = new QLabel(layoutWidget_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        formLayout_4->setWidget(8, QFormLayout::LabelRole, label_21);

        rowHeadLine = new QLineEdit(layoutWidget_2);
        rowHeadLine->setObjectName(QString::fromUtf8("rowHeadLine"));

        formLayout_4->setWidget(8, QFormLayout::FieldRole, rowHeadLine);

        checkBoxNameCounter = new QCheckBox(tab_3);
        checkBoxNameCounter->setObjectName(QString::fromUtf8("checkBoxNameCounter"));
        checkBoxNameCounter->setGeometry(QRect(10, 10, 171, 20));
        tabWidget->addTab(tab_3, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayoutWidget = new QWidget(tab);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 10, 251, 258));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(label);

        checkMon = new QCheckBox(verticalLayoutWidget);
        checkMon->setObjectName(QString::fromUtf8("checkMon"));

        verticalLayout->addWidget(checkMon);

        checkTue = new QCheckBox(verticalLayoutWidget);
        checkTue->setObjectName(QString::fromUtf8("checkTue"));

        verticalLayout->addWidget(checkTue);

        checkWed = new QCheckBox(verticalLayoutWidget);
        checkWed->setObjectName(QString::fromUtf8("checkWed"));

        verticalLayout->addWidget(checkWed);

        checkThurs = new QCheckBox(verticalLayoutWidget);
        checkThurs->setObjectName(QString::fromUtf8("checkThurs"));

        verticalLayout->addWidget(checkThurs);

        checkFri = new QCheckBox(verticalLayoutWidget);
        checkFri->setObjectName(QString::fromUtf8("checkFri"));

        verticalLayout->addWidget(checkFri);

        line = new QFrame(verticalLayoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setMinimumSize(QSize(0, 10));
        line->setMaximumSize(QSize(90, 16777215));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        checkSat = new QCheckBox(verticalLayoutWidget);
        checkSat->setObjectName(QString::fromUtf8("checkSat"));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        checkSat->setPalette(palette);

        verticalLayout->addWidget(checkSat);

        checkSun = new QCheckBox(verticalLayoutWidget);
        checkSun->setObjectName(QString::fromUtf8("checkSun"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        checkSun->setPalette(palette1);

        verticalLayout->addWidget(checkSun);

        line_2 = new QFrame(verticalLayoutWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setMinimumSize(QSize(0, 10));
        line_2->setMaximumSize(QSize(180, 16777215));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        checkSendCrit = new QCheckBox(verticalLayoutWidget);
        checkSendCrit->setObjectName(QString::fromUtf8("checkSendCrit"));

        verticalLayout->addWidget(checkSendCrit);

        tabWidget->addTab(tab, QString());
        exitBtn = new QPushButton(centralWidget);
        exitBtn->setObjectName(QString::fromUtf8("exitBtn"));
        exitBtn->setGeometry(QRect(270, 350, 80, 24));
        saveAllBtn = new QPushButton(centralWidget);
        saveAllBtn->setObjectName(QString::fromUtf8("saveAllBtn"));
        saveAllBtn->setGeometry(QRect(70, 350, 80, 24));
        GeneralParamClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GeneralParamClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 365, 22));
        GeneralParamClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GeneralParamClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        GeneralParamClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GeneralParamClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GeneralParamClass->setStatusBar(statusBar);

        retranslateUi(GeneralParamClass);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(GeneralParamClass);
    } // setupUi

    void retranslateUi(QMainWindow *GeneralParamClass)
    {
        GeneralParamClass->setWindowTitle(QCoreApplication::translate("GeneralParamClass", "\320\241\320\262\320\276\320\271\321\201\321\202\320\262\320\260", nullptr));
        label_19->setText(QCoreApplication::translate("GeneralParamClass", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        nameLine->setText(QString());
        label_13->setText(QCoreApplication::translate("GeneralParamClass", "\320\240\320\260\321\201\320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265", nullptr));
#if QT_CONFIG(tooltip)
        directoryLine->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        directoryLine->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(accessibility)
        directoryLine->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        directoryLine->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        directoryLine->setText(QString());
        label_14->setText(QCoreApplication::translate("GeneralParamClass", "\320\241\321\200\320\276\320\272\320\270", nullptr));
        deadlineLine->setText(QString());
        label_15->setText(QCoreApplication::translate("GeneralParamClass", "\320\222\321\200\320\265\320\274\321\217", nullptr));
        timeLine->setText(QString());
        label_16->setText(QCoreApplication::translate("GeneralParamClass", "\320\241\321\202\321\200\320\276\320\272\320\260", nullptr));
        rowLine->setInputMask(QString());
        rowLine->setText(QString());
        label_17->setText(QCoreApplication::translate("GeneralParamClass", "\320\241\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
        columnLine->setText(QString());
        label_18->setText(QCoreApplication::translate("GeneralParamClass", "Telegram Id", nullptr));
        telegramLine->setText(QString());
        label_20->setText(QCoreApplication::translate("GeneralParamClass", "\320\233\320\270\321\201\321\202", nullptr));
        listLine->setText(QString());
        label_21->setText(QCoreApplication::translate("GeneralParamClass", "\320\227\320\260\320\263\320\276\320\273\320\276\320\262\320\276\320\272", nullptr));
        rowHeadLine->setText(QString());
        checkBoxNameCounter->setText(QCoreApplication::translate("GeneralParamClass", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265/\320\270\320\274\321\217 \320\272\320\260\320\272 \321\201\321\207\321\221\321\202\321\207\320\270\320\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("GeneralParamClass", "\320\236\321\201\320\275\320\276\320\262\320\275\321\213\320\265 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \321\202\320\260\320\261\320\273\320\270\321\206\321\213", nullptr));
        label->setText(QCoreApplication::translate("GeneralParamClass", "\320\224\320\275\320\270 \320\275\320\265\320\264\320\265\320\273\320\270 \320\264\320\273\321\217 \320\276\321\202\320\277\321\200\320\260\320\262\320\272\320\270 \321\203\320\262\320\265\320\264\320\276\320\274\320\273\320\265\320\275\320\270\320\271", nullptr));
        checkMon->setText(QCoreApplication::translate("GeneralParamClass", "\320\237\320\276\320\275\320\265\320\264\320\265\320\273\321\214\320\275\320\270\320\272", nullptr));
        checkTue->setText(QCoreApplication::translate("GeneralParamClass", "\320\222\321\202\320\276\321\200\320\275\320\270\320\272", nullptr));
        checkWed->setText(QCoreApplication::translate("GeneralParamClass", "\320\241\321\200\320\265\320\264\320\260", nullptr));
        checkThurs->setText(QCoreApplication::translate("GeneralParamClass", "\320\247\320\265\321\202\320\262\320\265\321\200\320\263", nullptr));
        checkFri->setText(QCoreApplication::translate("GeneralParamClass", "\320\237\321\217\321\202\320\275\320\270\321\206\320\260", nullptr));
        checkSat->setText(QCoreApplication::translate("GeneralParamClass", "\320\241\321\203\320\261\320\261\320\276\321\202\320\260", nullptr));
        checkSun->setText(QCoreApplication::translate("GeneralParamClass", "\320\222\320\276\321\201\320\272\321\200\320\265\321\201\320\265\320\275\321\214\320\265", nullptr));
        checkSendCrit->setText(QCoreApplication::translate("GeneralParamClass", "\320\225\320\266\320\265\320\264\320\275\320\265\320\262\320\275\320\276 \320\276\321\202\320\277\321\200\320\260\320\262\320\273\321\217\321\202\321\214 \320\265\321\201\320\273\320\270 < 15 \320\264\320\275\320\265\320\271", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("GeneralParamClass", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\271", nullptr));
        exitBtn->setText(QCoreApplication::translate("GeneralParamClass", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        saveAllBtn->setText(QCoreApplication::translate("GeneralParamClass", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GeneralParamClass: public Ui_GeneralParamClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERALPARAM_H
