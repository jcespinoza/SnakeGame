#include "graphicelement.h"

GraphicElement::GraphicElement()
{
    x = y = z = 0;
}

GraphicElement::GraphicElement(int x, int y, int z){
    setX(x);
    setY(y);
    setZ(z);
}

GraphicElement::GraphicElement(GraphicElement* original){
    setX(original->getX());
    setY(original->getY());
    setZ(original->getZ());
}
