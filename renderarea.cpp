#include "renderarea.h"

RenderArea::RenderArea(QWidget *parent) :
    QWidget(parent)
{
    resize(1000, 600);
}

void RenderArea::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setBrush(Qt::white);
    painter.drawRect(0,0, geometry().width()-1, geometry().height()-1);
}
