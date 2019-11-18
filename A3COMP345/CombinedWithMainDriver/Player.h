#ifndef Player_h
#define Player_h

#include <vector>
#include <string>
#include "Cards.h"
#include "Map.h"
#include "BidingFacility.h"
#include "Army.h"
#include "City.h"
#include "GameObservers.h"

class BidingFacility;
using namespace std;

class Player : public GameObservers {

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
	vector<City*> getCities();
	vector<Map*> getContinents();
	vector<Army*> getPlayerArmies();
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
	void setPlayerScore(int);
	void setPlayerNumOfArmiesBasedOnSoldiers(int);

	//Print info of player
	void printInfo();

	//Implemented player methods
	void addCountry(Node*);
	void addContinent(Map*);
	void Bid(int);
	void BuyCard(int);
	bool PayCoin(int);
	void PlaceNewArmies(Node*);
	void MoveArmies(Node*, Node*);
	void BuildCity(Node*);
	void DestroyArmy(Node*, int);
	
	int getArmyCount();
	int getCardCount();
	int getPlayerScore();
	int getArmyCountBasedOnSoldiers();

    void setAsGreedyComputer();
    void setAsModerateComputer();
    bool isGreedyComputer();
    bool isModerateComputer();
    
    void update(int code);
private:

    bool GreedyComputer;
    bool ModerateComputer;
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
	vector<Army*> playerArmy;
	vector<City*> playerCities;
	vector<Map*> playerContinents;
    	int* playerScore;
    	int* playerNumOfArmiesBasedOnSoldiers;
};

#endif // Player_h
