#include "opponentBoard.h"
#include "playerBoard.h"
#include "boat.h"
#include "player.h"
#include "human.h"
#include "ai.h"
#include "helpers.h"
#include <stdio.h>

using namespace std;

int main (){
    bool endProgram = false;

    while(endProgram == false){
        displayMenu();
        int userChoice = getInput<int>();

        switch(userChoice){
            case 1: 
                endProgram = playGame();
            case 2:
                return 0;
        }
    }

    return 0;
}