//
//  GameScore.hpp
//  A2_Part_6
//
//  Created by Wilson Fong on 2019-11-04.
//  Copyright © 2019 Wilson Fong. All rights reserved.
//

#ifndef GameScore_hpp
#define GameScore_hpp

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
    bool isGameEnd();
    void processRegionsScore();
    int computeGoodsScore(Player*);
    int carrotsScore(int);
    int oreScore(int);
    int crystalScore(int);
    int forestScore(int);
    int anvilScore(int);
private:
    
    // Properties
    vector<Player*> players;
    Map* map;
};

#endif /* GameScore_hpp */

