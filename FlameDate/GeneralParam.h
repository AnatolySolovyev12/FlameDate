#pragma once

#include <QMainWindow>
#include "ui_GeneralParam.h"

class GeneralParam : public QMainWindow
{
	Q_OBJECT

public:
	GeneralParam(QWidget *parent = nullptr);
	~GeneralParam();

private:
	Ui::GeneralParamClass ui;
};
