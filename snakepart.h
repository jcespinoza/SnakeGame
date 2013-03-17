#ifndef SNAKEPART_H
#define SNAKEPART_H
#define DefStep = 20;
#include "graphicelement.h"
class SnakePart: public GraphicElement
{
public:
    SnakePart();
    void advance();
    virtual void paint(QPainter *);
    int getValue() const{return value;}
    void setValue(int v){value = v;}
    int getWidth()const{return width;}
    void setWidth(int w){width = w;}
    int getHeight()const {return height;}
    void setHeight(int h){height = h;}
private:
    int value;
    int width;
    int height;
};

#endif // SNAKEPART_H
