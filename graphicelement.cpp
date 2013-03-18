#include "graphicelement.h"
#include <QDebug>

GraphicElement::GraphicElement()
{
    _x = _y = z = 0;
    partSize = SIZE;
}

GraphicElement::GraphicElement(int x, int y, int z){
    setX(x);
    setY(y);
    setZ(z);
    partSize = SIZE;
}

GraphicElement::GraphicElement(GraphicElement* original){
    setX(original->x());
    setY(original->y());
    setZ(original->getZ());
}
