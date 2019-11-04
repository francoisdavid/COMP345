#include "Part4GameLoop.h"

Part4GameLoop::Part4GameLoop()
{
}

Part4GameLoop::Part4GameLoop(Player* player)
{
	mainPlayer = player;
}

Part4GameLoop::~Part4GameLoop()
{
}

Player* Part4GameLoop::getPlayer()
{
	return mainPlayer;
}

void Part4GameLoop::PlaceNewArmies(Node* location)
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

	if (exists)
	{
		mainPlayer->PlaceNewArmies(location);
		cout << "You have successfully placed an army unit in " << *(location->getName()) << "." << endl;
	}
	else
		cout << *(location->getName()) << " is not the starting location and you don't have a city there." << endl;
}

void Part4GameLoop::MoveArmies(Node* startLocation, Node* endLocation)
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

	if (exists && *(startLocation->getArmies()[index]->getNumberOfSoldiers()) > 0)
	{
		mainPlayer->MoveArmies(startLocation, endLocation);
		cout << "You have successfully moved an army unit from " << *(startLocation->getName()) << " to " << *(endLocation->getName()) << "." << endl;
	}
	else
		cout << "You don't have an army in " << *(startLocation->getName()) << "." << endl;
}

void Part4GameLoop::MoveOverLand(Node* startLocation, Node* endLocation)
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
			MoveArmies(startLocation, endLocation);
		else
			cout << "You can't move over water" << endl;
	}
	else
		cout << *(startLocation->getName()) << " and " << *(endLocation->getName()) << " are not adjacent." << endl;
}

void Part4GameLoop::MoveOverWater(Node* startLocation, Node* endLocation)
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
		MoveArmies(startLocation, endLocation);
	else
		cout << *(startLocation->getName()) << " and " << *(endLocation->getName()) << " are not adjacent." << endl;
}

void Part4GameLoop::BuildCity(Node* location)
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
		cout << "You have successfully built a city in " << *(location->getName()) << endl;
	}
	else
		cout << "You don't have an army in " << *(location->getName()) << "." << endl;
}

void Part4GameLoop::DestroyArmy(Node* location, Player* opponent)
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

void Part4GameLoop::AndOrAction()
{

}

void Part4GameLoop::Ignore()
{
	cout << "Ignore the action. Take the good." << endl;
}
