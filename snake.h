#ifndef SNAKE_H
#define SNAKE_H
#include "graphicelement.h"
#include "snakepart.h"


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
    void setDirection(int arg);
    int getScore() const{return score;}
    void addHead(SnakePart*);
    SnakePart* getHead();
    void addPart(SnakePart*);
    void addPart(int i);
    int indexOfPart(SnakePart*);
    int getCount() const{return parts.count();}
    SnakePart* getPart(int pos);
    void removePart(int pos);
    SnakePart* takePart(int pos);
    QList<SnakePart*> getPartsList(){return parts;}
    void resetSnake();
    bool colisionWall();
    bool selfColission();
    void removeHead();
    void stealParts(int,Snake*);
    bool collidesWith(Snake*);
    void substract(int);
    void addPoints(int);

private:
    QList<SnakePart*> parts;
    int score;
    int partSize;
    QColor color;
};
#endif // SNAKE_H
