#include <iostream>
#include <vector>
#include "game_state.h"
#include "card.h"
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <cctype>
using namespace std;
/** 
* Function to clear the terminal by inserting many new line characters. 
*/
void clearTerminal();
void buildDeck(vector<Card*>& deck);
void shuffleDeck(vector<Card*>&);
/** 
* Function to draw a card from the deck to either the hand or discard pile. 
*  
* @param deck A vector reference of Card pointers representing the deck 
* @param target A vector representing the structure that the card being drawn  
* from the deck is being drawn to. This can be either a hand or the discard 
* pile 
*/
void drawCards(vector<Card*>& deck, vector<Card*>& target, int);
void populateHands(vector<Card*>& deck, vector<vector<Card*>>& hands);
/**  
* Renders the cards in the hand vector passed. 
*  
* @param hand A vector containing Card pointers 
*/
void renderHand(vector<Card*> hand);
/** 
 * Renders the top card of the passed discard vector. 
 * 
 * @param hand A vector containing Card pointers 
 */
void renderDiscard(vector<Card*>);
/** 
* Passed references to the deck, hand, and discard vectors and a reference to  
* the game state. This function will resolve the turn for the current player 
* (whose index is stored in the game state). TakeTurn will query the user for 
* input, draw cards if the previous card was a draw 2 card, or skip the current 
* players turn (see numCardsToPlay in GameState). 
*  
* @param deck A vector reference of Card pointers representing the deck 
* @param hand A vector reference of Card pointers representing a single player's hand 
* @param discard A vector reference of Card pointers representing the discard pile 
* @param gameState A reference of the game state object 
*/
void takeTurn(vector<Card*>& deck, vector<Card*>& hand, vector<Card*>& discard, GameState& gameState,vector<vector<Card*>>&hands);

bool checkWinner(vector<vector<Card*>>&hands);


int main(){
    srand(time(0));
    
    
    cout << "Greeting Welcome to UNO!" << endl;
    
    string nPlayers;
    int theWinner;
    cout << "How many players are playing?" << endl;
    getline(cin,nPlayers);
    for (unsigned int index = 0; index < nPlayers.size(); index++){
        if (!isdigit(nPlayers.at(index))){
            nPlayers.erase(remove(nPlayers.begin(), nPlayers.end(), nPlayers.at(index)), nPlayers.end());
        }
    }
    int numberOfPlayers = stoi(nPlayers);
    bool winner = false;
    if (numberOfPlayers <= 1){
        cout << "There are to few players. Try between 2 and 10 players." << endl;
    }
    else{
        while (numberOfPlayers > 10 ){
            cout << "There are too many players. There is a maximum of 10 players that can play." << endl;
            cout << "How many players are playing?" << endl;
            getline(cin,nPlayers);
            for (unsigned int index = 0; index < nPlayers.size(); index++){
                if (!isdigit(nPlayers.at(index))){
                    nPlayers.erase(remove(nPlayers.begin(), nPlayers.end(), nPlayers.at(index)), nPlayers.end());
                }
            }
            numberOfPlayers = stoi(nPlayers);
        }
        const int NUM_PLAYERS = numberOfPlayers;
        cout << "Based on your input there is " << NUM_PLAYERS << " player(s) playing :)" << endl;
        GameState gameState(NUM_PLAYERS);
        
        vector<Card*> deck;
        vector<Card*> discard;
        
        vector<vector<Card*>> hands(NUM_PLAYERS);//represents a vector for the number of players
        
        buildDeck(deck);
        shuffleDeck(deck);
        populateHands(deck, hands);
        drawCards(deck, discard, 1);
        
        while(winner == false){        
            takeTurn(deck, hands.at(gameState.currentPlayerIndex), discard, gameState,hands);
            winner = checkWinner(hands);
        }
        cout << "We have a winner! Player " /*<< gameState.getWinner()*/ << " wins!" << endl;
    }
    return 0;
}

void clearTerminal(){    
    for(int i = 0; i < 100; i++){        
        cout << endl;    
    }
}
void buildDeck(vector<Card*> &deck){
    int type;
    for (int c = RED; c < NUM_COLORS; c++){
        for (int n = 0; n < 10; n++){
            type = NUMBER;
            Card* tmp1 = new NumberCard((Color)c, n,(Type)type);
            deck.push_back(tmp1);
            deck.push_back(tmp1);
        }
        for (int num = 0; num < 2; num++){
            type = REVERSE;
            Card* tmp2 = new ReverseCard((Color)c,(Type)type);
            deck.push_back(tmp2);
        }
        for (int num = 0; num < 2; num++){
            type = SKIP;
            Card* tmp3 = new SkipCard((Color)c,(Type)type);
            deck.push_back(tmp3);
        }
        for (int num = 0; num < 2; num++){
            type = DRAW2;
            Card* tmp4 = new Draw2Card((Color)c,(Type)type);
            deck.push_back(tmp4);
        }
        for (int num = 0; num < 1; num++){
            type = WILD;
            Card* tmp5 = new WildCard((Color)c,(Type)type);
            deck.push_back(tmp5);
        }
        for (int num = 0; num < 1; num++){
            type = PLUS4;
            Card* tmp6 = new Plus4Card((Color)c,(Type)type);
            deck.push_back(tmp6);
        }
    }
}
void shuffleDeck(vector<Card*>&deck){
    for (int i = 0; i < 1000; i++){
        int idx1 = rand() % deck.size();
        int idx2 = rand() % deck.size();
        Card* temp = deck.at(idx1);
        deck.at(idx1) = deck.at(idx2);
        deck.at(idx2) = temp;
    }
}
void drawCards(vector<Card*> &deck, vector<Card*> &target, int numToDraw){
    for (int i = 0; i < numToDraw; i++){
        if (deck.size() > 0) {
            target.push_back(deck.at(deck.size() - 1));
            deck.pop_back(); //removes card picked from the deck
        }
        else {
            cout << "WARNING: Deck out of cards!" << endl;
        }
    }
}
void populateHands(vector<Card*> &deck,vector<vector<Card*>> &hands){
    for (int i = 0; i < hands.size(); i++){
        drawCards(deck,hands.at(i),3);
    }
}
void renderHand(vector<Card*> hand){    
    if(hand.size() > 0){        
        for(int i = 0; i <= 7; i++){            
            for(int j = 0; j < hand.size(); j++){                
                cout << hand.at(j)->render(i) << " ";            
            }            
            cout << endl;        
        }
    } 
    else{        
        for(int i = 0; i <= 7; i++)            
        cout << endl;    
    }
}
void renderDiscard(vector<Card*> discard){    
    for(int i = 0; i <= 7; i++){        
        cout << discard.at(discard.size() - 1)->render(i) << endl;    
    }
}
void takeTurn(vector<Card*> &deck, vector<Card*> &hand, vector<Card*> &discard, GameState &gameState,vector<vector<Card*>>&hands){    
    clearTerminal();    
    renderDiscard(discard);    
        
       
    drawCards(deck, hand, gameState.numCardsToDraw);    
    gameState.numCardsToDraw = 0; 
       
    if(!gameState.skipTurn){        
        // Collect user input
        cout << "Player " << gameState.currentPlayerIndex << "'s turn." << endl;
        renderHand(hand);
        cout << "What would you like to do?" << endl;        
        int i;        
        for(i = 0; i < hand.size(); i++){            
            cout << i << ": Play Card" << endl;        
        }        
        cout << i << ": Draw a Card" << endl;        
        int input;        
        cin >> input;        
        // Evaluate user input        
        if(input < i){            
            // Play card at index input            
            if(hand.at(input)->play(discard.at(discard.size()-1), gameState)){                
                Card* temp;                
                temp = hand.at(input);                
                discard.push_back(temp);                
                hand.erase(hand.begin() + input); // Remove card in hand at position "input"            
            } 
            else {                
                cout << "Improper choice" << endl;                
                takeTurn(deck, hand, discard, gameState,hands);                
                return;            
            }        
        }
        else if(input == i){            
            drawCards(deck, hand, 1);        
        }    
    }
    else{        
        gameState.skipTurn = false;
        cout << "Player " << gameState.currentPlayerIndex << " got skipped!" << endl;
        if (gameState.numCardsToDraw > 0){
            cout << "Player " << gameState.currentPlayerIndex << " has to draw " << gameState.numCardsToDraw << "cards!" << endl;
        }
        renderHand(hand);
        
    }    
    // update variables for next turn 
    gameState.nextTurn();
    
}
bool checkWinner(vector<vector<Card*>>&hands){
    for (unsigned int amtPlayers = 0; amtPlayers < hands.size(); amtPlayers++){
        if (hands.at(amtPlayers).size() == 0) {
            return true;
            break;
        } 
        else {
            return false;
            break;
        }
    }
}