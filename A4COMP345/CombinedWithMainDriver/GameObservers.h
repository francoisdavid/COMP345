//
// Created by Francois David on 2019-11-13.
//

#ifndef COMBINEDPARTSWITHCOMMENTEDDRIVERS_GAMEOBSERVERS_H
#define COMBINEDPARTSWITHCOMMENTEDDRIVERS_GAMEOBSERVERS_H

#include <list>
using namespace std;


//Abstract class for subjects. The list _views_ contains all the observer objects to which this subject


//Abstract class for observers. All classes that inherit from this class must define what they will
//do when update() is invoked.
class GameObservers {

public:

	virtual ~GameObservers() = default;
	virtual void update(int code, int type, int num) = 0;

protected:

	GameObservers();
	
};

//will be sharing information.
class Subject {

public:

    Subject();
    ~Subject();
    virtual void attach(GameObservers*);
    virtual void detach(GameObservers*);
    virtual void notify(int code, int type, int num);

private:
    list<GameObservers*> *observers;

};


#endif //COMBINEDPARTSWITHCOMMENTEDDRIVERS_GAMEOBSERVERS_H
