#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_FlameDate.h"

class FlameDate : public QMainWindow
{
    Q_OBJECT

public:
    FlameDate(QWidget *parent = nullptr);
    ~FlameDate();

private:
    Ui::FlameDateClass ui;
};
