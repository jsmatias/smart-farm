#include "MainWindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi();
    resize(800, 600);
}

MainWindow::~MainWindow()
{
    // Destructor if you need to release resources
}

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
