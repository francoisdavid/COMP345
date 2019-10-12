#ifndef MAPS_MAP_H
#define MAPS_MAP_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Map;
class Edge;
class Node;

class Map {
private:
  std::string *name;
  std::vector<Node*> countries;
  std::vector<Edge*> edges;
  std::vector<Map*> continents;
public:
  Map();
  Map(std::string*);
  ~Map();

  friend std::ostream &operator<<(std::ostream &os, const Map &map);

  void addCountry(Node *);

  void addContinent(Map*);

  void addEdge(Edge*);

  std::string *getName();

  void setContinent(Node *, Map * continent);

  void validate();
};

class Node {
private:
  std::string *name;
  Map *continent;
  std::vector<Edge*> edges;
public:
  Node();
  Node(std::string*);

  ~Node();

  std::string* getName();

  void setContinent(Map *);
  void addEdge(Edge*);

  const std::vector<Edge *> &getEdges() const;


  friend std::ostream &operator<<(std::ostream &os, const Node &node);
};

class Edge {
private:
  std::string *name;
  bool* field;
  Node *node1;
  Node *node2;
public:
  Edge();
  Edge(std::string *, Node *, Node *, bool*);
  ~Edge();
  Node *getNode1() const;
  Node *getNode2() const;
  friend std::ostream &operator<<(std::ostream &os, const Edge &edge);
};

#endif //Map.h
