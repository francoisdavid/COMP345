//
//  Card.cpp
//  DeckCardsT4A1
//
//  Created by Francois David on 2019-10-02.
//  Copyright © 2019 Francois David. All rights reserved.
//

#include "Cards.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;


Card::Card(){
  
}
Card::Card(int index){

    switch(index){
        // 8 Forest cards.
        case 1: goods = "Forest"; action = "Move 3 Armies."; break;
        case 2: goods = "Forest"; action = "Add 3 Armies."; break;
       // case 3: goods = "Forest"; action = "Move 6 Armies."; break;
        case 3: goods = "Forest"; action = "Destroy Army or Build City."; break;
        case 4: goods = "Forest"; action = "Add 2 Armies OR Move 3 Armies." ; break;
        case 5: goods = "Forest"; action = "Move 4 Armies over Water."; break;
        case 6: goods = "Forest"; action = "Build City."; break;
        case 7: goods = "Forest"; action = "Move 3 Armies over Water."; break;
        
        // 10 Carrots cards.
        case 8: goods = "Carrots"; action = "Build City."; break;
        case 9: goods = "Carrots"; action = "Destroy Army AND Build City."; break;
        case 10: goods = "Carrots"; action = "Add 3 Armies."; break;
        case 11: goods = "Carrots"; action = "Move 4 Armies."; break;
        case 12: goods = "Carrots"; action = "Move 5 Armies."; break;
        case 13: goods = "Carrots"; action = "Add 3 Armies."; break;
        case 14: goods = "Carrots"; action = "Move 3 Armies over Water."; break;
        //case 16: goods = "Carrots"; action = "Add 4 Armies OR Move 2 Armies."; break;
        case 15: goods = "Carrots"; action = "Move 4 Armies."; break;
        case 16: goods = "Carrots"; action = "Build City."; break;
        
        // 9 Anvil cards.
        case 17: goods = "Anvil"; action = "Move 4 Armies."; break;
        case 18: goods = "Anvil"; action = "Move 3 Armies OR Move 4 Armies."; break;
        case 19: goods = "Anvil"; action = "Move 5 Armies.";break;
        case 20: goods = "Anvil"; action = "Add 3 Armies."; break;
        case 21: goods = "Anvil"; action = "Add 3 Armies."; break;
        case 22: goods = "Anvil"; action = "Move 3 Armies over Water."; break;
        case 23: goods = "Anvil"; action = "Build City."; break;
        //case 26: goods = "Anvil"; action = "Move 4 Armies."; break;
        case 24: goods = "Anvil"; action = "Add 3 Armies OR Move 3 Armies."; break;
        
        // 7 Ore cards.
        case 25: goods = "Ore"; action = "Move 2 Armies."; break;
        case 26: goods = "Ore"; action = "Move 3 Armies over Water."; break;
        //case 30: goods = "Ore"; action = "Move 2 Armies over Water."; break;
        case 27: goods = "Ore"; action = "Move 2 Armies over Water."; break;
        case 28: goods = "Ore"; action = "Add 3 Armies."; break;
        case 29: goods = "Ore"; action = "Add 3 Armies."; break;
        case 30: goods = "Ore"; action = "Add 2 Armies."; break;
            
        // 5 Crystal cards.
        case 31: goods = "Crystal"; action = "Add 2 Armies.";break;
        case 32: goods = "Crystal"; action = "Add 2 Armies.";break;
        case 33: goods = "Crystal"; action = "Move 2 Armies.";break;
        case 34: goods = "Crystal"; action = "Add 1 Army.";break;
        case 35: goods = "Crystal"; action = "Add 2 Armies.";break;
            
        // 3 Wild cards.
        case 36: goods = "Wild"; action = "Move 2 Armies.";break;
        case 37: goods = "Wild"; action = "Move 2 Armies.";break;
        //case 42: goods = "Wild"; action = "Add 2 Armies.";break;

        // Only 5 player cards.
        case 38: goods = "Forest"; action = "Move 6 Armies."; break;
        case 39: goods = "Carrots"; action = "Add 4 Armies OR Move 2 Armies."; break;
        case 40: goods = "Anvil"; action = "Move 4 Armies."; break;
        case 41: goods = "Ore"; action = "Move 2 Armies over Water."; break;
        case 42: goods = "Wild"; action = "Add 2 Armies.";break;


        default: cout << "Trying to instantiate more than 42 cards." << endl;
    }

}

// Destructor.
Card::~Card(){
    
}

// Accessor method.
string Card::getAction(){
    return action;
}

// Accessor method.
string Card::getGoods(){
    return goods;
}

void Card::setAction(string act)
{
	action = act;
}



// Deck CLASS.
// Default Constructor.
Deck::Deck(){
    if(cards.size() == 0){
        for(int i = 1 ; i <= 42 ; i++ ){
            Card* pointer = new Card(i);
            cards.emplace_back(pointer);
        }
        //random_shuffle(cards.begin(), cards.end());
        //random_shuffle(cards.begin(), cards.end());
        randomizeDeck();
    }
}

// Destructor.
Deck::~Deck(){
    cards.clear();
}

// Constructor with the nbOfCards Specified.
Deck::Deck(int nbOfCards){
    if(cards.size() == 0 ){
        for(int i = 1 ; i <= nbOfCards ; i++ ){
              Card* pointer = new Card(i);
              cards.emplace_back(pointer);
        }
        // random_shuffle(cards.begin(), cards.end());
        randomizeDeck();
    }
}

// Method that returns a pointer to the card drawed from the deck.
Card* Deck::drawCard(){
    Card &temp = *cards.back();
    cards.pop_back();
    return &temp;
}

// Returns the number of cards in the Deck.
int Deck::howManyCards(){
    //cout<< cards.size() <<endl;
    return cards.size();
}


ostream& operator<<(ostream& os, const Deck& dt)
{
    for(int i= 0 ; i< dt.cards.size();i++){
        Card *pointer = dt.cards[i];
        os << pointer->getAction() <<endl;
    }
    return os;
}


// The HandObject CLASS
// Default Constructor.
HandObject::HandObject() {
   
    if(deck->howManyCards() == 42){
        //Deck* deck = new Deck();
        for(int i= 0 ; i < 6 ;i++){
           displayCards[i] = deck->drawCard();
        }
    }
}
// Default destuctor.
HandObject::~HandObject(){
    
}

// Constructor with size of deck specified.
HandObject::HandObject(Deck* deckPassed){
    if(deck->howManyCards() != deckPassed->howManyCards()){
        deck = deckPassed;
        for(int i= 0 ; i < 6 ; i++ ){
            displayCards[i] = deck->drawCard();

        }
    }
}

// For static variables (definition).
Deck* HandObject::deck = new Deck();
Card* HandObject::displayCards[6] = {NULL, NULL, NULL, NULL, NULL, NULL};


// Exhcnage method for the hand object.
Card* HandObject::exchange(int indexOfCard){
    
    Card* pointer;
    
    int price = ceil(double(indexOfCard)/2);
    
    cout << "The cost of that card is " << price <<" since it is in position : " << indexOfCard+1 << endl;
    
    pointer = displayCards[indexOfCard];
  
    // Slide the cards in decreasing order.
    for(int i = indexOfCard ; i < 5 ; i++ ){
        displayCards[i] = displayCards[i + 1];
    }
    // Draw a new card for the new last card of the showing hand.
    displayCards[5] = deck->drawCard();
    return pointer;
}

// To String object.
void HandObject::toString(){
    cout << "Cards to select:" <<endl;
    for(int i = 0 ; i < 6  ; i++ ){
        cout << "\t" <<  i + 1 << "- Price: "<< ceil(double(i)/2) <<  "$\t Goods: " << displayCards[i]->getGoods()<<"\t\t Action: " << displayCards[i]->getAction() << endl ;
    }
}

int HandObject::getDeckCount() {
    return deck->howManyCards();
}

Card *HandObject::getCard(int indexOfCard) {
    return displayCards[indexOfCard];
}

void Deck::randomizeDeck() {
    for(int i = 0; i < cards.size(); i++){
        //srand(time(0));
        int i1 = rand()  % cards.size();
        int i2 = rand() % cards.size();
        Card* temp = cards.at(i1);
        cards.at(i1)  = cards.at(i2);
        cards.at(i2) = temp;
    }

}