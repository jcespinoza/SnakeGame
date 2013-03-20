#ifndef FOOD_H
#define FOOD_H
#include "graphicelement.h"
class Food: public GraphicElement
{
public:
    Food();
    virtual void paint(QPainter *);
};

#endif // FOOD_H
