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
    int getScore() const{return score;}
    void addHead(SnakePart*);
    void addPart(SnakePart*);
    int getCount() const{return members->count();}
    SnakePart* getPart(int pos);
    void resetSnake();
    bool colisionWall();
    void removeHead();



private:
    SnakeList* members;
    int score;
    int maxWidth;
    int maxHeight;
    int partSize;
    QColor color;
};
#endif // SNAKE_H
