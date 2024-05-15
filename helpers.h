#ifndef HELPERS_H
#define HELPERS_H
#include "player.h"
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
void startTurn(P, O);

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

