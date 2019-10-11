
#include <iostream>
#include "Player.h"
#include "Cards.hpp"
#include <string>
using namespace std;

//Determines player number
int Player::objCounter = 1;

Player::Player()
{
	this->playerNumber = objCounter;
	this->playerName = "Player "+ to_string(playerNumber);
	this->playerCoins = 0;

	objCounter++;
}

Player::Player(string name, int coins, int age)
{
	this->playerName = name;
	this->playerCoins = coins;
	this->playerNumber = objCounter;
	this->playerAge = age;

	objCounter++;
}

Player::~Player()
{
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

int Player::getPlayerAge()
{
	return this->playerAge;
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
