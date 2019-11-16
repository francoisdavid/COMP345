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
#include <regex>
#include <string>
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
        cout << endl << "It is " << p->player->getName() << "'s turn to play now. The player's current coin total is " 
			<< *p->player->getPlayerCoins()<<" coins."<< endl;

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
	int index = 0;

	while (index < 1 || index > 2)
	{
		cout << "Please select one of the options." << endl;
		cout << "1. " << action << endl;
		cout << "2. Ignore the action." << endl;
		cout << "What would you like to do, " << player->getName() << "? ";
		cin >> index;
		cout << endl;
	}

	if (index == 1)
	{
		//Build City action
		if (action == "Build City.")
			playerActions->BuildCity(player);

		//Destroy Army action
		else
			if (action == "Destroy Army.")
				playerActions->DestroyArmy(players, player);

		//And action
		else
			if (regex_match(action, regex("(.*)( AND )(.*)")))
			{
				int first = action.find(" AND ");

				string action1 = action.substr(0, first) + ".";
				string action2 = action.substr(first + 5, action.size() - 1);

				Card* card1 = new Card();
				card1->setAction(action1);
				processCard(card1, player);

				Card* card2 = new Card();
				card2->setAction(action2);
				processCard(card2, player);
			}


		//Or Action
		else 
			if (regex_match(action, regex("(.*)( OR )(.*)")))
			{
				int first = action.find(" OR ");

				string action1 = action.substr(0, first) + ".";
				string action2 = action.substr(first + 4, action.size() - 1);

				int choice = 0;

				while (choice < 1 || choice > 2)
				{
					cout << "Please select one of the options." << endl;
					cout << "1. " << action1 << endl;
					cout << "2. " << action2 << endl;
					cout << "What would you like to do, " << player->getName() << "? ";
					cin >> choice;
					cout << endl;

					if (choice == 1)
					{
						Card* card1 = new Card();
						card1->setAction(action1);
						processCard(card1, player);
						break;
					}

					else if (choice == 2)
					{
						Card* card2 = new Card();
						card2->setAction(action2);
						processCard(card2, player);
						break;
					}
				}
			}


		//Move army action: checks if the action starts with "Mov" (Move) and ends with "ater" (Water) 
		//and extracts the number of army units
		else 
			if (regex_match(action, regex("(Mov)(.*)(ater)(.*)")))
			{
				int amt = action.at(5) - '0';
				MoveArmyOverWater(player, amt);
			}

		//Move army action: checks if the action starts with "Mov" (Move) and extracts the number of army units
		else
			if (regex_match(action, regex("(Mov)(.*)")))
			{
				int amt = action.at(5) - '0';
				MoveArmies(player, amt);
			}

		//Add army action: checks if the action starts with "Ad" (Add) and extracts the number of army units
		else
			if (regex_match(action, regex("(Ad)(.*)")))
			{
				int amt = action.at(4) - '0';
				AddArmies(player, amt);
			}
	}

}

void MainGameLoop::MoveArmies(Player* player, int amount)
{
    //vector<Node*> nodes = PlayerActions::getStartingLocation()->getNeighbours();
	for (int i = 0; i < amount; i++)
	{
		cout << "You can now move " << amount - i << " armies." << endl;
		playerActions->MoveOverLand(player);
	}
}

void MainGameLoop::MoveArmyOverWater(Player* player, int amount)
{

}

void MainGameLoop::AddArmies(Player* player, int amount)
{
	for (int i = 0; i < amount; i++) 
	{
		cout << "\nYou can now add " << amount - i << " armies. Here are the location you can add an army. " << endl;
		AddOneArmy(player);
	}
}

void MainGameLoop::MoveOneArmy(Player* player){

    //vector<Node*> nodes = PlayerActions::getStartingLocation()->getNeighbours();
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
    cout <<"\t" << nodeOfCities.size()+1 << "- Add 1 army to " << *PlayerActions::getStartingLocation()->getName() 
		<< " (starting location)."<< endl;
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
            cout << "One "<< player->getName()<< " army have been placed on the location " << *nodeOfCities.at(index)->getName() 
				<< "." << endl;
        }else {
            playerActions->PlaceNewArmies(PlayerActions::getStartingLocation(), player);
            cout << "One "<< player->getName()<< " army have been placed on the location " 
				<< *PlayerActions::getStartingLocation()->getName() << "." << endl;
        }

    } else {
        cout << "Action was ignored." << endl;
    }
}