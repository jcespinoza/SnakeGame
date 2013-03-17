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
public slots:
    void updateTime();
protected:
    virtual void keyPressEvent(QKeyEvent *);
};

#endif // MAINWINDOW_H
