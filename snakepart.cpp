#include "snakepart.h"
#include <QDebug>

SnakePart::SnakePart(){
    setDirection(GraphicElement::UP);
    value = -1;
    setX(-1);
    setY(-1);
    setZ(-1);
    setWidth(partSize);
    setHeight(partSize);
}

void SnakePart::paint(QPainter *painter){
    painter->drawRect(getX(),getY(),getWidth(),getHeight());
}

void SnakePart::advance(){
    qDebug() << "Entered here, advancing";
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

void SnakePart::setDirection(int arg){
    dir = arg;
}
