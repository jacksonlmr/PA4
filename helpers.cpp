#include "helpers.h"

/**
 * @brief Combines all needed functions in order to run the game
 * @param None
 * @return void
*/
void playGame(){

}

/**
 * @brief Gets the users input for a location to attack in format <A1> and converts to usable indices in format <[0, 0]>
 * @param None
 * @return int array of length two representing an index on the board
*/
int* convertInput(){

}

/**
 * @brief Checks if input from user is a valid index
 * @param int array of length two representing an index
 * @return bool, true if input is valid, false if it is not
*/
bool checkInput(){

}

/**
 * @brief Randomly determines whether the human or ai player goes first
 * @param None
 * @return int, 1 means human goes first, 0 means ai goes first
*/
int chooseStartingPlayer(){

}
/**
 * @brief Returns true if all of either player's ships have been destroyed, false otherwise
 * @param None
 * @return bool, true if both players have at least one ship left, false if at least one player had 0 ships left
*/
bool gameFinished(){

}

/**
 * @brief Runs the turn of either AI or human player
 * @param T parameter can be of type Human or AI, depending on what is needed
 * @return void
*/
template <typename T>
void startTurn(T){

}