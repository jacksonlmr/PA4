#include "ai.h"

AI::AI(): Player(){
    usedIndex = 0;
}

AI::AI(int** i, playerBoard* p, opponentBoard* o): Player(p, o){
    usedIndex = i;
}

AI::AI(const AI& rhs): AI(rhs){
    usedIndex = rhs.usedIndex;

}

int** AI::getusedIndex(){
    return usedIndex;
}

void AI::setusedIndex(int** u){
    usedIndex = u;
}

void AI::takeTurn(){

}

int* AI::generateIndex(){

}

void AI::generateBoards(){
    
}

/**
 * @brief generates array of boats with indices and directions, using playerBoards method indexAvailable
 * @param None
 * @return Boat* array of boats
*/
Boat* AI::generateBoatArray(){

}