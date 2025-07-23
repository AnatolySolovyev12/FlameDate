#include "FlameDate.h"



FlameDate::FlameDate(QWidget* parent)
	: QMainWindow(parent), sBar(new QStatusBar()), tgObject(new TelegramJacket), timerUpdate(new QTimer), myGenParam(new GeneralParam)
{
	ui.setupUi(this);

	QMainWindow::setStatusBar(sBar);

	tgObject->setWeekMask(myGenParam->getMessegeWeekMaskInGeneral());

	//myGenParam->setWindowIcon(QIcon("iconParam.png"));

	connect(timerUpdate, &QTimer::timeout, tgObject, &TelegramJacket::getUpdates);
	timerUpdate->start(12000);

	refreshSettingInFlameDate();
	startingImportXml();
	initializationPoolFunc();

	getTokenFromFile();
}


void FlameDate::importXml()
{
	/* Открываем файл для Чтения с помощью пути, указанного в lineEditWrite */

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
		// qDebug() << "Don't find browse file. Add a directory with a tree.";
		sBar->showMessage("Don't find browse file. Add a directory with a tree.", 10000);
		return;
	}

	QTextStream in(&txtFile);

	in << addFileDonor << Qt::endl;

	if (addFileDonor == "")
		txtFile.remove();

	txtFile.close();

	initializationPoolFunc();
}


void FlameDate::loopXmlReader(QXmlStreamReader& xmlReader)
{
	QList <QTreeWidgetItem*> myList;

	QTreeWidgetItem* some = nullptr;;

	ui.treeWidget->clear(); // очищаем дерево перед загрузкой новых данных

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

			if (!myList.isEmpty()) 
			{ 
				some = new QTreeWidgetItem(myList.constLast());
			}
			else 
			{
				some = new QTreeWidgetItem(ui.treeWidget);
			}

			myList.push_back(some);

			offChanger = true;

			some->setBackground(0, QColor(221, 221, 221, 255));
			some->setBackground(1, QColor(245, 216, 183, 255));
			some->setBackground(2, QColor(217, 225, 187, 255));
			some->setBackground(5, QColor(98, 244, 249, 255));
			some->setBackground(6, QColor(125, 198, 210, 255));
			some->setBackground(7, QColor(119, 168, 142, 255));
			some->setBackground(8, QColor(79, 168, 142, 255));
			some->setBackground(9, QColor(88, 122, 111, 255));
			some->setBackground(10, QColor(94, 140, 113, 255));

			some->setText(0, xmlReader.name().toString());

			for (QXmlStreamAttribute& val : xmlReader.attributes())
			{
				if (val.name().toString() == "Name") some->setText(0, val.value().toString());

				if (val.name().toString() == "Directory") some->setText(1, val.value().toString());

				if (val.name().toString() == "Update") some->setText(2, val.value().toString());

				if (val.name().toString() == "Check")
				{
					if (val.value().toString() == "1")
						some->setCheckState(3, Qt::Checked);
					else
						some->setCheckState(3, Qt::Unchecked);
				}

				if (val.name().toString() == "Send")
				{
					if (val.value().toString() == "1")
						some->setCheckState(4, Qt::Checked);
					else
						some->setCheckState(4, Qt::Unchecked);
				}

				if (val.name().toString() == "Time") some->setText(5, val.value().toString());

				if (val.name().toString() == "Column") some->setText(6, val.value().toString());

				if (val.name().toString() == "Row") some->setText(7, val.value().toString());

				if (val.name().toString() == "Id") some->setText(8, val.value().toString());

				if (val.name().toString() == "List") some->setText(9, val.value().toString());

				if (val.name().toString() == "RowHead") some->setText(10, val.value().toString());
			}

			offChanger = false;

		//	FlameDate::closeEditor(some);
		}

		if (xmlReader.isEndElement() && !myList.isEmpty())
			myList.pop_back();

		countOfTopItems = ui.treeWidget->topLevelItemCount();
	}
}


void FlameDate::startingImportXml()
{
	/* Открываем файл для Чтения с помощью пути, указанного в lineEditWrite */

	QFile file("tree.txt");

	if (!file.open(QIODevice::ReadOnly))
	{
		sBar->showMessage("Don't find browse file. Add a directory with a tree.", 10000);
		return;
	}

	QTextStream out(&file);

	QString myLine = out.readLine(); // метод readLine() считывает одну строку из потока

	if (myLine == "")
	{
		sBar->showMessage("Don't find browse file. Add a directory with a tree.", 10000);
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
		sBar->showMessage("Don't find browse file. Add a directory with a tree.", 10000);
		return;
	}
	
	QXmlStreamReader xmlReader(&xmlFile);

	loopXmlReader(xmlReader);

	xmlFile.close();
}


void FlameDate::initializationPoolFunc()
{
	countOfTopItems = ui.treeWidget->topLevelItemCount();

	poolParse.clear();

	for (int count = 0; count < countOfTopItems; count++)
	{
		if (ui.treeWidget->topLevelItem(count)->text(0).toStdString().length() > 500) 
		{
			ui.treeWidget->topLevelItem(count)->setText(0, "Not more then 500 signs");
		}

		if (ui.treeWidget->topLevelItem(count)->text(1).toStdString().length() > 500) 
		{
			ui.treeWidget->topLevelItem(count)->setText(1, "Not more then 500 signs");
		}

		if (ui.treeWidget->topLevelItem(count)->text(2).toInt() < 15 || ui.treeWidget->topLevelItem(count)->text(2).toInt() > 120) 
		{
			ui.treeWidget->topLevelItem(count)->setText(2, QString::number(15));
		}

		if (ui.treeWidget->topLevelItem(count)->text(5).isEmpty()) 
		{
			ui.treeWidget->topLevelItem(count)->setText(5, "07:00:00");
		}


		if (ui.treeWidget->topLevelItem(count)->text(6).toStdString().length() > 300) 
		{
			ui.treeWidget->topLevelItem(count)->setText(6, QString::number(1));
		}

		if (ui.treeWidget->topLevelItem(count)->text(7).toStdString().length() > 300) 
		{
			ui.treeWidget->topLevelItem(count)->setText(7, QString::number(1));
		}

		if (ui.treeWidget->topLevelItem(count)->text(8).toStdString().length() > 150) 
		{
			ui.treeWidget->topLevelItem(count)->setText(8, "Not more then 150 signs");
		}

		if (ui.treeWidget->topLevelItem(count)->text(10).toInt() < 1 || ui.treeWidget->topLevelItem(count)->text(10).toInt() > 50)
		{
			ui.treeWidget->topLevelItem(count)->setText(10, QString::number(1));
		}

		poolParse.append(QSharedPointer<ProcessObject>::create());

		poolParse.last().data()->setParam(
			ui.treeWidget->topLevelItem(poolParse.length() - 1)->text(0),
			ui.treeWidget->topLevelItem(poolParse.length() - 1)->text(1),
			ui.treeWidget->topLevelItem(poolParse.length() - 1)->text(2),
			ui.treeWidget->topLevelItem(poolParse.length() - 1)->checkState(3),
			ui.treeWidget->topLevelItem(poolParse.length() - 1)->checkState(4),
			ui.treeWidget->topLevelItem(poolParse.length() - 1)->text(5),
			ui.treeWidget->topLevelItem(poolParse.length() - 1)->text(6),
			ui.treeWidget->topLevelItem(poolParse.length() - 1)->text(7),
			ui.treeWidget->topLevelItem(poolParse.length() - 1)->text(8),
			ui.treeWidget->topLevelItem(poolParse.length() - 1)->text(9),
			ui.treeWidget->topLevelItem(poolParse.length() - 1)->text(10)

		);

		connect(poolParse.last().data(), &ProcessObject::messageReceived, tgObject, &TelegramJacket::sendMessage);
	}
}


void FlameDate::getTokenFromFile()
{
	QFile file("token.txt");

	if (!file.open(QIODevice::ReadOnly))
	{
		sBar->showMessage("Don't find browse file. Add a directory with a token (token.txt).", 10000);
		return;
	}

	QTextStream out(&file);

	QString myLine = out.readLine(); // метод readLine() считывает одну строку из потока

	if (myLine == "")
	{
		sBar->showMessage("Don't find browse file. Add a directory with a token (token.txt).", 10000);
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
	 mFlame_name = myGenParam->m_name;
	 mFlame_directory = myGenParam->m_directory;
	 mFlame_deadlineLine = myGenParam->m_deadlineLine;
	 mFlame_timeLine = myGenParam->m_timeLine;
	 mFlame_rowLine = myGenParam->m_rowLine;
	 mFlame_columnLine = myGenParam->m_columnLine;
	 mFlame_telegramLine = myGenParam->m_telegramLine;
	 mFlame_list = myGenParam->m_list;
	 mFlame_rowHead = myGenParam->m_rowHead;

	 tgObject->setWeekMask(myGenParam->getMessegeWeekMaskInGeneral());
}
