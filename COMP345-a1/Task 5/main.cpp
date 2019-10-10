//
//  main.cpp
//  BidingT5A1
//
//  Created by Francois David on 2019-10-09.
//  Copyright © 2019 Francois David. All rights reserved.
//

#include "Cards.hpp"
#include "Player.hpp"
#include "BidingFacility.hpp"
#include <iostream>
#include <vector>
#include <iostream>
using namespace std;


int main(int argc, const char * argv[]) {
    
    // Create a few players to test the biding facility.
    Player* player1 = new Player();
    Player* player2 = new Player();
    Player* player3 = new Player();
    Player* player4 = new Player();
    
    // Set their name.
    player1->setName("Player1");
    player2->setName("Player2");
    player3->setName("Player3");
    player4->setName("Player4");

    // Set their age.
    player1->setAge(3);
    player2->setAge(1);
    player3->setAge(2);
    player4->setAge(5);
    
    // Create a new biding facility.
    BidingFacility* bf = new BidingFacility();
    
    // Make the players bid.
    bf->playerBid(player1, 11);
    bf->playerBid(player2, 0);
    bf->playerBid(player3, 0);
    bf->playerBid(player4, 3);
    
    cout << "\nNormal case where they bid different amount but one player bids more than he has." << endl;
    // Reveal the highest bider and display its name.
    Player* winner = bf->revailHighestBider();
    
    cout << "\tWinner is : " << winner->getName() << endl;
    
    BidingFacility* bf1 = new BidingFacility();
    
    
    bf1->resetCurrentBid();
    bf1->playerBid(player1, 0);
    bf1->playerBid(player2, 0);
    bf1->playerBid(player3, 0);
    bf1->playerBid(player4, 0);
    
    
    cout << "\nCase where they all bid zero, so the youngest is choosen (player2)." << endl;
    winner = bf1->revailHighestBider();
    cout << "\tWinner is : " << winner->getName() << endl;
    
    
    bf1->resetCurrentBid();
    bf1->playerBid(player1, 5);
    bf1->playerBid(player2, 1);
    bf1->playerBid(player3, 4);
    bf1->playerBid(player4, 5);
    
    
    cout << "\nCase where there is a tie between 2 players, so the youngest is choosen as the winner (player1)." << endl;
    winner = bf1->revailHighestBider();
    cout << "\tWinner is : " << winner->getName() << endl;
    
    return 0;
}
