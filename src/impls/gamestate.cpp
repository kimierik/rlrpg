
#include "../headers/gamestate.h"

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

