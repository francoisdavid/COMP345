
#include <iostream>
#include "Player.h"
#include <string>

using namespace std;

//Determines player number
int* Player::objCounter = new int(1);

//Constructors initialize playerHand and biddingFacility objects
Player::Player()
{
	playerNumber = new int(*objCounter);
	playerName = "Player "+ to_string(*playerNumber);
	playerHand = new HandObject();
	playerBiddingFacility = new BiddingFacility();

	*objCounter = *objCounter + 1;
}

Player::Player(string name, int coins, int DOB, int MOB, int YOB)
{
	playerName = name;
	playerCoins = new int (coins);
	playerNumber = new int(*objCounter);
	dayOfBirth = new int (DOB);
	monthOfBirth = new int(MOB);
	yearOfBirth = new int(YOB);
	playerHand = new HandObject();
	playerBiddingFacility = new BiddingFacility();

	*objCounter = *objCounter + 1;
}

//Destructor
Player::~Player()
{

}

//Getters
string Player::getName()
{
	return playerName;
}

int* Player::getPlayerNumber()
{
	return playerNumber;
}

int* Player::getPlayerCoins()
{
	return playerCoins;
}

int* Player::getDayOfBirth()
{
	return dayOfBirth;
}

int* Player::getMonthOfBirth()
{
	return monthOfBirth;
}

int* Player::getYearOfBirth()
{
	return yearOfBirth;
}

//returns a double made by combining the day, month and year into one "age" value.
double* Player::getPlayerAge()
{
	double DOB = *dayOfBirth;
	double MOB = *monthOfBirth;
	double YOB = *yearOfBirth;
	double birthday = (DOB + MOB * 30.44 + YOB * 365.25);
	*playerAge = birthday;
	return (playerAge);
}

vector<Card*> Player::getCards()
{
	return playerCards;
}

//Setters
void Player::setName(string name)
{
	playerName = name;
}

void Player::setDayOfBirth(int DOB)
{
	*dayOfBirth = DOB;
}

void Player::setMonthOfBirth(int MOB)
{
	*monthOfBirth = MOB;
}

void Player::setYearOfBirth(int YOB)
{
	*yearOfBirth = YOB;
}

void Player::setPlayerCoins(int coins)
{
	*playerCoins = coins;
}

void Player::printInfo()
{
	cout << "Name: " + playerName << endl;
	cout << "Number: " << *playerNumber << endl;
	cout << "Date of Birth: " << *dayOfBirth << "/" << *monthOfBirth << "/" << *yearOfBirth << endl;
	cout << "Coins: " << *playerCoins << endl;
	cout << endl;
	
}

void Player::addCountry(Map::Node* country)
{
	Map::Node* count = country;
	playerCountries.emplace_back(count);
}

void Player::Bid(int bid)
{
	while (bid > *playerCoins)
		cout << "You don't have enough coins. Please enter another bid." << endl;
		
	if (bid <= *playerCoins)
	{
		playerBiddingFacility->playerBid(this, bid);
		this->PayCoin(bid);
	}
}

void Player::BuyCard(int index)
{
	Card* card = playerHand->exchange(index);
	playerCards.emplace_back(card);
	int price = ceil(double(index) / 2);
	this->PayCoin(price);
}

void Player::PayCoin(int cost)
{
	if (cost <= *playerCoins)
		*playerCoins = *playerCoins - cost;
	else
		cout << "You don't have enough coins." << endl;
}
void Player::PlaceNewArmies()
{
	cout << "Armies can be placed in the starting location or in a city." << endl;
}

void Player::MoveArmies()
{
	cout << "Armies can only move over land." << endl;
}

void Player::MoveOverLandOrWater()
{
	cout << "Armies can move over land or water." << endl;
}

void Player::BuildCity()
{
	cout << "Cities can only be built in countries where an army exists." << endl;
}

void Player::DestroyArmy()
{
	cout << "An army is destroyed." << endl;
}

