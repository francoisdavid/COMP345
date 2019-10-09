#include <iostream>
#include "Map.h"

int main() {
  auto *france = new Map::Node("France");
  auto *england = new Map::Node("England");
  auto *canada = new Map::Node("Canada");

  auto *eng_fra = new Map::Edge("ENG/FRA", england, france);

  auto *world = new Map("The World");
  auto *europe = new Map("Europe");
  france->setContinent(europe);
  england->setContinent(europe);
  world->addCountry(france);
  world->addCountry(canada);
  world->addCountry(england);

  std::cout << *eng_fra << std::endl;
  std::cout << *world << std::endl;
  delete world;
  delete eng_fra;
  return 0;
}