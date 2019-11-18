#pragma once

#include "Map.h"
class Node;

class City {

public:

	//Constructors/Destructor
	City();
	City(Node*, int);
	~City();

	//Getters
	Node* getLocation();
	int* getOwnerNumber();

	//Setters
	void setLocation(Node*);
	void setOwnerNumber(int);

private:

	Node* mapLocation;
	int* ownerNumber;

};

