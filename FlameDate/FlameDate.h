#pragma once

#include <QMainWindow>

#include <ProcessObject.h>
#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamAttribute>
#include <TelegramJacket.h>
#include "GeneralParam.h"

class FlameDate : public QMainWindow
{
    Q_OBJECT

public:

    FlameDate(QWidget* parent = nullptr);

    void importXml();
    void loopXmlReader(QXmlStreamReader& xmlReader);
    void startingImportXml();

    void getTokenFromFile();

    void showGeneralParam();

    void refreshSettingInFlameDate();

private:
    bool offChanger = false;
    bool sortBool = true;

    int middleColumn = 0;
    int countRow = 1;

    QString line;

    QList<QSharedPointer<ProcessObject>>poolParse;
    TelegramJacket* tgObject = nullptr;

    int countOfTopItems;

    QDateTime fullTimeWork;

    bool windowShow = false;

    QTimer* timerUpdate = nullptr;

    GeneralParam* myGenParam = nullptr;
};


