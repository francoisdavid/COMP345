#ifndef PlayerActions_h
#define PlayerActions_h

#include "Player.h"

using namespace std;

class PlayerActions {

public:
	PlayerActions();
	~PlayerActions();

	void PlaceNewArmies(Node* location, Player*  player);
	void MoveArmies(Node*, Node*, Player* player);
	void MoveOverLand(Node*, Node*, Player* player);
	void MoveOverWater(Node*, Node*, Player* player);
	void BuildCity(Node*, Player*);
	void DestroyArmy(Node*, Player* Opponent, Player* ThisPlayer);
	int AndOrAction();
	void Ignore();
	static void setStartingLocation(Node*);

	static Node* getStartingLocation();

    //Player* getPlayer();s
    //PlayerActions(Player*);
private:
	//Player* mainPlayer;

	static Node* startingLocation;
	

};

#endif // PlayerActions_h
