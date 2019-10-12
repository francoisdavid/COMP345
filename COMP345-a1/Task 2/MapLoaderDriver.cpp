#include <iostream>
#include "MapLoader.h"

using namespace std;

int main() {
    // Valid map file with valid graph
    string filePath = "../Task 2/Maps/Map_expected_format_valid.map";
    MapLoader *mapLoader = new MapLoader(filePath);
    mapLoader->processMap();
    delete mapLoader;

    // Valid map file with invalid graph
    filePath = "../Task 2/Maps/Map_expected_format_invalid.map";
    mapLoader = new MapLoader(filePath);
    mapLoader->processMap();
    delete mapLoader;

    // Valid map file with physical country name and valid graph
    filePath = "../Task 2/Maps/another_working_example.map";
    mapLoader = new MapLoader(filePath);
    mapLoader->processMap();
    delete mapLoader;

    // Invalid map file with non-existing node referenced in edge
    filePath = "../Task 2/Maps/not_referenced_node.map";
    mapLoader = new MapLoader(filePath);
    mapLoader->processMap();
    delete mapLoader;

    // File with wrong extension exception
    filePath = "../Task 2/Maps/bad_file_extension.map.txt";
    mapLoader = new MapLoader(filePath);
    mapLoader->processMap();
    delete mapLoader;

    // File does not exist exception
    filePath = "../Task 2/Maps/bad_file_extension.map";
    mapLoader = new MapLoader(filePath);
    mapLoader->processMap();
    delete mapLoader;

    // Bad formatting exception nodes
    filePath = "../Task 2/Maps/bad_format_nodes.map";
    mapLoader = new MapLoader(filePath);
    mapLoader->processMap();
    delete mapLoader;

    // Bad formatting exception nodes
    filePath = "../Task 2/Maps/bad_format_edges.map";
    mapLoader = new MapLoader(filePath);
    mapLoader->processMap();
    delete mapLoader;

    return 0;
}
