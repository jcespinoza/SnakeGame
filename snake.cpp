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
    addPoints(headPart->getValue());
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
    addPoints(nPart->getValue());
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

/*Este metodo es devuelve true, si choca con la cabeza de otra snake y tienen el mismo valor*/
/*si choca con otra parte, las toma y devuelve false*/
bool Snake::collidesWith(Snake *other){
    int myX = getHead()->x(); //My X position
    int myY = getHead()->y(); //My Y position
    int thX = other->getHead()->x(); //Their X position
    int thY = other->getHead()->y(); //Their Y position
    //iteratte through their parts list
    for(int i = 0; i < other->getCount(); i++){
        //save the curret part
        SnakePart* temp = other->getPart(i);
        //save its XY values
        thX = temp->x();
        thY = temp->y();
        //take action depending on my direction
        switch(direction()){
        //in case I'm going up
        case UP:
            //if the current part is in front of me
            if(myY - partSize == thY && myX == thX){
                //check if my value is higher
                if(getHead()->getValue() > temp->getValue())
                    //then make sure I dont eat their head
                    if(i == 0)
                        stealParts(1, other);
                    else
                        stealParts(i, other);
                //if their value is higher
                else if(getHead()->getValue() < temp->getValue())
                    //eat all their parts except for the head
                    other->stealParts(1, this);
                else
                    //if the values are equal return true, and I'll stop advancing
                    return true;
            }
            break;
        case DOWN:
            if(myY + partSize == thY && myX == thX){
                if(getHead()->getValue() > temp->getValue())
                    if(i == 0)
                        stealParts(1, other);
                    else
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
                    if(i == 0)
                        stealParts(1, other);
                    else
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
                    if(i == 0)
                        stealParts(1, other);
                    else
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
    substract(parts.at(pos)->getValue());
    parts.removeAt(pos);
}

SnakePart* Snake::takePart(int pos){
    substract(parts.at(pos)->getValue());
    return parts.takeAt(pos);
}

void Snake::stealParts(int pos, Snake* other){
    //iterate through their parts list
    for(int i = pos; i < other->getCount(); i++){
        //save the current part
        SnakePart* temp = other->getPart(i);
        //append that part to my tail
        addPart(temp);
        //remove that part from their tail
        other->removePart(other->indexOfPart(temp));
        //substract the part's value from their score
        i--;
    }
}

void Snake::substract(int v){
    score -= v;
}

void Snake::addPoints(int v){
    score += v;
}

int Snake::indexOfPart(SnakePart *pa){
    return parts.indexOf(pa);
}
