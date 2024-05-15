#ifndef HELPERS_H
#define HELPERS_H
#include "player.h"
#include "ai.h"
#include "human.h"
#include "boat.h"
#include "human.h"
#include "ai.h"
#include <stdio.h>

using namespace std;

bool playGame();
void displayMenu();
int* convertInput(string, int*);
void generateBoatArray(Boat**);
int chooseStartingPlayer();
bool gameFinished(Human*, AI*);

template <typename P, typename O>
void startTurn(P p1,  O p2){
    int* indexToMark = p1.takeTurn();
    bool temp = p2.getOpponentBoard()->indexAvailable(indexToMark);
    if(temp == false){
        p2.getPlayerBoard()->changeIndex(indexToMark, 'X');
    }
    else{
        p2.getPlayerBoard()->changeIndex(indexToMark, 'O');
    }
    indexToMark = p2.takeTurn();
    temp = p1.getOpponentBoard()->indexAvailable(indexToMark);
    if(temp == false){
        p1.getPlayerBoard()->changeIndex(indexToMark, 'X');
    }
    else{
        p1.getPlayerBoard()->changeIndex(indexToMark, 'O');
    }
}

/**
 * @brief gets user input
 * @param None
 * @return string containing the users input
*/
template <typename T>
T getInput(){
    T output;
    cin >> output;
    return output;
}
#endif

