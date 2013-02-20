#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QDebug>
#include <QPainter>
#include <QPaintEvent>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = 0);
private:
    void paintEvent(QPaintEvent *);
    
signals:
    
public slots:
    
};

#endif // RENDERAREA_H
