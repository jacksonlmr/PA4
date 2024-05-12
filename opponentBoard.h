#ifndef OPPONENTBOARD_H
#define OPPONENTBOARD_H
#include <stdio.h>
#include <iostream>
#include <string>
#include "boat.h"
#define BOARD_SIZE 11
using namespace std;

class opponentBoard{
    protected:
        char boardArray[BOARD_SIZE][BOARD_SIZE];

    public:
        opponentBoard();
        opponentBoard(char board[][BOARD_SIZE]);
        opponentBoard(const opponentBoard& rhs);

        void clearBoard();
        bool virtual indexAvailable(Boat b, bool h, int idx[]);
        void changeIndex(int idx[2], char c);
        
        opponentBoard& operator = (const opponentBoard& rhs);
        friend ostream& operator<< (ostream& out, const opponentBoard& rhs);


};

#endif