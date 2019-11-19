
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
    lastPlayerScore = new int();
    playerNumOfArmiesBasedOnSoldiers = new int();

    playerHand = new HandObject();
    playerBiddingFacility = new BidingFacility();

    GreedyComputer = false;
    ModerateComputer = false;
    *objCounter = *objCounter + 1;
    strategy = new HumanStrategy();
    HumanPlayer = true;
}

Player::Player(string name, int coins, int DOB, int MOB, int YOB, Strategy* str)
{
    playerNumber = new int(*objCounter);
    playerName = name;
    playerCoins = new int (coins);
    dayOfBirth = new int (DOB);
    monthOfBirth = new int(MOB);
    yearOfBirth = new int(YOB);
    playerAge = new double();
	armyUnitsLeft = new int(14);
	citiesLeft = new int(3);
    playerScore = new int();
    lastPlayerScore = new int();
    playerNumOfArmiesBasedOnSoldiers = new int();
    playerHand = new HandObject();
    playerBiddingFacility = new BidingFacility();
    GreedyComputer = false;
    ModerateComputer = false;
    *objCounter = *objCounter + 1;
    strategy = str;
}

//Destructor 
Player::~Player()
{
    delete strategy;
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

int* Player::getArmyUnitsLeft()
{
	return armyUnitsLeft;
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

void Player::setArmyUnitsLeft(int armyUnits)
{
	*armyUnitsLeft = armyUnits;
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
        this->PayCoin(bid);
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

	//QUICK FIX -- need a better fix for full game
	if (*armyUnitsLeft <= 14 && *armyUnitsLeft >= 12)
		*armyUnitsLeft = *armyUnitsLeft - 1;

    //playerCountries.emplace_back(location);
}

void Player::MoveArmies(Node* startLocation, Node* endLocation)
{
    for (int i = 0; i < startLocation->getArmies().size(); i++)
    {
        if (*(startLocation->getArmies()[i]->getOwnerNumber()) == *(this->playerNumber))
        {
            startLocation->getArmies()[i]->setNumberOfSoldiers(*(startLocation->getArmies()[i]->getNumberOfSoldiers()) - 1);

            PlaceNewArmies(endLocation);

            if ( *(startLocation->getArmies()[i]->getNumberOfSoldiers()) == 0) {
                for(int j = 0 ; j < startLocation->getArmies().size() ; j++ ){
                    if(*(startLocation->getArmies()[i]->getOwnerNumber()) == *(this->playerNumber)){
                        playerArmy.erase(playerArmy.begin() + j);
                    }
                }
            }


            break;
        }
    }
}

void Player::BuildCity(Node* location)
{
    City* city = new City(location,*(this->playerNumber));
    playerCities.emplace_back(city);
	*citiesLeft = *citiesLeft - 1;
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
    cout <<"Player " << *getPlayerNumber() << ": " << getName() << "\n\t  Coins: " << *getPlayerCoins() << "\n\t  Date of Birth: " << *getDayOfBirth()
         << "/" << *getMonthOfBirth() << "/" << *getYearOfBirth()<< endl;
}

MainGameLoop* Player::getSubject()
{
	return game;
}

vector<City*> Player::getCities() {
    return playerCities;
}

int Player::getPlayerScore() {
    return *playerScore;
}

void Player::setPlayerScore(int score) {
    *playerScore = score;
    *lastPlayerScore = score;
}

int Player::getArmyCountBasedOnSoldiers() {
    return *playerNumOfArmiesBasedOnSoldiers;
}

// Sets the number of armies based on # of soldiers 
void Player::setPlayerNumOfArmiesBasedOnSoldiers(int number) {
    *playerNumOfArmiesBasedOnSoldiers += number;
}

void Player::setSubject(MainGameLoop* subject, GameScore* gameScore)
{
    game = subject;
	game->attach(this);
    score = gameScore;
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


bool Player::isGreedyComputer() {
    return GreedyComputer;
}

bool Player::isModerateComputer() {
    return ModerateComputer;
}

bool Player::isHuman() {
    return HumanPlayer;
}

vector<Army*> Player::getPlayerArmies(){
    return playerArmy;
}

void Player::setStrategy(Strategy* str) {
    strategy = str;
    if(dynamic_cast<GreedyComputerStrategy*>(str)){
        GreedyComputer=true;
        ModerateComputer=false;
        HumanPlayer= false;
    }
    else if(dynamic_cast<ModerateComputerStrategy*>(str)){
        ModerateComputer=true;
        HumanPlayer = false;
        GreedyComputer=false;
    }else if(dynamic_cast<HumanStrategy*>(str)) {
        HumanPlayer = true;
        GreedyComputer=false;
        ModerateComputer=false;
    }
}

Strategy* Player:: getStrategy(){
    return strategy;
}

void Player::update(int code, int type, int num)
{
	if (code == 1) {
		updatePhase(type, num);
	}
	else if (code == 2) {
		updateGameStats(type);
	}
}

void Player::updatePhase(int type, int num)
{
	Player* currentPlayer = game->getTurn()->player;

	if (type == 1)
	{
		vector<Card*> cards = currentPlayer->playerCards;
		cout << "\n" << currentPlayer->playerName << " has picked the card in position " << num + 1 << "." << endl;
		cout << "The card selected has good: " << cards[cards.size() - 1]->getGoods() << " and action: " << cards[cards.size() - 1]->getAction() 
			<< "\n" << endl;
	}

	if (type != 1)
	{
		cout << endl;

		if (type == 2)
		{
			cout << currentPlayer->playerName << " has moved " << num << " army units." << endl;
		}

		if (type == 3)
		{
			cout << currentPlayer->playerName << " has placed " << num << " army units." << endl;
		}

		if (type == 4)
		{
			cout << currentPlayer->playerName << " has built a city." << endl;
		}

		if (type == 5)
		{
			cout << currentPlayer->playerName << " has destroyed an army unit." << endl;
		}

		vector<Army*> army = currentPlayer->playerArmy;
		vector<City*> cities = currentPlayer->playerCities;

		cout << "\n" << currentPlayer->playerName << " Status:" << endl;

		cout << "-Player Coins: " << *currentPlayer->playerCoins << endl;

		cout << "-Army Units: (" << *currentPlayer->armyUnitsLeft << " left)" << endl;
		for (int i = 0; i < army.size(); i++)
			cout << "   " << *army[i]->getNumberOfSoldiers() << " on " << *army[i]->getLocation()->getName() << endl;

		cout << "-Cities: (" << *currentPlayer->citiesLeft << " left)" << endl;
		for (int i = 0; i < cities.size(); i++)
			cout << "   " << *cities[i]->getLocation()->getName() << endl;

	}
}

void Player::pickStrategy() {
    int strategy_choice=-1;
    while(strategy_choice<0 || strategy_choice>3) {
        cout << "Which strategy would you like to use, player " << this->getName() << " ?" << endl;
        cout << "1. Human strategy 2.Greedy computer strategy 3. Moderate computer strategy" << endl;
        cin >> strategy_choice;
        if(strategy_choice<0 || strategy_choice>3)
            cout<<"Invalid choice. Please choose between option 1-3.";
    }
    switch(strategy_choice){
        case 1:
            this->setStrategy(new HumanStrategy());
            break;
        case 2:
            this->setStrategy(new GreedyComputerStrategy());
            break;
        case 3:
            this->setStrategy(new ModerateComputerStrategy());
            break;
    }
}

// Updates game stats upon receiving notification from subject
void Player::updateGameStats(int type) {

    // City has been built by player
    if (type == 4) {
        cout << endl << "City has been built by " << game->getTurn()->player->getName() << endl;
    }
    
    vector<int> currentPlayerScores = game->getCurrentPlayerScores();
    score->computeGameStatsOnCardDraw();
    game->checkPlayerScore(currentPlayerScores);
    
    // Army has been destroyed by player
    if (type == 5) {
        // Check if players have had some of their nodes removed
        vector<int> currentPlayerCountries = game->getCurrentPlayerCountries();
        game->checkPlayerCountries(currentPlayerCountries);
    }
    
    // Reset game score values for re-computation next turn
    game->resetPlayerScoreValues();
}

void Player::resetScore() {
    *playerScore = 0;
    *playerNumOfArmiesBasedOnSoldiers = 0;
    
    for (int i = 0; i < playerCountries.size(); i++) {
        playerCountries.erase(playerCountries.begin() + i);
    }
    
    for (int i = 0; i < playerCities.size(); i++) {
        playerCities.erase(playerCities.begin() + i);
    }
    
    for (int i = 0; i < playerContinents.size(); i++) {
        playerContinents.erase(playerContinents.begin() + i);
    }
    
    playerCountries.clear();
    playerCities.clear();
    playerContinents.clear();
}
