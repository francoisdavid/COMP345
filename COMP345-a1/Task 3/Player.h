
#ifndef Player_h
#define Player_h

#include <vector>
#include <string>
#include "Cards.hpp"
#include "Map.h"
#include "BidingFacility.hpp"
class BidingFacility;

class Player {

public:

    //Constructors/Destructor
    Player();
    Player(string, int, int, int, int);
    ~Player();

<<<<<<< HEAD
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
=======
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
>>>>>>> 79a969af53687e698b7011da35a12c5acd0112d5

    //Setters
    void setName(string);
    void setDayOfBirth(int);
    void setMonthOfBirth(int);
    void setYearOfBirth(int);
    void setPlayerCoins(int);

    //Print info of player
    void printInfo();

<<<<<<< HEAD
    //Implemented player methods
    void addCountry(Node*);
    void Bid(int);
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
    vector<Node*> playerCountries;
    vector<Card*> playerCards;
    HandObject* playerHand;
    BidingFacility* playerBiddingFacility;
    //vector<Army*> playerArmy;
    //vector<City*> playerCities;
=======
	//Implemented player methods
	void addCountry(Node*);
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
	vector<Node*> playerCountries;
	vector<Card*> playerCards;
	HandObject* playerHand;
	//BiddingFacility* playerBiddingFacility;
	//vector<Army*> playerArmy;
	//vector<City*> playerCities;
>>>>>>> 79a969af53687e698b7011da35a12c5acd0112d5

};

#endif // Player_h
