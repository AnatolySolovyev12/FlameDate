﻿#pragma once

#include <QObject>
#include <QFile>
#include <QTimer>
#include <QDateTime>
#include <windows.h>
#include <tlhelp32.h>

#include <QAxWidget>
#include <QAxObject>

#include <QSharedPointer.h>

#include <QRegularExpression>

#include <QFileInfo>

#include <QtMath>


class ProcessObject : public QObject
{
	Q_OBJECT

public:
	ProcessObject(QObject* parent = nullptr);

	void setParam(QString name, QString URL, QString deadlineDays, bool checkParse, bool checkSend, QString timeForCheck, QString rows, QString columns, QString tgIds, QString list, QString rowHead);
	void check();

signals:
	void messageReceived(const QString&, const QString&);

private:
	void classTimerIsDone();

private:
	QString m_name;
	QString m_URL;
	QString m_deadlineDays;
	bool m_checkParse = false;
	bool m_checkSend = false;
	QString m_timeForCheck;
	QString m_rows;
	QString m_columns;
	QString m_tgIds;
	QString m_list;
	QString m_rowHead;
	QTimer* classTimer = nullptr;
	QString pattern = "[\u200E\u200F\u202A\u202B\u202C\u202D\u202E]";
	bool canMessegeSend = true;
	QList<int>minimalDate;

	


};
