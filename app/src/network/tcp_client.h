#pragma once

#include <QString>
#include <QObject>
#include <QTcpSocket>

class TcpClient : public QObject
{
    Q_OBJECT

    public:
        TcpClient(const QString& ip, const quint16& port, QObject* parent = nullptr);
        ~TcpClient() noexcept override;

        bool connectToHost();
        bool disconnectFromHost();
        QString sendMessage(const QString& message);
        QString getIP();
        
    private:
        QTcpSocket* socket;
        QString ipTarget;
        quint16 port;
};