//
//  MainGameLoop.cpp
//  A2_Part_3
//
//  Created by Wilson Fong on 2019-11-01.
//  Copyright © 2019 Wilson Fong. All rights reserved.
//

#include "MainGameLoop.hpp"
#include <cmath>
#include <vector>
#include <regex>
#include <string>
#include "PlayerActions.h"
#include "GameObservers.h"
#include "GameScore.h"

using namespace std;

// Constructor
MainGameLoop::MainGameLoop(HandObject *handObj, vector<Player*> playersList, GameScore *gameScore) {
    handObject = handObj;
    players = playersList;
    playerActions = new PlayerActions();
    score = gameScore;

	for (int i = 0; i < players.size(); i++) {
        if (i == 0) {
            this->Subject::attach(players[0]);
        }
        
        players[i]->setSubject(this, score);
	}

    // Initialize
    setup();
}

// Destructor
MainGameLoop::~MainGameLoop() {
    delete handObject;
    delete head;
    delete score;
    for (int i = 0; i < players.size(); ++i)
        delete players[i];
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
    currentPlayer = p;

    // Perform action when traversing the list
    do
    {
        // Display who's player's turn it is.
        cout << endl << "It is " << p->player->getName() << "'s turn to play now. The player's current coin total is "
             << *p->player->getPlayerCoins()<<" coins."<< endl;

        //the strategy adopted by a player can be changed dynamically during play:
        p->player->pickStrategy();

        // Initialize it to a number that will make it enter the while loop.
        int indexOfCard = -1 ;
        handObject->toString();
        // Select one of the six cards facing up (if it is a computer player). Else let the user choose.
        int * case_ = new int(-2);
        p->player->getStrategy()->execute(&indexOfCard, p,handObject, case_);

        Card *card = handObject->getCard(indexOfCard);

        p->player->BuyCard(indexOfCard);

		//When this works, there is no need for the above cout statement
		notify(1, 1, indexOfCard);
        //notify(2, 1, indexOfCard);

        int type = processCard(card, p->player);
        notify(2, type, indexOfCard);
        
        // Check to see if the deck is empty.
        if (handObject->getDeckCount() > 0) {
            // Next player's turn
            p = p -> next;
        } else {
            throw invalid_argument("Deck of cards is finished. The game is over.");
        }
    } while(p != last->next);
}

int MainGameLoop::processCard(Card*  card, Player* player) {
    int type = 0;
    string action = card->getAction();
    int* index = new int(-1);

    while (*index < 1 || *index > 2)
    {
        cout << "Please select one of the options." << endl;
        cout << "1. " << action << endl;
        cout << "2. Ignore the action." << endl;
        cout << "What would you like to do, " << player->getName() << "? ";
       // cin >> index;
        player->getStrategy()->execute(nullptr, nullptr,handObject, index);
        cout << endl;
    }

    if (*index == 1)
    {
        //Build City action
		if (action == "Build City.")
		{
			playerActions->BuildCity(player);
			notify(1, 4, 0);
            type = 4;
		}

            //Destroy Army action
        else
			if (action == "Destroy Army.")
			{
				playerActions->DestroyArmy(players, player);
				notify(1, 5, 0);
                type = 5;
			}

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

            int* choice = new int(0);

            while (*choice < 1 || *choice > 2)
            {
                cout << "Please select one of the options." << endl;
                cout << "1. " << action1 << endl;
                cout << "2. " << action2 << endl;
                cout << "What would you like to do, " << player->getName() << "? ";
               // cin >> choice;
                player->getStrategy()->execute(nullptr, nullptr,handObject, choice);
                cout << endl;

                if (*choice == 1)
                {
                    Card* card1 = new Card();
                    card1->setAction(action1);
                    processCard(card1, player);
                    break;
                }

                else if (*choice == 2)
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
            for (int i = 0; i < amt; i++)
            {
                cout << "You can now move " << amt - i << " armies." << endl;
                playerActions->MoveOverWater(player);
            }
			notify(1, 2, amt);
            type = 2;
        }

            //Move army action: checks if the action starts with "Mov" (Move) and extracts the number of army units
        else
        if (regex_match(action, regex("(Mov)(.*)")))
        {
            int amt = action.at(5) - '0';
            for (int i = 0; i < amt; i++)
            {
                cout << "You can now move " << amt - i << " armies." << endl;
                playerActions->MoveOverLand(player);
            }
			notify(1, 2, amt);
            type = 2;
        }

            //Add army action: checks if the action starts with "Ad" (Add) and extracts the number of army units
        else
        if (regex_match(action, regex("(Ad)(.*)")))
        {
            int amt = action.at(4) - '0';
            for (int i = 0; i < amt; i++)
            {
                cout << "\nYou can now add " << amt - i << " armies." << endl;
                playerActions->PlaceNewArmies(player);
            }
			notify(1, 3, amt);
            type = 3;
        }
    }
    
    return type;
}

Turn* MainGameLoop::getTurn()
{
    return currentPlayer;
}

void MainGameLoop::resetPlayerScoreValues() {
    for (int i = 0; i < players.size(); i++) {
        players[i]->resetScore();
    }
}

void MainGameLoop::checkPlayerScore(vector<int> originalScores) {
    for (int i = 0; i < players.size(); i++) {
        int newScore = players[i]->getPlayerScore();
        if (originalScores[i] < newScore) {
            cout << "Congratulations to " << players[i]->getName() << " for scoring this turn!!!" << endl;
        }
    }
}

vector<int> MainGameLoop::getCurrentPlayerScores() {
    vector<int> scores;
    
    for (int i = 0; i < players.size(); i++) {
        scores.push_back(*players[i]->lastPlayerScore);
    }
    
    return scores;
}

vector<int> MainGameLoop::getCurrentPlayerCountries() {
    vector<int> countries;
    
    for (int i = 0; i < players.size(); i++) {
        countries.push_back(players[i]->getCountries().size());
    }
    
    return countries;
}

void MainGameLoop::checkPlayerCountries(vector<int> originalCountries) {
    for (int i = 0; i < players.size(); i++) {
        int newCount = players[i]->getCountries().size();
        if (originalCountries[i] < newCount) {
            cout << "One or more countries have been removed from " << players[i]->getName() << " during this turn!!!" << endl;
        }
    }
}
