#pragma once

#include <QString>
#include <QObject>
#include <QTcpSocket>

class TcpClient : public QObject
{
    Q_OBJECT

    public:
        TcpClient(const QString& ip, const quint16& port, QObject* parent = nullptr);
        ~TcpClient();

        bool connectToHost();
        bool disconnectFromHost();
        bool sendMessage(const QString& message);
        
    private:
        QTcpSocket* socket;
        QString ipTarget;
        quint16 port;
};