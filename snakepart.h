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
};

#endif // SNAKEPART_H
