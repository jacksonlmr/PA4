#include "boat.h"

Boat::Boat(){
name = "NA";
size = 0;
hitCount = 0;
isHorizontal = false;
isDestroyed = false;
isHit = false;
occupiedIndex = 0;
}
Boat::Boat(string n , int s, int hc, bool isHor, bool isD, bool isH, int j[], int** oi){
name = n;
size = s;
isHorizontal = isHor;
isDestroyed = isD;
isHit = isH;
for (int i = 0; i < 2; i++){
    index[i] = j[i];
}
occupiedIndex = oi;
}
Boat::Boat(const Boat& rhs){
name = rhs.name;
size = rhs.size;
isHorizontal = rhs.isHorizontal;
isDestroyed = rhs.isDestroyed;
isHit = rhs.isHit;
for(int i = 0; i < 2; i++){
    index[i] = rhs.index[i];
}
occupiedIndex = rhs.occupiedIndex;
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
void Boat::getisHit(bool h){
    isHit = h;
}
int* Boat::getIndex(){
    return index;
}
void Boat::setIndex(int j[]){
    for(int i = 0; i < 2; i++){
        index[i] = j[i];
    }
}
int** Boat::getOccupiedIndex(){
    return occupiedIndex;
}
void Boat::setOccupiedIndex(int** i){
    occupiedIndex = i;
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
//ostream& Boat::operator<<(ostream& os, const Boat& b){
//
//}
// void Boat::destroyBlock(){

// }