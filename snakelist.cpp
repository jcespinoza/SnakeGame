#include "snakelist.h"

Nodo::Nodo(SnakePart *arg){
    next = prev = 0;
    content = arg;
}

SnakeList::SnakeList()
{
    first = last = current = 0;
    conteo = 0;
}

void SnakeList::goToFirst()
{ current = first;}

void SnakeList::goToLast()
{current = last;}

void SnakeList::goToNext()
{current = (current == 0) ? current: current->next;}

void SnakeList::goToPrevious()
{current = (current == 0) ? current: current->prev;}

SnakePart* SnakeList::get(){
    qDebug() << "in the get method";
    if(current != 0)
        return current->content;
    else
        return 0;
}

SnakePart* SnakeList::at(int pos){
    qDebug() << "in the at() method";
    if(isEmpty()){
        qDebug() << "it was empty";
        return 0;
    }
    qDebug() << "it was NOT empty";
    if( (pos > count()) || (pos <= 0))

        return 0;
    else{
        goToFirst();
        for(int i = 1; i < pos; i++)
            goToNext();
        return current->content;
    }
}

void SnakeList::add(SnakePart* cont){
    Nodo* elem = new Nodo(cont);
    if(conteo == 0){
        first = last = elem;
        current = elem;
    }else{
        last->next = elem;
        elem->prev = last;
        last = elem;
    }
    conteo++;
}

SnakeList::~SnakeList(){
    clear();
}

void SnakeList::clear(){
    current = first;
    while(current != 0){
        first = first->next;
        delete current->content;
        delete current;
        current = first;
    }
    first = last = current = 0;
    conteo = 0;
}

void SnakeList::clearRecursively(Nodo* n){
    if(n == 0) return;
    else{
        clearRecursively(n->next);
        delete n;
    }
}

SnakePart* SnakeList::take(int pos){
    SnakePart* sp = 0;
    goToFirst();

    for(int i = 1; i < pos; i++)
        goToNext();

    if(pos != 1 && pos != conteo){
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }else if(pos == conteo){
        first = current->next;
        if(current->next != 0)
            current->next->prev = 0;
    }else if(pos == conteo){
        last = current->prev;
        current->prev->next = 0;
    }

    if(pos > 0 && pos <= conteo){
        conteo--;
        sp = current->content;
        delete current;
    }
    return sp;
}

bool SnakeList::isEmpty(){
    qDebug() << "in the isEmpty() method";
    bool f = (this->first == 0);
    qDebug() << "first == 0" << f;
    bool c = conteo == 0;
    qDebug() << "conteo == 0" << c;
    return f || c;
}

void SnakeList::goTo(int pos){
    if(pos <= 1){
        goToNext(); return;
    }
    if(pos == conteo - 1){
        goToLast(); return;
    }
    goToFirst();
    for(int i = 1; i < pos; i++){
        if(current->next != 0)
            goToNext();
    }
}

void SnakeList::insert(SnakePart* con, int pos){
    if(pos >= 1){
        if(isEmpty() || conteo <= pos){
            add(con); return;
        }
        goTo(pos);
        Nodo* newE = new Nodo(con);
        if(pos == 1){
            first = newE;
            current->prev = newE;
            newE->next = current;
        }else{
            current->prev->next = newE;
            current->prev = newE;
            newE->next = current;
            newE->prev = current->prev;
            if(pos > conteo)
                last = newE;
        }
        conteo++;
    }
}

void SnakeList::advanceItems(){
    goToFirst();
    SnakePart* head = get();

    switch(head->getDirection()){
    case head->UP:
        head->setY( head->getY() - head->partSize );
        break;
    case head->DOWN:
        head->setY( head->getY() + head->partSize );
        break;
    case head->RIGHT:
        head->setX( head->getX() + head->partSize );
        break;
    case head->LEFT:
        head->setX( head->getX() - head->partSize );
        break;
    }

    goToLast();
    for(int i = count()-1; i > 1; i--){
        SnakePart* act = get();
        SnakePart* previ = 0;
        if(current->prev != 0)
            previ = current->prev->content;
        if(previ != 0 && act != 0){
            act->setDirection(previ->getDirection());
            act->setX(previ->getX());
            act->setY(previ->getY());
            act->setZ(previ->getZ());
            act->advance();
        }
        goToPrevious();
    }
}
