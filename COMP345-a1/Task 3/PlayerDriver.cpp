#include "Player.h"
#include <vector>
#include <iostream>
using namespace std;

int main(int argc, const char* argv[]) {
	
	Player *player1 = new Player();
	Player *player2 = new Player("Rami", 8, 23);

	cout << "Printing player info..." << endl;
	player1->printInfo();
	player2->printInfo();

	cout << player1->getName() +" pays 5 coins." << endl;
	player1->PayCoin(5);
	player1->printInfo();

	return 0;

}