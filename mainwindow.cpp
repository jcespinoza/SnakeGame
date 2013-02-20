#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    renderer = new RenderArea(this);
    ui->grid->addWidget(renderer);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete renderer;
}
