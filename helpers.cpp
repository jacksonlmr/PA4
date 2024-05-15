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
    Human humanPlayer;
    AI aiPlayer;
    bool end = false;
    int startingPlayer;
    char* winner;

    aiPlayer.populateBoard();
    humanPlayer.createPlayerBoard();

    while (end == false){
        startingPlayer = chooseStartingPlayer();
        switch (startingPlayer){
            case 1:
                while(gameFinished(&humanPlayer, &aiPlayer) == true){
                    startTurn<Human, AI>(humanPlayer, aiPlayer);
                }
                end = true;
            case 2:
                while(gameFinished(&humanPlayer, &aiPlayer) == true){
                    startTurn<AI, Human>(aiPlayer, humanPlayer);
                }
                end = true;
        }
    }
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
    srand((unsigned) time(NULL));
    int starter = 0 + (rand() % 1);
    return starter;
}
/**
 * @brief Returns true if all of either player's ships have been destroyed, false otherwise
 * @param None
 * @return bool, true if both players have at least one ship left, false if at least one player had 0 ships left
*/
bool gameFinished(Human* H, AI* A){
    if(H->getPlayerBoard()->getNumBoats() <= 0 ){
        return false;
        cout << "AI is the winner!" << endl;

    }
    if( A->getPlayerBoard()->getNumBoats() <= 0){
        string name = H->getName();
        cout << name<< " is the winner!" << endl;
        return false;
    }
    else{
        return true;
    }
}

/**
 * @brief Runs the turn of either AI or human player
 * @param P this will be the type of the player that is taking their turn currently
 * @param O this will be the type of the players opponent
 * @return void
*/
// template <typename P, typename O>
// void startTurn(P p1,  O p2){
//     int* indexToMark = p1.takeTurn();
//     bool temp = p2.getOpponentBoard()->indexAvailable(indexToMark);
//     if(temp == false){
//         p2.getPlayerBoard()->changeIndex(indexToMark, 'X');
//     }
//     else{
//         p2.getPlayerBoard()->changeIndex(indexToMark, 'O');
//     }
//     indexToMark = p2.takeTurn();
//     temp = p1.getOpponentBoard()->indexAvailable(indexToMark);
//     if(temp == false){
//         p1.getPlayerBoard()->changeIndex(indexToMark, 'X');
//     }
//     else{
//         p1.getPlayerBoard()->changeIndex(indexToMark, 'O');
//     }
// }
