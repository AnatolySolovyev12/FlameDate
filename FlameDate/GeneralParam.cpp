
#include "GeneralParam.h"
#include <QElapsedTimer>
#include <QFile>


GeneralParam::GeneralParam(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.exitBtn, SIGNAL(clicked()), this, SLOT(close()));
	connect(ui.saveAllBtn, SIGNAL(clicked()), this, SLOT(writeCurrent()));

	readDefaultConfig();
}

GeneralParam::~GeneralParam()
{
}


void GeneralParam::fileNameSetter(QString any)
{
	fileForSend = any;
}


void GeneralParam::readDefaultConfig()
{
	QFile file("config.txt");

	if (!file.open(QIODevice::ReadOnly))
	{
		qDebug() << "Dont find config file. Add file with parameters.";
		return;
	}

	QTextStream in(&file);

	int countParam = 0;

	// Считываем файл строка за строкой

	while (!in.atEnd()) // метод atEnd() возвращает true, если в потоке больше нет данных для чтения
	{
		QString line = in.readLine(); // метод readLine() считывает одну строку из потока
		++countParam;
		QString temporary;

		for (auto& val : line)
		{
			temporary += val;
		}

		temporary = temporary.trimmed();

		switch (countParam)
		{
		case(1):
		{
			m_name = temporary;

			if (m_name.length() > 500)
				m_name = "Not more then 500 signs";

			ui.nameLine->setText(m_name);
			break;
		}
		case(2):
		{
			m_directory = temporary;

			if (m_directory.length() > 500)
				m_directory = "Not more then 500 signs";

			ui.directoryLine->setText(m_directory);
			break;
		}
		case(3):
		{
			m_deadlineLine = temporary;

			if (m_deadlineLine.toInt() < 15 || m_deadlineLine.toInt() > 120)
				m_deadlineLine = QString::number(15);

			ui.deadlineLine->setText(m_deadlineLine);
			break;
		}
		case(4):
		{
			m_timeLine = temporary;

			if (m_timeLine.length() != 8)
				m_timeLine = "07:00:00";

			if (QTime::fromString(m_timeLine, "hh:mm:ss").toString().isEmpty())
				m_timeLine = "07:00:00";

			ui.timeLine->setText(m_timeLine);
			break;
		}
		case(5):
		{
			m_rowLine = temporary;

			if (m_rowLine.toInt() < 1 || m_rowLine.toInt() > 300)
				m_rowLine = QString::number(1);

			ui.rowLine->setText(m_rowLine);
			break;
		}
		case(6):
		{
			m_columnLine = temporary;

			if (m_columnLine.toInt() < 1 || m_columnLine.toInt() > 300)
				m_columnLine = QString::number(1);

			ui.columnLine->setText(m_columnLine);
			break;
		}
		case(7):
		{
			m_telegramLine = temporary;

			if (m_telegramLine.length() > 500)
				m_telegramLine = "Not more then 500 signs";

			ui.telegramLine->setText(m_telegramLine);
			break;
		}
		case(8):
		{
			m_list = temporary;

			if (m_list.toInt() < 1 || m_list.toInt() > 50)
				m_list = QString::number(1);

			ui.listLine->setText(m_list);
			break;
		}
		case(9):
		{
			m_rowHead = temporary;

			if (m_rowHead.toInt() < 1 || m_rowHead.toInt() > 50)
				m_rowHead = QString::number(1);

			ui.rowHeadLine->setText(m_rowHead);
			break;
		}

		}
	}

	file.close();
}


void GeneralParam::writeCurrent()
{
	QFile file("config.txt");

	// Открываем файл в режиме "Только для записи"
	if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
		QTextStream out(&file); // поток записываемых данных направляем в файл

		// Для записи данных в файл используем оператор <<
		out << ui.nameLine->text() << Qt::endl;
		out << ui.directoryLine->text() << Qt::endl;
		out << ui.deadlineLine->text() << Qt::endl;
		out << ui.timeLine->text() << Qt::endl;
		out << ui.rowLine->text() << Qt::endl;
		out << ui.columnLine->text() << Qt::endl;
		out << ui.telegramLine->text() << Qt::endl;
		out << ui.listLine->text() << Qt::endl;
		out << ui.rowHeadLine->text() << Qt::endl;

	}
	else
	{
		qWarning("Could not open file");
	}

	file.close();

	readDefaultConfig();

	emit refreshSetting();
}

bool GeneralParam::getNameCheck()
{
	return ui.checkBoxNameCounter->isChecked();
}

