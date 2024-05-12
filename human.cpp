#include "human.h"
#include "helpers.h"
#define NUM_BOATS 5
Human::Human(): Player(){
    name = "NA";
}

Human::Human(string n, playerBoard* p, opponentBoard* o): Player(p, o){
    name = n;
}

Human::Human(const Human& rhs) : Player(rhs){
    name = rhs.name;
}

string Human::getName(){
    return name;
}

void Human::setName(string n){
    name = n;
}

/**
 * @brief uses getInput, convertInput, checkInput, and generateBoatArray from helpers to create a playerBoard. 
 * Iterates through the boats, prompting the player to choose a location for each one. Once the user enters a valid
 * starting index and location, the boat is added to the board at that location.
 * @param None
 * @return void
*/
void Human::createPlayerBoard(){
    Boat** boats = new Boat*[NUM_BOATS];
    int* processedIndex;
    string rawIndex, orientation;
    bool validInput;

    generateBoatArray(boats);

    for (int i = 0; i < NUM_BOATS; i++){
        cout << "Boat to place: " << endl << boats[i];
        //get input until user enters a valid, unused input
        do {
            cout << "Enter Starting Index (Example: A1): ";
            rawIndex = getInput();

            cout << "Enter Orientation (h for horizontal or v for vertical): ";
            orientation = getInput();
            
            if (orientation == "h"){
                boats[i]->setisHorizontal(true);
            }

            else{
                boats[i]->setisHorizontal(false);
            }

            convertInput(rawIndex, processedIndex);
            validInput = pBoard->indexAvailable(boats[i], processedIndex);

            if(validInput == false){
                cout << "Please enter a valid index and orientation that has not already been used";
            }

            else{
                boats[i]->setStartIndex(processedIndex);
                pBoard->addBoatToArray(boats[i]);
            }

        }while(validInput == false);
    }
}
/**
 * @brief Gets input from player of an index to attack on opponents board, and marks the location on
 * the human players opponentBoard
 * @param None
 * @return int* array of length 2 containing the index to mark on the opponents playerBoard
*/
int* Human::takeTurn(AI opponent){
    
}