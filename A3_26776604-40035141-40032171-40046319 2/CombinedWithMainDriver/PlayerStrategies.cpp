//
// Created by Iana Belitchka on 2019-11-17.
//

#include <cmath>
#include <vector>
#include "PlayerStrategies.h"
//#include "MainGameLoop.hpp"

void HumanStrategy:: execute(int* indexOfCard, Turn* p, HandObject*, int* index_case2) {
    if (*index_case2 == -2) {
        cout << "inside human strategy execute.." << endl;
        // Prompt the user to enter the card he wants to select, continues this process until the input is valid.
        do {
            cout << "Please enter the index of the card you want to select (1 to 6) : ";
            cin >> *indexOfCard;
            *indexOfCard -= 1;
            // Display to the user that he does not have enough coins for that.
            if (*p->player->getPlayerCoins() < ceil(double(*indexOfCard) / 2)) {
                cout << "You can't afford this card." << endl;
            }
        } while (*indexOfCard > 5 || *indexOfCard < 0 || *p->player->getPlayerCoins() < ceil(double(*indexOfCard) / 2));
    } else
        cin>>  *index_case2;
}

void GreedyComputerStrategy:: execute(int* indexOfCard, Turn* p, HandObject* handObject,int* index_case2) {
    if(*index_case2==-2) {
        cout << "inside greedy computer strategy execute.." << endl;
        vector<int> possibilities;
        for (int i = 0; i < 6; i++) {
            if (handObject->getCard(i)->getAction().rfind("Destroy", 0) == 0 ||
                handObject->getCard(i)->getAction().rfind("Build", 0) == 0) { //yes starts with prefix
                possibilities.push_back(i);
            }
        }
        if (possibilities.size() != 0)
            *indexOfCard = possibilities[rand() % possibilities.size()];
        else
            *indexOfCard = rand() % 5;

        // Display to the user that he does not have enough coins for that.
        if (*p->player->getPlayerCoins() < ceil(double(*indexOfCard) / 2)) {
            cout << "You can't afford this card." << endl;
        }
    } else
        *index_case2 = 1;
}

void ModerateComputerStrategy:: execute(int* indexOfCard, Turn* p,HandObject* handObject, int* index_case2) {
        if(*index_case2==-2){
        cout<<"inside moderate computer strategy execute.."<<endl;
        vector<int> possibilities;
        for(int i=0; i< 6;i++) {
            if (handObject->getCard(i)->getAction().rfind("Add", 0) == 0) { //yes starts with prefix
                possibilities.push_back(i);
            }
        }
        if(possibilities.size()!=0)
            *indexOfCard= possibilities[rand() % possibilities.size()];
        else
            *indexOfCard = rand()%5;

        // Display to the user that he does not have enough coins for that.
        if (*p->player->getPlayerCoins() < ceil(double(*indexOfCard) / 2)) {
            cout << "You can't afford this card." << endl;
        }
        } else
            *index_case2 = 1;
}