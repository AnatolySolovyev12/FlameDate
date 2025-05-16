#include "FlameDate.h"

FlameDate::FlameDate(QWidget* parent)
	: QMainWindow(parent), sBar(new QStatusBar()), tgObject(new TelegramJacket)
{
	ui.setupUi(this);

	trayIcon = new QSystemTrayIcon(this);
	trayIcon->setIcon(QIcon("icon.png"));

	QMenu* menu = new QMenu(this);
	QAction* restoreAction = menu->addAction("CMD open and connect");
	QAction* restoreActionHide = menu->addAction("CMD disconnect");
	QAction* quitAction = menu->addAction("Exit");

	connect(restoreAction, &QAction::triggered, this, &FlameDate::cmdOpen);
	connect(restoreActionHide, &QAction::triggered, this, &FlameDate::cmdClose);
	connect(quitAction, &QAction::triggered, qApp, &QApplication::quit);

	trayIcon->setContextMenu(menu);
	trayIcon->setVisible(true);

	connect(trayIcon, &QSystemTrayIcon::activated, this, &FlameDate::iconActivated);

	connect(ui.pushButtonAdd, &QPushButton::clicked, this, &FlameDate::addItemInList);
	connect(ui.pushButtonAddMinus, &QPushButton::clicked, this, &FlameDate::deleteItemInList);

	connect(ui.treeWidget, &QTreeWidget::itemDoubleClicked, this, &FlameDate::setData);
	connect(ui.treeWidget, &QTreeWidget::itemChanged, this, &FlameDate::closeEditor);
	connect(ui.treeWidget, &QTreeWidget::itemClicked, this, &FlameDate::otherItemWasChecked);

	connect(ui.pushButtonExport, &QPushButton::clicked, this, &FlameDate::exportXml);
	connect(ui.pushButtonImport, &QPushButton::clicked, this, &FlameDate::importXml);
	connect(ui.pushButtonRefresh, &QPushButton::clicked, this, &FlameDate::initializationPoolFunc);

	QMainWindow::setStatusBar(sBar);

	startingImportXml();
	initializationPoolFunc();
}


FlameDate::~FlameDate()
{
}


void FlameDate::addItemInList()
{
	QTreeWidgetItem* any = nullptr;

	if (ui.treeWidget->currentItem() == nullptr)
	{
		any = new QTreeWidgetItem();
		ui.treeWidget->addTopLevelItem(any);
	}
	else
		return;

	countOfTopItems = ui.treeWidget->topLevelItemCount();

	int column = ui.treeWidget->currentColumn();

	offChanger = true;

	any->setText(0, "new");

	any->setText(2, QString::number(30));

	any->setBackground(0, QColor(221, 221, 221, 255));
	any->setBackground(1, QColor(245, 216, 183, 255));
	any->setBackground(2, QColor(217, 225, 187, 255));
	any->setCheckState(3, any->checkState(3));
	any->setCheckState(4, any->checkState(4));


	any->setBackground(5, QColor(98, 244, 249, 255));
	any->setBackground(6, QColor(125, 198, 210, 255));
	any->setBackground(7, QColor(119, 168, 142, 255));

	offChanger = false;

	poolParse.append(QSharedPointer<ProcessObject>::create());
	//poolParse.push_back(QSharedPointer<uniqueParseObject>(new uniqueParseObject));
	poolParse.last().data()->setParam(
		ui.treeWidget->topLevelItem(poolParse.length() - 1)->text(0), 
		ui.treeWidget->topLevelItem(poolParse.length() - 1)->text(1), 
		ui.treeWidget->topLevelItem(poolParse.length() - 1)->text(2), 
		ui.treeWidget->topLevelItem(poolParse.length() - 1)->checkState(3),
		ui.treeWidget->topLevelItem(poolParse.length() - 1)->checkState(4), 
		ui.treeWidget->topLevelItem(poolParse.length() - 1)->text(5), 
		ui.treeWidget->topLevelItem(poolParse.length() - 1)->text(6), 
		ui.treeWidget->topLevelItem(poolParse.length() - 1)->text(7)
	);

	connect(poolParse.last().data(), &ProcessObject::messageReceived, tgObject, &TelegramJacket::sendMessage);

	any = nullptr;
}


void FlameDate::deleteItemInList()
{
	if (ui.treeWidget->currentItem() == nullptr) return;
	countOfTopItems = ui.treeWidget->topLevelItemCount();

	poolParse.removeAt(ui.treeWidget->indexOfTopLevelItem(ui.treeWidget->currentItem()));
	ui.treeWidget->takeTopLevelItem(ui.treeWidget->indexOfTopLevelItem(ui.treeWidget->currentItem()));
}


void FlameDate::setData() // � ������ �������� ����� � ������ ��������� ��������
{
	QTreeWidgetItem* any = ui.treeWidget->currentItem(); // ����������� ��������� ��������� ������
	int column = ui.treeWidget->currentColumn(); // ����������� ���������� ����� �������� ������� (������ ���������� � 0-���)

	if (column == 3 || column == 4) return; // �� ��� ������������� ������ �������� �������            

	//qDebug() << "OPEN EDITOR";

	middleColumn = column;
	middleItem = any;

	ui.treeWidget->openPersistentEditor(any, column); // ��������� �������������� ������
	ui.treeWidget->editItem(any, column); // ��������� ��������
}


void FlameDate::closeEditor(QTreeWidgetItem* any) // ���� �������� ��������� � ������ �������� ��������� (����� ������� Enter)
{
	if (offChanger) return; // ������������ ������������� ���������� ���� ������� ��� ��������� ������

	QString temporary = any->text(0).trimmed(); // ������� �������
	any->setText(0, temporary);

	temporary = any->text(1).trimmed(); // ������� �������
	any->setText(1, temporary);

	temporary = any->text(2).trimmed(); // ������� �������
	any->setText(2, temporary);

	temporary = any->text(5).trimmed(); // ������� �������
	any->setText(5, temporary);

	temporary = any->text(6).trimmed(); // ������� �������
	any->setText(6, temporary);

	temporary = any->text(7).trimmed(); // ������� �������
	any->setText(7, temporary);

	offChanger = true;

	any->setCheckState(3, any->checkState(3));
	any->setCheckState(4, any->checkState(4));

	if (any->text(2).toInt() < 30) // ������ ���� ���-�� �������� � ���������
	{
		any->setText(2, QString::number(30));
	}

	if (any->checkState(3) == Qt::Unchecked) // ������ ���� ���-�� �������� � ���������
	{
		any->setBackground(3, QColor("white"));
	}
	else
	{
		any->setBackground(3, QColor(128, 243, 150, 255));
	}

	if (any->checkState(4) == Qt::Unchecked) // ������ ���� ���-�� �������� � ���������
	{
		any->setBackground(4, QColor("white"));
	}
	else
	{
		any->setBackground(4, QColor(128, 243, 150, 255));
	}

	offChanger = false;

	ui.treeWidget->closePersistentEditor(middleItem, middleColumn); // ��������� ��������
}


void FlameDate::otherItemWasChecked(QTreeWidgetItem* any) // ��������� �������� �������� � ������ ������������ �� ������ �������
{
	if (offChanger) return;

	int column = ui.treeWidget->currentColumn();
	//qDebug() << "Checked " << any->text(column) << ui.treeWidget->indexOfTopLevelItem(ui.treeWidget->currentItem()) << "Size PoolParse " << poolParse.length();/////////////////////////

	if (any == middleItem && column == middleColumn)
		return;

	QString temporary = any->text(0).trimmed(); // ������� �������
	any->setText(0, temporary);

	temporary = any->text(1).trimmed(); // ������� �������
	any->setText(1, temporary);

	temporary = any->text(2).trimmed(); // ������� �������
	any->setText(2, temporary);

	temporary = any->text(5).trimmed(); // ������� �������
	any->setText(5, temporary);

	temporary = any->text(6).trimmed(); // ������� �������
	any->setText(6, temporary);

	temporary = any->text(7).trimmed(); // ������� �������
	any->setText(7, temporary);

	ui.treeWidget->closePersistentEditor(middleItem, middleColumn);
	middleItem = nullptr;
}


void FlameDate::exportXml()
{
	QString savedFile = QFileDialog::getSaveFileName(0, "Save XML", "", "*.xml");
	QFile file(savedFile);
	file.open(QIODevice::WriteOnly);

	QXmlStreamWriter xmlWriter(&file); // �������������� ������ QXmlStreamWriter ������� �� ������ � ������� ����� ��������

	xmlWriter.setDevice(&file);
	xmlWriter.setAutoFormatting(true); // ���������� ��� ��������������� �������� �� ����� ������
	xmlWriter.setAutoFormattingIndent(2); // ����� ���������� �������� � ������� (�� ��������� 4)
	xmlWriter.writeStartDocument(); // ����� � ����� ��������� ���������

	int countOfTopItems = ui.treeWidget->topLevelItemCount();

	xmlWriter.writeStartElement("Root");

	if (countOfTopItems)
	{
		for (int val = 0; val < countOfTopItems; val++)
		{
			QTreeWidgetItem* any = ui.treeWidget->topLevelItem(val);

			recursionXmlWriter(any, xmlWriter);
		}
	}

	xmlWriter.writeEndElement();

	xmlWriter.writeEndDocument();

	file.close();
}


void FlameDate::recursionXmlWriter(QTreeWidgetItem* some, QXmlStreamWriter& someXmlWriter)
{
	if (some->childCount())
	{
		someXmlWriter.writeStartElement("Point"); // ��������� ��������� ������� "��������" xml

		someXmlWriter.writeAttribute("Name", some->text(0)); // ����������� �������� ������ ��������� ������� ��������  

		someXmlWriter.writeAttribute("Directory", some->text(1));

		someXmlWriter.writeAttribute("Update", some->text(2));

		if (some->text(2) != nullptr)
		{
			if (some->checkState(3) == Qt::Unchecked)
				someXmlWriter.writeAttribute("Check", "0");
			else
				someXmlWriter.writeAttribute("Check", "1");

			if (some->checkState(4) == Qt::Unchecked)
				someXmlWriter.writeAttribute("Send", "0");
			else
				someXmlWriter.writeAttribute("Send", "1");
		}

		someXmlWriter.writeAttribute("Time", some->text(5));

		someXmlWriter.writeAttribute("Column", some->text(6));

		someXmlWriter.writeAttribute("Row", some->text(7));


		int count = some->childCount();

		for (int x = 0; x < count; x++)
		{
			recursionXmlWriter(some->child(x), someXmlWriter);
		}

		someXmlWriter.writeEndElement();
	}
	else
	{
		someXmlWriter.writeStartElement("Point"); // ��������� ��������� ������� "��������" xml  

		someXmlWriter.writeAttribute("Name", some->text(0)); // ����������� �������� ������ ��������� ������� ��������   

		someXmlWriter.writeAttribute("Directory", some->text(1)); //

		someXmlWriter.writeAttribute("Update", some->text(2));

		if (some->text(2) != nullptr)
		{
			if (some->checkState(3) == Qt::Unchecked)
				someXmlWriter.writeAttribute("Check", "0");
			else
				someXmlWriter.writeAttribute("Check", "1");

			if (some->checkState(4) == Qt::Unchecked)
				someXmlWriter.writeAttribute("Send", "0");
			else
				someXmlWriter.writeAttribute("Send", "1");
		}

		someXmlWriter.writeAttribute("Time", some->text(5));

		someXmlWriter.writeAttribute("Column", some->text(6));

		someXmlWriter.writeAttribute("Row", some->text(7));

		someXmlWriter.writeEndElement();

		return;
	}
}


void FlameDate::importXml()
{
	/* ��������� ���� ��� ������ � ������� ����, ���������� � lineEditWrite */

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

	if (!(txtFile.open(QIODevice::WriteOnly | QIODevice::Truncate))) // Truncate - ��� ������� ����������� �����
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

	ui.treeWidget->clear(); // ������� ������ ����� ��������� ����� ������

	while (!xmlReader.atEnd())
	{
		if (xmlReader.readNextStartElement())
		{
			if (xmlReader.name().toString() == "Root")
				continue;

			if (myList.length() == 0)
			{
				some = new QTreeWidgetItem(ui.treeWidget);
			}
			else
				some = new QTreeWidgetItem(myList.constLast());

			myList.push_back(some);

			offChanger = true;

			some->setBackground(0, QColor(221, 221, 221, 255));
			some->setBackground(1, QColor(245, 216, 183, 255));
			some->setBackground(2, QColor(217, 225, 187, 255));
			some->setBackground(5, QColor(98, 244, 249, 255));
			some->setBackground(6, QColor(125, 198, 210, 255));
			some->setBackground(7, QColor(119, 168, 142, 255));

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
			}

			offChanger = false;

			FlameDate::closeEditor(some);
		}

		if (xmlReader.isEndElement())
			myList.pop_back();

		countOfTopItems = ui.treeWidget->topLevelItemCount();
	}
}


void FlameDate::startingImportXml()
{
	/* ��������� ���� ��� ������ � ������� ����, ���������� � lineEditWrite */

	QFile file("tree.txt");

	if (!file.open(QIODevice::ReadOnly))
	{
		sBar->showMessage("Don't find browse file. Add a directory with a tree.", 10000);
		return;
	}

	QTextStream out(&file);

	QString myLine = out.readLine(); // ����� readLine() ��������� ���� ������ �� ������

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


void FlameDate::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton) {
		ui.treeWidget->setCurrentItem(ui.treeWidget->invisibleRootItem());
	}
}

void FlameDate::initializationPoolFunc()
{
	countOfTopItems = ui.treeWidget->topLevelItemCount();

	poolParse.clear();

	for (int count = 0; count < countOfTopItems; count++)
	{
		if (ui.treeWidget->topLevelItem(count)->text(2).toInt() < 30) // ������ ���� ���-�� �������� � ���������
		{
			ui.treeWidget->topLevelItem(count)->setText(2, QString::number(30));
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
			ui.treeWidget->topLevelItem(poolParse.length() - 1)->text(7)
		);

		connect(poolParse.last().data(), &ProcessObject::messageReceived, tgObject, &TelegramJacket::sendMessage);
	}
}

void FlameDate::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
	if (reason == QSystemTrayIcon::ActivationReason::DoubleClick)
	{
		if (!windowShow)
		{
			this->show();
			windowShow = true;
		}
		else
		{
			this->hide();
			windowShow = false;
		}
	}
}


void FlameDate::cmdOpen()
{
	AllocConsole(); // ������� ������� � ������������ � ��� ������� �������
	FILE* stream;
	freopen_s(&stream, "CONOUT$", "w", stdout); // �������������� ����������� �����
	freopen_s(&stream, "CONOUT$", "w", stderr); // �������������� ����������� ����� ������

	printf("\nOpen console for logout\n\n");
}


void FlameDate::cmdClose()
{
	qDebug() << "\nProgramm disconnect from console.";

	FreeConsole(); // �������� ������� �� cmd. ����� cmd ��������� ������.
}
