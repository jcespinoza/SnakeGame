#include "snakepart.h"

SnakePart(){

}

void SnakePart::paint(QPainter *painter){
    painter->setBrush(Qt::black);
    painter->drawRect(20,20,20,20);
}

void SnakePart::advance(){
    switch(getDirection()){
        case GraphicElement::UP:
            y -= 20;
            break;
        case GraphicElement::DOWN:
            y += 20;
            break;
        case GraphicElement::LEFT:
            x -= 20;
            break;
        case GraphicElement::RIGHT:
            x += 20;
            break;
    }
}
