#include "opponentBoard.h"
#include "playerBoard.h"
#include "boat.h"
#include "player.h"
#include "human.h"
//#include "ai.h"
#include <stdio.h>

using namespace std;

int main (){
    Human human = Human();

    human.createPlayerBoard();

    playerBoard* testBoard = human.getPlayerBoard();

    cout << testBoard;

    return 0;
}