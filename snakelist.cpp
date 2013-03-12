#include "snakelist.h"

Nodo::Nodo(SnakePart *arg){
    next = prev = 0;
    content = arg;
}

SnakeList::SnakeList()
{
    first = last = current = 0;
    countP = 0;
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
    if(current != 0)
        return current->content;
    else
        return 0;
}

SnakePart* SnakeList::at(int pos){
    if(countP == 0 || pos > countP || pos <= 0)
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
    if(countP == 0){
        first = last = elem;
        current = elem;
    }else{
        last->next = elem;
        elem->prev = last;
        last = elem;
    }
    countP++;
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
    countP = 0;
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

    if(pos != 1 && pos != countP){
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }else if(pos == countP){
        first = current->next;
        if(current->next != 0)
            current->next->prev = 0;
    }else if(pos == countP){
        last = current->prev;
        current->prev->next = 0;
    }

    if(pos > 0 && pos <= countP){
        countP--;
        sp = current->content;
        delete current;
    }
    return sp;
}

bool SnakeList::isEmpty()
{ return first == 0 || countP == 0;}

void SnakeList::goTo(int pos){
    if(pos <= 1){
        goToNext(); return;
    }
    if(pos == countP - 1){
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
        if(isEmpty() || countP <= pos){
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
            if(pos > countP)
                last = newE;
        }
        countP++;
    }
}
