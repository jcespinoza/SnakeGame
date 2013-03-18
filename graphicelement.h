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
    int dir;
    static const int SIZE = 20;
    int partSize;
    GraphicElement();
	GraphicElement(int x, int y, int z);
    GraphicElement(GraphicElement*);
    virtual void paint(QPainter*)=0;
    int getType()const {return type;}
    virtual void setX(int a){_x = a;}
    virtual void setY(int a){_y = a;}
    virtual void setZ(int a){z = a;}
    int x() const{return _x;}
    int y() const{return _y;}
    int getZ() const{return z;}
    int direction()const{return dir;}
    QColor getFillColor()const{return fill;}
    void setFillColor(QColor c){fill = c;}
    QColor getOutlineColor()const{return outline;}
    void setOutlineColor(QColor o){outline = o;}
    int getMaxHeight()const {return maxHeight;}
    void setMaxHeight(int h){maxHeight = h;}
    int getMaxWidth() const {return maxWidth;}
    void setMaxWidth(int w){maxWidth = w;}

private:
    int type, _x, _y, z;
    QColor fill;
    QColor outline;
    int maxWidth;
    int maxHeight;
};

#endif // GRAPHICELEMENT_H
