//
//  MainGameLoop.cpp
//  A2_Part_3
//
//  Created by Wilson Fong on 2019-11-01.
//  Copyright © 2019 Wilson Fong. All rights reserved.
//

#include "MainGameLoop.hpp"
#include <cmath>
#include <string.h>
#include <vector>
#include "PlayerActions.h"

using namespace std;



// Constructor
MainGameLoop::MainGameLoop(HandObject *handObj, vector<Player*> playersList) {
    handObject = handObj;
    players = playersList;
    playerActions = new PlayerActions();
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
        last = addToEnd(last, players.at(i));
        
        // Set head to first added player
        if (head == NULL) {
            head = last;
        }
    }
    
    // Start game with the first player
    executeGameLoop(last);
}

// Add to beginning of empty circular linked list
Turn *MainGameLoop::addToEmpty(Turn* last, Player* player)
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
Turn *MainGameLoop::addToEnd(Turn *last, Player* player)
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
    cout << "Running game loop..." << endl;
    int roundCounter =  1;
    try {
        while (true) {
            cout << endl << "ROUND " << roundCounter<< " STARTS" << endl;
            traverse(last);
            roundCounter++;
        }
    } catch (const std::exception& ex) {
        cout << endl << ex.what() << endl;
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
        // Display who's player's turn it is.
        cout << endl << "It is " << p->player->getName() << "'s turn to play now. This player's current bank account shows: " << *p->player->getPlayerCoins()<<"$. "<< endl;

        // Initialize it to a number that will make it enter the while loop.
        int indexOfCard = -1 ;
        handObject->toString();
        // Select one of the six cards facing up (if it is a computer player). Else let the user choose.
        if(p->player->isGreedyComputer() || p->player->isModerateComputer()) {
            // Randomize the card picked.
            indexOfCard = rand() % 5;
        } else {
            // Prompt the user to enter the card he wants to select, continues this process until the input is valid.
            while(indexOfCard > 5 || indexOfCard < 0 || *p->player->getPlayerCoins() < ceil(double(indexOfCard)/2)) {
                cout << "Please enter the index of the card you want to select (1 to 6) : ";
                cin >> indexOfCard;
                indexOfCard -=1;
                // Display to the user that he does not have enough coins for that.
                if(*p->player->getPlayerCoins() < ceil(double(indexOfCard)/2) ){
                    cout<< "You can't afford this card." << endl;
                }
            }
        }
        Card *card = handObject->getCard(indexOfCard);

        p->player->BuyCard(indexOfCard);

        // Display the card chosen.
        cout << "\tGood: " << card->getGoods() << "\tAction: " << card->getAction() << endl;


        processCard(card, p->player);



        // Check to see if the deck is empty.
        if (handObject->getDeckCount() > 0) {
            // Next player's turn
            p = p -> next;
        } else {
            throw invalid_argument("Deck of cards is finished. The game is over.");
        }
    } while(p != last->next);
}

void MainGameLoop::processCard(Card*  card, Player* player) {
    string action = card->getAction();

    if (action == "Build City.") {
        cout << "Here are the countries you have that do not already have a city." << endl;
        vector<Army *> armyLoc = player->getPlayerArmies();
        for (int i = 0; i < armyLoc.size(); i++) {
            cout << i + 1 << "- Build city on " << *armyLoc.at(i)->getLocation()->getName() << endl;
        }
        cout << armyLoc.size() + 1 << " - Ignore the action" << endl;
        int index = 0;
        cout << "Where do you want to build that city? ";
        cin >> index;
        index -= 1;
        while (index < 0 || index > armyLoc.size()) {
            cout << "Not a valid action! Re-enter the index of the region where you want to build a city: ";
            cin >> index;
            index -= 1;
        }
        if (index != armyLoc.size()) {
            playerActions->BuildCity(armyLoc.at(index)->getLocation(), player);
            cout << player->getName() << " built a city on " << *armyLoc.at(index)->getLocation()->getName() << "."
                 << endl;
        } else {
            cout << "\nAction was ignored." << endl;
        }

    }else if (action == "Move 2 armies.") {
        for(int i = 0 ; i < 2 ;i++) {
            cout << "\nYou can now move "<<2-i<<" armies. Here are the armies you have that you can move."<< endl;
            MoveOneArmy(player);
        }
    }else if (action == "Move 3 armies.") {
        for(int i = 0 ; i < 3 ;i++) {
            cout << "\nYou can now move "<<3-i<<" armies. Here are the armies you have that you can move."<< endl;
            MoveOneArmy(player);
        }
    }else if (action == "Move 4 armies.") {
        for(int i = 0 ; i < 4 ;i++) {
            cout << "\nYou can now move "<<4-i<<" armies. Here are the armies you have that you can move."<< endl;
            MoveOneArmy(player);
        }
    }else if (action == "Move 5 armies."){
        for(int i = 0 ; i < 5 ;i++) {
            cout << "\nYou can now move "<<5-i<<" armies. Here are the armies you have that you can move."<< endl;
                MoveOneArmy(player);
        }
    } else if (action == "Move 6 armies."){
        for(int i = 0 ; i < 5 ;i++) {
            cout << "\nYou can now move "<<5-i<<" armies. Here are the armies you have that you can move."<< endl;
            MoveOneArmy(player);
        }
    } else if (action == "Add 1 army."){
        cout << "\nYou can now Add 1 army. Here are the location you can add an army."<< endl;
            AddOneArmy(player);
    } else if (action == "Add 2 armies."){
        for(int i = 0 ; i < 2 ;i++) {
            cout << "\nYou can now Add "<<2-i<<" armies. Here are the location you can add an army. "<< endl;
            AddOneArmy(player);
        }
    }else if (action == "Add 3 armies."){
        for(int i = 0 ; i < 3 ;i++) {
            cout << "\nYou can now Add "<<3-i<<" armies. Here are the location you can add an army."<< endl;
            AddOneArmy(player);
        }
    } else if (action == ""){

    }

}



void MainGameLoop::MoveOneArmy(Player* player){
    // Get the regions of the current player.
    vector<Army*> armyLoc = player->getPlayerArmies();
    for(int i = 0 ; i < armyLoc.size(); i++ ){
        cout <<"\t" << i+1 << " - Move 1 of the " << *armyLoc.at(i)->getNumberOfSoldiers() << " soldiers "<< player->getName() <<" have on " << *armyLoc.at(i)->getLocation()->getName() <<".";
        cout<< "\tPossible destinations: " ;
            for(int j  = 0 ; j < armyLoc.at(i)->getLocation()->getNeighbours().size(); j++){
                cout << *armyLoc.at(i)->getLocation()->getNeighbours().at(j)->getName() << ", ";
            }
            cout << endl;
    }
    cout <<"\t" <<armyLoc.size()+1 << " - Ignore the action" << endl;
    int index = 0 ;
    cout<< "From where do you want to move armies? " ;
    cin >> index;
    index -=1;
    while(index < 0 || index > armyLoc.size()){
        cout<<"Not a valid action! Re-enter the index of the army you want to move. ";
        cin >> index;
        index -=1;
    }
    // Check if the action was ignored.
    if( index!=armyLoc.size()) {
        Node* from = armyLoc.at(index)->getLocation();
        vector<Node*> neighbours = from->getNeighbours();
        for(int i = 0 ; i < neighbours.size(); i++ ){
            cout << "\t"<< i+1<< " - Move 1 army from "<< *from->getName() << " to " << *neighbours.at(i)->getName() << endl;
        }
        int index2 = -1;
        cout<< "Which location do you want to move that army? ";
        cin >> index2;
        index2 -=1;
        while(index < 0 || index > neighbours.size()){
            cout<<"Not a valid action! Re-enter the index of the destination you want to move that army. ";
            cin >> index;
            index -=1;
        }

        playerActions->MoveArmies(from, neighbours.at(index2), player);
        cout << player->getName() << " moved 1 army from " << *from->getName() << " to "<< *neighbours.at(index2)->getName() << endl;
    }
}


void MainGameLoop::AddOneArmy(Player* player) {
    vector<City*> cities = player->getCities();
    vector<Node*> nodeOfCities;
    // Add all the nodes to the vector.
    for(int i = 0 ; i < cities.size(); i++ ){
        nodeOfCities.emplace_back(cities.at(i)->getLocation());
    }

    for(int i = 0; i < nodeOfCities.size() ; i++){
        cout <<"\t" <<i+1 << "- Add 1 army to " << *nodeOfCities.at(i)->getName() << endl;

    }
    cout <<"\t" << nodeOfCities.size()+1 << "- Add 1 army to " << *PlayerActions::getStartingLocation()->getName() << " (starting location)."<< endl;
    cout << "\t" << nodeOfCities.size()+2 << "- Ignore the action. "<< endl;
    cout<< "Which location do you want to add that army? ";
    int index = -1;

    cin >> index;
    index -=1;

    while (index < 0 || index > nodeOfCities.size() + 1) {
        cout << "Not a valid action! Re-enter the index of the destination you want to add that army. ";
        cin >> index;
        index -= 1;
    }

    if (index != nodeOfCities.size()+1) {
        if(index != nodeOfCities.size()) {
            playerActions->PlaceNewArmies(nodeOfCities.at(index), player);
            cout << "One "<< player->getName()<< " army have been placed on the location " << *nodeOfCities.at(index)->getName() << "." << endl;
        }else {
            playerActions->PlaceNewArmies(PlayerActions::getStartingLocation(), player);
            cout << "One "<< player->getName()<< " army have been placed on the location " << *PlayerActions::getStartingLocation()->getName() << "." << endl;
        }

    } else {
        cout << "Action was ignored." << endl;
    }
}