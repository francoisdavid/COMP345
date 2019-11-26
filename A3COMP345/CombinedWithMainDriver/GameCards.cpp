//
// Created by Francois David on 2019-11-26.
//


#include "CardsFactory.h"


// FORREST
ForestCard::ForestCard(string actionGiven) {
    action = actionGiven;
}

string ForestCard::getAction() {
    return action;
}

string ForestCard::getGoods() {
    return "Forest";
}

void ForestCard::setAction(string actionGiven) {
    action = actionGiven;
}

// CARROTS
CarrotsCard::CarrotsCard(string actionGiven) {
    action = actionGiven;
}

string CarrotsCard::getAction() {
    return action;
}

string CarrotsCard::getGoods() {
    return "Carrots";
}

void CarrotsCard::setAction(string actionGiven) {
    action = actionGiven;
}


// ANVIL

AnvilCard::AnvilCard(string actionGiven) {
    action = actionGiven;
}

string AnvilCard::getAction() {
    return action;
}

string AnvilCard::getGoods() {
    return "Anvil";
}

void AnvilCard::setAction(string actionGiven) {
    action = actionGiven;
}


// ORE


OreCard::OreCard(string actionGiven) {
    action = actionGiven;
}

string OreCard::getAction() {
    return action;
}

string OreCard::getGoods() {
    return "Ore";
}

void OreCard::setAction(string actionGiven) {
    action = actionGiven;
}

// WILD


WildCard::WildCard(string actionGiven) {
    action = actionGiven;
}

string WildCard::getAction() {
    return action;
}

string WildCard::getGoods() {
    return "Wild";
}

void WildCard::setAction(string actionGiven) {
    action = actionGiven;
}

// CRYSTAL

CrystalCard::CrystalCard(string actionGiven) {
    action = actionGiven;
}

string CrystalCard::getAction() {
    return action;
}

string CrystalCard::getGoods() {
    return "Crystal";
}

void CrystalCard::setAction(string actionGiven) {
    action = actionGiven;
}