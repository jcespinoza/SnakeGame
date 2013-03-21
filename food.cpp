#include "food.h"

Food::Food():GraphicElement()
{
    setType(FOOD);
}

void Food::paint(QPainter* painter){
    painter->drawRect(x(), y(), partSize, partSize);
}
