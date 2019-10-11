
//  BidingFacility.hpp
//  BidingT5A1
//
//  Created by Francois David on 2019-10-09.
//  Copyright © 2019 Francois David. All rights reserved.
//

#ifndef BidingFacility_hpp
#define BidingFacility_hpp

#include <string>
#include <vector>
#include <stdio.h>

using namespace std;


class BidingFacility{
public:
    BidingFacility();
    ~BidingFacility();
    void playerBid(Player* player, int bid);
    Player* revailHighestBider();
private:
    static Player* currentlyHighestBidder;
    static int* currentBid;
    
};



#endif /* BidingFacility_hpp */

