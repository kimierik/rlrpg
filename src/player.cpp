#pragma once

#include "./inventory.cpp"
#include <raylib.h>



class Player{
    public:
    Vector2 cords;

    Inventory *inv;

    
    ~Player(){
        delete inv;
    }

};
