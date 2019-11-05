#include <iostream>
#include "Map.h"

int main() {
    Map* world = new Map(new std::string("The World"));
    auto* node1 = new Node(1, "node1");
    auto* node2 = new Node(2, "node2");
    auto* node3 = new Node(3, "node3");
    auto* node4 = new Node(4, "node4");
    auto* node5 = new Node(5, "node5");

    auto* edge1_2 = new Edge("Edge1_2", node1, node2, "land");
    auto* edge2_3 = new Edge("Edge2_3", node2, node3, "water");
    auto* edge5_1 = new Edge("Edge5_1", node5, node1, "land");
    auto* edge1_5 = new Edge("Edge1_5", node1, node5, "water");
    auto* edge3_1 = new Edge("Edge3_1", node3, node1, "land");
    auto* edge5_3 = new Edge("Edge5_3", node5, node3, "water");
    auto* edge1_4 = new Edge("Edge1_4", node1, node4, "water");
    auto* edge4_5 = new Edge("Edge4_5", node4, node5, "water");//comment this for non-connected graph

    world->addCountry(node1, "Europe");
    world->addCountry(node2, "Europe");
    world->addCountry(node3, "Africa");
    world->addCountry(node4, "Africa");
    world->addCountry(node5);

    world->addEdge(edge1_2);
    world->addEdge(edge2_3);
    world->addEdge(edge3_1);
    world->addEdge(edge1_5);
    world->addEdge(edge5_3);
    world->addEdge(edge1_4);
    world->addEdge(edge5_1);
    world->addEdge(edge4_5);//comment this for non-connected graph


    world->validate();

    delete world;
    return 0;
}