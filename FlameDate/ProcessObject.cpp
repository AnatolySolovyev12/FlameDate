#include "ProcessObject.h"

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
	m_URL.replace(QRegularExpression(pattern), ""); // избавляемся от управляющих символов путём замены через регулярку. Тогда спокойно можно вписывать адрес файла как есть из свойств файла.

	m_deadlineDays = deadlineDays;
	m_checkParse = checkParse;
	m_checkSend = checkSend;

	m_timeForCheck = timeForCheck;
	m_column = column;
	m_row = row;

	if (m_checkParse || m_checkSend)
		classTimer->start(5000); // каждые 10 минут 600000
	else
		classTimer->stop();
}


void ProcessObject::classTimerIsDone()
{
	check();
}


void ProcessObject::check()
{
	QSharedPointer<QAxObject>excelDonor(new QAxObject("Excel.Application", 0));
	QSharedPointer<QAxObject>workbooksDonor(excelDonor.data()->querySubObject("Workbooks"));
	QSharedPointer<QAxObject>workbookDonor(workbooksDonor.data()->querySubObject("Open(const QString&)", m_URL));
	QSharedPointer<QAxObject>sheetsDonor(workbookDonor.data()->querySubObject("Worksheets"));
	QSharedPointer<QAxObject>sheetDonor(sheetsDonor.data()->querySubObject("Item(int)", 1));
	QSharedPointer<QAxObject>dateInFilePtr(sheetDonor.data()->querySubObject("Cells(int,int)", m_column, m_row));

	QString dateInFileString = dateInFilePtr.data()->property("Value").toString();

	workbookDonor.data()->dynamicCall("Close()");
	excelDonor.data()->dynamicCall("Quit()");

	QDate testDate = QDate::fromString(dateInFileString, "dd.MM.yyyy");

	qDebug() << "TestDate " << testDate.toString("dd.MM.yyyy");
	qDebug() << "CurrDate " << QDate::currentDate().toString("dd.MM.yyyy");

	if (QDate::currentDate().daysTo(testDate) < m_deadlineDays.toInt())
	{
		QString messegeString = QString::number(QDate::currentDate().daysTo(testDate)) + " дней осталось до сдачи заказчику " + m_name;
		if (m_checkSend)
		{
			emit messageReceived(messegeString);

		}
	}
	else
		qDebug() << "NORMAL";

}


QString ProcessObject::getStartString(QString any)
{
	return 0;
}
