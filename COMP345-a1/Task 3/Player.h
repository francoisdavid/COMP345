#ifndef Player_h
#define Player_h

#include <vector>
#include <string>
#include "Cards.hpp"
#include "Map.h"
//#include "BiddingFacility.hpp"

using namespace std;

class Player {

public:

	//Constructors/Destructor
	Player();
	Player(string, int, int, int, int);
	~Player();

	//Getters
	string getName();
	int* getPlayerNumber();
	int* getPlayerCoins();
	int* getDayOfBirth();
	int* getMonthOfBirth();
	int* getYearOfBirth();
	double* getPlayerAge();
	vector<Card*> getCards();

	//Setters
	void setName(string);
	void setDayOfBirth(int);
	void setMonthOfBirth(int);
	void setYearOfBirth(int);
	void setPlayerCoins(int);

	//Print info of player
	void printInfo();

	//Implemented player methods
	void addCountry(Map::Node*);
	//void Bid(int);
	void BuyCard(int);
	void PayCoin(int);
	void PlaceNewArmies();
	void MoveArmies();
	void MoveOverLandOrWater();
	void BuildCity();
	void DestroyArmy();

private:

	static int* objCounter;
	string playerName;
	int* playerNumber;
	int* dayOfBirth;
	int* monthOfBirth;
	int* yearOfBirth;
	double* playerAge;
	int* playerCoins;
	vector<Map::Node*> playerCountries;
	vector<Card*> playerCards;
	HandObject* playerHand;
	vector<Map::Node*> playerCountries;
	//BidingFacility* playerBidingFacility;
	//vector<Army*> playerArmy;
	//vector<City*> playerCities;

};

#endif // Player_h