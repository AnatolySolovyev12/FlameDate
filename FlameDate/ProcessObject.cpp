#include "ProcessObject.h"

ProcessObject::ProcessObject(QObject* parent)
	: QObject(parent), classTimer(new QTimer())
{
	AttachConsole(ATTACH_PARENT_PROCESS);

	connect(classTimer, &QTimer::timeout, this, &ProcessObject::classTimerIsDone);
	classTimer->stop();
}


void ProcessObject::setParam(QString name, QString URL, QString deadlineDays, bool checkParse, bool checkSend, QString timeForCheck, QString rows, QString columns, QString tgIds, QString list, QString rowHead)
{
	m_name = name;

	m_URL = URL;
	m_URL.replace(QRegularExpression(pattern), ""); // избавляемся от управляющих символов путём замены через регулярку. Тогда спокойно можно вписывать адрес файла как есть из свойств файла.

	m_deadlineDays = deadlineDays;
	m_checkParse = checkParse;
	m_checkSend = checkSend;

	m_timeForCheck = timeForCheck;
	m_rows = rows;
	m_columns = columns;
	m_tgIds = tgIds;
	m_list = list;
	m_rowHead = rowHead;

	if (m_checkParse)
	{
		if (classTimer->isActive())
		{
			classTimer->stop();
			classTimer->start(60000); // каждую минуту 60000
		}
		else
			classTimer->start(60000); // каждую минуту 60000
	}
	else
		classTimer->stop();
}


void ProcessObject::classTimerIsDone()
{
	QtConcurrent::run([this]() { check(); });
}


void ProcessObject::check()
{
	HRESULT hr = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED); // без инициализации COM-объектов для данного потока не откроется Excel. COM объекты требуют вызова CoInitialize (или CoInitializeEx) в каждом потоке, в котором будут использоваться COM функции.
	if (FAILED(hr)) {
		qDebug() << "Failed to initialize COM in this thread";
		return;
	}

	QTime testTime = QTime::fromString(m_timeForCheck, "hh:mm:ss");

	qDebug() << m_name << " " << testTime.toString() << " " << QTime::currentTime().toString() << " " << QTime::currentTime().secsTo(testTime);

	if (QTime::currentTime().secsTo(testTime) > 0)
	{
		if (QTime::currentTime().secsTo(testTime) < 300)
		{
			qDebug() << m_name << " " << "less then 3 min";

			QFileInfo directoryFile(m_URL);

			if (!directoryFile.exists() || !directoryFile.isFile()) {

				qDebug() << "Error: for " << m_name << " can't find file from Directory!";
				return;
			}

			QSharedPointer<QAxObject>excelDonor(new QAxObject("Excel.Application", 0));

			if (excelDonor.data()->isNull())
			{
				qDebug() << "Error in check(): Excel object is NULL. Maybe Excel not instaled.";
				return;
			}

			QSharedPointer<QAxObject>workbooksDonor(excelDonor.data()->querySubObject("Workbooks"));
			QSharedPointer<QAxObject>workbookDonor(workbooksDonor.data()->querySubObject("Open(const QString&)", m_URL));
			QSharedPointer<QAxObject>sheetsDonor(workbookDonor.data()->querySubObject("Worksheets"));
			QSharedPointer<QAxObject>sheetDonor(sheetsDonor.data()->querySubObject("Item(int)", m_list.toInt())); // лист с которым будем работать

			QSharedPointer<QAxObject>usedRangeColDonor(sheetDonor->querySubObject("UsedRange")); // свойоство листа
			QSharedPointer<QAxObject>columnsDonor(usedRangeColDonor->querySubObject("Columns")); // столбец
			int countColsDonor = columnsDonor->property("Count").toInt(); // переводим в int

			QList<QString>dateMassiveFromFile;

			for (int startingCol = m_columns.toInt(); startingCol < countColsDonor; startingCol++)
			{

				QSharedPointer<QAxObject>dateInFilePtr(sheetDonor.data()->querySubObject("Cells(int,int)", m_rows, startingCol));
				QString dateInFileString = dateInFilePtr.data()->property("Value").toString();

				if (dateInFileString == "")
					continue;

				QSharedPointer<QAxObject>headText(sheetDonor.data()->querySubObject("Cells(int,int)", m_rowHead.toInt(), startingCol)); // нужно добавить выбор строки с шапкой
				QString headTextInFileString = headText.data()->property("Value").toString();

				qDebug() << dateInFileString;

				if (dateInFileString.length() > 10)
				{
					dateInFileString = QDateTime::fromString(dateInFileString, Qt::ISODate).date().toString("dd.MM.yyyy");
				}

				QDate testDate = QDate::fromString(dateInFileString, "dd.MM.yyyy");

				qDebug() << m_name << " " << "CurrDate " << QDate::currentDate().toString("dd.MM.yyyy") << " " << "TestDate " << testDate.toString("dd.MM.yyyy");

				if (testDate.toString("dd.MM.yyyy") == "")
					continue;

				if (QDate::currentDate().daysTo(testDate) < m_deadlineDays.toInt())
				{
					minimalDate.push_back(QDate::currentDate().daysTo(testDate));

					QString messegeString = (QDate::currentDate().daysTo(testDate) > 0) ? (headTextInFileString + " действует " + QString::number(QDate::currentDate().daysTo(testDate)) + " дней") : (headTextInFileString + " просрочилось " + QString::number(qFabs(QDate::currentDate().daysTo(testDate))) + " дней");

					qDebug() << messegeString << "\n";

					dateMassiveFromFile.append(messegeString);
				}
				else
					qDebug() << m_name << " more then " << m_deadlineDays.toInt() << "\n";
			}

			QString finalMessegeString;

			for (int firstColumnInFile = 1; firstColumnInFile < m_columns.toInt(); firstColumnInFile++)
			{
				QSharedPointer<QAxObject>headText(sheetDonor.data()->querySubObject("Cells(int,int)", m_rows, firstColumnInFile));
				QString headTextInFileString = headText.data()->property("Value").toString();
				finalMessegeString += headTextInFileString + "\n";
			}

			QSharedPointer<QAxObject>headText(sheetDonor.data()->querySubObject("Cells(int,int)", m_rows, 2));
			QString headTextInFileString = headText.data()->property("Value").toString();

			for (auto& val : dateMassiveFromFile)
			{
				finalMessegeString += val + "\n";
			}

			if (m_checkSend && canMessegeSend && dateMassiveFromFile.length())
			{
				qDebug() << finalMessegeString;

				auto minDateInArray = std::min_element(minimalDate.begin(), minimalDate.end());
				int indexMininmalDate = std::distance(minimalDate.begin(), minDateInArray);

				emit messageReceived(m_tgIds + "@" + finalMessegeString, QString::number(minimalDate[indexMininmalDate]));
				canMessegeSend = false;

				QTimer::singleShot(240000, [this]() {canMessegeSend = true; });
			}

			workbookDonor.data()->dynamicCall("Close()");
			excelDonor.data()->dynamicCall("Quit()");

			minimalDate.clear();
		}
		else
			qDebug() << m_name << "more then 3 min\n";
	}

	CoUninitialize(); // освобождаем COM из данного потока.
}
