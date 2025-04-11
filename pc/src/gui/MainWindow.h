#pragma once

#include <QMainWindow>
#include <QPushButton>
#include "../network/TcpClient.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void setupUi();
    bool setupNetwork();

    bool ledOn;
    QPushButton* button;
    TcpClient* client;

private slots:
    void handleLedButton();
};
