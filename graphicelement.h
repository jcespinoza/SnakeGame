#ifndef GRAPHICELEMENT_H
#define GRAPHICELEMENT_H

#include <QPainter>
/**
 * @brief The GraphicElement class
 * An abstract class for graphic elements in the game.
 */
class GraphicElement
{
public:
    enum Type{
        SNAKE_ELEMENT, HEAD, FOOD
    };
    enum DIRECTION{
        UP, RIGHT, DOWN,LEFT
    };
    GraphicElement();
	GraphicElement(int x, int y, int z);
    GraphicElement(GraphicElement*);
    virtual void paint(QPainter*)=0;
    int getType()const {return type;}
    virtual void setX(int a){x = a;}
    virtual void setY(int a){y = a;}
    virtual void setZ(int a){z = a;}
    int getX() const{return x;}
    int getY() const{return y;}
    int getZ() const{return z;}
    int getDirection()const{return dir;}
    void setDirection(int arg){dir = arg;}
private:
    int type, x, y, z;
    int dir;
};

#endif // GRAPHICELEMENT_H
