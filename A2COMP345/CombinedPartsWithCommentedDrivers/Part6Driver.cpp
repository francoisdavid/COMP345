//
//  Driver.cpp
//  A2_Part_6
//
//  Created by Wilson Fong on 2019-11-04.
//  Copyright © 2019 Wilson Fong. All rights reserved.
//

#include <iostream>
#include "GameScore.hpp"
#include "Cards.h"
#include "Player.h"
#include "MapLoader.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    cout << "Welcome to the driver of A2_Part_6." << endl;
    
    // Declaration
    Deck *deck = new Deck();
    HandObject *handObject = new HandObject(deck);
    vector<Player*> players;
    int numberOfPlayers = 2;
    
    // Create players
    for (int i = 0; i < numberOfPlayers; i++) {
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
    
    cout << "There are " << to_string(numberOfPlayers) << " players." << endl;
    
    MapLoader *mapLoader = new MapLoader("/Users/Wilson/git/COMP345/A2COMP345/A2_Part_6/A2_Part_6/Maps/MAP1.map");
    mapLoader->processMap();
    Map* map = mapLoader->getGraph();
    
    Node* spain = map->getNode(1);
    Node* france = map->getNode(2);
    Node* holland = map->getNode(3);
    Node* italy = map->getNode(4);
    
    // Place armies
    players.at(0)->PlaceNewArmies(spain);
    players.at(1)->PlaceNewArmies(france);
    players.at(0)->PlaceNewArmies(holland);
    players.at(1)->PlaceNewArmies(holland);
    players.at(1)->PlaceNewArmies(holland);
    players.at(1)->PlaceNewArmies(italy); // Comment this line to tie the game
    
    // Build cities
    players.at(0)->BuildCity(holland);
    players.at(1)->BuildCity(holland);
    players.at(1)->BuildCity(italy);
    
    int numberOfCards = 0;
    switch (numberOfPlayers) {
        case 2:
            numberOfCards = 13;
            break;
        case 3:
            numberOfCards = 10;
            break;
        case 4:
            numberOfCards = 8;
            break;
        case 5:
            numberOfCards = 7;
            break;
    }
    
    // Assign cards to each player to meet game end requirements
    for (int i = 0; i < numberOfPlayers; i++) {
        for (int j = 0; j < numberOfCards; j++) {
            players.at(i)->BuyCard(1);
        }
    }
    
    // Compute game score
    GameScore *gameScore = new GameScore(players, map);
    gameScore->computeGameScore();
    
    return 0;
}
