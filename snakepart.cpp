#include "snakepart.h"

SnakePart::SnakePart(){
    setDirection(GraphicElement::UP);
    value = -1;
    setX(-1);
    setY(-1);
    setZ(-1);
    setWidth(20);
    setHeight(20);
}

void SnakePart::paint(QPainter *painter){
    painter->setBrush(Qt::black);
    painter->drawRect(getX(),getY(),getWidth(),getHeight());
}

void SnakePart::advance(){
    switch(getDirection()){
        case GraphicElement::UP:
            setY(getY()-getHeight());
            break;
        case GraphicElement::DOWN:
            setY(getY()+getHeight());
            break;
        case GraphicElement::LEFT:
            setX(getX()-getWidth());
            break;
        case GraphicElement::RIGHT:
            setX(getX()+getWidth());
            break;
    }
}
