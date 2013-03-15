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
    snake1 = snake2 = 0;
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
