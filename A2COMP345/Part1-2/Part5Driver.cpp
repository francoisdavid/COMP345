#include <iostream>
#include "Player.h"
#include "Cards.h"
#include "MapLoader.h"
#include "BidingFacility.h"

int main() {

  int number = 2;

  // Vector that will hold the pointers to the different players.
  vector<Player*> players;
  BidingFacility* bidingFacility = new BidingFacility();

  Player *player1 = new Player("Red", 10, rand() % 31 + 1, rand() % + 12, rand() % 99+ 1930);
  Player *player2 = new Player("Blue", 10, rand() % 31 + 1, rand() % + 12, rand() % 99+ 1930);

  player1->setPlayerCoins(14);
  player2->setPlayerCoins(14);

  player1->setPlayerBiddingFacility(bidingFacility);
  player2->setPlayerBiddingFacility(bidingFacility);

  players.emplace_back(player1);
  players.emplace_back(player2);

  Deck *deck = new Deck(37);

  HandObject* handObj = new HandObject(deck);

  for (Player* player : players) {
    std::cout << "Showing cards on the board." << std::endl;
    handObj->toString();
    player->BuyCard(2);
    std::cout << "Showing cards on the board after player's buying 3rd card." << std::endl;
  }


  return 0;
}
