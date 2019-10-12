#ifndef COMP345_A1_MAPLOADER_H
#define COMP345_A1_MAPLOADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include "../Task 1/Map.h"

class MapLoader {
private:
    std::ifstream* mapfile;
    std::string* filepath;
    std::string* filename;
    Map* map;
    std::string extractFilename(std::string);
public:
    MapLoader(const std::string&);
    ~MapLoader();
    bool validateMap();
    bool validateNode(const std::string&);
    bool validateEdge(const std::string&);
};


#endif //COMP345_A1_MAPLOADER_H
