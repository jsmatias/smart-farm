#include "./mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->connectPushButton, &QPushButton::clicked, this, &MainWindow::onConnectPushButton);
    connect(ui->actionControl, &QAction::triggered, this, &MainWindow::showControlView);
    connect(ui->actionHistory, &QAction::triggered, this, &MainWindow::showHistoryView);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onConnectPushButton()
{
    ui->statusbar->showMessage(QString::asprintf("Arduino connected!"), 2000);
}


void MainWindow::showControlView()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->statusbar->showMessage(QString::asprintf("Control view..."), 2000);
}

void MainWindow::showHistoryView()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->statusbar->showMessage(QString::asprintf("History view..."), 2000);
}

