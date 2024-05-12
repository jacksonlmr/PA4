#include "boat.h"

//default initializes a boat of size 3, that is vertical
Boat::Boat(){
    name = "NA";
    size = 3;
    hitCount = 0;
    isHorizontal = false;
    isDestroyed = false;
    isHit = false;
    occupiedIndex = new int*[size];
    for (int i = 0; i < size; i++){
        occupiedIndex[i] = new int[2];
    }
}
//
Boat::Boat(string n , int s, int hc, bool isHor, bool isD, bool isH){
    name = n;
    size = s;
    isHorizontal = isHor;
    isDestroyed = isD;
    isHit = isH;
    hitCount = hc;
}

Boat::Boat(const Boat& rhs){
    name = rhs.name;
    size = rhs.size;
    isHorizontal = rhs.isHorizontal;
    isDestroyed = rhs.isDestroyed;
    isHit = rhs.isHit;
    startIndex[0] = rhs.startIndex[0];
    startIndex[1] = rhs.startIndex[1];

    occupiedIndex = new int*[size];
    for (int i = 0; i < size; i++){
        occupiedIndex[i] = new int[2];
    }
    for(int i = 0; i < size; i++){
        occupiedIndex[i][0] = rhs.occupiedIndex[i][0];
        occupiedIndex[i][1] = rhs.occupiedIndex[i][1];
    }
}

Boat::~Boat(){
    if (occupiedIndex != nullptr){
        for (int i = 0; i < size; i++){
            delete [] occupiedIndex[i];
            
        }
        delete [] occupiedIndex;
    }
}

string Boat::getName(){
    return name;
}
void Boat::setName(string n){
    name = n;
}
int Boat::getSize(){
    return size;
}
void Boat::setSize(int s){
    size = s;
}
bool Boat::getisHorizontal(){
    return isHorizontal;
}
void Boat::setisHorizontal(bool h){
    isHorizontal = h;
}
bool Boat::getisDestroyed(){
    return isDestroyed;
}
void Boat::setisDestroyed(bool d){
    isDestroyed = d;
}
bool Boat::getisHit(){
    return isHit;
}
void Boat::setisHit(bool h){
    isHit = h;
}
int* Boat::getIndex(){
    return startIndex;
}
void Boat::setStartIndex(int j[]){
    for(int i = 0; i < 2; i++){
        startIndex[i] = j[i];
    }
}
int** Boat::getOccupiedIndex(){
    return occupiedIndex;
}
void Boat::setOccupiedIndex(){
    if (isHorizontal == true){
        //if boat is horizontal, add i to the column value of the index and add to occupiedIndex until size is reached
        for (int i = 0; i < size; i++){
            int* nextIndex = new int[2];
            nextIndex[0] = startIndex[0];
            nextIndex[1] = startIndex[1] + i;
            occupiedIndex[i] = nextIndex;
        }
    }

    else{
        for (int i = 0; i < size; i++){
            int* nextIndex = new int[2];
            nextIndex[0] = startIndex[0] + i;
            nextIndex[1] = startIndex[1];
            occupiedIndex[i] = nextIndex;
        }
    }
}
bool Boat::shipSank(){
    if(size == hitCount){
        isDestroyed = true;
    }
    else{
        isDestroyed = false;
    }
    return isDestroyed;
}

Boat& Boat::operator=(const Boat& rhs){
    name = rhs.name;
    size = rhs.size;
    isHorizontal = rhs.isHorizontal;
    isDestroyed = rhs.isDestroyed;
    isHit = rhs.isHit;
    startIndex[0] = rhs.startIndex[0];
    startIndex[1] = rhs.startIndex[1];

    occupiedIndex = new int*[size];
    for (int i = 0; i < size; i++){
        occupiedIndex[i] = new int[2];
    }
    for(int i = 0; i < size; i++){
        occupiedIndex[i][0] = rhs.occupiedIndex[i][0];
        occupiedIndex[i][1] = rhs.occupiedIndex[i][1];
    }
    return *this;
}
//ostream& Boat::operator<<(ostream& os, const Boat& b){
//
//}
// void Boat::destroyBlock(){

// }