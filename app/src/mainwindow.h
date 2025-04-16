#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QAction>
#include <QString>

#include "./network/tcp_client.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void showControlView();
    void showHistoryView();
    void onConnectPushButton();
    void onLedPushButton();

private:
    Ui::MainWindow *ui;
    TcpClient* client;
    bool isLedOn;
};
#endif // MAINWINDOW_H
