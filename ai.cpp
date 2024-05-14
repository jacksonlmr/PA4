#include "ai.h"
#include "helpers.h"
#define NUM_BOATS 5

AI::AI(): Player(){
    usedIndex = 0;
}

AI::AI(int** i, playerBoard* p, opponentBoard* o): Player(p, o){
    usedIndex = i;
}

AI::AI(const AI& rhs){
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

/**
 * @brief uses random library to generate a random index on the board
 * @param None
 * @return void
*/
int* AI::generateIndex(){
    return 0;
}

void AI::generatePlayerBoard(){
    
}

/**
 * @brief uses generateBoatArray, then adds the boats to the board in random locations
 * @param None
 * @return Boat* array of boats
*/
void AI::populateBoard(){ 
    int* idx;
    Boat** boats = pBoard->getBoatsOnBoard();

    generateBoatArray(boats);

    for (int i = 0; i < NUM_BOATS; i++){
        do{
            idx = generateIndex();
        }while(pBoard->indexAvailable(boats[i], idx) == false);

        boats[i]->setStartIndex(idx);
        pBoard->addBoat(boats[i]);
    }
}
