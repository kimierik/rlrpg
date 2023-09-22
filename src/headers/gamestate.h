#pragma once

#include "../player.cpp"
#include "../globals.h"

#include <cstdio>
#include <raylib.h>

#include <string>
#include <vector>

#include "../inventory.cpp"

#include "./entity.h" 



class GameState{

    //todo make a propper interface to interface with player not just a public variable
    public:
    Player* player=nullptr;
    std::vector<Entity*> entities;
    std::vector<EItem*> entityDestructionQueue;


    //singelton logic
    private:
    static GameState * instance;
    GameState(){}

    public:
    GameState(const GameState&ob)=delete;
    static GameState * getGameState();
    // end of singelton logic







    // ------------------------------ functions ------------------------------ //  
    public:
    void registerEntity(Entity *ent){
        entities.push_back(ent);
    }


    void registerEntityForDestruction(EItem *ent){
        entityDestructionQueue.push_back(ent);
    }

    void unRegisterEntity(Entity *ent){
        printf("entities list has %lu entries \n",entities.size());
        for(unsigned long i=0; i<entities.size();i++){
            if (entities.at(i)==ent){
                entities.erase(entities.begin()+i);
                printf("found entity to remove and removed it\n");
            }
        }
        printf("entities list has %lu entries \n",entities.size());
        //idk what happens if we unreqister something that was never there
    }





    //goes trough every entity and sees if cords are the same
    void checkCollisions(){
        for(unsigned long i=0; i<entities.size();i++){
            if(entities.at(i)->cord.x==player->cords.x){
                if(entities.at(i)->cord.y==player->cords.y){
                    entities.at(i)->interactionHandle();
                }
            }
        }
    }

    void clearEntityDestructionQueue(){
        for(unsigned long i=0; i<entityDestructionQueue.size();i++){
            printf("deleting\n");
            delete entityDestructionQueue.at(i);
        }
        entityDestructionQueue.clear();
        //printf("destruction list has %lu entries \n",entityDestructionQueue.size());

    }



    void drawScreen(){
        BeginDrawing();

        ClearBackground(RAYWHITE);
        // make a grid on the side of the screen that displays an inventory
        // then we can later make somethign that adds etc to the inv and maybe even reads it idk

        DrawRectangle(0, 0, GAMEW, GAMEH, BLACK);

        drawInv();

        drawEntities();



        // make c a member in player
        Color c = ColorFromHSV(110, 80, 86);
        //draw player
        DrawRectangle(player->cords.x*TILESIZE, player->cords.y*TILESIZE, TILESIZE, TILESIZE, c);


        EndDrawing();
    }


    //loops through all entities and draws them
    void drawEntities(){
        for(unsigned long i=0; i<entities.size();i++){
            entities.at(i)->draw();
        }
        
    }



    void drawInv(){
        int offs=5;// offset
        int size=45;// size of the inventory grid piece in pixels

        for ( int coll =0; coll<player->inv->collumns;coll++) {
            for ( int row =0; row<player->inv->rows;row++) {
                DrawRectangle(GAMEW+offs+ coll*size+offs, row*size+offs, size-offs, size-offs, GRAY);

                DrawText(TextFormat("id:%d",player->inv->grid[coll][row].itemId), GAMEW+offs+ coll*size+offs, row*size+offs, 5,  BLACK);
                DrawText(TextFormat("quan:%d",player->inv->grid[coll][row].quantity), GAMEW+offs+ coll*size+offs, row*size+offs+size/2, 5,  BLACK);
            }
        
        }
    }


    //
    void makePlayer(int x, int y){
        if (player != nullptr){
            //deconstruct player if it exists
            delete player;
        }

        player = new Player;
        player->inv = new Inventory;
        player->cords.x =x;
        player->cords.y =y;
    }



};

