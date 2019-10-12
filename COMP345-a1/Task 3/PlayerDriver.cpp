#include "Player.h"
#include <vector>
#include <iostream>
using namespace std;

int main(int argc, const char* argv[]) {
	
	Player *player = new Player("Rami", 10, 3, 10, 1994);

	player->printInfo();
	cout << endl;

	cout << player->getName() << " will add a card to his collection..." << endl;
	player->BuyCard(1);
	cout << "Card: Action: " << player->getCards()[0]->getAction() << "; Good: " << player->getCards()[0]->getGoods() << endl;
	cout << player->getName() << " now has " << *player->getPlayerCoins() << " coins." << endl;
	cout << endl;

	cout << player->getName() << " pays 5 coins..." << endl;
	player->PayCoin(5);
	cout << player->getName() << " now has " << *player->getPlayerCoins() << " coins." << endl;
	cout << endl;

	//cout << player->getName() << " bids 2 coins..." << endl;
	//player->Bid(2);
	//cout << player->getName() << " now has " << *player->getPlayerCoins() << " coins." << endl;
	//cout << endl;

	player->BuildCity();
	player->DestroyArmy();
	player->MoveArmies();
	player->MoveOverLandOrWater();
	player->PlaceNewArmies();
	cout << endl;

	Node* country1 = new Node();

	string* countryName = new string("Canada");
	Node* country = new Node(countryName);
	player->addCountry(country);
	cout << player->getName() << " owns " << *player->getCountries()[0]->getName() << "." << endl;


	return 0;

}