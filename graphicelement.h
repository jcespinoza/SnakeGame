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
    static const int SIZE = 20;
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
    QColor getFillColor()const{return fill;}
    void setFillColor(QColor c){fill = c;}
    QColor getOutlineColor()const{return outline;}
    void setOutlineColor(QColor o){outline = o;}
private:
    int type, x, y, z;
    int dir;
    QColor fill;
    QColor outline;
};

#endif // GRAPHICELEMENT_H
