#ifndef AI_H
#define AI_H
#include "player.h"

class AI : public Player{
int** usedIndex;

    public:
    AI(): Player(){
        usedIndex = 0;
    }
    AI(int** i, opponentBoard o, playerBoard p):Player(o,p){
        usedIndex = i;
    }
    AI(const AI& rhs): AI(rhs){
        usedIndex = rhs.usedIndex;

    }
    int** getusedIndex(){
        return usedIndex;
    }
    void setusedIndex(int** u){
        usedIndex = u;
    }
    void takeTurn(){

    }
    int[] generateIndex(){

    }
    void generateBoard(){
        
    }
};
#endif