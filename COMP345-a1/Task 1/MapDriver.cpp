#include <iostream>
#include "Map.h"

int main() {
  Map* world = new Map(new std::string("The World"));
  Map* europe = new Map(new std::string("Europe"));
  Map* africa = new Map(new std::string("Africa"));
  auto* node1 = new Node(new std::string("node1"));
  auto* node2 = new Node(new std::string("node2"));
  auto* node3 = new Node(new std::string("node3"));
  auto* node4 = new Node(new std::string("node4"));
  auto* node5 = new Node(new std::string("node5"));

  auto* edge1_2 = new Edge(new std::string("Edge1_2"), node1, node2, new bool(true));
  auto* edge2_3 = new Edge(new std::string("Edge2_3"), node2, node3, new bool(true));
  auto* edge5_1 = new Edge(new std::string("Edge5_1"), node5, node1, new bool(true));
  auto* edge1_5 = new Edge(new std::string("Edge1_5"), node1, node5, new bool(true));
  auto* edge3_1 = new Edge(new std::string("Edge3_1"), node3, node1, new bool(true));
  auto* edge5_3 = new Edge(new std::string("Edge5_3"), node5, node3, new bool(true));
  auto* edge1_4 = new Edge(new std::string("Edge1_4"), node1, node4, new bool(true));

  world->addCountry(node1);
  world->addCountry(node2);
  world->addCountry(node3);
  world->addCountry(node4);
  world->addCountry(node5);

  world->setContinent(node1, europe);
  world->setContinent(node2, europe);
  world->setContinent(node3, africa);
  world->setContinent(node4, africa);
  world->setContinent(node5, europe);

  world->addEdge(edge1_2);
  world->addEdge(edge2_3);
  world->addEdge(edge3_1);
  world->addEdge(edge1_5);
  world->addEdge(edge5_3);
  world->addEdge(edge1_4);
  world->addEdge(edge5_1);
  auto* BG = new Node((new std::string("Bulgaria")));


  world->validate();

//  std::cout << *node1 << std::endl;
//  std::cout << *europe << std::endl;
//  std::cout << *europe << std::endl;

//  delete world;
//  delete europe;
//  delete africa;
//  delete node1;
//  delete node2;
//  delete node2;
//  delete node3;
//  delete node4;
//  delete node5;
//  delete edge1_2;
//  delete edge2_3;
//  delete edge1_5;
//  delete edge3_1;
//  delete edge5_3;
//  delete edge1_4;
  return 0;
}