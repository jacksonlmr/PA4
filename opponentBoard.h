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
        opponentBoard(){
            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    if (i == 0 && j == 0) {
                        boardArray[i][j] = ' ';
                    }

                    else if (i == 0) {
                        boardArray[i][j] = 'A' + j - 1;
                    } 

                    else if (j == 0) {
                        boardArray[i][j] = '0' + i - 1;
                    } 

                    else {
                        boardArray[i][j] = '-';
                    }
                }
            }
        }

        opponentBoard(char board[][BOARD_SIZE]){
            for (int i = 0; i < BOARD_SIZE; i++){
                for (int j = 0; j < BOARD_SIZE; j++){
                    boardArray[i][j] = board[i][j];
                }
            }
        }
        opponentBoard(const opponentBoard& rhs){
            for (int i = 0; i < BOARD_SIZE; i++){
                for (int j = 0; j < BOARD_SIZE; j++){
                    boardArray[i][j] = rhs.boardArray[i][j];
                }
            }
        }

        void clearBoard(){
            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    if (i == 0 && j == 0) {
                        boardArray[i][j] = ' ';
                    }

                    else if (i == 0) {
                        boardArray[i][j] = 'A' + j - 1;
                    } 

                    else if (j == 0) {
                        boardArray[i][j] = '0' + i - 1;
                    } 

                    else {
                        boardArray[i][j] = '-';
                    }
                }
            }
        }

        bool virtual indexAvailable(Boat b, bool h, int idx[]){
            if (boardArray[idx[0]][idx[1]] != '-'){
                return false;
            }

            else {
                return true;
            }
        }

        opponentBoard& operator = (const opponentBoard& rhs){
            for (int i = 0; i < BOARD_SIZE; i++){
                for (int j = 0; j < BOARD_SIZE; j++){
                    boardArray[i][j] = rhs.boardArray[i][j];
                }
            }
            return *this;
        }

        friend ostream& operator<< (ostream& out, const opponentBoard& rhs);


};

ostream& operator<< (ostream& out, const opponentBoard& rhs){
            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    out << rhs.boardArray[i][j] << " ";
                }
                out << endl;
            }
            return out;
}
#endif