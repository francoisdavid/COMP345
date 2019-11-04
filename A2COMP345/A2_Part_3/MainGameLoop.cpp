//
//  MainGameLoop.cpp
//  A2_Part_3
//
//  Created by Wilson Fong on 2019-11-01.
//  Copyright © 2019 Wilson Fong. All rights reserved.
//

#include "MainGameLoop.hpp"

using namespace std;

// Constructor
MainGameLoop::MainGameLoop(HandObject *handObj, vector<Player*> playersList) {
    handObject = handObj;
    players = playersList;
    
    // Initialize
    setup();
}

// Destructor
MainGameLoop::~MainGameLoop() {
    delete handObject;
    delete head;
    players.clear();
};

// Add players to the game
void MainGameLoop::setup() {
    cout << endl << "Setting game up..." << endl;
    Turn *last = NULL;
    
    for (int i = 0; i < players.size(); i++) {
        last = addToEnd(last, *players.at(i));
        
        // Set head to first added player
        if (head == NULL) {
            head = last;
        }
    }
    
    // Start game with the first player
    executeGameLoop(last);
}

// Add to beginning of empty circular linked list
Turn *MainGameLoop::addToEmpty(Turn* last, Player player)
{
    if (last != NULL)
        return last;
    
    Turn *temp = new Turn();
    
    // Assign player data
    temp -> player = player;
    last = temp;
    
    // Creating the link
    last -> next = last;
    
    return last;
}

// Add to the end of circular linked list
Turn *MainGameLoop::addToEnd(Turn *last, Player player)
{
    if (last == NULL)
        return addToEmpty(last, player);
    
    Turn *temp = new Turn();
    
    // Assign player data
    temp -> player = player;
    
    // Adjusting the links
    temp -> next = last -> next;
    last -> next = temp;
    last = temp;
    
    return last;
}

// Game loop remains in its execution phase until compute game score determines winner
void MainGameLoop::executeGameLoop(Turn *last) {
    int count = 0;
    cout << "Running game loop..." << endl;
    
    while (count < 3) {
        cout << endl << "ROUND START" << endl;
        count++;
        traverse(last);
        cout << endl << "ROUND END" << endl;
    }
    
    cout << endl << "GAME IS OVER." << endl;
}

// Going through each player for each round
void MainGameLoop::traverse(Turn *last)
{
    Turn *p;
    
    if (last == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    
    // Pointing to first node of the list
    p = last -> next;
    
    // Perform action when traversing the list
    do
    {
        cout << endl << "It is " << p->player.getName() << "'s turn to play now." << endl;
        
        // Select one of the six cards facing up
        int indexOfCard = rand() % + 5;
        
        Card *card = handObject->getCard(indexOfCard);
        // Player pays for card
        p->player.BuyCard(indexOfCard);
        cout << "Good: " << card->getGoods() << endl;
        cout << "Action: " << card->getAction() << endl;
    
        // Next player's turn
        p = p -> next;
    } while(p != last->next);
}
