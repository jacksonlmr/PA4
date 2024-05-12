#ifndef HUMAN_H
#define HUMAN_H
#include "player.h"
#include "opponentBoard.h"
#include "playerBoard.h"

class Human : public Player{
    string name;

    public:
    Human();
    Human(string, playerBoard*, opponentBoard*);
    Human(const Human& rhs);

    string getName();

    void setName(string);

    void createPlayerBoard();
    void takeTurn();

    friend Human& operator<<(ostream&, const Human&);
};
#endif