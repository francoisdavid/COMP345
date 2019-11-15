#include "PlayerActions.h"


 Node* PlayerActions::startingLocation = 0;

PlayerActions::PlayerActions()
{
}

void  PlayerActions::setStartingLocation(Node * startLoc) {
    startingLocation = startLoc;
}


/*
PlayerActions::PlayerActions(Player* player)
{
	mainPlayer = player;
}
*/
PlayerActions::~PlayerActions()
{
}
/*
Player* PlayerActions::getPlayer()
{
	return mainPlayer;
}
 */

void PlayerActions::PlaceNewArmies(Node* location, Player* mainPlayer)
{
	bool exists = false;
	int index;
	
	for(int i=0; i<location->getCities().size(); i++)
		if (*(location->getCities()[i]->getOwnerNumber()) == *(mainPlayer->getPlayerNumber()))
		{
			index = i;
			exists = true;
			break;
		}

	if (exists || location == startingLocation)
	{
		mainPlayer->PlaceNewArmies(location);
		cout << mainPlayer->getName()<< " have successfully placed an army unit in " << *(location->getName()) << "." << endl;
	}
	else
		cout << *(location->getName()) << " is not the starting location and you don't have a city there." << endl;
}

void PlayerActions::MoveArmies(Node* startLocation, Node* endLocation, Player* mainPlayer)
{
	bool exists = false;
	int index;

	for (int i = 0; i < startLocation->getArmies().size(); i++)
		if (*(startLocation->getArmies()[i]->getOwnerNumber()) == *(mainPlayer->getPlayerNumber()))
		{
			exists = true;
			index = i;
			break;
		}

	if (exists && *(startLocation->getArmies()[index]->getNumberOfSoldiers()) > 0 )
	{
		mainPlayer->MoveArmies(startLocation, endLocation);
		cout << "You have successfully moved an army unit from " << *(startLocation->getName()) << " to " << *(endLocation->getName()) << "." << endl;
	}
	else
		cout << "You don't have an army in " << *(startLocation->getName()) << "." << endl;
}

void PlayerActions::MoveOverLand(Node* startLocation, Node* endLocation, Player* player)
{
	bool isAdjacent = false;
	int index;

	for (int i = 0; i < startLocation->getEdges().size(); i++)
		if ((startLocation->getEdges()[i]->getNode1() == startLocation && startLocation->getEdges()[i]->getNode2() == endLocation) ||
			(startLocation->getEdges()[i]->getNode1() == endLocation && startLocation->getEdges()[i]->getNode2() == startLocation))
		{
			isAdjacent = true;
			index = i;
			break;
		}

	if (isAdjacent)
	{
		string type = *(startLocation->getEdges()[index]->getOver());

		if (type == "land")
			MoveArmies(startLocation, endLocation, player);
		else
			cout << "You can't move over water" << endl;
	}
	else
		cout << *(startLocation->getName()) << " and " << *(endLocation->getName()) << " are not adjacent." << endl;
}

void PlayerActions::MoveOverWater(Node* startLocation, Node* endLocation, Player* player)
{
	bool isAdjacent = false;
	int index;

	for (int i = 0; i < startLocation->getEdges().size(); i++)
		if ((startLocation->getEdges()[i]->getNode1() == startLocation && startLocation->getEdges()[i]->getNode2() == endLocation) ||
			(startLocation->getEdges()[i]->getNode1() == endLocation && startLocation->getEdges()[i]->getNode2() == startLocation))
		{
			isAdjacent = true;
			index = i;
			break;
		}

	if (isAdjacent)
		MoveArmies(startLocation, endLocation, player);
	else
		cout << *(startLocation->getName()) << " and " << *(endLocation->getName()) << " are not adjacent." << endl;
}

void PlayerActions::BuildCity(Node* location, Player* mainPlayer)
{
	bool exists = false;
	int index;

	for (int i = 0; i < location->getArmies().size(); i++)
		if (*(location->getArmies()[i]->getOwnerNumber()) == *(mainPlayer->getPlayerNumber()))
		{
			index = i;
			exists = true;
			break;
		}

	if (exists)
	{
		mainPlayer->BuildCity(location);

		//cout << "You have successfully built a city in " << *(location->getName()) << endl;
	}
	else
		cout << "You don't have an army in " << *(location->getName()) << "." << endl;
}

void PlayerActions::DestroyArmy(Node* location, Player* opponent, Player* mainPlayer)
{
	bool exists = false;
	int index;

	for (int i = 0; i < location->getArmies().size(); i++)
		if (*(location->getArmies()[i]->getOwnerNumber()) == *(opponent->getPlayerNumber()))
		{
			index = i;
			exists = true;
			break;
		}

	if (exists)
	{
		mainPlayer->DestroyArmy(location, *(opponent->getPlayerNumber()));
		cout << "You have successfully destroyed " << opponent->getName() << "'s army in " << *(location->getName()) << "." << endl;
	}
	else
		cout << opponent->getName() << " does not have an army in " << *(location->getName()) << "." << endl;
}

int PlayerActions::AndOrAction()
{
	cout << "1. Destroy army or build a city." << endl;
	cout << "2. Add army unit or move an army unit." << endl;
	cout << "3. Destroy army and build a city." << endl;
	cout << "Select an option: ";

	int selection;
	cin >> selection;
	cout << endl;
	return selection;
}

void PlayerActions::Ignore()
{
	cout << "Ignore the action. Take the good." << endl;
}

Node* PlayerActions::getStartingLocation() {
    return startingLocation;
}
