#include "card.h"

Color Card::getColor() const{
    return color;
}

int Card::getNumber() const{
    return number;
}

void Card::setNumber(int n){
    number = n;
}
void Card::setColor(Color c){
    color = c;
}
Type Card::getType() const{
    return typeOfCard;
}
NumberCard::NumberCard(Color cN,int n,Type t){
    setColor(cN);
    setNumber(n);
    typeOfCard = t;
}
string NumberCard::render(int line) const{
    stringstream ss;    
    switch(line){        
        case 0: 
            return ".___________.";        
        case 1: 
            return "|           |";        
        case 2:             
            switch(color){            
                case RED:                
                    return "|    RED    |";                
                    break;            
                case BLUE:                
                    return "|    BLUE   |";                
                    break;            
                case GREEN:                
                    return "|   GREEN   |";                
                    break;            
                case YELLOW:                
                    return "|  YELLOW   |";                
                    break;            
                default:                
                    return "|           |";                
                    break;            
            break;            }        
        case 3:            
            ss << "|     " <<  number << "     |";            
            return ss.str();            
            break;        
        case 4: 
            return "|           |";        
        case 5: 
            return "|           |";        
        case 6: 
            return "|           |";        
        case 7: 
            return "|___________|";        
        default:            
            return " ";    
    }
}
bool NumberCard::play(Card* discard, GameState &gameState) {    
    if(color == discard->getColor() || number == discard->getNumber()){
        return true;    
    } 
    else {        
        return false;    
        
    }
    
}
ReverseCard::ReverseCard(Color cR,Type t){
    setColor(cR);
    typeOfCard = t;
}
string ReverseCard::render(int line) const{
    stringstream ss;    
    switch(line){        
        case 0: 
            return ".___________.";        
        case 1: 
            return "|           |";        
        case 2: 
            switch(color){            
                case RED:                
                    return "|    RED    |";
                    break;            
                case BLUE:                
                    return "|    BLUE   |";                
                    break;            
                case GREEN:                
                    return "|   GREEN   |";                
                    break;            
                case YELLOW:                
                    return "|  YELLOW   |";                
                    break;            
                default:                
                    return "|           |";                
                    break;            
            break;            }        
        case 3:            
            ss << "| --------> |";            
            return ss.str();            
            break;
        case 4: 
            ss << "|  REVERSE  |";            
            return ss.str();            
            break;        
        case 5: 
            ss << "| <-------- |";            
            return ss.str();            
            break;        
        case 6: 
            return "|           |";        
        case 7: 
            return "|___________|";        
        default:            
            return " ";    
    }
}
bool ReverseCard::play(Card* discard, GameState& gameState){
    if(color == discard->getColor() || typeOfCard == discard->getType()){
        
        TurnDirection direc = gameState.getDirection();
        gameState.setDirection(direc);
        return true;    
        
    } 
    else {        
        return false;    
        
    }
}

SkipCard::SkipCard(Color cS,Type t){
    setColor(cS);
    typeOfCard = t;
}
string SkipCard::render(int line) const{
    stringstream ss;    
    switch(line){        
        case 0: 
            return ".___________.";        
        case 1: 
            return "|           |";        
        case 2: 
            switch(color){            
                case RED:                
                    return "|    RED    |";
                    break;            
                case BLUE:                
                    return "|    BLUE   |";                
                    break;            
                case GREEN:                
                    return "|   GREEN   |";                
                    break;            
                case YELLOW:                
                    return "|  YELLOW   |";                
                    break;            
                default:                
                    return "|           |";                
                    break;            
            break;            }        
        case 3:            
            ss << "|    SKIP   |";            
            return ss.str();            
            break;
        case 4: 
            ss << "|     X     |";            
            return ss.str();            
            break;        
        case 5: 
            return "|           |";        
        case 6: 
            return "|           |";        
        case 7: 
            return "|___________|";        
        default:            
            return " ";    
    }
}
bool SkipCard::play(Card* discard, GameState& gameState){
    if(color == discard->getColor() || typeOfCard == discard->getType()){
        gameState.skipTurn = true;
        return true;    
    } 
    else {        
        return false;    
    }
}
Draw2Card::Draw2Card(Color cD,Type t){
    setColor(cD);
    typeOfCard = t;
}
string Draw2Card::render(int line) const{
    stringstream ss;    
    switch(line){        
        case 0: 
            return ".___________.";        
        case 1: 
            return "|           |";        
        case 2: 
            switch(color){            
                case RED:                
                    return "|    RED    |";
                    break;            
                case BLUE:                
                    return "|    BLUE   |";                
                    break;            
                case GREEN:                
                    return "|   GREEN   |";                
                    break;            
                case YELLOW:                
                    return "|  YELLOW   |";                
                    break;            
                default:                
                    return "|           |";                
                    break;            
            break;            }        
        case 3:            
            ss << "|    DRAW2  |";            
            return ss.str();            
            break;
        case 4: 
            ss << "|     +2    |";            
            return ss.str();            
            break;        
        case 5: 
            return "|           |";        
        case 6: 
            return "|           |";        
        case 7: 
            return "|___________|";        
        default:            
            return " ";    
    }
}
bool Draw2Card::play(Card* discard, GameState& gameState){
    if(color == discard->getColor() || typeOfCard == discard->getType()){
        //gameState.nextTurn();
        gameState.numCardsToDraw = 2;
        gameState.skipTurn = true;
        return true;    
        
    } 
    else {        
        return false;    
        
    }
}

WildCard::WildCard(Color col,Type t){
    typeOfCard = t;
    color = col;
}
string WildCard::render(int line) const{
    stringstream ss;    
    switch(line){        
        case 0: 
            return ".___________.";        
        case 1: 
            return "|           |";        
        case 2: 
            return "|           |";
        case 3:            
            ss << "|    WILD   |";            
            return ss.str();            
            break;
        case 4: 
            ss << "|    RBGY   |";            
            return ss.str();            
            break;        
        case 5: 
            return "|           |";        
        case 6: 
            return "|           |";        
        case 7: 
            return "|___________|";        
        default:            
            return " ";    
    }
}
bool WildCard::play(Card* discard, GameState& gameState){
    
    string input;
    
    
    cout << "What color would you like it to be? R-Red, B-Blue, G-Green, Y-Yellow " << endl;
    getline(cin,input);

    int lengthString = input.length();
    char userInput[lengthString + 1];
    
    strcpy(userInput,input.c_str());//converts to character array so that I can use following functions
    Color col;
    bool correctColor = true;
    
    do{
        if ((strchr(userInput,'R') != NULL) || (strchr(userInput,'r') != NULL)){
            col = RED;
            setColor(col);
            correctColor = true;
        }
        else if ((strchr(userInput,'B') != NULL) || (strchr(userInput,'b') != NULL)){
            col = BLUE;
            setColor(col);
            correctColor = true;
        }
        else if ((strchr(userInput,'G') != NULL) || (strchr(userInput,'g') != NULL)){
            col = GREEN;
            setColor(col);
            correctColor = true;
        }
        else if ((strchr(userInput,'Y') != NULL) || (strchr(userInput,'y') != NULL)){
            col = YELLOW;
            setColor(col);
            correctColor = true;
        }
        else {
            cout << "Not a valid input. Try again." << endl;
            correctColor = false;
            cout << "What color would you like it to be? R-Red, B-Blue, G-Green, Y-Yellow " << endl;
            getline(cin,input);
            strcpy(userInput,input.c_str());
        }
    }while(correctColor == false);
        
    
    return true;
}
Plus4Card::Plus4Card(Color cP,Type t){
    typeOfCard = t;
    color = cP;
}
bool Plus4Card::play(Card* discard, GameState& gameState){
    
    string input;
    
    
    cout << "What color would you like it to be? R-Red, B-Blue, G-Green, Y-Yellow " << endl;
    getline(cin,input);

    int lengthString = input.length();
    char userInput[lengthString + 1];
    
    strcpy(userInput,input.c_str());//converts to character array so that I can use following functions
    Color cP;
    bool correctColor = true;
    
    do{
        if ((strchr(userInput,'R') != NULL) || (strchr(userInput,'r') != NULL)){
            cP = RED;
            setColor(cP);
            correctColor = true;
        }
        else if ((strchr(userInput,'B') != NULL) || (strchr(userInput,'b') != NULL)){
            cP = BLUE;
            setColor(cP);
            correctColor = true;
        }
        else if ((strchr(userInput,'G') != NULL) || (strchr(userInput,'g') != NULL)){
            cP = GREEN;
            setColor(cP);
            correctColor = true;
        }
        else if ((strchr(userInput,'Y') != NULL) || (strchr(userInput,'y') != NULL)){
            cP = YELLOW;
            setColor(cP);
            correctColor = true;
        }
        else {
            cout << "Not a valid input. Try again." << endl;
            correctColor = false;
            cout << "What color would you like it to be? R-Red, B-Blue, G-Green, Y-Yellow " << endl;
            getline(cin,input);
            strcpy(userInput,input.c_str());
        }
    }while(correctColor == false);
    gameState.skipTurn = true;    
    gameState.numCardsToDraw = 4;
    
    return true;
}
string Plus4Card::render(int line) const{
    stringstream ss;    
    switch(line){        
        case 0: 
            return ".___________.";        
        case 1: 
            return "|           |";        
        case 2: 
            return "|           |";
        case 3:            
            ss << "|    +4     |";            
            return ss.str();            
            break;
        case 4: 
            ss << "|    RBGY   |";            
            return ss.str();            
            break;        
        case 5: 
            return "|           |";        
        case 6: 
            return "|           |";        
        case 7: 
            return "|___________|";        
        default:            
            return " ";    
    }
}