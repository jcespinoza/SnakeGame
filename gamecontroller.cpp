#include "gamecontroller.h"
#include "QDebug"

GameController::GameController()
{
    srand(time(NULL));
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
    int rx = rand()%(940/40)*40;
    int ry = rand()%(600/40)*40;
    int dir = rand() % (4);
    h1->setDirection(dir);
    h1->setX(rx); h1->setY(ry);
    h1->setValue(rand()%(9-1)+1);
    snake1->addHead(h1);
    snake1->setFillColor(Qt::green);
    snake1->setMaxHeight(600);
    snake1->setMaxWidth(940);


    SnakePart* h2 = new SnakePart();
    dir = rand() % 3;
    rx = rand()%(940/40)*40;
    ry = rand()%(600/40)*40;
    h2->setDirection(dir);
    h2->setX(rx); h2->setY(ry);
    h2->setValue(rand()%9);
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
    if(!snake1->colisionWall() && !snake1->selfColission() && !snake1->collidesWith(snake2))
        snake1->advance();
    if(!snake2->colisionWall() && !snake2->selfColission() && !snake2->collidesWith(snake1))
        snake2->advance();
    emit updateScores(snake1->getScore(), snake2->getScore());
    renderer->update();    
}

Pair GameController::generateXY(int min, int max, int mult){
    Pair par;
    int s1 = rand()%((max-min)/mult) * mult;
    int s2 = rand()%((max-min)/mult) * mult;
    par.first = s1;
    par.second = s2;
    return par;
}

void GameController::stopGame(){

}
