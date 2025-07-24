/********************************************************************************
** Form generated from reading UI file 'GeneralSetting.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERALSETTING_H
#define UI_GENERALSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GeneralSettingClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GeneralSettingClass)
    {
        if (GeneralSettingClass->objectName().isEmpty())
            GeneralSettingClass->setObjectName(QString::fromUtf8("GeneralSettingClass"));
        GeneralSettingClass->resize(600, 400);
        menuBar = new QMenuBar(GeneralSettingClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        GeneralSettingClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GeneralSettingClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        GeneralSettingClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(GeneralSettingClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        GeneralSettingClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(GeneralSettingClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GeneralSettingClass->setStatusBar(statusBar);

        retranslateUi(GeneralSettingClass);

        QMetaObject::connectSlotsByName(GeneralSettingClass);
    } // setupUi

    void retranslateUi(QMainWindow *GeneralSettingClass)
    {
        GeneralSettingClass->setWindowTitle(QCoreApplication::translate("GeneralSettingClass", "GeneralSetting", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GeneralSettingClass: public Ui_GeneralSettingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERALSETTING_H
