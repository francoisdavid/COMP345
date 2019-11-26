//
// Created by Francois David on 2019-11-26.
//

#ifndef COMBINEDWITHMAINDRIVER_CARDSFACTORY_H
#define COMBINEDWITHMAINDRIVER_CARDSFACTORY_H
#include "Cards.h"


// Concrete classes that implements the cards.
class ForestCard: public Card {
public:
    ForestCard(string);
    string getGoods();
    string getAction();
    void setAction(string);
private:
    string action;
};

class CarrotsCard: public Card {
public:
    CarrotsCard(string);
    string getGoods();
    string getAction();
    void setAction(string);
private:
    string action;
};

class AnvilCard: public Card {
public:
    AnvilCard(string);
    string getGoods();
    string getAction();
    void setAction(string);
private:
    string action;
};

class OreCard: public Card {
public:
    OreCard(string);
    string getGoods();
    string getAction();
    void setAction(string);
private:
    string action;
};

class WildCard: public Card {
public:
    WildCard(string);
    string getGoods();
    string getAction();
    void setAction(string);
private:
    string action;
};

class CrystalCard: public Card {
public:
    CrystalCard(string);
    string getGoods();
    string getAction();
    void setAction(string);
private:
    string action;
};

class CardFactory {
    public:
    static Card *NewCard(const string goods, string action)
    {
        if(goods == "Forest")
            return new ForestCard(action);
        if(goods == "Carrots")
            return new CarrotsCard(action);
        if(goods == "Anvil")
            return new AnvilCard(action);
        if(goods == "Ore")
            return new OreCard(action);
        if(goods == "Wild")
            return new WildCard(action);
        if(goods == "Crystal")
            return new CrystalCard(action);
        return nullptr;
    }
};

#endif //COMBINEDWITHMAINDRIVER_CARDSFACTORY_H
