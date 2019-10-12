#include "Map.h"

Map::Map(std::string* name) : name(name) {
}

Map::~Map() {
//  for (auto & country : countries)
//    delete country;
//  for (auto & continent : continents)
//    delete continent;
//  for (auto & edge : edges)
//    delete edge;
//  delete name;
}

Node::Node(std::string* name) : name(name), continent(nullptr) {

}

Node::~Node() {
}

<<<<<<< HEAD
=======
std::string* Node::getName()
{
	return name;
}

>>>>>>> 79a969af53687e698b7011da35a12c5acd0112d5
void Node::setContinent(Map *continent) {
  this->continent = continent;

}

Edge::Edge(std::string *name, Node *n1, Node *n2, bool* field) : name(name), node1(n1), node2(n2), field(field) {
  n1->addEdge(this);
  n2->addEdge(this);
}

std::ostream &operator<<(std::ostream &os, const Edge &edge) {
  os << "Edge {\n\tname: " << *edge.name << ",\n\tnode1: " << *edge.node1 << ",\n\tnode2: " << *edge.node2 << "\n}";
  return os;
}

Edge::~Edge() {
  delete name;
  delete node1;
  delete node2;
  delete field;
}

Edge::Edge() {
  node1 = nullptr;
  node2 = nullptr;
}

Node *Edge::getNode1() const {
  return node1;
}

Node *Edge::getNode2() const {
  return node2;
}

std::ostream &operator<<(std::ostream &os, const Node &node) {
  os << "Node {name: " << *node.name << ", continent: "<< ((node.continent && node.continent->getName()) ? (*node.continent->getName()) : ("NULL")) << "}";
  return os;
}

Node::Node() {

}


void Node::addEdge(Edge * edge) {
  edges.push_back(edge);
}

const std::vector<Edge *> &Node::getEdges() const {
  return edges;
}

std::string * Map::getName() {
  return name;
}

std::ostream &operator<<(std::ostream &os, const Map &map) {
  os << *map.name << " map {\n";
  for (int i = 0; i < map.countries.size(); i++)
    os << "\t" << map.countries[i] << ",\n";
  os << "}";
  return os;
}

void Map::addCountry(Node * country) {
  countries.push_back(country);
}

void Map::addContinent(Map * continent) {
  continents.push_back(continent);
}

void Map::addEdge(Edge * edge) {
  edges.push_back(edge);
}

void Map::setContinent(Node * node, Map * continent){
  if(std::find(continents.begin(), continents.end(), continent) == continents.end())
    continents.push_back(continent);
  node->setContinent(continent);
}

void Map::validate() {
  for(auto & country : countries)
    if (country->getEdges().empty())
      std::cout << *country << "HAS NO EDGES." << std::endl;
  for (auto & edge : edges)
    if (edge->getNode1() == nullptr || edge->getNode2() == nullptr)
      std::cout << *edge << "HAS ONE OR LESS NODES." << std::endl;
}