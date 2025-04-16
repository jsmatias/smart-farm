#include "./mainwindow.h"
#include "./ui_mainwindow.h"
#include "./network/tcp_client.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionControl, &QAction::triggered, this, &MainWindow::showControlView);
    connect(ui->actionHistory, &QAction::triggered, this, &MainWindow::showHistoryView);
    connect(ui->connectPushButton, &QPushButton::clicked, this, &MainWindow::onConnectPushButton);
    connect(ui->ledPushButton, &QPushButton::clicked, this, &MainWindow::onLedPushButton);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onConnectPushButton()
{
    QString ip = ui->ipLineEdit->text();
    quint16 port = ui->portLineEdit->text().toShort();

    client = new TcpClient(ip, port);
    client->connectToHost();
    ui->statusbar->showMessage("Arduino connected!", 2000);
}

void MainWindow::onLedPushButton()
{

    client->connectToHost();
    QString msg;
    msg = isLedOn ? "LED_OFF\n" : "LED_ON\n";
    client->sendMessage(msg);
    isLedOn = !isLedOn;
    
    ui->statusbar->showMessage("LED was switched.", 2000);
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

