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
/*
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
    
    /*string filePath = "/Users/Wilson/git/COMP345/A2COMP345/A2_Part_6/A2_Part_6/Maps/MAP1.map";
    MapLoader *mapLoader = new MapLoader(filePath);
    mapLoader->processMap();
    Map* map = mapLoader->getGraph();
    Node* node = map->getNode(1);
    
    players.at(1)->addCountry(node);
    players.at(1)->PlaceNewArmies(node);
    
    vector<Army*> armies = node->getArmies();
    cout << *node->getName() << endl;
    cout << armies.size() << endl;*/
    
    // CONTINENTS
    Map *europe = new Map(new std::string("Europe"));
    Map *america = new Map(new std::string("America"));
    Map *asia = new Map(new std::string("Asia"));
    
    // REGIONS
    Node *korea = new Node(1, "Korea");
    Node *japan = new Node(2, "Japan");
    Node *thailand = new Node(3, "Thailand");
    
    asia->addCountry(korea);
    asia->addCountry(japan);
    asia->addCountry(thailand);
    
    players.at(1)->addCountry(korea);
    players.at(1)->addCountry(japan);
    players.at(1)->addCountry(thailand);
    
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
    
    players.at(1)->PlaceNewArmies(korea);
    players.at(1)->PlaceNewArmies(thailand);
    
    vector<Node*> countries = players.at(1)->getCountries();
    cout << "Countries count: " << countries.size() << endl;
    vector<Army*> armies = korea->getArmies();
    cout << "Armies count: " << armies.size() << endl;
    
    // Compute game score
    GameScore *gameScore = new GameScore(players);
    gameScore->computeGameScore();
    
    return 0;
}*/
