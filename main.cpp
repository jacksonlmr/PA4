#include "opponentBoard.h"
#include "playerBoard.h"
#include "boat.h"
#include <stdio.h>

using namespace std;

int main (){
    playerBoard test;
    cout << test;

    Boat testBoat;
    int testIndex[2] = {1, 1};
    test.addBoat(testBoat, testIndex);

    cout << test;
    return 0;
}