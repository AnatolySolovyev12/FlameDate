
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
{}

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

		switch (countParam)
		{

		case(1):
		{
			smtpServer = temporary;
			ui.directoryLine->setText(smtpServer);
			break;
		}
		case(2):
		{
			smtpPort = temporary;
			ui.deadlineLine->setText(smtpPort);
			break;
		}
		case(3):
		{
			userName = temporary;
			ui.timeLine->setText(userName);
			break;
		}
		case(4):
		{
			password = temporary;
			ui.rowLine->setText(password);
			break;
		}
		case(5):
		{
			recipantTo = temporary;
			ui.columnLine->setText(recipantTo);
			break;
		}
		case(6):
		{
			subject = temporary;
			ui.telegramLine->setText(subject);
			break;
		}
		/*case(7):
		{
			hostName = temporary;
			ui.lineEditHostName->setText(hostName);
			break;
		}
		case(8):
		{
			odbc = temporary;
			ui.lineEditOdbc->setText(odbc);
			break;
		}
		case(9):
		{
			userNameDb = temporary;
			ui.lineEditUserName->setText(userNameDb);
			break;
		}
		case(10):
		{
			passDb = temporary;
			ui.lineEditPassword->setText(passDb);
			break;
		}
		case(11):
		{
			if (temporary.toInt() > 240 || temporary.toInt() < 1)
			{
				temporary = "240";
				qDebug() << "Hours for autocreater have wrong value in config file. Was accept default value 240 hours";
			}
			timerTime = temporary.toInt();
			ui.spinBoxHours->setValue(timerTime);
			break;
		}*/
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
		out << ui.directoryLine->text() << Qt::endl;
		out << ui.deadlineLine->text() << Qt::endl;
		out << ui.timeLine->text() << Qt::endl;
		out << ui.rowLine->text() << Qt::endl;
		out << ui.columnLine->text() << Qt::endl;
		out << ui.telegramLine->text() << Qt::endl;
		
		/*
		out << ui.lineEditHostName->text() << Qt::endl;
		out << ui.lineEditOdbc->text() << Qt::endl;
		out << ui.lineEditUserName->text() << Qt::endl;
		out << ui.lineEditPassword->text() << Qt::endl;

		out << ui.spinBoxHours->text() << Qt::endl;
		*/
	}
	else
	{
		qWarning("Could not open file");
	}

	file.close();

	readDefaultConfig();

	emit status(tr("dbreconnet"));
}

