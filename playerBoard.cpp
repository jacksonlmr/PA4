#include "playerBoard.h"

playerBoard::playerBoard(): opponentBoard(){
    numBoats = 0;
    maxNumBoats = 3;
    boatsOnBoard = new Boat[maxNumBoats];
}

playerBoard::playerBoard(int n, int m, Boat* b, char board[][11]): opponentBoard(board){
    numBoats = n; 
    maxNumBoats = m;
    
    boatsOnBoard = new Boat[maxNumBoats];
    for (int i = 0; i < numBoats; i++){
        boatsOnBoard[i] = b[i];
    }
}

playerBoard::playerBoard(const playerBoard& rhs): opponentBoard(rhs){
    numBoats = rhs.numBoats;
    maxNumBoats = rhs.maxNumBoats;
    
    boatsOnBoard = new Boat[maxNumBoats];
    for (int i = 0; i < numBoats; i++){
        boatsOnBoard[i] = rhs.boatsOnBoard[i];
    }
}

Boat* playerBoard::getBoatsOnBoard(){
    return boatsOnBoard;
}

int playerBoard::getNumBoats(){
    return numBoats;
}

/**
 * @brief Finds if an index is available based on the index given, and whether the boat is horizontal or vertical
 * @param Boat b, boat to check index for 
 * @param int[] idx, index to check at
 * @return bool, true if index is available false if it is not
*/
bool playerBoard::indexAvailable(Boat* b, int idx[]){
    bool returnValue = true, horizontal = b->getisHorizontal();
    int rowIndex = idx[0];
    int columnIndex = idx[1];
    int endColumnIndex = columnIndex + b->getSize();
    int endRowIndex = rowIndex + b->getSize();

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
bool playerBoard::addBoat(Boat b, int idx[2]){
    bool checkIndex = indexAvailable(b, idx), returnValue = false;
    int startR = idx[0], startC = idx[1];
    b.setStartIndex(idx);
    b.setOccupiedIndex();
    //add boat, if the index is available
    if (checkIndex == true){
        addBoatToArray(b);
        //add boat horizontally
        if (b.getisHorizontal() == true){
            for (int i = 0; i < b.getSize(); i++){
                int indexToChange[2] = {startR+i, startC};
                changeIndex(indexToChange, BOAT_CHARACTER);
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

void playerBoard::addBoatToArray(Boat* b){
    if (maxNumBoats == numBoats){
        maxNumBoats += 3;
        Boat** temp = new Boat*[maxNumBoats];
        for (int i = 0; i < numBoats; i++){
            boatsOnBoard[i] = temp[i];
        }
        delete [] boatsOnBoard;
        boatsOnBoard = temp;
        boatsOnBoard[numBoats] = b;
        numBoats++;
    }

    else {
        boatsOnBoard[numBoats] = b;
        numBoats++;
    }
}

playerBoard& playerBoard::operator =(const playerBoard& rhs){
    for (int i = 0; i < BOARD_SIZE; i++){
        for (int j = 0; j < BOARD_SIZE; j++){
            boardArray[i][j] = rhs.boardArray[i][j];
        }
    }

    numBoats = rhs.numBoats;
    maxNumBoats = rhs.maxNumBoats;
    
    boatsOnBoard = new Boat[maxNumBoats];
    for (int i = 0; i < numBoats; i++){
        boatsOnBoard[i] = rhs.boatsOnBoard[i];
    }
    return *this;
}