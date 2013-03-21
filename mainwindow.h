#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamecontroller.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    RenderArea* renderer;
    GameController* controller;
    int segundos;
private slots:
    void showFinalScores(int,int);
    void on_actionConfiguracion_triggered();
    void resetTime();

public slots:
    void updateTime();
    void updateScores(int,int);
protected:
    virtual void keyPressEvent(QKeyEvent *);
};

#endif // MAINWINDOW_H
