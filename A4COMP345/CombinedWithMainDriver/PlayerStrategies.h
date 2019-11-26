//
// Created by Iana Belitchka on 2019-11-17.
//
#ifndef PART1_2_PLAYERSTRATEGIES_H
#define PART1_2_PLAYERSTRATEGIES_H
#include <iostream>
#include "MainGameLoop.hpp"
using namespace std;
class Turn;
class Strategy{ //abstract class with pure virtual execute function
private:
    string test;
public:
    virtual void execute(int*, Turn*,HandObject*, int*)=0;
    virtual ~Strategy() {};
};

class HumanStrategy: public Strategy{
private:
public:
    void execute(int*, Turn*,HandObject*, int*);
};

class GreedyComputerStrategy: public Strategy{
private:
public:
    void execute(int*, Turn*,HandObject*, int*);
};

class ModerateComputerStrategy: public Strategy{
private:
public:
    void execute(int*, Turn*,HandObject*, int*);
};


#endif //PART1_2_PLAYERSTRATEGIES_H
