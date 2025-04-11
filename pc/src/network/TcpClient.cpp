
#include <QString>
#include <QObject>
#include <QTcpSocket>

#include "TcpClient.h"

TcpClient::TcpClient(
    const QString &ip,
    const quint16 &port,
    QObject *parent)
    : ipTarget(ip), port(port), socket(new QTcpSocket(this)), QObject(parent)
{
}

TcpClient::~TcpClient() { disconnectFromHost(); }

bool TcpClient::connectToHost()
{   
    if (!socket->isOpen()) {
        socket->connectToHost(ipTarget, port);
    }
    bool isConnected = socket->waitForConnected(3000);
    if (!isConnected)
    {
        qDebug() << "Connection failed:" << socket->errorString();
        qDebug() << "Error code:" << socket->error();
    }
    return isConnected;
}

bool TcpClient::disconnectFromHost()
{
    if (socket->isOpen())
    {
        socket->close();
    }
    return socket->isOpen();
}

bool TcpClient::sendMessage(const QString &message)
{
    if (socket->isOpen())
    {
        socket->write(message.toUtf8());
        socket->flush();

        if (socket->waitForReadyRead(3000))
        {
            QString response = QString::fromUtf8(socket->readAll());
            qDebug() << "Received from Arduino: " << response;
            return true;
        }
    }
    return false;
}