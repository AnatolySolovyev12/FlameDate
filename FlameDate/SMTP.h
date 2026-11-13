#pragma once

#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QtWidgets/QMessageBox>
#include <QByteArray>
#include <QFile>
#include <QFileInfo>
#include <QTimer>
#include <QCoreApplication>



struct mailStruct
{
    QString toMail;
    QString subjectMail;
    QString textMail;
    QString files;
};



class SMTP : public QObject
{
    Q_OBJECT

public:
    SMTP();

    ~SMTP();

    void stepsForSendSomeMessege(const QString& mailsAndText, const QString& subscribe, const QString& minimalDate, const QString& filesSend);
    void sendMail(const QString& to, const QString& subject, const QString& textMessege, QString files);
    void setWeekMask(QList<int> any);
    void loopSending();

signals:
    void status(const QString&); // самоделашный сигнал для вывод в объект основного класса. 

private slots:
    //сигналы для них используются бибилиотечные
   // void stateChangedInfo(QAbstractSocket::SocketState socketState);
    void errorReceivedInfo(QAbstractSocket::SocketError socketError);
    void handShakeErrorInfo(const QSslError& socketError);
    void verifyErrorInfo(const QSslError& socketError);
    void disconnectedInfo();
    void connectedInfo();
    void readyReadFromSocket();
    void sslErrorsReceived(const QList<QSslError>& errors);
    void readDefaultConfig();


private:
    int timeout;
    QString message;
    QTextStream* t = nullptr;
    QSslSocket* socket = nullptr;
    QString from;
    QString rcpt;
    QString response;
    QString user;
    QString pass;
    QByteArray userByte;
    QByteArray passByte;
    QString host;
    int port;
    enum states { Tls, HandShake, Auth, User, Pass, Rcpt, Mail, Data, Init, Body, Quit, Close };
    int state = 8;
    QList<int>messegeWeekMask{ 0,0,0,0,0,0,0,0 };
    QList<mailStruct>mailsBuff;
    QTimer* senderTimer = nullptr;
};