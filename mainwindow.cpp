#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    controller = new GameController();
    renderer = controller->getRenderer();
    ui->grid->addWidget(renderer);
    segundos = 0;
    connect(controller, SIGNAL(pTimeOutS()), this, SLOT(updateTime()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete controller;
}

void MainWindow::updateTime(){
    segundos++;
    ui->lbTime->setText(QString::number(segundos));
}
