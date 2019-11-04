#ifndef MAPS_MAP_H
#define MAPS_MAP_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Army.h"
#include "City.h"

class Map;
class Edge;
class Node;
class City;

class Map {
private:
  std::string *name;
  std::vector<Node*> countries;
  std::vector<Edge*> edges;
  std::vector<Map*> continents;
public:
  Map(std::string*);
  ~Map();

  friend std::ostream &operator<<(std::ostream &os, const Map &map);

  void addCountry(Node *);

  void addCountry(Node *node, std::string continent);

  void addEdge(Edge*);

  std::string *getName();

  void validate();

  Node* getNode(int id);

  int getIndexOf(Node*);

  void traverse(Node*, bool[]);

  bool isConnected();

  void removeCountry(Node*);

  int getNumberCountries();
};

class Node {
private:
  std::string *name;
  int* id;
  Map *continent;
  std::vector<Edge*> edges;
  std::vector<Army*> armies;
  std::vector<City*> cities;

public:
  Node(int id, std::string);
  ~Node();

  std::string* getName();
  int *getId() const;
  void setContinent(Map *);
  void addEdge(Edge*);

  const std::vector<Edge *> &getEdges() const;

  std::vector<Army*> getArmies();
  std::vector<City*> getCities();


  friend std::ostream &operator<<(std::ostream &os, const Node &node);
};

class Edge {
private:
  std::string *name;
  std::string* over;
  Node *node1;
  Node *node2;
public:
  Edge(std::string, Node *, Node *, std::string);
  ~Edge();
  Node *getNode1() const;
  Node *getNode2() const;
  friend std::ostream &operator<<(std::ostream &os, const Edge &edge);
};

#endif //MAPS_MAP_H
