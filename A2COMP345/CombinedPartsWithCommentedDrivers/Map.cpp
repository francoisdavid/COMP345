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

string* Edge::getOver()
{
	return over;
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

std::vector<Army*> Node::getArmies()
{
	return armies;
}

std::vector<City*> Node::getCities()
{
	return cities;
}

void Node::addCity(City* city)
{
	cities.emplace_back(city);
}

void Node::addArmy(Army* army)
{
	armies.emplace_back(army);
}

std::string* Node::getName()
{
	return name;
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
    if (std::find(edges.begin(),edges.end(), edge) == edges.end()) //edge not found in edges vector
        edges.push_back(edge);
}

void Map::validate() {
  for(auto & country : countries)
    if (country->getEdges().empty())
      std::cout << *country << " HAS NO EDGES." << std::endl;
  for (auto & edge : edges)
    if (edge->getNode1() == nullptr || edge->getNode2() == nullptr)
      std::cout << *edge << " HAS ONE OR LESS NODES." << std::endl;
  //Check that graph is connected
  if (isConnected())
    std::cout << "Graph is connected" << std::endl;
  else
    std::cout << "Graph is not connected." << std::endl;

}

void Map::traverse(Node* n, bool visited[]){
  if (this->getIndexOf(n) != -1) {
    visited[this->getIndexOf(n)] = true; //mark node as visited
    std::vector<Edge*>::const_iterator it;
    for(it = n->getEdges().begin(); it != n->getEdges().end(); it++)
      if (!visited[getIndexOf((*it)->getNode2())])  //Go through all connected nodes that are not visited yet
        traverse((*it)->getNode2(), visited);       //DFS recursively
  } else
    std::cerr << "Error trying to verify connected graph: Node not added to the graph" << std::endl;
}

bool Map::isConnected(){
  bool **visited = new bool*[this->countries.size()];
  bool allVisited = true;   //Assume all nodes will be visited, change if not
  for (int i = 0; i < this->countries.size(); ++i) {
    visited[i] = new bool[this->countries.size()];
    for (int j = 0; j < this->countries.size(); ++j)
      visited[i][j] = false;
  }   //create adjacency matrix and set it to false

  std::vector<Node*>::iterator it;
  for(it = this->countries.begin(); it != this->countries.end(); it++)
    traverse(*it, visited[getIndexOf(*it)]);    //Traverse every node of the world, recursively with DFS

  for (int i = 0; i < this->countries.size(); ++i)  //Check that every node has been visited from any other node
    for (int j = 0; j < this->countries.size(); ++j)
      if (!visited[i][j])
        allVisited = false;   //If a node has not been visited, then it is not connected graph

  for (int k = 0; k < this->countries.size(); ++k)
    delete[] visited[k];    //Clean-up dynamic array
  delete[] visited;

  return allVisited;
}

int Map::getIndexOf(Node * n) {
  auto itr = std::find(this->countries.begin(), this->countries.end(), n);
  if (itr != this->countries.cend())
    return std::distance(this->countries.begin(), itr);
  else
    return -1;
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
