#pragma once

#include <cstdio>
#include <raylib.h>





class Entity{

    public:
    Vector2 cord;

    //constructor for cordinates
    Entity( int x, int y);

    //tells gamestate that it no longer exists
    virtual ~Entity();

    // handles if player interacts with this.. 
    virtual void interactionHandle(){}
    
    //if the entity has logic that needs to be run on game update 
    virtual void Update(){}

    //abstract draw method for entities
    ///all entities probably should have a sprite or something
    virtual void draw(){}

};


//Entity item
class EItem :public Entity{


    public:
    int _id=0;
    int _quantity=0;

    EItem(int x, int y, int id, int quantity) : Entity(x,y){
        _id=id;
        _quantity=quantity;
    }

    ~EItem();

    void interactionHandle() override;

    void draw() override;

};


