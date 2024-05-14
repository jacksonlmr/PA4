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
//Select random index
    srand((unsigned) time(NULL));
    int randomRow = 0 + (rand() % 11);
    int randomCol = 0 + (rand() % 11);
  //  cout << "AI shoots at " <<randomRow << randomCol << endl;

}

/**
 * @brief uses random library to generate a random index on the board
 * @param None
 * @return void
*/
int* AI::generateIndex(){
    srand((unsigned) time(NULL));
    int randomRow = 0 + (rand() % 11);
    int randomCol = 0 + (rand() % 11);
    int boolean = 0 + (rand() % 1);
    int array[2];
    array[0] = randomRow;
    array[1] = randomCol;
    int* PArray = array;
    return PArray;
}

void AI::generatePlayerBoard(playerBoard* p){
    srand((unsigned) time(NULL));
    int randomRow = 0 + (rand() % 11);
    int randomCol = 0 + (rand() % 11);
    int boolean = 0 + (rand() % 1);
    bool isHorizontal = boolean;
    if(isHorizontal == 0){
        int* start = randomCol;
        for(int i = randomRow; i < boats->getSize() + randomRow; i++){
            *p[i][randomCol] = boats;
        }
    }
    if(isHorizontal == 1){
        int* start = randomRow;
        for(int i = randomCol; i < boats->getSize() + randomCol; i++){
            *p[randomRow][i] = boats;
        }
    }
    return start;
    
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

