#ifndef PlayerActions_h
#define PlayerActions_h

#include "Player.h"

using namespace std;

class PlayerActions {

public:
	PlayerActions();
	~PlayerActions();

	void PlaceNewArmies(Player*);
	void MoveArmies(Node*, Node*, Player* player);
	void MoveOverLand(Player*);
	void MoveOverWater(Player*);
	void BuildCity(Player*);
	void DestroyArmy(vector<Player*>, Player*);
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
