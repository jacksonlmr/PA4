#include "opponentBoard.h"

opponentBoard::opponentBoard(){
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

opponentBoard::opponentBoard(char board[][BOARD_SIZE]){
    for (int i = 0; i < BOARD_SIZE; i++){
        for (int j = 0; j < BOARD_SIZE; j++){
            boardArray[i][j] = board[i][j];
        }
    }
}

opponentBoard::opponentBoard(const opponentBoard& rhs){
    for (int i = 0; i < BOARD_SIZE; i++){
        for (int j = 0; j < BOARD_SIZE; j++){
            boardArray[i][j] = rhs.boardArray[i][j];
        }
    }
}

/**
 * @brief clears the board of any markers, sets back to default
 * @param None
 * @return void
*/
void opponentBoard::clearBoard(){
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

/**
 * @brief checks if there are any markers at the desired index on the board
 * @param idx length 2 array containing the index to check
 * @return bool- false if board contains something at the index, true if it is empty
*/
bool opponentBoard::indexAvailable(int idx[]){
    if (boardArray[idx[0]][idx[1]] != '-'){
        return false;
    }

    else {
        return true;
    }
}

/**
 * @brief changes a desired index to a new character. Used for adding hit markers
 * @param idx index to change
 * @param c char character to change index to
 * @return void
*/
void opponentBoard::changeIndex(int idx[2], char c){
    int rowIndex = idx[0];
    int columnIndex = idx[1];

    boardArray[rowIndex][columnIndex] = c;
}

opponentBoard& opponentBoard::operator=(const opponentBoard& rhs){
    for (int i = 0; i < BOARD_SIZE; i++){
        for (int j = 0; j < BOARD_SIZE; j++){
            boardArray[i][j] = rhs.boardArray[i][j];
        }
    }
    return *this;
}

ostream& operator<< (ostream& out, const opponentBoard& rhs){
            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    out << rhs.boardArray[i][j] << " ";
                }
                out << endl;
            }
            return out;
}