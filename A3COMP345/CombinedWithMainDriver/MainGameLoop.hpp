//
//  MainGameLoop.hpp
//  A2_Part_3
//
//  Created by Wilson Fong on 2019-11-01.
//  Copyright © 2019 Wilson Fong. All rights reserved.
//

#ifndef MainGameLoop_hpp
#define MainGameLoop_hpp

#include <stdio.h>
#include "Player.h"
#include "Cards.h"
#include "PlayerActions.h"
#include "GameObservers.h"

using namespace std;

// Use circular linked list to form clockwise playing style

struct Turn {
    Player *player;
    Turn *next;
};

class MainGameLoop : public Subject {

public:

    PlayerActions* playerActions;
    // Constructors/Destructor
    MainGameLoop(HandObject *handObject, vector<Player*> players);
    ~MainGameLoop();
    
    // Methods
    void setup();
    Turn *addToEmpty(Turn *, Player*);
    Turn *addToEnd(Turn *, Player*);
    void traverse(Turn *);
    void executeGameLoop(Turn *);
    void processCard(Card*, Player* );
	void BuildCity(Player*);
	void DestroyArmy(Player*);
	void MoveArmies(Player*, int);
	void MoveArmyOverWater(Player*, int);
	void AddArmies(Player*, int);
    void MoveOneArmy(Player*);
    void AddOneArmy(Player*);
    void attach(GameObservers*);
private:
    
    // Properties
    HandObject *handObject;
    Turn *head;
    vector<Player*> players;
    // PlayerActions playerAction;
};

#endif // MainGameLoop_h
