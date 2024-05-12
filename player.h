#ifndef PLAYER_H
#define PLAYER_H
#include <stdio.h>
#include <iostream>
#include <string>
#include "playerBoard.h"
#include "opponentBoard.h"

using namespace std;

class Player{
    protected:
        playerBoard* pBoard;
        opponentBoard* oBoard;

    public:
        Player();
        Player(playerBoard*, opponentBoard*);
        Player(const Player&);
        ~Player();

        void updateBoard(int[2], char, char);
        virtual void takeTurn() = 0;

        playerBoard* getPlayerBoard();
        opponentBoard* getOpponentBoard();

        void setPlayerBoard(playerBoard*);
        void setOpponentBoard(opponentBoard*);

};

#endif