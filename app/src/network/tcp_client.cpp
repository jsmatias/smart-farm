
#include <QString>
#include <QObject>
#include <QTcpSocket>

#include "tcp_client.h"

TcpClient::TcpClient(
    const QString &ip,
    const quint16 &port,
    QObject *parent)
    : ipTarget(ip), port(port), socket(new QTcpSocket(this)), QObject(parent)
{
}

TcpClient::~TcpClient() noexcept { disconnectFromHost(); }

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

QString TcpClient::sendMessage(const QString &message)
{
    if (socket->isOpen())
    {
        QString formattedMsg = message + "\n";  
        QByteArray msgBytes = formattedMsg.toUtf8();
        socket->write(msgBytes);
        socket->flush();

        if (socket->waitForReadyRead(3000))
        {
            return QString::fromUtf8(socket->readLine());
        }
    }
    return "";
}

QString TcpClient::getIP()
{
    return ipTarget;
}