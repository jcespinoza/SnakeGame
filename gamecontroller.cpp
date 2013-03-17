#include "gamecontroller.h"
#include "QDebug"

GameController::GameController()
{
    int x = rand() % (700 - 0) + 0;
    int y = rand() % (600);
    int z = 0;
    elapsed = new QTimer(this);
    connect(elapsed, SIGNAL(timeout()), this, SLOT(pTimeOut()));
    refresher = new QTimer(this);
    snake1 = new Snake();
    snake2 = new Snake();
    renderer = new RenderArea();
    elapsed->setInterval(1000);
    elapsed->start();
}

void GameController::pTimeOut(){
    emit pTimeOutS();
}

GameController::~GameController(){
    delete elapsed;
    delete refresher;
    delete snake1;
    delete snake2;
    delete renderer;
}

void GameController::processKey(int key){
    switch(key){
    case Qt::Key_Left:
        processDirection(1,GraphicElement::LEFT);
        break;
    case Qt::Key_Right:
        processDirection(1,GraphicElement::RIGHT);
        break;
    case Qt::Key_Up:
        processDirection(1,GraphicElement::UP);
        break;
    case Qt::Key_Down:
        processDirection(1,GraphicElement::DOWN);
        break;
    case Qt::Key_W:
        processDirection(2,GraphicElement::UP);
        break;
    case Qt::Key_A:
        processDirection(2,GraphicElement::LEFT);
        break;
    case Qt::Key_S:
        processDirection(2,GraphicElement::DOWN);
        break;
    case Qt::Key_D:
        processDirection(2,GraphicElement::RIGHT);
        break;
    }
}

void GameController::processDirection(int who, int dir){
    Snake* snk;
    if(who == 1)
        snk = snake1;
    else
        snk = snake2;
    switch(snk->getDirection()){
    case GraphicElement::UP:
        if(dir != GraphicElement::DOWN)
            snk->setDirection(dir);
        break;
    case GraphicElement::LEFT:
        if(dir != GraphicElement::RIGHT)
            snk->setDirection(dir);
        break;
    case GraphicElement::RIGHT:
        if(dir != GraphicElement::LEFT)
            snk->setDirection(dir);
        break;
    case GraphicElement::DOWN:
        if(dir != GraphicElement::UP)
            snk->setDirection(dir);
        break;
    }
}
