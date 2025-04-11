#include <QVBoxLayout>
#include <QTcpSocket>
#include <QDebug>
#include "MainWindow.h"
#include "../network/TcpClient.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi();
    button->setDisabled(true);
    ledOn = false;

    if (setupNetwork())
    {
        connect(button, &QPushButton::clicked, this, &MainWindow::handleLedButton);
        button->setEnabled(true);
    }

    resize(800, 600);
}

MainWindow::~MainWindow() {}

void MainWindow::setupUi()
{
    button = new QPushButton("LED", this);

    // Set up the layout and add widgets
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(button);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

bool MainWindow::setupNetwork()
{
    client = new TcpClient("192.168.2.30", 80);
    return client->connectToHost();
}

void MainWindow::handleLedButton()
{
    client->connectToHost();
    const QString& msg{!ledOn ? "LED_ON\n" : "LED_OFF\n"};
    bool success = client->sendMessage(msg);
    ledOn = success ? !ledOn : ledOn;
    client->disconnectFromHost();

}
