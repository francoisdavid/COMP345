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

using namespace std;

class GameScore {
    
public:
    
    // Constructors/Destructor
    GameScore(vector<Player*> players);
    ~GameScore();
    
    // Methods
    void computeGameScore();
    bool isGameEnd();
private:
    
    // Properties
    vector<Player*> players;
};

#endif /* GameScore_hpp */

