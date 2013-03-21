#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QDebug>
#include <QPainter>
#include <QPaintEvent>
#include <QList>
#include "food.h"

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = 0);
    void addGraphicElement(GraphicElement*);
    QList<Food> getFoodList()const{return foodl;}
    void addFoodElement();
    void addFoodElement(int);
    void removeFood(int);
    void setWidthHeight(int w,int h){_width = w; _height = h;}
private:
    /**
     * @brief paintEvent
     * This method iterates the list and calls the paint() method
     *on each element of the list;
     */
    void paintEvent(QPaintEvent *);
    void focusInEvent(QFocusEvent *);
    void focusOutEvent(QFocusEvent *);
    void enterEvent(QEvent *);
    QList<GraphicElement*> lista;
    QList<Food> foodl;
    int _width;
    int _height;
signals:
    
public slots:
    
};

#endif // RENDERAREA_H
