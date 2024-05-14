#include "player.h"

Player::Player(){
    pBoard = new playerBoard;
    oBoard = new opponentBoard;
}

Player::Player(playerBoard* p, opponentBoard* o){
    pBoard = p;
    oBoard = o;
}

Player::Player(const Player& rhs){
    pBoard = rhs.pBoard;
    oBoard = rhs.oBoard;
}

Player::~Player(){
    delete pBoard;
    delete oBoard;
}

/**
*@brief Updates desired coordinate of pBoard or oBoard to a new character
*@param idx index to change
*@param c character to change the coordinate to
*@param b which board to change. 'p' corresponds to pBoard, 'o' corresponds to oBoard
*@return void
*/
void Player::updateBoard(int idx[2], char c, char b){
    if(b == 'p'){
        pBoard->changeIndex(idx, c);
    }

    else if (b == 'o'){
        oBoard->changeIndex(idx, c);
    }

    else{
        cout << "Invalid board selection";
    }
}

playerBoard* Player::getPlayerBoard(){
    return pBoard;
}

opponentBoard* Player::getOpponentBoard(){
    return oBoard;
}

/**
 * @brief sets the pBoard object to a new board
 * @param p playerBoard object to change to
 * @return void
*/
void Player::setPlayerBoard(playerBoard* p){
    delete pBoard;
    pBoard = p;
}

/**
 * @brief sets the oBoard object to a new board
 * @param o opponentBoard object to change to
 * @return void
*/
void Player::setOpponentBoard(opponentBoard* o){
    delete oBoard;
    oBoard = o;
}

