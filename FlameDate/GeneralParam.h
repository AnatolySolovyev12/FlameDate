#pragma once
/*
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
*/



#pragma once

#include <QMainWindow>
#include "ui_GeneralParam.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QString>

class GeneralParam : public QMainWindow
{
	Q_OBJECT

public:
	GeneralParam(QWidget* parent = nullptr);
	~GeneralParam();

	void readDefaultConfig();
	void fileNameSetter(QString any);


	QString smtpServer;
	QString smtpPort;
	QString userName;
	QString password;
	QString recipantTo;
	QString subject;

	QString hostName;
	QString odbc;
	QString userNameDb;
	QString passDb;

signals:
	void status(const QString&);

private slots:
	void writeCurrent();

private:
	Ui::GeneralParamClass ui;
	QString fileForSend;
};
