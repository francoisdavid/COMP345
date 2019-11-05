//
//  GameScore.cpp
//  A2_Part_6
//
//  Created by Wilson Fong on 2019-11-04.
//  Copyright © 2019 Wilson Fong. All rights reserved.
//

#include "GameScore.hpp"

using namespace std;

// Constructor
GameScore::GameScore(vector<Player*> playersList, Map* graph) {
    players = playersList;
    map = graph;
}

// Destructor
GameScore::~GameScore() {
    // Delete the players.
    for(std::vector<Player*>::size_type i = 0; i != players.size(); i++) {
        Player* temp = players[i];
        delete temp;
    }
};

// Compute game score for each player based on criteria
void GameScore::computeGameScore() {
    if (isGameEnd()) {
        processRegionsScore();
        
        vector<int> playerScores;
        for (int p = 0; p < players.size(); p++) {
            playerScores.push_back(0);
        }
        
        // Compute total score
        for (int i = 0; i < players.size(); i++) {
            
            int playerScore = 0;
            
            // Compute regions score
            playerScore += players.at(i)->getCountries().size();
            
            // Compute goods score
            playerScore += computeGoodsScore(players.at(i));
            
            cout << "Player " << to_string(i + 1) << ": " << playerScore << endl;
            playerScores[i] = playerScore;
        }
        
        // Determine winner
        int max = 0;
        
        for (int i = 0; i < playerScores.size(); i++) {
            if (playerScores.at(i) > max) {
                max = playerScores.at(i);
            }
        }
        
        int counter = 0;
        for (int k = 0; k < playerScores.size(); k++) {
            if (playerScores.at(k) == max) {
                counter++;
            }
        }
        
        // There is only one winner with max score
        if (counter == 1) {
            for (int k = 0; k < playerScores.size(); k++) {
                if (playerScores.at(k) == max) {
                    cout << "Winner is " << "player " << to_string(k+1) << ": " << players.at(k)->getName() << endl;
                }
            }
        }
        
        // If tied, check armies
        else {
            int maxArmies = 0;
            
            for (int i = 0; i < players.size(); i++) {
                if (players.at(i)->getArmyCount() > maxArmies) {
                    maxArmies = players.at(i)->getArmyCount();
                }
            }
            
            int armiesCounter = 0;
            for (int k = 0; k < players.size(); k++) {
                if (players.at(k)-> getArmyCount() == maxArmies) {
                    armiesCounter++;
                }
            }
            
            // There is only one winner with max armies
            if (armiesCounter == 1) {
                for (int k = 0; k < players.size(); k++) {
                    if (players.at(k)->getArmyCount() == maxArmies) {
                        cout << "Winner is " << "player " << to_string(k+1) << ": " << players.at(k)->getName() << endl;
                    }
                }
            }
            
            // If tied, check coins
            else {
                int maxCoins = 0;
                
                for (int i = 0; i < players.size(); i++) {
                    if (*players.at(i)->getPlayerCoins() > maxCoins) {
                        maxCoins = *players.at(i)->getPlayerCoins();
                    }
                }
                
                int coinsCounter = 0;
                for (int k = 0; k < players.size(); k++) {
                    if (*players.at(k)-> getPlayerCoins() == maxCoins) {
                        coinsCounter++;
                    }
                }
                
                // There is only one winner with max armies
                if (coinsCounter == 1) {
                    for (int k = 0; k < players.size(); k++) {
                        if (*players.at(k)->getPlayerCoins() == maxCoins) {
                            cout << "Winner is " << "player " << to_string(k+1) << ": " << players.at(k)->getName() << endl;
                        }
                    }
                }
                
                // If tied, check regions
                /*else {
                    int maxCountries = 0;
                    
                    for (int i = 0; i < players.size(); i++) {
                        if (players.at(i)->getCountries().size() > maxCoins) {
                            maxCoins = *players.at(i)->getPlayerCoins();
                        }
                    }
                    
                    int coinsCounter = 0;
                    for (int k = 0; k < players.size(); k++) {
                        if (*players.at(k)-> getPlayerCoins() == maxCoins) {
                            coinsCounter++;
                        }
                    }
                    
                    // There is only one winner with max armies
                    if (coinsCounter == 1) {
                        for (int k = 0; k < players.size(); k++) {
                            if (*players.at(k)->getPlayerCoins() == maxCoins) {
                                cout << "Winner is " << "player " << to_string(k+1) << ": " << players.at(k)->getName() << endl;
                            }
                        }
                    }
                }*/
            }
        }
    }
}

// Determines whether game is over based on # of players and # of cards in their hand
bool GameScore::isGameEnd() {
    bool isGameEnd = true;
    
    if (players.size() == 2) {
        for (int i = 0; i < 2; i++) {
            if (players.at(i)->getCardCount() != 13) {
                isGameEnd = false;
            }
        }
        
        if (isGameEnd) {
            cout << "STOP GAME. " << "All players are currently holding 13 cards." << endl;
        }
    }
    else if (players.size() == 3) {
        for (int i = 0; i < 2; i++) {
            if (players.at(i)->getCardCount() != 10) {
                isGameEnd = false;
            }
        }
        
        if (isGameEnd) {
            cout << "STOP GAME. " << "All players are currently holding 10 cards." << endl;
        }
    }
    else if (players.size() == 4) {
        for (int i = 0; i < 2; i++) {
            if (players.at(i)->getCardCount() != 8) {
                isGameEnd = false;
            }
        }
        
        if (isGameEnd) {
            cout << "STOP GAME. " << "All players are currently holding 8 cards." << endl;
        }
        
    }
    else if (players.size() == 5) {
        for (int i = 0; i < 2; i++) {
            if (players.at(i)->getCardCount() != 7) {
                isGameEnd = false;
            }
        }
        
        if (isGameEnd) {
            cout << "STOP GAME. " << "All players are currently holding 7 cards." << endl;
        }
    }
    
    return isGameEnd;
}

void GameScore::processRegionsScore() {
    vector<Node*> countries = map->getCountries();
    vector<int> playerCityCounts;
    
    for (int p = 0; p < players.size(); p++) {
        playerCityCounts.push_back(0);
    }
    
    // Compute region score
    for (int i = 0; i < countries.size(); i++) {
        vector<Army*> armies = countries.at(i)->getArmies();
        vector<City*> cities = countries.at(i)->getCities();
        
        // Process city counts
        for (int c = 0; c < cities.size(); c++) {
            int ownerNumber = *cities.at(c)->getOwnerNumber() - 1;
            playerCityCounts[ownerNumber]++;
        }
        
        int max = 0;
        
        for (int j = 0; j < armies.size(); j++) {
            if (*armies.at(j)->getNumberOfSoldiers() > max) {
                max = *armies.at(j)->getNumberOfSoldiers();
            }
        }
        
        // Treat countries with armies
        if (max > 0) {
            int counter = 0;
            for (int k = 0; k < armies.size(); k++) {
                if (*armies.at(k)->getNumberOfSoldiers() == max) {
                    counter++;
                }
            }
            
            // There is only one winner per region/country
            if (counter == 1) {
                for (int k = 0; k < armies.size(); k++) {
                    if (*armies.at(k)->getNumberOfSoldiers() == max) {
                        int ownerNumber = *armies.at(k)->getOwnerNumber() - 1;
                        players.at(ownerNumber)->addCountry(countries.at(i));
                    }
                }
            }
        }
    }
}

// Computes score for goods
int GameScore::computeGoodsScore(Player* player) {
    int forest = 0, carrots = 0, ore = 0, crystal = 0, anvil = 0;
    string good = "";
    
    vector<Card*> playerCards = player->getCards();
    
    for (int i = 0; i < playerCards.size(); i++) {
        good = playerCards[i]->getGoods();
        
        if(good == "Forest")
            forest++;
        if(good == "Carrots")
            carrots++;
        if(good == "Ore")
            ore++;
        if(good == "Crystal")
            crystal++;
        if(good == "Anvil")
            anvil++;
    }
    
    int goodsScore = carrotsScore(carrots) + oreScore(ore) + crystalScore(crystal) + forestScore(forest) + anvilScore(anvil);
    
    return goodsScore;
}

int GameScore::carrotsScore(int carrots){
    int total = 0;
    
    if(carrots < 3)
        total = 0;
    
    if(carrots >= 3 && carrots < 5)
        total = 1;
    
    if(carrots >=5 && carrots < 7)
        total = 2;
    
    if(carrots == 7)
        total = 3;
    
    if(carrots >= 8)
        total = 5;
    
    return total;
}

int GameScore::oreScore(int ore){
    int total = 0;
    
    if(ore < 2)
        total = 0;
    
    if(ore == 2)
        total = 1;
    
    if(ore == 3)
        total = 2;
    
    if(ore == 4)
        total = 3;
    
    if(ore >= 5)
        total = 5;
    
    return total;
}

int GameScore::crystalScore(int crystal){
    int total = 0;
    
    if(crystal < 1)
        total = 0;
    
    if(crystal == 1)
        total = 1;
    
    if(crystal == 2)
        total = 2;
    
    if(crystal == 3)
        total = 3;
    
    if(crystal >= 4)
        total = 5;
    
    return total;
}

int GameScore::forestScore(int forest){
    int total = 0;
    
    if(forest < 2)
        total = 0;
    
    if(forest >= 2 && forest < 4)
        total = 1;
    
    if(forest == 4)
        total = 2;
    
    if(forest == 5)
        total = 3;
    
    if(forest >= 6)
        total = 5;
 
    return total;
}

int GameScore::anvilScore(int anvil){
    int total = 0;
    
    if(anvil < 2)
        total = 0;
    
    if(anvil >= 2 && anvil < 4)
        total = 1;
    
    if(anvil >= 4 && anvil < 6)
        total = 2;
    
    if(anvil == 6)
        total = 3;
    
    if(anvil >= 7)
        total = 5;
    
    return total;
}
