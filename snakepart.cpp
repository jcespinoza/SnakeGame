#include "snakepart.h"

SnakePart::SnakePart(){

}

void SnakePart::paint(QPainter *painter){
    painter->setBrush(Qt::black);
    painter->drawRect(20,20,20,20);
}

void SnakePart::advance(){
    switch(getDirection()){
        case GraphicElement::UP:
            setY(getY()-20);
            break;
        case GraphicElement::DOWN:
            setY(getY()+20);
            break;
        case GraphicElement::LEFT:
            setX(getX()-20);
            break;
        case GraphicElement::RIGHT:
            setX(getX()+20);
            break;
    }
}
