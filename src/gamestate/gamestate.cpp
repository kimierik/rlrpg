
#include "./gamestate.h"
#include <cstdio>
#include "globalappstate.h"

//these are in .cpp and not in .h since they have to be in order for singelton to work propperly


//contains state of the game
GameState* GameState::instance=nullptr;

GameState * GameState::getGameState(){
    if (instance==nullptr) {
        instance= new GameState;
        return instance;
    }else{
        return instance;
    }
}

void GameState::handleInput(InputAction action) {
    switch (action) {
        case MoveDownAction:
            player->cords.y++;
            break;

        case MoveUpAction:
            player->cords.y--;
            break;

        case MoveLeftAction:
            player->cords.x--;
            break;

        case MoveRightAction:
            player->cords.x++;
            break;

        case InteractAction:
            checkCollisions();
            break;

        case ChangeMenuAction:
                GlobalAppState::getGlobalAppState()->SetView(MainMenuContext);
            break;

        default:
            printf("unknown action%i\n",action);
            break;
    
    }

}




