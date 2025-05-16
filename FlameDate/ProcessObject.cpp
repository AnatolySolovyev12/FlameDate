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
	m_deadlineDays = deadlineDays;
	m_checkParse = checkParse;
	m_checkSend = checkSend;

	m_timeForCheck = timeForCheck;
	m_column = column;
	m_row = row;


	if (m_checkParse || m_checkSend)
		classTimer->start(600000); // ������ 10 �����
	else
		classTimer->stop();
}


void ProcessObject::classTimerIsDone()
{
	check();
}


void ProcessObject::check()
{
	// ��������� snapshot ��������� ���������, � ����� ����, ������ � ������, ������������ ����� ����������. 
	// TH32CS_SNAPPROCESS - �������� ��� �������� � ������� � snapshot.
	// ���� ������� ����������� �������, ��� ���������� �������� ���������� ��������� snapshot.

	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	// ���� ������� ����������� �����, ��� ���������� INVALID_HANDLE_VALUE.�������������� �������� �� ������ ����� ��������, ������ GetLastError.��������� ���� ������ �������� ERROR_BAD_LENGTH.

	if (hSnapshot == INVALID_HANDLE_VALUE)
	{
		qDebug() << GetLastError();
	}

	PROCESSENTRY32 pe; // ��������� PROCESSENTRY32 (tlhelp32.h) ��������� ������ �� ������ ���������, ����������� � ��������� �������� ������������ ��� snapshot.

	pe.dwSize = sizeof(PROCESSENTRY32); // ������ ��������� � ������. ����� ������� ������� Process32First ������� ��� ����� �������� �������� sizeof(PROCESSENTRY32). ���� �� ���������������� dwSize, process32First ����������� �����.

	Process32First(hSnapshot, &pe); // ��������� �������� � ������ ��������, ������������ � ��������� snapshot. ������ ��� �������� ������� �������, �� ������ � �������.

	while (Process32Next(hSnapshot, &pe)) // false � ������ ���������� ���������� ������� �������� �.�. ����� �� ����� ��� ������ snapshot ������
	{
		if (QString::fromWCharArray(pe.szExeFile) == m_name)
		{
			qDebug() << QDateTime::currentDateTime() << ": " << m_name << "OK";
			return;
		}
	}

	qDebug() << QDateTime::currentDateTime() << ": " << m_name << " NOT WORK";

	if (m_checkSend)
		emit messageReceived("�� �������� " + m_name);

	QString temporary = getStartString(m_URL);

	if (m_checkParse)
		QTimer::singleShot(5000, [temporary]() {

		system(temporary.toUtf8().constData());

			});
}


QString ProcessObject::getStartString(QString any)
{
	QString temporary = "start \"\" \""; // start - ��� ���� ����� system() �� ����������� ���������� ����������� ���������.
	//�������� "" ������������ ��� �������� ��������� ���� (����� �������� ������).

	for (auto& val : any)
	{
		if (val == '\\')
		{
			temporary += "\\";
			continue;
		};
		temporary += val;
	}

	temporary += "\\";
	temporary += m_name + "\"";

	return temporary;
}
