//
//  BidingFacility.cpp
//  BidingT5A1
//
//  Created by Francois David on 2019-10-09.
//  Copyright © 2019 Francois David. All rights reserved.
//

#include "BidingFacility.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>
using namespace std;

Player* BidingFacility::currentlyHighestBidder = NULL;
int* BidingFacility::currentBid = new int(0);


// Default Constructor.
BidingFacility::BidingFacility (){
    
}
BidingFacility::~BidingFacility(){
    
}

void BidingFacility::playerBid(Player* player, int bid) {

	//cout << player->getName() << " bids " << bid << " coins." << endl;
    if (currentlyHighestBidder == NULL){
        currentlyHighestBidder = player;
    }
    if(*player->getPlayerCoins() < bid){
        cout << "You cannot bid more than you have !! Player's bid is disqualified." << endl;
    } else if (*currentBid < bid ){
        currentlyHighestBidder = player;
        *currentBid = bid;
    }else if (*currentBid == bid && *player->getPlayerAge() > *currentlyHighestBidder->getPlayerAge()) {
        
        *currentBid = bid;
        currentlyHighestBidder = player;
    }
}

Player* BidingFacility::revailHighestBider(){
    
    cout << "The winner of the Biding Facility is " << currentlyHighestBidder->getName() << " with a bid of " << *currentBid << " coins." <<endl;
    
    currentlyHighestBidder->PayCoin(*currentBid);
    return currentlyHighestBidder;
    
}

void BidingFacility::resetCurrentBid(){
    *currentBid = 0;
    currentlyHighestBidder = NULL;
}
