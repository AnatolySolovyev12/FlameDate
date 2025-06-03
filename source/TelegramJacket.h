#pragma once

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTimer>
#include <QUrlQuery>
#include <windows.h>
#include <QFile.h>


class TelegramJacket : public QObject
{
	Q_OBJECT

public:
	TelegramJacket(QObject* parent = nullptr);
	~TelegramJacket();

	void getUpdates();
	void setToken(QString val);

	void setWeekMask(QList<int> any);

public slots:
	//void sendMessage(const QString chatId, const QString message);

	void sendMessage(const QString message, const QString d_message);

public:
	QString token = "";
	qint64 iD;

	QList<QString>idMassive;

private:
	QNetworkAccessManager* manager = nullptr;

	QList<int>messegeWeekMask{ 0,0,0,0,0,0,0,0 };
	bool startBool = false;
};


