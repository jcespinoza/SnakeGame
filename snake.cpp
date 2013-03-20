#include "snake.h"

Snake::Snake():GraphicElement(){
    score = 0;
    setDirection(UP);
    setFillColor(Qt::green);
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
    for(int i = parts.count()-1; i > 0; i--){
        parts.at(i)->setDirection(parts.at(i-1)->direction());
        parts.at(i)->setX(parts.at(i-1)->x());
        parts.at(i)->setY(parts.at(i-1)->y());
    }
    SnakePart* head = parts.at(0);
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

void Snake::addPart(int i){
    SnakePart* t = new SnakePart();
    t->setValue(i);
    addPart(t);
}

bool Snake::selfColission(){
    int xh = getHead()->x();
    int yh = getHead()->y();
    for(int i = 3; i < parts.count(); i++){
        int xi = parts.at(i)->x();
        int yi = parts.at(i)->y();
        switch(direction()){
        case UP:
            if(yh - partSize == yi && xh == xi)
                return true;
            break;
        case DOWN:
            if(yh + partSize == yi && xh == xi)
                return true;
            break;
        case LEFT:
            if(xh - partSize == xi && yh == yi)
                return true;
            break;
        case RIGHT:
            if(xh + partSize == xi && yh == yi)
                return true;
        }
    }
    return false;
}

/*Este metodo es devuelve true, si choca con la cabeza de otra snake*/
/*si choca con otra parte, las toma y devuelve false*/
bool Snake::collidesWith(Snake *other){
    int myX = getHead()->x();
    int myY = getHead()->y();
    int thX = other->getHead()->x();
    int thY = other->getHead()->y();
    /*Check the heads first*/
    switch(direction()){
    case UP:
        if(myY - partSize == thY && myX == thX)
            return true;
        break;
    case DOWN:
        if(myY + partSize == thY && myX == thX)
            return true;
        break;
    case LEFT:
        if(myX - partSize == thX && myY == thY)
            return true;
        break;
    case RIGHT:
        if(myX + partSize == thX && myY == thY)
            return true;
        break;
    }
    /*Now check collision with the body parts*/
    for(int i = 1; i < other->getCount(); i++){
        SnakePart* temp = other->getPart(i);
        thX = temp->x();
        thY = temp->y();
        switch(direction()){
        case UP:
            if(myY - partSize == thY && myX == thX){
                if(getHead()->getValue() > temp->getValue())
                    stealParts(i, other);
                else if(getHead()->getValue() < temp->getValue())
                    other->stealParts(1, this);
                else
                    return true;
            }
            break;
        case DOWN:
            if(myY + partSize == thY && myX == thX){
                if(getHead()->getValue() > temp->getValue())
                    stealParts(i, other);
                else if(getHead()->getValue() < temp->getValue())
                    other->stealParts(1, this);
                else
                    return true;
            }
            break;
        case LEFT:
            if(myX - partSize == thX && myY == thY){
                if(getHead()->getValue() > temp->getValue())
                    stealParts(i, other);
                else if(getHead()->getValue() < temp->getValue())
                    other->stealParts(1, this);
                else
                    return true;
            }
            break;
        case RIGHT:
            if(myX + partSize == thX && myY == thY){
                if(getHead()->getValue() > temp->getValue())
                    stealParts(i, other);
                else if(getHead()->getValue() < temp->getValue())
                    other->stealParts(1, this);
                else
                    return true;
            }
            break;
        }
    }

    return false;
}

void Snake::removePart(int pos){
    parts.removeAt(pos);
}

SnakePart* Snake::takePart(int pos){
    return parts.takeAt(pos);
}

void Snake::stealParts(int pos, Snake* other){
    for(int i = pos; i < other->getCount(); i++){
        addPart(other->getPart(i));
        other->removePart(i);
        i--;
    }
}
