#include "FlameDate.h"

FlameDate::FlameDate(QWidget* parent)
	: QMainWindow(parent), tgObject(new TelegramJacket), timerUpdate(new QTimer), myGenParam(new GeneralParam)
{
	tgObject->setWeekMask(myGenParam->getMessegeWeekMaskInGeneral());

	connect(timerUpdate, &QTimer::timeout, tgObject, &TelegramJacket::getUpdates);
	timerUpdate->start(12000);

	refreshSettingInFlameDate();
	startingImportXml();
	getTokenFromFile();
}


void FlameDate::importXml()
{
	QString addFileDonor = QFileDialog::getOpenFileName(0, "Choose XML for import", "", "*.xml");

	if (addFileDonor == "")
	{
		return;
	}

	QFile file(addFileDonor);
	QXmlStreamReader xmlReader(&file);

	file.open(QFile::ReadWrite);

	loopXmlReader(xmlReader);

	file.close();

	QFile txtFile("tree.txt");

	if (!(txtFile.open(QIODevice::WriteOnly | QIODevice::Truncate))) // Truncate - для очистки содержимого файла
	{
		qDebug() << "Don't find browse file. Add a directory with a tree.";
		return;
	}

	QTextStream in(&txtFile);

	in << addFileDonor << Qt::endl;

	if (addFileDonor == "")
		txtFile.remove();

	txtFile.close();
}


void FlameDate::loopXmlReader(QXmlStreamReader& xmlReader)
{
	while (!xmlReader.atEnd())
	{
		if (xmlReader.readNextStartElement())
		{
			if (xmlReader.hasError())
			{
				qDebug() << "XML error:" << xmlReader.errorString();
				break;
			}

			if (xmlReader.name().toString() == "Root")
				continue;
	
			poolParse.append(QSharedPointer<ProcessObject>::create());

			QString name;
			QString URL;
			QString deadlineDays;
			bool checkParse = false;
			bool checkSend = false;
			QString timeForCheck;
			QString rows;
			QString columns;
			QString tgIds;
			QString list;
			QString rowHead;

			for (QXmlStreamAttribute& val : xmlReader.attributes())
			{
				if (val.name().toString() == "Name") name = val.value().toString();

				if (val.name().toString() == "Directory") URL = val.value().toString();

				if (val.name().toString() == "Update") deadlineDays = val.value().toString();

				if (val.name().toString() == "Check")
				{
					if (val.value().toString() == "1")
						checkParse = true;
					else
						checkParse = false;
				}

				if (val.name().toString() == "Send")
				{
					if (val.value().toString() == "1")
						checkSend = true;
					else
						checkSend = true;
				}

				if (val.name().toString() == "Time") timeForCheck = val.value().toString();

				if (val.name().toString() == "Column") rows = val.value().toString();

				if (val.name().toString() == "Row") columns = val.value().toString();

				if (val.name().toString() == "Id") tgIds = val.value().toString();

				if (val.name().toString() == "List") list = val.value().toString();

				if (val.name().toString() == "RowHead") rowHead = val.value().toString();
			}

			poolParse.last().data()->setParam(name, URL, deadlineDays, checkParse, checkSend, timeForCheck, rows, columns, tgIds, list, rowHead);
			connect(poolParse.last().data(), &ProcessObject::messageReceived, tgObject, &TelegramJacket::sendMessage);
		}
	}
}


void FlameDate::startingImportXml()
{
	/* Открываем файл для Чтения с помощью пути, указанного в lineEditWrite */

	QFile file("tree.txt");

	if (!file.open(QIODevice::ReadOnly))
	{
		
		qDebug() << "Don't find browse file. Add a directory with a tree.";
		return;
	}

	QTextStream out(&file);

	QString myLine = out.readLine(); // метод readLine() считывает одну строку из потока

	if (myLine == "")
	{
		
		qDebug() << "Don't find browse file. Add a directory with a tree.";
		return;
	}

	file.close();

	QFile xmlFile(myLine);

	if (xmlFile.exists())
	{
		xmlFile.open(QFile::ReadWrite);
	}
	else
	{
	
		qDebug() << "Don't find browse file. Add a directory with a tree.";
		return;
	}

	QXmlStreamReader xmlReader(&xmlFile);

	loopXmlReader(xmlReader);

	xmlFile.close();
}


void FlameDate::getTokenFromFile()
{
	QFile file("token.txt");

	if (!file.open(QIODevice::ReadOnly))
	{
		qDebug() << "Don't find browse file. Add a directory with a token (token.txt).";
		return;
	}

	QTextStream out(&file);

	QString myLine = out.readLine(); // метод readLine() считывает одну строку из потока

	if (myLine == "")
	{
		qDebug() << "Don't find browse file. Add a directory with a token (token.txt).";
		file.close();
		return;
	}

	tgObject->setToken(myLine);
	file.close();
}


void FlameDate::showGeneralParam()
{
	myGenParam->show();
}


void FlameDate::refreshSettingInFlameDate()
{
	tgObject->setWeekMask(myGenParam->getMessegeWeekMaskInGeneral());
}
