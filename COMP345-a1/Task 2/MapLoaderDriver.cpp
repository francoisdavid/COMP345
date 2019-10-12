#include <iostream>
#include "MapLoader.h"

using namespace std;

int main() {
    // Valid map file with valid graph
    string filePath = "/Users/Wilson/Desktop/MapLoader/MapLoader/MapLoader/Maps/Map_expected_format_valid.map";
    
    // Valid map file with invalid graph
    //string filePath = "/Users/Wilson/Desktop/MapLoader/MapLoader/MapLoader/Maps/Map_expected_format_invalid.map";
    
    // Valid map file with physical country name and valid graph
    //string filePath = "/Users/Wilson/Desktop/MapLoader/MapLoader/MapLoader/Maps/another_working_example.map";
    
    // Invalid map file with non-existing node referenced in edge
    //string filePath = "/Users/Wilson/Desktop/MapLoader/MapLoader/MapLoader/Maps/not_referenced_node.map";
    
    // File with wrong extension exception
    //string filePath = "/Users/Wilson/Desktop/MapLoader/MapLoader/MapLoader/Maps/bad_file_extension.map.txt";
    
    // File does not exist exception
    //string filePath = "/Users/Wilson/Desktop/MapLoader/MapLoader/MapLoader/Maps/bad_file_extension.map";
    
    // Bad formatting exception nodes
    //string filePath = "/Users/Wilson/Desktop/MapLoader/MapLoader/MapLoader/Maps/bad_format_nodes.map";
    
    // Bad formatting exception nodes
    //string filePath = "/Users/Wilson/Desktop/MapLoader/MapLoader/MapLoader/Maps/bad_format_edges.map";
    
    MapLoader *mapLoader = new MapLoader(filePath);
    mapLoader->processMap();
    
    return 0;
}
