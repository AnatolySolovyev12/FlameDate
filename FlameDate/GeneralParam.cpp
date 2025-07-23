
#include "GeneralParam.h"
#include <QElapsedTimer>
#include <QFile>


GeneralParam::GeneralParam(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//connect(ui.exitBtn, SIGNAL(clicked()), this, SLOT(close()));
	//connect(ui.saveAllBtn, SIGNAL(clicked()), this, SLOT(writeCurrent()));

	readDefaultConfig();
}
/*
GeneralParam::~GeneralParam()
{
}
*/
/*
void GeneralParam::fileNameSetter(QString any)
{
	fileForSend = any;
}
*/

void GeneralParam::readDefaultConfig()
{
	qDebug() << "GeneralParam::readDefaultConfig():";

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

			qDebug() << m_name;
			break;
		}
		case(2):
		{
			m_directory = temporary;

			if (m_directory.length() > 500)
				m_directory = "Not more then 500 signs";

			qDebug() << m_directory;
			break;
		}
		case(3):
		{
			m_deadlineLine = temporary;

			if (m_deadlineLine.toInt() < 15 || m_deadlineLine.toInt() > 120)
				m_deadlineLine = QString::number(15);

			qDebug() << m_deadlineLine;
			break;
		}
		case(4):
		{
			m_timeLine = temporary;

			if (m_timeLine.length() != 8)
				m_timeLine = "07:00:00";

			if (QTime::fromString(m_timeLine, "hh:mm:ss").toString().isEmpty())
				m_timeLine = "07:00:00";

			qDebug() << m_timeLine;
			break;
		}
		case(5):
		{
			m_rowLine = temporary;

			if (m_rowLine.toInt() < 1 || m_rowLine.toInt() > 300)
				m_rowLine = QString::number(1);

			qDebug() << m_rowLine;
			break;
		}
		case(6):
		{
			m_columnLine = temporary;

			if (m_columnLine.toInt() < 1 || m_columnLine.toInt() > 300)
				m_columnLine = QString::number(1);

			qDebug() << m_columnLine;
			break;
		}
		case(7):
		{
			m_telegramLine = temporary;

			if (m_telegramLine.length() > 500)
				m_telegramLine = "Not more then 500 signs";

			qDebug() << m_telegramLine;
			break;
		}
		case(8):
		{
			m_list = temporary;

			if (m_list.toInt() < 1 || m_list.toInt() > 50)
				m_list = QString::number(1);

			qDebug() << m_list;
			break;
		}
		case(9):
		{
			m_rowHead = temporary;

			if (m_rowHead.toInt() < 1 || m_rowHead.toInt() > 50)
				m_rowHead = QString::number(1);

			qDebug() << m_rowHead;
			break;
		}
		case(10):
		{
			if (temporary.toInt() > 1 || temporary.toInt() < 0)
				messegeWeekMaskInGeneral[1] = 1;
			else
				messegeWeekMaskInGeneral[1] = temporary.toInt();

			qDebug() << messegeWeekMaskInGeneral[1];
			break;
		}
		case(11):
		{
			if (temporary.toInt() > 1 || temporary.toInt() < 0)
				messegeWeekMaskInGeneral[2] = 1;
			else
				messegeWeekMaskInGeneral[2] = temporary.toInt();

			qDebug() << messegeWeekMaskInGeneral[2];
			break;
		}
		case(12):
		{
			if (temporary.toInt() > 1 || temporary.toInt() < 0)
				messegeWeekMaskInGeneral[3] = 1;
			else
				messegeWeekMaskInGeneral[3] = temporary.toInt();

			qDebug() << messegeWeekMaskInGeneral[3];
			break;
		}
		case(13):
		{
			if (temporary.toInt() > 1 || temporary.toInt() < 0)
				messegeWeekMaskInGeneral[4] = 1;
			else
				messegeWeekMaskInGeneral[4] = temporary.toInt();

			qDebug() << messegeWeekMaskInGeneral[4];
			break;
		}
		case(14):
		{
			if (temporary.toInt() > 1 || temporary.toInt() < 0)
				messegeWeekMaskInGeneral[5] = 1;
			else
				messegeWeekMaskInGeneral[5] = temporary.toInt();

			qDebug() << messegeWeekMaskInGeneral[5];
			break;
		}
		case(15):
		{
			if (temporary.toInt() > 1 || temporary.toInt() < 0)
				messegeWeekMaskInGeneral[6] = 1;
			else
				messegeWeekMaskInGeneral[6] = temporary.toInt();

			qDebug() << messegeWeekMaskInGeneral[6];
			break;
		}
		case(16):
		{
			if (temporary.toInt() > 1 || temporary.toInt() < 0)
				messegeWeekMaskInGeneral[7] = 1;
			else
				messegeWeekMaskInGeneral[7] = temporary.toInt();

			qDebug() << messegeWeekMaskInGeneral[7];
			break;
		}
		case(17):
		{
			if (temporary.toInt() > 1 || temporary.toInt() < 0)
				messegeWeekMaskInGeneral[0] = 1;
			else
				messegeWeekMaskInGeneral[0] = temporary.toInt();

			qDebug() << messegeWeekMaskInGeneral[0];
			break;
		}
		}
	}

	file.close();
}

/*
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

		out << ui.checkMon->isChecked() << Qt::endl;
		out << ui.checkTue->isChecked() << Qt::endl;
		out << ui.checkWed->isChecked() << Qt::endl;
		out << ui.checkThurs->isChecked() << Qt::endl;
		out << ui.checkFri->isChecked() << Qt::endl;
		out << ui.checkSat->isChecked() << Qt::endl;
		out << ui.checkSun->isChecked() << Qt::endl;
		out << ui.checkSendCrit->isChecked() << Qt::endl;

	}
	else
	{
		qWarning("Could not open file");
	}

	file.close();

	readDefaultConfig();

	emit refreshSetting();
}
*/

bool GeneralParam::getNameCheck()
{
	return ui.checkBoxNameCounter->isChecked();
}

QList<int> GeneralParam::getMessegeWeekMaskInGeneral()
{
	return messegeWeekMaskInGeneral;
}
