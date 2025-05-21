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

	QString m_name;
	QString m_directory;
	QString m_deadlineLine;
	QString m_timeLine;
	QString m_rowLine;
	QString m_columnLine;
	QString m_telegramLine;

	QString hostName;
	QString odbc;
	QString userNameDb;
	QString passDb;

signals:
	void refreshSetting();

private slots:
	void writeCurrent();

private:
	Ui::GeneralParamClass ui;
	QString fileForSend;
};
