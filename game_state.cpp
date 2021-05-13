#include "game_state.h"

using namespace std;

GameState::GameState(int n){    
    numPlayers = n;    
    currentPlayerIndex = 0;    
    numCardsToPlay = 1;    
    numCardsToDraw = 0;    
    turnDirection = LEFT;
    
}
void GameState::nextTurn(){    
    if(turnDirection == LEFT){        
        currentPlayerIndex++;        
        if(currentPlayerIndex >= numPlayers){            
            currentPlayerIndex = 0;        
        }    
    } 
    else{        
        currentPlayerIndex--;        
        if(currentPlayerIndex < 0){            
            currentPlayerIndex = numPlayers - 1;    
        }
    }
    
}
void GameState::setDirection(TurnDirection& td){
    if (td == LEFT){
        turnDirection = RIGHT;
        return;
    }
    else if (td == RIGHT){
        turnDirection = LEFT;
        return;
    }
}
TurnDirection GameState::getDirection(){
    return turnDirection;
}
