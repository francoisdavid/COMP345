#ifndef MAPS_MAP_H
#define MAPS_MAP_H

#include <iostream>

class Player { //Replace with #include "Player.h"
};

class Army {  //Replace with #include "Army.h"
};

class Map {
public:
  class Node {
  private:
    char *name;
    Map *continent;
  public:
    Node();
    Node(char *);

    ~Node();

    void setContinent(Map *);

    friend std::ostream &operator<<(std::ostream &os, const Node &node);
  };

  class Edge {
  private:
    char *name;
    Map::Node *node1;
    Map::Node *node2;
  public:
    Edge(char *, Map::Node *, Map::Node *);

    friend std::ostream &operator<<(std::ostream &os, const Edge &edge);
  };

private:
  char *name;
  int *countriesSize;
  int *numOfCountries;
  Map::Node *countries;
public:
  Map(char *);

  ~Map();

  friend std::ostream &operator<<(std::ostream &os, const Map &map);

  void addCountry(Map::Node *);

  char* getName();


};


#endif //MAPS_MAP_H
