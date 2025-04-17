#include "./mainwindow.h"
#include "./ui_mainwindow.h"
#include "./network/tcp_client.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pollTimer = new QTimer(this);
    connect(pollTimer, &QTimer::timeout, this, &MainWindow::pollArduino);
    connect(ui->actionControl, &QAction::triggered, this, &MainWindow::showControlView);
    connect(ui->actionHistory, &QAction::triggered, this, &MainWindow::showHistoryView);
    connect(ui->connectPushButton, &QPushButton::clicked, this, &MainWindow::onConnectPushButton);
    connect(ui->ledPushButton, &QPushButton::clicked, this, &MainWindow::onLedPushButton);
    // connect(ui->fanPushButton, &QPushButton::clicked, this, &MainWindow::onFanPushButton);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pollArduino()
{
    client->connectToHost();
    QString response = client->sendMessage("GET_DATA");

    QStringList parts = response.split(":");
    if (parts.size() == 2) {
        bool ok;
        int value = parts[1].trimmed().toInt(&ok);
        if (ok) {
            ui->ledLcdNumber->display(value);
            qDebug() << "Parsed value:" << value;
        } else {
            qDebug() << "Conversion to int failed for:" << parts[1];
        }
    } else {
        qDebug() << "Unexpected response format:" << response;
    }
    client->disconnectFromHost();
}

void MainWindow::onConnectPushButton()
{
    QString ip = ui->ipLineEdit->text();
    quint16 port = ui->portLineEdit->text().toShort();

    client = new TcpClient(ip, port);
    ui->statusbar->showMessage("Arduino connected!", 2000);
    pollTimer->start(1000);
}

void MainWindow::onLedPushButton()
{

    client->connectToHost();
    QString msg;
    msg = isLedOn ? "LED_OFF" : "LED_ON";
    QString response = client->sendMessage(msg);

    isLedOn = !isLedOn;
    QString onOrOFF = isLedOn ? "on." : "off.";
    ui->statusbar->showMessage("LED was switched " + onOrOFF, 2000);
    client->disconnectFromHost();
}

void MainWindow::showControlView()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->statusbar->showMessage("Control view...", 2000);
}

void MainWindow::showHistoryView()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->statusbar->showMessage("History view...", 2000);
}

