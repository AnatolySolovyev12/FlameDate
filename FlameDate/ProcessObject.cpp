#include "ProcessObject.h"
#include <chrono>

ProcessObject::ProcessObject(QObject* parent)
	: QObject(parent), classTimer(new QTimer())
{
	AttachConsole(ATTACH_PARENT_PROCESS);

	connect(classTimer, &QTimer::timeout, this, &ProcessObject::classTimerIsDone);
	classTimer->stop();
}


void ProcessObject::setParam(QString name, QString URL, QString deadlineDays, bool checkParse, bool checkSend, QString timeForCheck, QString column, QString row)
{
	m_name = name;
	m_URL = URL;
	m_deadlineDays = deadlineDays;
	m_checkParse = checkParse;
	m_checkSend = checkSend;

	m_timeForCheck = timeForCheck;
	m_column = column;
	m_row = row;


	if (m_checkParse || m_checkSend)
		classTimer->start(2000); // каждые 10 минут 600000
	else
		classTimer->stop();
}


void ProcessObject::classTimerIsDone()
{
	check();
}


void ProcessObject::check()
{
	QString textDate = "12.07.2025";

	QDate testDate = QDate::fromString(textDate, "dd.MM.yyyy");

	qDebug() << "TestDate " << testDate.toString("dd.MM.yyyy");
	qDebug() << "CurrDate " << QDate::currentDate().toString("dd.MM.yyyy");

	if (QDate::currentDate().daysTo(testDate) < m_deadlineDays.toInt())
		qDebug() << "ALARM!";
	else
		qDebug() << "NORMAL";




	/*
	if (false) ////////
	{
		qDebug() << QDateTime::currentDateTime() << ": " << m_name << "OK";
		return;
	}


	qDebug() << QDateTime::currentDateTime() << ": " << m_name << " NOT WORK";

	if (m_checkSend)
		emit messageReceived("Не работает " + m_name);

	QString temporary = getStartString(m_URL);

	if (m_checkParse)
		QTimer::singleShot(5000, [temporary]() {

		system(temporary.toUtf8().constData());

			});

			*/
}


QString ProcessObject::getStartString(QString any)
{
	return 0;
}
