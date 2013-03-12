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

class Snake: public GraphicElement{
public:
    Snake();
    Snake(int x, int y, int z);
    void advance();
    /**
     * @brief paint
     * This method will iterate through the list
     * and call the paint() method on each element
     */
    virtual void paint(QPainter *);
private:
    //ListaPartes* lista;
};

#endif // SNAKEPART_H
