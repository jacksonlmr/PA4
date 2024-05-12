#ifndef HUMAN_H
#define HUMAN_H
#include "Player.h"

class Human : public Player{
    string name;

    public:
    Human(): Player(){
        name = "NA"
    }
    Human(string n, opponentBoard o, playerBoard p ): Player(o,p){
        name = n;
    }
    Human(const Human& rhs) : Player(rhs){
        name = rhs.name;

    }
    string getName(){
        return name;
    }
    void setName(string n){
        name = n;
    }
    void generateBoard(){

    }
    void takeTurn(){

    }
    Human& operator<<(ostream& o, const Human& i){

    }

};
#endif