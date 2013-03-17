#include "snake.h"

Snake::Snake():GraphicElement(){
    score = 0;
    setDirection(UP);
    setFillColor(Qt::green);
}

Snake::Snake(int x, int y, int z):GraphicElement(x, y, z){

}

void Snake::paint(QPainter *painter){
    painter->setBrush(getFillColor());
    painter->setPen(getOutlineColor());
    members->goToFirst();
    for(int i = 1; i < members->count(); i++){
        members->get()->paint(painter);
    }
}

void Snake::advance(){
    members->advanceItems();
}

void Snake::resetSnake(){
    members->clear();
    score = 0;
    setDirection(UP);
}

void Snake::addHead(SnakePart *headPart){
    if(members->count()!=0)
        return;
    members->add(headPart);
    setDirection(headPart->getDirection());
    score = headPart->getValue();
}

void Snake::addPart(SnakePart *nPart){
    if(members->count() <= 0)
        return;

    members->goToLast();
    SnakePart* last = members->get();
    nPart->setDirection( last->getDirection() );
    switch(nPart->getDirection()){
    case UP:
        nPart->setX( last->getX() );
        nPart->setY( last->getY() + partSize );
        break;
    case DOWN:
        nPart->setX( last->getX() );
        nPart->setY( last->getY() - partSize );
        break;
    case LEFT:
        nPart->setX( last->getX() + partSize );
        nPart->setY( last->getY() );
        break;
    case RIGHT:
        nPart->setX( last->getX() - partSize );
        nPart->setY( last->getY() );
        break;
    }
    members->add(nPart);
    score += nPart->getValue();
}

SnakePart* Snake::getPart(int pos){
    return members->at(pos);
}
