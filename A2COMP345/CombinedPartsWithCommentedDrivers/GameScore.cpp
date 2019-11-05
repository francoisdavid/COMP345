//
// Created by Francois David on 2019-11-04.
//

#include "GameScore.h"

using namespace std;

// Constructor
GameScore::GameScore(vector<Player*> playersList) {
    players = playersList;
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
        cout << "The score is ..." << endl;
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