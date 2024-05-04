#ifndef BOAT_H
#define BOAT_H
#include <optional>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class Boat{
    string name;
    int size, hitCount;
    bool isHorizontal, isDestroyed, isHit;
    int** occupiedIndex;
    int index[];

    public:
    Boat();
    Boat(string, int, int, bool, bool, bool, int[], int**);
    Boat(const Boat&);

    string getName();
    void setName(string);
    int getSize();
    void setSize(int);
    bool getisHorizontal();
    void setisHorizontal(bool);
    bool getisDestroyed();
    void setisDestroyed(bool);
    bool getisHit();
    void getisHit(bool);
    int* getIndex();
    void setIndex(int[]);
    int** getOccupiedIndex();
    void setOccupiedIndex(int**);
    bool shipSank();
    friend ostream& operator<<(ostream&, const Boat&);
    //void destroyBlock();
                          

};
#endif