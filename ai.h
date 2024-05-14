#ifndef AI_H
#define AI_H
#include "player.h"
#include<cstdlib>

class AI : public Player{
int** usedIndex;

    public:
    AI();
    AI(int** i, playerBoard*, opponentBoard*);
    AI(const AI& rhs);

    int** getusedIndex();

    void setusedIndex(int** u);

    void virtual takeTurn();
    int* generateIndex();
    void generatePlayerBoard();
    void populateBoard();
};
#endif