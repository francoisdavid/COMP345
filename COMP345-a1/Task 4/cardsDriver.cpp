//
//  main.cpp
//  DeckCardsT4A1
//
//  Created by Francois David on 2019-10-02.
//  Copyright © 2019 Francois David. All rights reserved.
//

#include <vector>
#include <iostream>
#include "Cards.hpp"
#include "Player.hpp"
using namespace std;


int main(int argc, const char * argv[]) {
    
    cout << "Welcome to the driver of the cards object of task 4!\n";
    
    
    Player* player1 = new Player();
    
   // Deck* deck = new Deck();
    Card* card = new Card();
    card->getAction();
    
    HandObject* hand = new HandObject();
    
    HandObject* hand2 = new HandObject();
    hand->toString();
    
   // Card* card = deck->drawCard();
    
   //hand->toString();
    cout << endl;

    hand->exchange(2);
    
    hand2->toString();
    
    
    // Delete the elements to avoid memory leaks and assign the dangling pointers to NULL.
    delete hand2;
    hand2 = NULL;
    delete hand;
    hand = NULL;
    delete card;
    card = NULL;
    
    return 0;
}

