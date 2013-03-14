#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include <QTimer>
#include "renderarea.h"
#include "snake.h"
#include "snakepart.h"

class GameController: public QObject
{
    Q_OBJECT
public:
    explicit GameController();
    void setRenderer(RenderArea*);
    ~GameController();
    RenderArea* getRenderer(){return renderer;}
signals:
    void pTimeOutS();
private slots:
    void pTimeOut();
signals:

private:
    QTimer *elapsed;
    QTimer* refresher;
    RenderArea* renderer;
    Snake* snake1;
    Snake* snake2;

};

#endif // GAMECONTROLLER_H
