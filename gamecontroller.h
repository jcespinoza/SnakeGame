#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include <QTimer>
#include "renderarea.h"
#include "snake.h"

class GameController: public QObject
{
    Q_OBJECT
public:
    explicit GameController();
    void setRenderer(RenderArea*);
    ~GameController();
    RenderArea* getRenderer(){return renderer;}
    void processKey(int);
    void processDirection(int, int);
    void startGame();
signals:
    void pTimeOutS();
    void updateScores(int,int);
private slots:
    void pTimeOut();
    void updateGraphics();
signals:

private:
    QTimer *elapsed;
    QTimer* refresher;
    RenderArea* renderer;
    Snake* snake1;
    Snake* snake2;

};

#endif // GAMECONTROLLER_H
