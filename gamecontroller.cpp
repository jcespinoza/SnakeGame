#include "gamecontroller.h"
#include "QDebug"

GameController::GameController()
{
    _seconds = 0;
    _maxSeconds = 120;
    srand(time(NULL));
    elapsed = new QTimer(this);
    connect(elapsed, SIGNAL(timeout()), this, SLOT(pTimeOut()));
    refresher = new QTimer(this);
    snake1 = new Snake();
    snake2 = new Snake();
    renderer = new RenderArea();
    connect(refresher, SIGNAL(timeout()), this, SLOT(updateGraphics()));
    foodGenTimer = new QTimer(this);
    connect(foodGenTimer, SIGNAL(timeout()), this, SLOT(generateFood()));
}

void GameController::pTimeOut(){
    _seconds++;
    if(_seconds < _maxSeconds)
        emit pTimeOutS();
    else
        emit stopGame();
}

GameController::~GameController(){
    delete elapsed;
    delete refresher;
    delete snake1;
    delete snake2;
    delete renderer;
    delete foodGenTimer;
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
    case Qt::Key_Q:
        snake2->setHeadValue(9);
        break;
    case Qt::Key_P:
        snake1->setHeadValue(9);
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
    elapsed->start(1000);
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
    dir = rand() % 4;
    rx = rand()%(940/40)*40;
    ry = rand()%(600/40)*40;
    h2->setDirection(dir);
    h2->setX(rx); h2->setY(ry);
    h2->setValue(rand()%(9-1)+1);
    snake2->addHead(h2);
    snake2->setFillColor(Qt::cyan);
    snake2->setMaxHeight(600);
    snake2->setMaxWidth(940);

    renderer->addGraphicElement(snake1);
    renderer->addGraphicElement(snake2);

    if(!refresher->isActive())
        refresher->start(100);

    generateFood();
    foodGenTimer->start(10000);
    emit gameStarted();
}

void GameController::updateGraphics(){
    QList<Food> food = renderer->getFoodList();
    if(!snake1->colisionWall() && !snake1->selfColission() && !snake1->collidesWith(snake2)){
        for(int i = 0; i < food.count(); i++){
            Food f = food.at(i);
            if(snake1->collidesWith( f.x(), f.y() )){
                renderer->removeFood(i);
                snake1->addPart(f.value());
            }
        }
        snake1->advance();
    }
    if(!snake2->colisionWall() && !snake2->selfColission() && !snake2->collidesWith(snake1)){
        for(int i = 0; i < food.count(); i++){
            Food f = food.at(i);
            if(snake2->collidesWith( f.x(), f.y() )){
                renderer->removeFood(i);
                snake2->addPart(f.value());
            }
        }
        snake2->advance();
    }
    emit updateScores(snake1->getScore(), snake2->getScore());
    renderer->update();    
}

Pair GameController::generateXY(int minw, int maxw, int minh, int maxh, int mult){
    Pair par;
    int s1 = rand()%((maxw-minw)/20) * mult;
    int s2 = rand()%((maxh-minh)/20) * mult;
    par.first = s1;
    par.second = s2;
    return par;
}

void GameController::stopGame(){
    resetData();
    emit gameFinished(snake1->getScore(), snake2->getScore());
}

void GameController::generateFood(){
    int nF = rand()%6+1; //number of food items to generate
    for(int i = 0; i < nF; i++){
        renderer->addFoodElement(Snake::PSIZE);
    }
}

void GameController::resetData(){
    elapsed->stop();
    refresher->stop();
    foodGenTimer->stop();
    renderer->clearFood();
    renderer->removeGraphics();
    _seconds = 0;
}
