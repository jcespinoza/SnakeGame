#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

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
    connect(controller, SIGNAL(updateScores(int,int)), this, SLOT(updateScores(int,int)));
    connect(controller, SIGNAL(gameFinished(int, int)), this, SLOT(showFinalScores(int, int)));
    controller->startGame();
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

void MainWindow::keyPressEvent(QKeyEvent *event){
    controller->processKey(event->key());
}

void MainWindow::updateScores(int p1, int p2){
    ui->lbScore1->setText(QString::number(p1));
    ui->lbScore2->setText(QString::number(p2));
}

void MainWindow::showFinalScores(int s1, int s2){
    QString winner("El ganador es Jugador ");
    winner.append(QString::number((s1 > s2) ? 1:2));
    QMessageBox::information(this, "Juego terminado", winner, QMessageBox::Ok);
    int r = QMessageBox::question(this, "Jugar de nuevo?", "Desea jugar de nuevo?");
    if(r == QMessageBox::Yes){
        resetTime();
        controller->startGame();
    }
    else
        close();
}

void MainWindow::on_actionConfiguracion_triggered()
{

}

void MainWindow::resetTime(){
    segundos = 0;
}
