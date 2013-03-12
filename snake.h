#ifndef SNAKE_H
#define SNAKE_H
#include "graphicelement.h"
#include "snakelist.h"

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
    SnakeList* members;
};
#endif // SNAKE_H
