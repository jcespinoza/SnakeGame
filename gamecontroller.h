#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include <QTimer>
#include "renderarea.h"
#include "snakepart.h"
class GameController: public QObject
{
    Q_OBJECT
public:
    explicit GameController();
    void setRenderer(RenderArea*);
private slots:

signals:

private:
    QTimer timer;
    RenderArea* renderer;
    Snake* snake1;
    Snake* snake2;
};

#endif // GAMECONTROLLER_H
