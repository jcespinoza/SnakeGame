#include "renderarea.h"

RenderArea::RenderArea(QWidget *parent) :
    QWidget(parent)
{
    resize(1000, 600);
    setFocusPolicy(Qt::TabFocus);
    lista = QList<GraphicElement*>();
}

void RenderArea::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setBrush(Qt::white);
    painter.drawRect(0,0, geometry().width()-1, geometry().height()-1);

    for(int k = 0; k < foodl.count(); k++)
        foodl[k].paint(&painter);
    for(int i = 0; i < lista.count(); i++)
        lista.at(i)->paint(&painter);
}

void RenderArea::focusInEvent(QFocusEvent *){
    grabKeyboard();
}

void RenderArea::focusOutEvent(QFocusEvent *){
    releaseKeyboard();
}

void RenderArea::enterEvent(QEvent *){
    setFocus();
}

void RenderArea::addGraphicElement(GraphicElement *gr){
    lista.push_back(gr);
}

void RenderArea::addFoodElement(){
    foodl.push_back(Food());
}

void RenderArea::addFoodElement(int mul){
    Food f = Food(width()-1, height()-1, mul);
    foodl.push_back( f );
}

void RenderArea::removeFood(int p){
    foodl.removeAt(p);
}
