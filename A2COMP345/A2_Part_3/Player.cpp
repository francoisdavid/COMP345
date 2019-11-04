
#include <iostream>
#include "Player.h"
#include <string>
#include <cmath>

using namespace std;

//Determines player number
int* Player::objCounter = new int(1);

//Constructors
Player::Player()
{
	playerNumber = new int(*objCounter);
	playerName = "Player "+ to_string(*playerNumber);
	playerCoins = new int();
	dayOfBirth = new int();
	monthOfBirth = new int();
	yearOfBirth = new int();
	playerAge = new double();

	playerHand = new HandObject();
	playerBiddingFacility = new BidingFacility();

	*objCounter = *objCounter + 1;
}

Player::Player(string name, int coins, int DOB, int MOB, int YOB)
{
	playerNumber = new int(*objCounter);
	playerName = name;
	playerCoins = new int (coins);
	dayOfBirth = new int (DOB);
	monthOfBirth = new int(MOB);
	yearOfBirth = new int(YOB);
	playerAge = new double();
	playerHand = new HandObject();
	playerBiddingFacility = new BidingFacility();

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

vector<Node*> Player::getCountries()
{
	return playerCountries;
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

void Player::setPlayerAge(double age)
{
	*playerAge = age;
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

//when a player takes control of a country it will be added to the list
void Player::addCountry(Node* country)
{
	Node* count = country;
	playerCountries.emplace_back(count);
}

//when a player makes a bid at the beginning of the game
void Player::Bid(int bid)
{
	while (bid > *playerCoins)
		cout << "You don't have enough coins. Please enter another bid." << endl;
		
	if (bid <= *playerCoins)
	{
		playerBiddingFacility->playerBid(this, bid);
		//this->PayCoin(bid);
	}
}

//when a player selects a card it will be added to their list of cards
void Player::BuyCard(int index)
{
    int price = ceil(double(index) / 2);
    if(this->PayCoin(price)) {
        Card *card = playerHand->exchange(index);
        playerCards.emplace_back(card);
    } else {
        Card *card = playerHand->exchange(0);
        playerCards.emplace_back(card);
    }

}
// Method that returns a boolean and if the user as enough money, if not the system will automatically make him buy the last one.
bool Player::PayCoin(int cost)
{
	if (cost <= *playerCoins) {
        *playerCoins = *playerCoins - cost;
        return true ;
    }
	else {
        cout << "You don't have enough coins.  You'll buy the free one." << endl;
        return false;
    }
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

void Player::setPlayerBiddingFacility(BidingFacility* bf){
    playerBiddingFacility =  bf;
}

BidingFacility* Player::getBuildingFacility() {
    return playerBiddingFacility;
}

void Player::playerBid(int coins) {
    playerBiddingFacility->playerBid(this, coins);
}

void Player::toString(){
    cout <<"Player-" << getName() << "\n\tCoins: " << *getPlayerCoins() << "\n\tDateOfBirth:" << *getDayOfBirth() << "/" << *getMonthOfBirth() << "/" << *getYearOfBirth()<< endl;
}

