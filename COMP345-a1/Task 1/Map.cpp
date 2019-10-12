#include "Map.h"

Map::Map(std::string* name) : name(name) {

}

Map::~Map() {
    for (auto & country : countries)
    delete country;
  for (auto & edge : edges)
    delete edge;
  delete name;
}

Node::Node(int id, std::string name) : name(new std::string(name)), continent(nullptr), id(new int(id)) {

}

Node::~Node() {
    if (continent != nullptr) {
        continent->removeCountry(this);
        if (continent->getNumberCountries() == 0)
            delete continent;
    }
    delete id;
    delete name;
}

void Node::setContinent(Map *continent) {
  this->continent = continent;
  this->continent->addCountry(this);
}

Edge::Edge(std::string name, Node *n1, Node *n2, std::string field) : name(new std::string(name)), node1(n1), node2(n2), over(new std::string(field)) {
  n1->addEdge(this);
  n2->addEdge(this);
}

std::ostream &operator<<(std::ostream &os, const Edge &edge) {
  os << "Edge {\n\tname: " << *edge.name << ",\n\tnode1: " << *edge.node1 << ",\n\tnode2: " << *edge.node2 << "\n}";
  return os;
}

Edge::~Edge() {
  delete name;
  delete over;
}


Node *Edge::getNode1() const {
  return node1;
}

Node *Edge::getNode2() const {
  return node2;
}

std::ostream &operator<<(std::ostream &os, const Node &node) {
  os << "Node {id: " << *node.id << ", name: " << *node.name << ", continent: "<< ((node.continent && node.continent->getName()) ? (*node.continent->getName()) : ("NULL")) << "}";
  return os;
}


void Node::addEdge(Edge * edge) {
  edges.push_back(edge);
}

const std::vector<Edge *> &Node::getEdges() const {
  return edges;
}

int *Node::getId() const {
    return id;
}

std::string * Map::getName() {
  return name;
}

std::ostream &operator<<(std::ostream &os, const Map &map) {
  os << *map.name << " map {\n";
  for (auto edge : map.edges)
      os << "\t" << *edge << ",\n";
  os << "}";
  return os;
}

void Map::addCountry(Node * country) {
  countries.push_back(country);
}

void Map::addCountry(Node *node, std::string continent) {
    auto it = find_if(continents.begin(),
            continents.end(),
            [this, continent](Map *obj) {return *obj->getName() == continent;});
    if (it != continents.end()) { // Already existing continent
        node->setContinent(*it);
    } else {
        Map* new_continent = new Map(new std::string(continent));
        continents.push_back(new_continent);
        node->setContinent(new_continent);
    }
    countries.push_back(node);
}

void Map::addEdge(Edge * edge) {
    if (std::find(edges.begin(),edges.end(), edge) == edges.end())
        edges.push_back(edge);
}

void Map::validate() {
  for(auto & country : countries)
    if (country->getEdges().empty())
      std::cout << *country << " HAS NO EDGES." << std::endl;
  for (auto & edge : edges)
    if (edge->getNode1() == nullptr || edge->getNode2() == nullptr)
      std::cout << *edge << " HAS ONE OR LESS NODES." << std::endl;
}

Node *Map::getNode(int id) {
    auto it = find_if(countries.begin(),
                      countries.end(),
                      [this, id](Node *obj) {return *obj->getId() == id;});
    if (it != countries.end())
        return *it;
    return nullptr;
}

void Map::removeCountry(Node* node) {
    countries.erase(std::find(countries.begin(), countries.end(), node));
}

int Map::getNumberCountries() {
    return countries.size();
}
