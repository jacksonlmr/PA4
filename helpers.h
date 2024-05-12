#ifndef HELPERS_H
#define HELPERS_H
#include "player.h"
#include "boat.h"
#include <stdio.h>

using namespace std;

void playGame();
string getInput();
int* convertInput(string);
bool checkInput(int*);
void generateBoatArray(Boat*);
int chooseStartingPlayer();
bool gameFinished();
template <typename T>
void startTurn(T);

#endif

