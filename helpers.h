#ifndef HELPERS_H
#define HELPERS_H
#include "player.h"
#include <stdio.h>

using namespace std;

void playGame();
int* convertInput();
bool checkInput();
int chooseStartingPlayer();
bool gameFinished();
template <typename T>
void startTurn(T);

#endif

