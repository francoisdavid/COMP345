#ifndef Player_h
#define Player_h

#include <vector>
#include <string>
#include "Cards.h"
#include "Map.h"
#include "BidingFacility.h"

class BidingFacility;

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
	vector<Node*> getCountries();
	BidingFacility* getBuildingFacility();
	void playerBid(int coins);
	void toString();

	//Setters
	void setName(string);
	void setDayOfBirth(int);
	void setMonthOfBirth(int);
	void setYearOfBirth(int);
	void setPlayerAge(double);
	void setPlayerCoins(int);
	void setPlayerBiddingFacility(BidingFacility* bf);

	//Print info of player
	void printInfo();

	//Implemented player methods
	void addCountry(Node*);
	void Bid(int);
	void BuyCard(int);
	bool PayCoin(int);
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
	vector<Node*> playerCountries;
	vector<Card*> playerCards;
	HandObject* playerHand;
	BidingFacility* playerBiddingFacility;
	//vector<Army*> playerArmy;
	//vector<City*> playerCities;

};

#endif // Player_h
