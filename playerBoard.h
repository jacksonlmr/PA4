#ifndef PLAYERBOARD_H
#define PLAYERBOARD_H
#include <stdio.h>
#include <iostream>
#include <string>
#include "opponentBoard.h"
#define BOARD_SIZE 11
#define BOAT_CHARACTER 'n'
using namespace std;

class playerBoard: public opponentBoard{
    int numBoats, maxNumBoats;
    Boat** boatsOnBoard;
    char board[11][11];

    public:
        playerBoard();
        playerBoard(int n, int m, Boat** b, char board[][11]);
        playerBoard(const playerBoard& rhs);

        Boat** getBoatsOnBoard();
        int getNumBoats();
        void initializeBoard(//Boat* b, int numBoats, char board[11][11]
        );

        bool virtual indexAvailable(Boat* b);
        bool addBoat(Boat* b);
        void addBoatToArray(Boat* b);

        playerBoard& operator =(const playerBoard& rhs);
};

#endif