#pragma once

#include "Map.h"

class Node;

class Army {

public:

	//Constructors/Destructor
	Army();
	Army(Node*, int, int);
	~Army();

	//Getters
	Node* getLocation();
	int* getOwnerNumber();
	int* getNumberOfSoldiers();

	//Setters
	void setLocation(Node*);
	void setOwnerNumber(int);
	void setNumberOfSoldiers(int);

private:

	Node* mapLocation;
	int* ownerNumber;
	int* numberOfSoldiers;

};
