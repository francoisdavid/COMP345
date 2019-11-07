//
// Created by Francois David on 2019-11-04.
//

#ifndef COMBINEDPARTSWITHCOMMENTEDDRIVERS_GAMESCORE_H
#define COMBINEDPARTSWITHCOMMENTEDDRIVERS_GAMESCORE_H

#include <stdio.h>
#include "Player.h"
#include "Cards.h"
#include "Map.h"

using namespace std;

class GameScore {
    
public:
    
    // Constructors/Destructor
    GameScore(vector<Player*> players, Map* graph);
    ~GameScore();
    
    // Methods
    void computeGameScore();
private:
    
    // Properties
    vector<Player*> players;
    Map* map;
    
    // Methods
    bool isGameEnd();
    void processRegionsScore();
    void processContinentsScore();
    int computeGoodsScore(Player*);
    int carrotsScore(int);
    int oreScore(int);
    int crystalScore(int);
    int forestScore(int);
    int anvilScore(int);
    void listScoreAndStatistics();
    void determineWinnerByScore();
    void determineWinnerByArmies();
    void determineWinnerByCoins();
    void determineWinnerByControlledRegions();
};

#endif //COMBINEDPARTSWITHCOMMENTEDDRIVERS_GAMESCORE_H
