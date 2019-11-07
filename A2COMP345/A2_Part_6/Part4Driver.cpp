#include "Part4GameLoop.h"
/*
int main() {

	Player* player1 = new Player("Player 1", 10, 18, 12, 1994);
	Part4GameLoop* gameLoop = new Part4GameLoop(player1);

	//Place New Armies
	cout << "Placing new army units..." << endl;

	Node* canada = new Node(1, "Canada");
	Node* us = new Node(2, "US");

	City* montreal = new City(canada,*(player1->getPlayerNumber()));

	gameLoop->PlaceNewArmies(us); // not a city, we cannot place an army there
	gameLoop->PlaceNewArmies(canada); //city so we can place an army there

	cout << endl;

	//Move Armies
	cout << "Moving army units..." << endl;

	Node* uk = new Node(3, "UK");
	Node* france = new Node(4, "France");
	Node* italy = new Node(5, "Italy");

	Edge* edge1 = new Edge("ukfrance", uk, france, "water");
	Edge* edge2 = new Edge("franceitaly", italy, france, "land");

	Army* ukArmy = new Army(uk,*(player1->getPlayerNumber()),1);

	gameLoop->MoveOverLand(uk, france); //not allowed, countries seperated by water
	gameLoop->MoveOverWater(uk, france); //allowed
	gameLoop->MoveOverLand(france, italy); //allowed
	gameLoop->MoveOverWater(france, italy); //allowed move over water also allows moving over land
	gameLoop->MoveOverWater(italy, uk); // not adjacent countries

	cout << endl;

	//Build a City
	cout << "Build a city..." << endl;

	Node* brazil = new Node(6, "Brazil");
	Node* argentina = new Node(7, "Argentina");

	Army* brazilArmy = new Army(brazil, *(player1->getPlayerNumber()), 1);

	gameLoop->BuildCity(brazil);
	gameLoop->BuildCity(argentina);

	cout << endl;

	//Destroy Army
	cout << "Destroying army units..." << endl;

	Player* player2 = new Player("Player 2", 10, 1, 1, 2000);

	Node* australia = new Node(8, "Australia");
	Node* newzealand = new Node(9, "New Zealand");

	Army* australiaArmy = new Army(australia, *(player2->getPlayerNumber()), 1);

	gameLoop->DestroyArmy(australia, player2);
	gameLoop->DestroyArmy(newzealand, player2);

	cout << endl;

	//And or Action
	cout << "And/Or actions..." << endl;

	Node* egypt = new Node(10, "Egypt");
	Node* algeria = new Node(11, "Algeria");

	Edge* edge3 = new Edge("egyptalgeria", egypt, algeria, "land");

	Army* egyptArmy = new Army(egypt, *(player1->getPlayerNumber()),2);
	Army* algeriaArmy = new Army(algeria, *(player2->getPlayerNumber()), 1);

	City* cairo = new City(egypt, *(player1->getPlayerNumber()));

	switch (gameLoop->AndOrAction()) {
		int selection;

	case 1:
		cout << "1. Destroy army" << endl;
		cout << "2. Build a city" << endl;
		cout << "Select an option: ";
		cin >> selection;
		cout << endl;

		if (selection == 1)
			gameLoop->DestroyArmy(algeria, player2);
		if (selection == 2)
			gameLoop->BuildCity(egypt);

		break;
	case 2:
		cout << "1. Add an army unit" << endl;
		cout << "2. Move an army unit" << endl;
		cout << "Select an option: ";
		cin >> selection;
		cout << endl;

		if (selection == 1)
			gameLoop->PlaceNewArmies(egypt);
		if (selection == 2)
			gameLoop->MoveOverLand(egypt,algeria);

		break;
	case 3:
		cout << "3. Destroy army and build a city." << endl;
		gameLoop->DestroyArmy(algeria, player2);
		gameLoop->BuildCity(egypt);
		break;
	}

	cout << endl;

	//Ignore
	cout << "Ignoring the action..." << endl;

	gameLoop->Ignore();

}*/
