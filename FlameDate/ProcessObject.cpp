#include "ProcessObject.h"

ProcessObject::ProcessObject(QObject* parent)
	: QObject(parent), classTimer(new QTimer())
{
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
		classTimer->start(15000); // каждую минуту 60000
	else
		classTimer->stop();

	qDebug() << "\n" << name << URL << deadlineDays << checkParse << checkSend << timeForCheck << rows << columns << tgIds << list << rowHead;
}


void ProcessObject::classTimerIsDone()
{
	QtConcurrent::run([this]() { check(); });
}


void ProcessObject::check()
{
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

			QXlsx::Document xlsxR(m_URL);

			int countColsDonor = m_columns.toInt() - 1;

			if (xlsxR.load()) // load excel file
			{
				xlsxR.selectSheet(m_list); // select a sheet. current sheet is 'added sheet'.

				for (int col = m_columns.toInt();; col++)
				{
					if (xlsxR.read(m_rowHead.toInt(), col).toString() != "")
					{
						countColsDonor++;
					}
					else
						break;
				}
			}

			QList<QString>dateMassiveFromFile;

			for (int startingCol = m_columns.toInt(); startingCol < countColsDonor; startingCol++)
			{

				QString dateInFileString = xlsxR.read(m_rows.toInt(), startingCol).toString();


				if (dateInFileString == "")
					continue;

				QString headTextInFileString = xlsxR.read(m_rowHead.toInt(), startingCol).toString();

				dateInFileString = QDateTime::fromString(dateInFileString, Qt::ISODate).date().toString("dd.MM.yyyy");

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
				QString headTextInFileString = xlsxR.read(m_rows.toInt(), firstColumnInFile).toString();
				finalMessegeString += headTextInFileString + "\n";
			}

			QString headTextInFileString = xlsxR.read(m_rows.toInt(), 2).toString();

			for (auto& val : dateMassiveFromFile)
			{
				finalMessegeString += val + "\n";
			}

			if (m_checkSend && canMessegeSend && dateMassiveFromFile.length())
			{
				qDebug() << finalMessegeString;

				auto minDateInArray = std::min_element(minimalDate.begin(), minimalDate.end()); // для определения минимальной даты
				int indexMininmalDate = std::distance(minimalDate.begin(), minDateInArray);

				emit messageReceived(m_tgIds + "@" + finalMessegeString, QString::number(minimalDate[indexMininmalDate]));
				canMessegeSend = false;
				
				//QTimer::singleShot(240000, [this]() {canMessegeSend = true; });
				void emitMessageRefresh();
			}
			minimalDate.clear();
		}
		else
			qDebug() << m_name << "more then 3 min\n";
	}
}


void ProcessObject::refreshStartMessage()
{
	QTimer::singleShot(240000, [this]() {canMessegeSend = true; });
}