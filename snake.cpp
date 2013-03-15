#include "snake.h"

Snake::Snake():GraphicElement(){

}

Snake::Snake(int x, int y, int z):GraphicElement(x, y, z){

}

void Snake::paint(QPainter *painter){
    members->goToFirst();
    for(int i = 1; i < members->count(); i++){
        members->get()->paint(painter);
    }
}

void Snake::advance(){
    members->advanceItems();
}
