﻿#pragma once

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


class TelegramJacket : public QObject
{
	Q_OBJECT

public:
	TelegramJacket(QObject* parent = nullptr);
	~TelegramJacket();

	void getUpdates();

public slots:
	//void sendMessage(const QString chatId, const QString message);

	void sendMessage(const QString message);

public:
	QString token = "";
	qint64 iD;
	
	const QString chatId = "1443295378";

	QList<QString>idMassive;

private:
	QNetworkAccessManager* manager = nullptr;

};
