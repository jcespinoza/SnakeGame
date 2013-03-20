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
    _head = false;
}

void SnakePart::paint(QPainter *painter){
    painter->drawRect(x(),y(),getWidth(),getHeight());
    painter->drawText(x(), y(), getWidth(), getHeight(), Qt::AlignCenter, QString::number(getValue()));
}

void SnakePart::advance(){
    switch(direction()){
        case GraphicElement::UP:
            setY(y()-getHeight());
            break;
        case GraphicElement::DOWN:
            setY(y()+getHeight());
            break;
        case GraphicElement::LEFT:
            setX(x()-getWidth());
            break;
        case GraphicElement::RIGHT:
            setX(x()+getWidth());
            break;
    }
}

void SnakePart::setDirection(int arg){
    dir = arg;
}
