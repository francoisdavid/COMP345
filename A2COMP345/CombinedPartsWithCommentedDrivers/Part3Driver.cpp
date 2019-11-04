//
//  main.cpp
//  A2_Part_3
//
//  Created by Wilson Fong on 2019-11-01.
//  Copyright © 2019 Wilson Fong. All rights reserved.
//

#include <iostream>
#include "MainGameLoop.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    cout << "Welcome to the driver of A2_Part_3." << endl;
    
    // Declaration
    Deck *deck = new Deck();
    HandObject *handObject = new HandObject(deck);
    vector<Player*> players;
    int number = 3;
    
    // Create players
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
        
        players.push_back(newPlayer);
    }

    // Execute main game loop
    MainGameLoop *mainGameLoop = new MainGameLoop(handObject, players);
    mainGameLoop->~MainGameLoop();
    
    return 0;
}
