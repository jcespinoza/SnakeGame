#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include <QTimer>
#include "renderarea.h"
#include "snake.h"
#include "time.h"
#include "food.h"

class Pair{
public:
    int first;
    int second;
};

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
    void stopGame();
    Pair generateXY(int minw, int maxw, int minh, int maxh, int mult);
signals:
    void pTimeOutS();
    void updateScores(int,int);
private slots:
    void pTimeOut();
    void updateGraphics();
    void generateFood();
signals:

private:
    QTimer *elapsed;
    QTimer* refresher;
    QTimer* foodGenTimer;
    RenderArea* renderer;
    Snake* snake1;
    Snake* snake2;

};

#endif // GAMECONTROLLER_H
