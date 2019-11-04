#include <iostream>
#include "Map.h"
#include <string>
#include "MapLoader.h"
#include <vector>
#include "Player.h"
#include "Cards.h"

using namespace std;
/*
int main() {
    // Valid map file with valid graph
    string filePath = "../Maps/MAP1.map";
    MapLoader *mapLoader = new MapLoader(filePath);
    mapLoader->processMap();
    delete mapLoader;


    int number = 0;
    while (number < 2 || number > 5) {
        cout << "Enter the number of players (2 to 5): " << endl;
        cin >> number;

    }
    cout << "Thank You ! \nThe game is will set up for " << number << " players" << endl;

    // Vector that will hold the pointers to the different players.
    vector<Player*> players;
    BidingFacility* bidingFacility = new BidingFacility();

    cout << "\n\nDISPLAY OF THE PLAYERS CREATED, THE DIFFERENT NAME, EMPTY HAND AND COINS ALLOWED." << endl;

    for (int i = 0; i < number; i++) {
        // Create a new player object with default name and coin number that will be changed later.
        Player *newPlayer = new Player("Red", 10, rand() % 31 + 1, rand() % + 12, rand() % 99+ 1930);

        // Change the name of the player created above depending on the value of i.  0 stays as "Red".
        if (i == 1){
             newPlayer->setName("Blue");
        }else if(i == 2){
            newPlayer->setName("Green");
        }else if(i == 3){
            newPlayer->setName("Yellow");
        }else if(i == 4){
            newPlayer->setName("Pink");
        }

        // Set the number of coins according to the number of players playing.
        if (number == 2) {
            newPlayer->setPlayerCoins(14);

        } else if (number == 3) {
            newPlayer->setPlayerCoins(11);
        } else if (number == 4) {
            newPlayer->setPlayerCoins(9);
        } else {
            newPlayer->setPlayerCoins(8);
        }

        cout  << "\n\tCoins supplied to player"<< i+1 << " ("<< newPlayer->getName() << "): " << *newPlayer->getPlayerCoins() << endl;

        // Set the playerBidingFacility to be shared between players.
        newPlayer->setPlayerBiddingFacility(bidingFacility);


        // Showing that each player have an empty hand of cards.
        vector<Card*> cards = newPlayer->getCards();
        cout  << "\tCards in the hand of player"<< i+1 << " ("<< newPlayer->getName() << "): " << cards.size() << endl;

        // Add the player to the vector of players.
        players.emplace_back(newPlayer);
    }

    cout << endl;

    // Instantiate the deck of cards depending on the number of players.
    Deck *deck;
    if (number != 5) {
        deck = new Deck(37);
        cout<< deck->howManyCards()<< " cards were created. Shuffled on creation." << endl;
    }else {
        deck =new Deck(42);
        cout<< deck->howManyCards()<< " cards were created. Shuffled on creation." << endl;
    }

    cout << "\n\nDISPLAY OF THE 6 CARDS IN THE MIDDLE OF THE BOARD." << endl;

    HandObject* handObj = new HandObject(deck);
    handObj->toString();

    cout << "\n\nPLAYER DETAILS FOR BIDDING VALIDATION." << endl;
    for(std::vector<Player*>::size_type i = 0; i != players.size(); i++) {
       // Player* player = players[i];
        players[i]->toString();
    }

    cout << "\n\nBIDDING PROCESS" << endl;
    for(std::vector<Player*>::size_type i = 0; i != players.size(); i++) {
        // Player* player = players[i];
        cout<<" Time to bid for "<< players[i]->getName() << endl;
        int bid;
       cin >> bid;
       players[i]->playerBid(bid);
    }

    Player* winner = bidingFacility->revailHighestBider();

   // cout << "The winner of the bid is :"<< winner->getName() ;


    return 0;
}*/