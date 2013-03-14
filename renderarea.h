#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QDebug>
#include <QPainter>
#include <QPaintEvent>
#include <QList>
#include "graphicelement.h"

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = 0);
private:
    /**
     * @brief paintEvent
     * This method iterates the list and calls the paint() method
     *on each element of the list;
     */
    void paintEvent(QPaintEvent *);
    //ListOfGraphicElements* list;
    QList<GraphicElement*> lista;
signals:
    
public slots:
    
};

#endif // RENDERAREA_H
