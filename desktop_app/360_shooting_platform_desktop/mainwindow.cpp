#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    statusLabel = new QLabel("Waiting for COM device...", this);
    ui->statusbar->addWidget(statusLabel);
}

MainWindow::~MainWindow() {
    delete ui;
}

QLabel* MainWindow::getStatusLabel() const {
    return statusLabel;
}
