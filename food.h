#ifndef FOOD_H
#define FOOD_H
#include "graphicelement.h"
class Food: public GraphicElement
{
public:
    Food();
    Food(int,int,int);
    virtual void paint(QPainter *);
    int value()const{return _value;}
private:
    int _value;
};

#endif // FOOD_H
