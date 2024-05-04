#ifndef PLAYERBOARD_H
#define PLAYERBOARD_H
#include <stdio.h>
#include <iostream>
#include <string>
#include <opponentBoard.h>
#define BOARD_SIZE 11
using namespace std;

class playerBoard: public opponentBoard{
    int numBoats;
    Boat* boatsOnBoard;

    public:
        playerBoard(): opponentBoard(){}

        playerBoard(int n, Boat* b, char board[][11]): opponentBoard(board){
            
        }

        playerBoard(const playerBoard&){

        }

        Boat* getBoatsOnBoard(){

        }

        int getNumBoats(){

        }

        bool virtual indexAvailable(Boat b, bool h, int idx[]){
            bool returnValue = true;
            int rowIndex = idx[0];
            int columnIndex = idx[1];
            int endColumnIndex = columnIndex + b.getSize();
            int endRowIndex = rowIndex + b.getSize();

            if (h == true){
                if (endColumnIndex > 9){
                    returnValue = false;
                }

                else{
                    for (int i = 0; i < 9; i++){
                        if (boardArray[rowIndex][columnIndex + i] != '-'){
                            returnValue = false;
                        }
                    }
                }
                
            }

            else {
                if (endRowIndex > 9){
                    returnValue = false;
                }

                else{
                    for (int i = 0; i < 9; i++){
                        if (boardArray[rowIndex+ i][columnIndex] != '-'){
                            returnValue = false;
                        }
                    }
                }
            }
            return returnValue;
        }

        void addBoat(Boat b, int idx[], bool h){
            bool returnValue = true;
            int rowIndex = idx[0];
            int columnIndex = idx[1];
            int endColumnIndex = columnIndex + b.getSize();
            int endRowIndex = rowIndex + b.getSize();

            if (h == true){
                if (endColumnIndex > 9){
                    returnValue = false;
                }

                else{
                    for (int i = 0; i < 9; i++){
                        if (boardArray[rowIndex][columnIndex + i] != '-'){
                            returnValue = false;
                        }
                    }
                }
                
            }

            else {
                if (endRowIndex > 9){
                    returnValue = false;
                }

                else{
                    for (int i = 0; i < 9; i++){
                        if (boardArray[rowIndex+ i][columnIndex] != '-'){
                            returnValue = false;
                        }
                    }
                }
            }
        }

        void populateBoard(){

        }

};

#endif