//
//  Player.cpp
//  T3A1-Player
//
//  Created by Francois David on 2019-10-09.
//  Copyright © 2019 Francois David. All rights reserved.
//

#include "Player.hpp"

using namespace::std;

int Player::objCounter = 0;

Player::Player()
{
    this->playerNumber = ++objCounter;
    this->playerName = "Player "+ to_string(playerNumber);
    this->playerCoins = 0;
    this->playerHand = new HandObject();
}


Player::Player(string name, int coins, int age)
{
    this->playerName = name;
    this->playerCoins = coins;
    this->playerNumber = objCounter;
    this->playerAge = age;

    objCounter++;
}

int Player::getPlayerAge(){
    return playerAge;
}

Player::~Player()
{
    delete playerHand;
}

string Player::getName()
{
    return this->playerName;
}

int Player::getPlayerNumber()
{
    return this->playerNumber;
}

int Player::getPlayerCoins()
{
    return this->playerCoins;
}
/*
int Player::getPlayerAge()
{
    return this->playerAge;
}*/

void Player::setAge(int age){
    this->playerAge = age;
}

void Player::printInfo()
{
    cout << "Name: " + this->playerName << endl;
    cout << "Number: " << this->playerNumber << endl;
    cout << "Coins: " << this->playerCoins << endl;
    cout << endl;
    
}

void Player::PayCoin(int cost)
{
    this->playerCoins = this->playerCoins - cost;
}

void Player::PlaceNewArmies()
{

}

void Player::MoveArmies()
{

}

void Player::MoveOverLandOrWater()
{

}

void Player::BuildCity()
{

}

void Player::DestroyArmy()
{

}
