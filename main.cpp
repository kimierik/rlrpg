

#include "raylib.h"
#include "./src/gamestate/gamestate.h"
#include <stdio.h>
#include "./src/globals.h"
#include "src/entities/entity.h"
#include "src/gamestate/globalappstate.h"






int main(void) {
    printf("init game \n");
    InitWindow( SCREENW, SCREENH, "raylib [core] example - basic window");


    GlobalAppState * globalAppState= GlobalAppState::getGlobalAppState();

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
        globalAppState->inputController.HandleInputs();
        BeginDrawing();

        globalAppState->currentlyDrawnView->DrawDrawables();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}


