
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
	playerScore = new int();
    	playerNumOfArmiesBasedOnSoldiers = new int();

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
	playerScore = new int();
    	playerNumOfArmiesBasedOnSoldiers = new int();
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
	
	if (this->PayCoin(price))
	{
		Card* card = playerHand->exchange(index);
		playerCards.emplace_back(card);
	}
	else
	{
		Card* card = playerHand->exchange(0);
		playerCards.emplace_back(card);
	}
}

bool Player::PayCoin(int cost)
{
	if (cost <= *playerCoins)
	{
		*playerCoins = *playerCoins - cost;
		return true;
	}
	else
	{
		cout << "You don't have enough coins. You'll buy the free one." << endl;
		return false;
	}
}
void Player::PlaceNewArmies(Node* location)
{
	bool exists = false;
	int index;
	for (int i = 0; i < location->getArmies().size(); i++)
	{
		if (*(location->getArmies()[i]->getOwnerNumber()) == *(this->playerNumber))
		{
			exists = true;
			index = i;
		}
	}

	if (exists)
		location->getArmies()[index]->setNumberOfSoldiers(*(location->getArmies()[index]->getNumberOfSoldiers()) + 1);
	else
	{
		Army* army = new Army(location, *(this->playerNumber), 1);
		playerArmy.emplace_back(army);
	}
}

void Player::MoveArmies(Node* startLocation, Node* endLocation)
{
	for (int i = 0; i < startLocation->getArmies().size(); i++)
	{
		if (*(startLocation->getArmies()[i]->getOwnerNumber()) == *(this->playerNumber))
		{
			startLocation->getArmies()[i]->setNumberOfSoldiers(*(startLocation->getArmies()[i]->getNumberOfSoldiers()) - 1);

			PlaceNewArmies(endLocation);

			break;
		}
	}
}

void Player::MoveOverLandOrWater(Node* startLocation, Node* endLocation)
{
	MoveArmies(startLocation, endLocation);
}

void Player::BuildCity(Node* location)
{
	City* city = new City(location,*(this->playerNumber));
	playerCities.emplace_back(city);
}

void Player::DestroyArmy(Node* location, int ownerNumber)
{
	for (int i = 0; i < location->getArmies().size(); i++)
		if (*(location->getArmies()[i]->getOwnerNumber()) == ownerNumber)
		{
			location->getArmies()[i]->setNumberOfSoldiers(*(location->getArmies()[i]->getNumberOfSoldiers()) - 1);
			break;
		}

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

int Player::getArmyCount() {
   return playerArmy.size();
}

// Returns number of card player has
int Player::getCardCount() {
   vector<Card*> cards = getCards();
   return cards.size();
}

void Player::toString(){
    cout <<"Player-" << getName() << "\n\tCoins: " << *getPlayerCoins() << "\n\tDateOfBirth:" << *getDayOfBirth() << "/" << *getMonthOfBirth() << "/" << *getYearOfBirth()<< endl;
}

vector<City*> Player::getCities() {
    return playerCities;
}

int Player::getPlayerScore() {
    return *playerScore;
}

void Player::setPlayerScore(int score) {
    *playerScore = score;
}

int Player::getArmyCountBasedOnSoldiers() {
    return *playerNumOfArmiesBasedOnSoldiers;
}

// Sets the number of armies based on # of soldiers
void Player::setPlayerNumOfArmiesBasedOnSoldiers(int number) {
    *playerNumOfArmiesBasedOnSoldiers += number;
}

// Returns list of continents
vector<Map*> Player::getContinents() {
    return playerContinents;
}

//when a player takes control of a continent it will be added to the list
void Player::addContinent(Map *map)
{
    Map *newMap = map;
    playerContinents.emplace_back(newMap);
}
