#ifndef Player_h
#define Player_h

#include <vector>
#include <string>
#include "Cards.hpp"

using namespace std;

class Player {

public:
	//Constructors/Destructor
	Player();
	Player(string, int, int);
	~Player();

	//Getters
	string getName();
	int getPlayerNumber();
	int getPlayerCoins();
	int getPlayerAge();

	//Print info of player
	void printInfo();

	//Implemented player methods
	void PayCoin(int);
	void PlaceNewArmies();
	void MoveArmies();
	void MoveOverLandOrWater();
	void BuildCity();
	void DestroyArmy();

private:
	static int objCounter;
	string playerName;
	int playerNumber;
	int playerAge;
	int playerCoins;
	vector<Card*> playerCards;
	HandObject playerHand;
	
	/*
	vector<Region*> playerRegions
	bidingFacility playerBidingFacility;

	Army?
	Cities?
	*/

};

#endif // Player_h