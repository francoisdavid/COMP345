#include <iostream>
#include "Player.h"
#include "Cards.h"
#include "MapLoader.h"
#include "BidingFacility.h"
/*
int main() {

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

  int cardIndex = 0;

  HandObject* handObj = new HandObject(deck);
    handObj->toString();
  for (Player* player : players) {
    std::cout << "Showing cards on the board." << std::endl;
    player->BuyCard(cardIndex);
      handObj->toString();
    std::cout << "Showing cards on the board after player's buying card #" << cardIndex << std::endl;
  }

  delete handObj;
  delete deck;
  delete player1;
  delete player2;
  delete bidingFacility;

  return 0;
}*/
