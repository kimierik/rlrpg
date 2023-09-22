

#include "raylib.h"
#include "./src/headers/gamestate.h"
#include <stdio.h>
#include "./src/globals.h"
#include "src/headers/entity.h"






int main(void) {
    printf("init game \n");
    InitWindow( SCREENW, SCREENH, "raylib [core] example - basic window");

    GameState * game= GameState::getGameState();
    printf("made game\n");
    game->makePlayer(10, 10);
    printf("made player\n");

    EItem *_item= new EItem(11,11,20,1);


    //manually set some items for debugging purpoises
    game->player->inv->grid[3][3].itemId=2;
    game->player->inv->grid[3][3].quantity=200;


   // game->player->inv->printInventory();

    //game loop
    while (!WindowShouldClose()) {
        
        //input needs to be hid somewhere since it look ugly rn
        //also make it somwehat modular
        //also make it so that the player does not go out of the gamescreen
        if (IsKeyPressed(KEY_W)) {
            game->player->cords.y--;
        }

        if (IsKeyPressed(KEY_S)) {
            game->player->cords.y++;
        }

        if (IsKeyPressed(KEY_A)) {
            game->player->cords.x--;
            
        }

        if (IsKeyPressed(KEY_D)) {
            game->player->cords.x++;
        }

        if (IsKeyPressed(KEY_E)) {
            game->checkCollisions();
        }


        game->drawScreen();
        //game->player->inv->printInventory();
        //printf("clearing EntityDestructionQueue\n");

        //entityDestructionQueue is dead code rn
        //was used for soemthign but can delete now
        //game->clearEntityDestructionQueue();
        //printf("cleared EntityDestructionQueue\n");
    }

    CloseWindow();

    return 0;
}


