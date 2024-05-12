#include "opponentBoard.h"
#include "playerBoard.h"
#include "boat.h"
#include <stdio.h>

using namespace std;

int main (){
    playerBoard test;

    Boat testBoat;

    int idx[2] = {1, 1};

    bool testBool = test.addBoat(testBoat, idx);

    cout << test;

    return 0;
}