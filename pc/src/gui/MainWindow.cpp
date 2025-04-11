#include "MainWindow.h"
#include <QVBoxLayout>
#include <QTcpSocket>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi();
    connect(button, &QPushButton::clicked, this, &MainWindow::handleLedButton);
    resize(800, 600);
}

MainWindow::~MainWindow(){}

void MainWindow::setupUi()
{
    // Create the button
    button = new QPushButton("Click Me", this);
    
    // Set up the layout and add widgets
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(button);
    
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}


void MainWindow::handleLedButton() {
    QTcpSocket *socket = new QTcpSocket(this);

    // Connect to Arduino's IP address and port
    socket->connectToHost("192.168.2.30", 80);

    if (socket->waitForConnected(3000)) {
        qDebug() << "Connected to Arduino!";
        socket->write("LED_ON\n");
        socket->flush();
        socket->waitForBytesWritten(1000);
        socket->close();
    } else {
        qDebug() << "Connection failed:" << socket->errorString();
        qDebug() << "Error code:" << socket->error();
    }

    socket->deleteLater();
}
