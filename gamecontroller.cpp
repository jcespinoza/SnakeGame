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
    elapsed->start(1000);
    connect(refresher, SIGNAL(timeout()), this, SLOT(updateGraphics()));
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
    switch(snk->direction()){
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

void GameController::startGame(){
    snake1->resetSnake();
    snake2->resetSnake();

    SnakePart* h1 = new SnakePart();
    h1->setDirection(h1->RIGHT);
    h1->setX(40); h1->setY(40);
    h1->setValue(9);
    snake1->addHead(h1);
    snake1->setFillColor(Qt::green);
    snake1->setMaxHeight(600);
    snake1->setMaxWidth(940);
    SnakePart* p1 = new SnakePart();
    p1->setValue(7);
    snake1->addPart(p1);
    SnakePart* p2 = new SnakePart();
    p2->setValue(6);
    snake1->addPart(p2);

    SnakePart* h2 = new SnakePart();
    h2->setDirection(h2->DOWN);
    h2->setX(200); h2->setY(200);
    h2->setValue(8);
    snake2->addHead(h2);
    snake2->setFillColor(Qt::blue);
    snake2->setMaxHeight(600);
    snake2->setMaxWidth(940);

    renderer->addGraphicElement(snake1);
    renderer->addGraphicElement(snake2);

    if(!refresher->isActive()){
        refresher->start(100);
    }

}

void GameController::updateGraphics(){
    if(!snake1->colisionWall()){
        snake1->advance();
    }
    if(!snake2->colisionWall())
        ;//snake2->advance();
    renderer->update();
}
