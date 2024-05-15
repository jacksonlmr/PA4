#include "playerBoard.h"

playerBoard::playerBoard(): opponentBoard(){
    numBoats = 0;
    maxNumBoats = 3;
    boatsOnBoard = new Boat*[maxNumBoats];
}

playerBoard::playerBoard(int n, int m, Boat** b, char board[][11]): opponentBoard(board){
    numBoats = n; 
    maxNumBoats = m;
    
    boatsOnBoard = new Boat*[maxNumBoats];
    for (int i = 0; i < numBoats; i++){
        boatsOnBoard[i] = b[i];
    }

    for (int i = 1; i < 12; i++) {
        board[0][i] = 'A' + i - 1;
    }
    for (int i = 1; i < 12; i++) {
        board[i][0] = '0' + i;
    }
    for (int i = 1; i < 12; i++) {
        for (int j = 1; j < 12; j++) {
            board[i][j] = '-';
        }
    }
 }

playerBoard::playerBoard(const playerBoard& rhs): opponentBoard(rhs){
    numBoats = rhs.numBoats;
    maxNumBoats = rhs.maxNumBoats;
    
    boatsOnBoard = new Boat*[maxNumBoats];
    for (int i = 0; i < numBoats; i++){
        boatsOnBoard[i] = rhs.boatsOnBoard[i];
    }
        for (int i = 1; i < 12; i++) {
        board[0][i] = rhs.board[0][i];
    }
    for (int i = 1; i < 12; i++) {
        board[i][0] = rhs.board[i][0];
    }
    for (int i = 1; i < 12; i++) {
        for (int j = 1; j < 12; j++) {
            board[i][j] =rhs.board[i][j];
        }
    }
}

Boat** playerBoard::getBoatsOnBoard(){
    return boatsOnBoard;
}

int playerBoard::getNumBoats(){
    return numBoats;
}

/**
 * @brief Finds if an index is available based on the index of the boat, and whether the boat is horizontal or vertical
 * @param Boat b, boat to check index for 
 * @return bool, true if index is available false if it is not
*/
bool playerBoard::indexAvailable(Boat* b){
    int* idx = b->getIndex();
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

/**
 * @brief checks if the boat can be added at the index it has
 * @param b Boat object to check
 * @return bool- true if boat can be added to desired index, false otherwise
*/
bool playerBoard::addBoat(Boat* b){
    bool checkIndex = indexAvailable(b), returnValue = false;
    int* idx = b->getIndex();
    int startR = idx[0], startC = idx[1];

    b->setOccupiedIndex();

    //add boat, if the index is available
    if (checkIndex == true){
        addBoatToArray(b);
        //add boat horizontally
        if (b->getisHorizontal() == true){
            for (int i = 0; i < b->getSize(); i++){
                int indexToChange[2] = {startR+i, startC};
                changeIndex(indexToChange, BOAT_CHARACTER);
            }
        }
        //add boat vertically
        else {
            for (int i = 0; i < b->getSize(); i++){
                boardArray[startR][startC+i] = BOAT_CHARACTER;
            }
        }
        //indicates boat was succesfully added to the board
        returnValue = true;
    }
    return returnValue;
}

/**
 * @brief adds a boat to the boat array
 * @param b Boat pointer to boat to be added
 * @return void
*/
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
    
    boatsOnBoard = new Boat*[maxNumBoats];
    for (int i = 0; i < numBoats; i++){
        boatsOnBoard[i] = rhs.boatsOnBoard[i];
    }
    return *this;
}

void playerBoard::initializeBoard(//Boat* b, int numBoats,char board[11][11]
) {
    int board[11][11];
    // for (int i = 0; i < numBoats; i++) {
    //     boatsOnBoard[i] = &b[i];
    // }
    for (int i = 1; i < 12; i++) {
        board[0][i] = 'A' + i - 1;
    }
    for (int i = 1; i < 12; i++) {
        board[i][0] = '0' + i;
    }
    for (int i = 1; i < 12; i++) {
        for (int j = 1; j < 12; j++) {
            board[i][j] = '-';
        }
    }
}