#include "graphicelement.h"
#include <QDebug>

GraphicElement::GraphicElement()
{
    x = y = z = 0;
    partSize = SIZE;
}

GraphicElement::GraphicElement(int x, int y, int z){
    setX(x);
    setY(y);
    setZ(z);
    partSize = SIZE;
}

GraphicElement::GraphicElement(GraphicElement* original){
    setX(original->getX());
    setY(original->getY());
    setZ(original->getZ());
}
