

//things like items and mobs
#include <cstdio>
#include <raylib.h>
#include "../headers/gamestate.h"

#include "../headers/entity.h"




Entity::Entity(int x,int y){
    cord.y=y;
    cord.x=x;

    //printf("entity constructor;\n");
    //tell gamestate that an entity exists now
    GameState::getGameState()->registerEntity(this);
}


Entity::~Entity(){
    //printf("entity deconstruct;\n");
    GameState::getGameState()->unRegisterEntity(this);
    //printf("unregistered \n");
}



EItem::~EItem(){ }




void EItem::interactionHandle() {
    if( GameState::getGameState()->player->inv->addToInv(_id, _quantity)){
        delete this;
    }
}



//super simple id to hardcoded color
void EItem::draw(){
    Color c;
    if (_id == 20) {
        c=RED;
    }
    
    DrawRectangle(cord.x*TILESIZE, cord.y*TILESIZE, TILESIZE-5, TILESIZE-5, c);
}

