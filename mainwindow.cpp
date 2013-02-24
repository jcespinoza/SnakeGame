#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    renderer = new RenderArea(this);
    controller = new GameController();
    ui->grid->addWidget(renderer);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete renderer;
    delete controller;
}
