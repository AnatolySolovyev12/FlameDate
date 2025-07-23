#pragma once

#include <QMainWindow>
#include <QFileDialog>
#include <QString>

class GeneralParam : public QMainWindow
{
	Q_OBJECT

public:
	GeneralParam(QWidget* parent = nullptr);

	void readDefaultConfig();

	QList<int> getMessegeWeekMaskInGeneral();

	QString m_name;
	QString m_directory;
	QString m_deadlineLine;
	QString m_timeLine;
	QString m_rowLine;
	QString m_columnLine;
	QString m_telegramLine;
	QString m_list;
	QString m_rowHead;

private:
	QString fileForSend;
	QList<int>messegeWeekMaskInGeneral{ 0,0,0,0,0,0,0,0 };
};
