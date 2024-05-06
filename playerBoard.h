#ifndef PLAYERBOARD_H
#define PLAYERBOARD_H
#include <stdio.h>
#include <iostream>
#include <string>
#include <opponentBoard.h>
#define BOARD_SIZE 11
#define BOAT_CHARACTER 'n'
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

        bool virtual indexAvailable(Boat b, int idx[]){
            bool returnValue = true, horizontal = b.getisHorizontal();
            int rowIndex = idx[0];
            int columnIndex = idx[1];
            int endColumnIndex = columnIndex + b.getSize();
            int endRowIndex = rowIndex + b.getSize();

            if (horizontal == true){
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

        //returns true if boat was added succesfully, false it index was invalid
        void addBoat(Boat b, int idx[], bool h){
            bool checkIndex = indexAvailable(b, idx), returnValue = false;
            int startR = idx[0], startC = idx[1];
            //add boat, if the index is available
            if (checkIndex == true){
                boatsOnBoard[numBoats] = b;
                numBoats++;
                //add boat horizontally
                if (b.getisHorizontal() = true){
                    for (int i = 0; i < b.getSize(); i++){
                        boardArray[startR+i][startC] = BOAT_CHARACTER;
                    }
                }
                //add boat vertically
                else {
                    for (int i = 0; i < b.getSize(); i++){
                        boardArray[startR][startC+i] = BOAT_CHARACTER;
                    }
                }
                //indicates boat was succesfully added to the board
                returnValue = true;
            }
            return returnValue;
        }

        void populateBoard(){

        }

};

#endif