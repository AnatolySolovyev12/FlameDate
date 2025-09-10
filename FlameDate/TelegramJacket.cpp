#include "TelegramJacket.h"

TelegramJacket::TelegramJacket(QObject* parent)
	: QObject(parent), manager(new QNetworkAccessManager)
{
	AttachConsole(ATTACH_PARENT_PROCESS);
}


void TelegramJacket::getUpdates()
{
	if (isBusy) return; // Уже выполняется запрос

	isBusy = true;

	/*
	QString urlString = QString("https://api.telegram.org/bot%1/deleteWebhook") // метод удаления перехватичков. Защиа от захвата бота и не только.
		.arg(token);
	QNetworkRequest request(urlString);
	QNetworkReply* reply = manager->get(request);
	*/

	// добавлен таймаут для LongPoll (при 0 ShortPoll) в секундах. Также добавлен offset для подтверждения получения сообщдения в Telegram (чтобы повторно не поулчать старые сообщения)
	QString urlString = QString("https://api.telegram.org/bot%1/getUpdates?offset=%2&timeout=12")
		.arg(token)
		.arg(iD);

	QNetworkRequest request(urlString);
	QNetworkReply* reply = manager->get(request);

	QObject::connect(reply, &QNetworkReply::finished, [reply, this]() {
		if (reply->error() == QNetworkReply::NoError)
		{
			QJsonDocument jsonDoc = QJsonDocument::fromJson(reply->readAll());

			if (jsonDoc["ok"].toBool())
			{
				QJsonArray updates = jsonDoc["result"].toArray();

				for (const QJsonValue& value : updates)
				{

					QJsonObject messageObj = value["message"].toObject();
					QJsonObject fromObj = messageObj["from"].toObject();

					if (messageObj.contains("text") && fromObj.contains("id")) {

						QString text = messageObj["text"].toString();

						qDebug() << "Received message (" << value["update_id"].toInteger() << "): " << messageObj["text"].toString() << "chatId: " << fromObj["id"].toInteger();

						iD = value["update_id"].toInteger() + 1;

						if (text == "/start")
						{
							const QString tempt = QString::number(fromObj["id"].toInteger()) + "@" + QString::number(fromObj["id"].toInteger());
							startBool = true;
							sendMessage(tempt, QString::number(15));
						}
					}
					else
					{
						qDebug() << "Error (TelegramJacket::getUpdates(1)): " << reply->error() << reply->errorString();
					}
				}
			}
		}
		else
		{
			qDebug() << "Error (TelegramJacket::getUpdates(2)): " << reply->error() << reply->errorString();
		}

		reply->deleteLater();

		isBusy = false;
		getUpdates();
		});	
}


void TelegramJacket::sendMessage(const QString message, const QString d_message)
{
	if (message.isEmpty()) {
		qWarning() << "Attempt to send empty message";
		return;
	}

	if (!startBool)
	{
		if (!messegeWeekMask[QDate::currentDate().dayOfWeek()] && (d_message.toInt() > 15))
		{
			qDebug() << "\nNot send in this day";
			return;
		}
		
		if (messegeWeekMask[0] && (d_message.toInt() > 15) && !messegeWeekMask[QDate::currentDate().dayOfWeek()])
		{
			qDebug() << "\nNot in critical zone";
			return;
		}
	}

	QString temporary;

	for (auto& val : message)
	{
		
		if (val.isSpace())
		{
			idMassive.push_back(temporary);
			temporary.clear();
			continue;
		}
		
		if (val == '@')
		{
			idMassive.push_back(temporary);
			temporary = message;
			temporary = temporary.sliced(message.indexOf('@') + 1);
			break;
		}
		
		temporary += val;
	}
	
	for (auto& val : idMassive)
	{
		const QString tempId = val;
		// Формирование URL запроса
		QString urlString = QString("https://api.telegram.org/bot%1/sendMessage").arg(token);

		QUrl url(urlString);

		// Настройка параметров сообщения
		QUrlQuery query;
		query.addQueryItem("chat_id", tempId);
		query.addQueryItem("text", temporary);

		//qDebug() << query.toString() << "\n";

		// Создание запроса
		QNetworkRequest request(url);
		request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

		// Отправка запроса
		manager->post(request, query.toString(QUrl::FullyEncoded).toUtf8());

		/*
		// Обработчик ответа (если необходимо). Пригодится.
		QObject::connect(manager, &QNetworkAccessManager::finished, [](QNetworkReply* reply) {

			if (reply->error() == QNetworkReply::NoError)
			{
				QString response = reply->readAll();
				qDebug() << response;
			}
			else
			{
				qDebug() << "Error:: " << reply->error();
			}
			reply->deleteLater();
			});

			*/
	}

	idMassive.clear();
	startBool = false;
}


void TelegramJacket::setToken(QString val)
{
	token = val;
}


void TelegramJacket::setWeekMask(QList<int> any)
{
	messegeWeekMask = any;
}

