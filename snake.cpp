#include "snake.h"

Snake::Snake():GraphicElement(){
    score = 0;
    setDirection(UP);
    setFillColor(Qt::green);
    members = new SnakeList();
    parts = QList<SnakePart*>();
    partSize = SIZE;
}

Snake::Snake(int x, int y, int z):GraphicElement(x, y, z){

}

void Snake::paint(QPainter *painter){
    painter->setBrush(getFillColor());
    painter->setPen(getOutlineColor());

    for(int k = 0; k < parts.count(); k++){
        parts.at(k)->paint(painter);
    }
}

void Snake::advance(){
    SnakePart* head = parts[0];

    switch(head->direction()){
    case head->UP:
        head->setY( head->y() - head->partSize );
        break;
    case head->DOWN:
        head->setY( head->y() + head->partSize );
        break;
    case head->RIGHT:
        head->setX( head->x() + head->partSize );
        break;
    case head->LEFT:
        head->setX( head->x() - head->partSize );
        break;
    }

    for(int i = parts.count()-1; i > 0; i--){
        parts.at(i)->setDirection(parts.at(i-1)->direction());
        parts.at(i)->setX(parts.at(i-1)->x());
        parts.at(i)->setY(parts.at(i-1)->y());
    }
    parts[0] = head;
    qDebug() << parts.count();
}

void Snake::resetSnake(){
    parts.clear();
    score = 0;
    setDirection(UP);
}

void Snake::addHead(SnakePart *headPart){
    if(parts.count() != 0)
        return;
    parts.push_back(headPart);
    setDirection(headPart->direction());
    score = headPart->getValue();
}

void Snake::addPart(SnakePart *nPart){
    if(parts.count() <= 0)
        return;

    SnakePart* last = parts.back();
    nPart->setDirection( last->direction() );
    switch(nPart->direction()){
    case UP:
        nPart->setX( last->x() );
        nPart->setY( last->y() + partSize );
        break;
    case DOWN:
        nPart->setX( last->x() );
        nPart->setY( last->y() - partSize );
        break;
    case LEFT:
        nPart->setX( last->x() + partSize );
        nPart->setY( last->y() );
        break;
    case RIGHT:
        nPart->setX( last->x() - partSize );
        nPart->setY( last->y() );
        break;
    }
    parts.push_back(nPart);
    score += nPart->getValue();
}

SnakePart* Snake::getPart(int pos){
    return parts.at(pos);
}

SnakePart* Snake::getHead(){
    if(!parts.isEmpty())
        return parts.at(0);
    return 0;
}

void Snake::setDirection(int arg){
    this->dir = arg;
    SnakePart* h = getHead();
    if(h != 0){
        h->setDirection(arg);
    }
}

bool Snake::colisionWall(){
    SnakePart* head = getHead();
    if( head->direction() == LEFT && head->x() - partSize < 0)
        return true;
    if(head->direction() == RIGHT && head->x() + partSize > getMaxWidth())
        return true;
    if(head->direction() == DOWN && head->y() + 2*partSize > getMaxHeight())
        return true;
    if(head->direction() == UP && head->y() - partSize < 0)
        return true;
    return false;
}
