#include "Map.h"

Map::Map(char *name) : name(name) {
  countriesSize = new int(20);
  numOfCountries = new int(0);
  countries = new Map::Node[*countriesSize];
}

Map::~Map() {
  delete [] countries;
  delete countriesSize;
  delete numOfCountries;
}


Map::Node::Node(char *name) : name(name), continent(nullptr) {

}

Map::Node::~Node() {
  delete continent;
}

void Map::Node::setContinent(Map *continent) {
  this->continent = continent;
}

Map::Edge::Edge(char *name, Map::Node *n1, Map::Node *n2) : name(name), node1(n1), node2(n2) {

}


std::ostream &operator<<(std::ostream &os, const Map::Edge &edge) {
  os << "Edge {\n\tname: " << edge.name << ",\n\tnode1: " << *edge.node1 << ",\n\tnode2: " << *edge.node2 << "\n}";
  return os;
}

std::ostream &operator<<(std::ostream &os, const Map::Node &node) {
  os << "Node {name: " << node.name << ", continent: " << node.continent->getName() << "}";
  return os;
}

Map::Node::Node() {

}

char *Map::getName() {
  return name;
}


std::ostream &operator<<(std::ostream &os, const Map &map) {
  os << map.name << " map {\n";
  for (int i = 0; i < *map.numOfCountries; i++)
    os << "\t" << map.countries[i] << ",\n";
  os << "}";
  return os;
}

void Map::addCountry(Map::Node * country) {
  if (*numOfCountries == *countriesSize) {
    *countriesSize *= 2;
    Map::Node* tmp = new Map::Node[*countriesSize];
    for (int i = 0; i < *numOfCountries; i++)
      tmp[i] = countries[i];
    delete [] countries;
    countries = tmp;
  }
  countries[(*numOfCountries)++] = *country;
}
