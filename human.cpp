#include "human.h"
#include "helpers.h"

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
 * @brief 
*/
void Human::generateBoards(){

}

void Human::takeTurn(){

}