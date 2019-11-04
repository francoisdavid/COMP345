//
//  Card.hpp
//  DeckCardsT4A1
//
//  Created by Francois David on 2019-10-02.
//  Copyright © 2019 Francois David. All rights reserved.
//

#ifndef Cards_h
#define Cards_h

#include <string>
#include <vector>
#include <stdio.h>
using namespace std;


// The Card CLASS.
class Card {
public:
    Card();
    ~Card();
    Card(int index);
    string getAction();
    string getGoods();

private:
    string action;
    string goods;
};


// The Deck CLASS.
class Deck{
public:
    Deck();
    Deck(int nbbOfCards);
    ~Deck();
    Card* drawCard();
    int howManyCards();
    friend ostream& operator<<(ostream& os, const Deck& dt);
private:
    vector<Card*> cards;
};


// The HandObject CLASS
class HandObject{
public:
    HandObject();
    HandObject(Deck* deck);
    ~HandObject();
    Card* exchange(int indexOfCard);
    Card* getCard(int indexOfCard);
    void setCard(Card card);
    void setDeck(Deck* deck);
    void toString();
   
private:
    static Card* displayCards[6];
    static Deck* deck;
};




#endif /* Cards_h *///s

