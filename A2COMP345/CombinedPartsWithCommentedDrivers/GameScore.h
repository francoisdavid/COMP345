//
// Created by Francois David on 2019-11-04.
//

#ifndef COMBINEDPARTSWITHCOMMENTEDDRIVERS_GAMESCORE_H
#define COMBINEDPARTSWITHCOMMENTEDDRIVERS_GAMESCORE_H

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


#endif //COMBINEDPARTSWITHCOMMENTEDDRIVERS_GAMESCORE_H
