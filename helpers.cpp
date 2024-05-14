#include "opponentBoard.h"
#include "playerBoard.h"
#include "boat.h"
#include "player.h"
#include "human.h"
#include "ai.h"
#include "helpers.h"

/**
 * @brief Combines all needed functions in order to run the game. 
 * @param None
 * @return bool- return true if game is over
*/
bool playGame(){
    Human humanPlayer = Human();
}

/**
 * @brief displays main menu for game
 * @param None
 * @return void
*/
void displayMenu(){
    cout << "=== MAIN MENU ===" << endl;
    cout << "1. Start Game" << endl;
    cout << "2. Exit Program" << endl;
}

/**
 * @brief Gets the users input for a location to attack in format <A1> and converts to usable indices in format <[0, 0]>
 * @param string input, string in format <A1>
 * @param int* array of length two for the final index
 * @return int array of length two representing an index on the board
*/
int* convertInput(string input, int* idx){
    int idx1, idx2;

    idx1 = input[0] - 'A' + 1;
    idx2 = input[1];

    idx[0] = idx1;
    idx[1] = idx2;

    return idx;
}

/**
 * @brief adds the neccesary boats to the array
 * @param Boat* pointer to array of boats
 * @return void
*/
void generateBoatArray(Boat** boats){
    Boat* b1 = new Boat("Carrier", 5);
    Boat* b2 = new Boat("Battleship", 4);
    Boat* b3 = new Boat("Destroyer", 3);
    Boat* b4 = new Boat("Submarine", 3);
    Boat* b5 = new Boat("Patrol Boat", 2);

    boats[0] = b1;
    boats[1] = b2;
    boats[2] = b3;
    boats[3] = b4;
    boats[4] = b5;
}

/**
 * @brief Randomly determines whether the human or ai player goes first
 * @param None
 * @return int, 1 means human goes first, 0 means ai goes first
*/
int chooseStartingPlayer(){
    return 0;
}
/**
 * @brief Returns true if all of either player's ships have been destroyed, false otherwise
 * @param None
 * @return bool, true if both players have at least one ship left, false if at least one player had 0 ships left
*/
bool gameFinished(){
    return false;
}

/**
 * @brief Runs the turn of either AI or human player
 * @param P this will be the type of the player that is taking their turn currently
 * @param O this will be the type of the players opponent
 * @return void
*/
template <typename P, typename O>
void startTurn(P, O){
    int* indexToMark = P->takeTurn();
    
}