#ifndef Part4GameLoop_h
#define Part4GameLoop_h

#include "Player.h"

using namespace std;

class Part4GameLoop {

public:
	Part4GameLoop();
	Part4GameLoop(Player*);
	~Part4GameLoop();

	Player* getPlayer();

	void PlaceNewArmies(Node* location);
	void MoveArmies(Node*, Node*);
	void MoveOverLand(Node*, Node*);
	void MoveOverWater(Node*, Node*);
	void BuildCity(Node*);
	void DestroyArmy(Node*, Player*);
	void AndOrAction();
	void Ignore();

private:
	Player* mainPlayer;
	

};

#endif // Part4GameLoop_h
