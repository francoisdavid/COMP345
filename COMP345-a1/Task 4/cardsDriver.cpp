//
//  main.cpp
//  DeckCardsT4A1
//
//  Created by Francois David on 2019-10-02.
//  Copyright © 2019 Francois David. All rights reserved.
//

#include <vector>
#include <iostream>
using namespace std;
#include "Cards.hpp"

int main(int argc, const char * argv[]) {
    
    cout << "Welcome to the driver of the cards object of task 4!\n";
    
    Deck* deck = new Deck();
    
    HandObject* hand = new HandObject(deck);
    
    Card* card = deck->drawCard();
    
    hand->toString();
    cout << endl;

    hand->exchange(2);
    
    hand->toString();
    
    
    return 0;
}
