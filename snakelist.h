#ifndef SNAKELIST_H
#define SNAKELIST_H
#include "snakepart.h"
#include <QDebug>

class Nodo{
public:
    Nodo(SnakePart*);
    Nodo(){next = prev = 0; content = 0;}
    Nodo* next;
    Nodo* prev;
    SnakePart* content;
    ~Nodo(){next = prev = 0;content = 0;}
};

class SnakeList
{
public:
    SnakeList();
    void goToNext();
    void goToPrevious();
    void goToLast();
    void goToFirst();
    void clear();
    void goTo(int);
    void insert(SnakePart*, int);
    SnakePart* at(int);
    SnakePart* get();
    void add(SnakePart*);
    SnakePart* take(int);
    bool isEmpty();
    int count() const{return countP;}
    void advanceItems();
    ~SnakeList();
private:
    Nodo* first;
    Nodo* last;
    Nodo* current;
    int countP;
    void clearRecursively(Nodo*);
};
#endif // SNAKELIST_H
