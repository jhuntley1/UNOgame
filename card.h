#ifndef CARD_H
#define CARD_H

#include <sstream>
#include <string>
#include "game_state.h"
#include <cstring>
#include <iostream>

using namespace std;


enum Color{RED, BLUE, GREEN, YELLOW, NUM_COLORS};
enum Type{NUMBER, REVERSE, SKIP, DRAW2, WILD, PLUS4, NUM_TYPES};

class Card{
    protected:
    Color color;
    int number;
    Type typeOfCard;
    
    public:
    Color getColor() const;
    int getNumber() const;
    void setColor(Color c);
    void setNumber(int n);
    void setType(Type t);
    Type getType() const;
    
    virtual string render(int line) const = 0;
    virtual bool play(Card* discard, GameState& gameState) = 0;
};

class NumberCard : public Card{
    public:
    NumberCard(Color cN,int n,Type t);
    string render(int) const;
    /**     
    * The function to play a the card. This function evaluates the top card of     
    * the discard pile for a match and if valid, will alter the state of the      
    * game accordingly. If not valid, the function will not alter the game      
    * state and return false.     
    *      
    * @param discard A pointer to the card that is on top of the discard pile.     
    * @param gameState A reference to the game state object.     
    * @return A boolean value representing if the card played was valid      
    * according to the top card of the discard pile.     
    */    
    bool play(Card*, GameState&);
    private:
    
};
class ReverseCard : public Card{
    public:
    ReverseCard(Color cR,Type t);
    string render(int) const;
    bool play(Card*, GameState&);
    private:
};
class SkipCard : public Card{
    public:
    SkipCard(Color cS,Type t);
    string render(int) const;
    bool play(Card*, GameState&);
    private:
};
class Draw2Card : public Card{
    public:
    Draw2Card(Color cD,Type t);
    string render(int) const;
    bool play(Card*, GameState&);
    private:
};
class WildCard : public Card{
    public:
    WildCard(Color col,Type t);
    string render(int) const;
    bool play(Card*, GameState&);
    private:
};
class Plus4Card : public Card{
    public:
    Plus4Card(Color cP,Type t);
    string render(int) const;
    bool play(Card*, GameState&);
    private:
};
#endif