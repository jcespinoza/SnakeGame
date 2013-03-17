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
    for(int i = 0; i < lista.count(); i++){
        lista.at(i)->paint(&painter);
    }
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
