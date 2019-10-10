//
//  BidingFacility.cpp
//  BidingT5A1
//
//  Created by Francois David on 2019-10-09.
//  Copyright © 2019 Francois David. All rights reserved.
//

#include "BidingFacility.hpp"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>
using namespace std;

Player* BidingFacility::currentlyHighestBidder = new Player();
int* BidingFacility::currentBid = 0;


// Default Constructor.
BidingFacility::BidingFacility (){
    
}

void BidingFacility::playerBid(Player* player, int bid) {
    if(player->getPlayerCoins()> bid){
        cout << "You cannot bbid more than you have !!" << endl;
    } else if (*currentBid < bid ){
        currentlyHighestBidder = player;
    } else if (*currentBid == bid && player->getPlayerAge() < currentlyHighestBidder->getPlayerAge()) {
        *currentBid = bid;
        *currentlyHighestBidder = *player;
    }
}

Player* BidingFacility::revailHighestBider(){
    
    cout << "The winner of the Biding Facility is " << currentlyHighestBidder->getName() << " with a bid of " << *currentBid << " coins." <<endl;
    
    currentlyHighestBidder->PayCoin(*currentBid);
    return currentlyHighestBidder;
    
}

