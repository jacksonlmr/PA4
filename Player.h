#ifndef PLAYER_H
#define PLAYER_H
#include <stdio.h>
#include <iostream>
#include "opponentBoard.h"
#include "playerBoard.h"
using namespace std;

class Player{
    protected:
    playerBoard play; 
    opponentBoard op;

    public:
        Player();
        Player(opponentBoard, playerBoard);
        Player(const Player&);

        void updateBoard(int*, char);
        PlayerBoard getPlayerBoard();
        void setPlayerBoard(PlayerBoard);
        opponentBoard getOpponentBoard();
        void setOpponentBoard(opponentBoard);

        void virtual takeTurn()=0;
        void virtual generateBoard()=0;

    


};
#endif