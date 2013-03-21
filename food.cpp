#include "food.h"
#include <QDebug>

Food::Food():GraphicElement()
{
    setType(FOOD);
    _value = rand() % (9)+1;
}

Food::Food(int maxw, int maxh, int mult):GraphicElement(){
    setType(FOOD);
    _value = rand() % (9)+1;
    setX(rand()%(maxw/mult) * mult);
    setY(rand()%(maxh/mult) * mult);
}

void Food::paint(QPainter* painter){
    painter->setBrush(Qt::red);
    painter->setPen(Qt::white);
    painter->drawRect(x(), y(), partSize, partSize);
    painter->drawText(x(), y(), partSize, partSize, Qt::AlignCenter, QString::number(value()));
}
