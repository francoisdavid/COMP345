//
// Created by Francois David on 2019-11-13.
//

#include <iostream>
#include "GameObservers.h"

using namespace std;

Subject::Subject()
{
	observers = new list<GameObservers*>;
}

Subject::~Subject()
{
	delete observers;
}

void Subject::attach(GameObservers* newObserver)
{
	observers->push_back(newObserver);
}

void Subject::detach(GameObservers* deleteObserver)
{
	observers->remove(deleteObserver);
}

void Subject::notify(int code)
{
	list<GameObservers*>::iterator i = observers->begin();
	for (; i != observers->end(); i++)
		(*i)->update(code);
}


GameObservers::GameObservers()
{
}

void GameObservers::update(int code) {
    
}
