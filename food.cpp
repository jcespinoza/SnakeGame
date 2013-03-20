#include "food.h"

Food::Food():GraphicElement()
{
}

void Food::paint(QPainter* painter){
    painter->drawRect(x(), y(), partSize, partSize);
}
