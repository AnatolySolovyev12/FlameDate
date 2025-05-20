#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_FlameDate.h"

#include <ProcessObject.h>


#include <QFileDialog>
#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamAttribute>
#include <QMouseEvent>

#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>

#include <windows.h>
#include <TelegramJacket.h>

class FlameDate : public QMainWindow
{
    Q_OBJECT

public:

    FlameDate(QWidget* parent = nullptr);
    ~FlameDate();

    void addItemInList();
    void deleteItemInList();
    void exportXml();
    void recursionXmlWriter(QTreeWidgetItem* some, QXmlStreamWriter& someXmlWriter);
    void importXml();
    void loopXmlReader(QXmlStreamReader& xmlReader);
    void startingImportXml();
    void mousePressEvent(QMouseEvent* event);
    void initializationPoolFunc();
    void validDate(QTreeWidgetItem* val);

    void setData();
    void closeEditor(QTreeWidgetItem* any);
    void otherItemWasChecked(QTreeWidgetItem* any);

    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void cmdOpen();
    void cmdClose();

    void getTokenFromFile();

   // void showGeneralParam();

private:
    Ui::FlameDateClass ui;
    bool offChanger = false;
    bool sortBool = true;

    int middleColumn = 0;
    int countRow = 1;

    QTreeWidgetItem* middleItem = nullptr;
    QStatusBar* sBar;

    QString line;

    QList<QSharedPointer<ProcessObject>>poolParse;
    TelegramJacket* tgObject = nullptr;

    int countOfTopItems;


    QSystemTrayIcon* trayIcon = nullptr;
    QDateTime fullTimeWork;

    bool windowShow = false;

    QTimer* timerUpdate = nullptr;
};


