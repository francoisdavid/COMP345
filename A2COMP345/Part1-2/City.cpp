#include <iostream>
#include "..\Header Files\City.h"
#include <string>

using namespace std;

City::City()
{
	ownerNumber = new int();
}

City::City(Node* location, int owner)
{
	mapLocation = location;
	ownerNumber = new int(owner);
}

City::~City()
{
}

Node* City::getLocation()
{
	return mapLocation;
}

int* City::getOwnerNumber()
{
	return ownerNumber;
}

void City::setLocation(Node* location)
{
	mapLocation = location;
}

void City::setOwnerNumber(int owner)
{
	*ownerNumber = owner;
}
