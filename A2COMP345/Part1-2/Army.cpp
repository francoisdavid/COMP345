#include <iostream>
#include "Army.h"
#include <string>

using namespace std;

Army::Army()
{
}

Army::Army(Node* location, int owner, int soldiers)
{
	mapLocation = location;
	ownerNumber = new int(owner);
	numberOfSoldiers = new int(soldiers);
}

Army::~Army()
{
}

Node* Army::getLocation()
{
	return mapLocation;
}

int* Army::getOwnerNumber()
{
	return ownerNumber;
}

int* Army::getNumberOfSoldiers()
{
	return numberOfSoldiers;
}

void Army::setLocation(Node* location)
{
	mapLocation = location;
}

void Army::setOwnerNumber(int owner)
{
	*ownerNumber = owner;
}

void Army::setNumberOfSoldiers(int soldiers)
{
	*numberOfSoldiers = soldiers;
}
