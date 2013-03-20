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
    void setDirection(int arg);
    bool isHead()const{return _head;}
    void makeHead(){_head = true;}
private:
    int value;
    bool _head;
    int width;
    int height;
};

#endif // SNAKEPART_H
