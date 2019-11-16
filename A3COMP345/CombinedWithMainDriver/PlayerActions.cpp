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
		cout << mainPlayer->getName()<< " has successfully placed an army unit in " << *(location->getName()) << "." << endl;
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

void PlayerActions::MoveOverLand(Player* player)
{
	// Get the regions of the current player.
	vector<Army*> armyLoc = player->getPlayerArmies();
	int index = -1;

	while (index < 0 || index > armyLoc.size())
	{
		cout << "\nPlease select one of the options." << endl;

		for (int i = 0; i < armyLoc.size(); i++)
		{
			cout << "\t" << i + 1 << ". Move 1 of the " << *armyLoc.at(i)->getNumberOfSoldiers() << " army units you have on "
				<< *armyLoc.at(i)->getLocation()->getName() << ".";

			cout << "\tPossible destinations: ";
			for (int j = 0; j < armyLoc.at(i)->getLocation()->getNeighboursLand().size(); j++)
				if (j + 1 == armyLoc.at(i)->getLocation()->getNeighboursLand().size())
					cout << *armyLoc.at(i)->getLocation()->getNeighboursLand().at(j)->getName();
				else
					cout << *armyLoc.at(i)->getLocation()->getNeighboursLand().at(j)->getName() << ", ";

			cout << endl;
		}

		cout << "What would you like to do, " << player->getName() << "? ";
		cin >> index;
		index -= 1;

		if (index >= 0 && index < armyLoc.size())
		{
			Node* from = armyLoc.at(index)->getLocation();
			vector<Node*> neighbours = from->getNeighboursLand();

			int index2 = -1;

			while (index2 < 0 || index2 > neighbours.size())
			{
				cout << "\nPlease select one of the options." << endl;

				for (int i = 0; i < neighbours.size(); i++)
					cout << "\t" << i + 1 << ". Move 1 army from " << *from->getName() << " to " << *neighbours.at(i)->getName() << endl;

				cout << "What would you like to do, " << player->getName() << "? ";

				cin >> index2;
				index2 -= 1;

				if (index2 >= 0 && index2 < neighbours.size())
				{
					player->MoveArmies(from, neighbours.at(index2));
					cout << player->getName() << " moved 1 army from " << *from->getName() << " to " << *neighbours.at(index2)->getName() << endl;
				}
			}
		}
	}
}

void PlayerActions::MoveOverWater(Node* startLocation, Node* endLocation, Player* player)
{
	// Get the regions of the current player.
    vector<Army*> armyLoc = player->getPlayerArmies();
	int index = -1;

	while (index < 0 || index > armyLoc.size())
	{
		cout << "\nPlease select one of the options." << endl;

		for (int i = 0; i < armyLoc.size(); i++)
		{
			cout << "\t" << i + 1 << ". Move 1 of the " << *armyLoc.at(i)->getNumberOfSoldiers() << " army units you have on "
				<< *armyLoc.at(i)->getLocation()->getName() << ".";

			cout << "\tPossible destinations: ";
			for (int j = 0; j < armyLoc.at(i)->getLocation()->getNeighbours().size(); j++)
				if (j + 1 == armyLoc.at(i)->getLocation()->getNeighbours().size())
					cout << *armyLoc.at(i)->getLocation()->getNeighbours().at(j)->getName();
				else
					cout << *armyLoc.at(i)->getLocation()->getNeighbours().at(j)->getName() << ", ";

			cout << endl;
		}

		cout << "What would you like to do, " << player->getName() << "? ";
		cin >> index;
		index -= 1;

		if (index >= 0 && index < armyLoc.size())
		{
			Node* from = armyLoc.at(index)->getLocation();
			vector<Node*> neighbours = from->getNeighbours();

			int index2 = -1;

			while (index2 < 0 || index2 > neighbours.size())
			{
				cout << "\nPlease select one of the options." << endl;

				for (int i = 0; i < neighbours.size(); i++)
					cout << "\t" << i + 1 << ". Move 1 army from " << *from->getName() << " to " << *neighbours.at(i)->getName() << endl;

				cout << "What would you like to do, " << player->getName() << "? ";

				cin >> index2;
				index2 -= 1;

				if (index2 >= 0 && index2 < neighbours.size())
				{
					player->MoveArmies(from, neighbours.at(index2));
					cout << player->getName() << " moved 1 army unit from " << *from->getName() << " to " << *neighbours.at(index2)->getName() 
						<< "." << endl;
				}
			}
		}		
	}
}

void PlayerActions::BuildCity(Player* mainPlayer)
{
	int index = -1;
	vector<Army*> armyLoc = mainPlayer->getPlayerArmies();

	while (index < 0 || index > armyLoc.size())
	{
		cout << "\nPlease select one of the options." << endl;

		for (int i = 0; i < armyLoc.size(); i++) {
			cout << i + 1 << ". Build city in " << *armyLoc.at(i)->getLocation()->getName() << endl;
		}

		cout << "What would you like to do, " << mainPlayer->getName() << "? ";
		cin >> index;
		index -= 1;

		if (index >= 0 && index < armyLoc.size())
		{
			mainPlayer->BuildCity(armyLoc.at(index)->getLocation());
			cout << mainPlayer->getName() << " built a city on " << *armyLoc.at(index)->getLocation()->getName() << "."
				<< endl;
		}
	}
}

void PlayerActions::DestroyArmy(vector<Player*> players, Player* mainPlayer)
{
	vector<Army*> allArmies;

	for (int i = 0; i < players.size(); i++)
		if (players[i]->getPlayerNumber() != mainPlayer->getPlayerNumber())
			for (int j = 0; j < players[i]->getArmyCount(); j++)
				allArmies.emplace_back(players[i]->getPlayerArmies()[j]);

	int index = -1;

	while (index < 0 || index > allArmies.size())
	{
		cout << "\nPlease select one of the options." << endl;

		for (int i = 0; i < allArmies.size(); i++) {
			cout << i + 1 << ". Destroy Player " << *allArmies[i]->getOwnerNumber() << "'s army unit in " << *allArmies[i]->getLocation()->getName()
				<< endl;
		}

		cout << "What would you like to do, " << mainPlayer->getName() << "? ";
		cin >> index;
		index -= 1;

		if (index >= 0 && index < allArmies.size())
		{
			Player* target = NULL;

			for (int i = 0; i < players.size(); i++)
				if (players[i]->getPlayerNumber() == allArmies[index]->getOwnerNumber())
					target = players[i];

			mainPlayer->DestroyArmy(allArmies.at(index)->getLocation(), *target->getPlayerNumber());
			cout << mainPlayer->getName() << " destroyed " << target->getName() << "'s army unit in " << *allArmies[index]->getLocation()->getName() << "."
				<< endl;
		}
	}
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
