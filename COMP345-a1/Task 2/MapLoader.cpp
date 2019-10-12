#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <array>
#include "MapLoader.h"

using namespace std;

// Constructor
MapLoader::MapLoader(string path)
{
    filePath = path;
    graph = new Map(new std::string("graph"));

}

// Destructor
MapLoader::~MapLoader()
{
    delete graph;
}

// Read file and parse map data
void MapLoader::processMap()
{
    validateFile(filePath);
    
    cout << endl << "Reading from " << filePath << endl;
    vector<string> nodeLines;
    vector<string> edgeLines;
    vector<Map*> maps;
    vector<Edge*> edges;
 
    getLines(filePath, "node", nodeLines);
    getLines(filePath, "edge", edgeLines);
    
    processContinents(nodeLines, maps);
    processNodes(nodeLines, maps);
    processEdges(edgeLines);
    
    cout << "Map validation ..." << endl;
    graph->validate();
}

// Determines whether the file has the accepted .map extension
void MapLoader::validateFile(string filePath) {
  try {
    cout << "Validating file...";
    ifstream f(filePath.c_str());

    if (f.good()) {
      if (!(filePath.substr(filePath.find_last_of(".")) == ".map")) {
        throw invalid_argument("File extension must be of type .map.");
      } else {
        cout << "File OK." << endl;
      }
    } else {
      throw invalid_argument("File does not exist.");
    }
  } catch (invalid_argument& e) {
    std::cerr << e.what() << std::endl;
  }
}

// Extract the concerned lines associated with entity type
void MapLoader::getLines(string filePath, string entityType, vector<string> &lines) {
    ifstream file;
    file.open(filePath);
    string line;
    
    while (getline(file, line)) {
        // Ignore lines that do not concern entity type as well as empty lines at the same time
        if (line.find(entityType) != std::string::npos) {
            lines.push_back(line);
        }
    }
    
    file.close();
}

// Extracts distinct values of continents and feeds into maps vector
void MapLoader::processContinents(vector<string> nodeLines, vector<Map*> &maps) {
  try{
    vector<string> continents;
    
    // Collect all values of continents
    for (int i = 0; i < nodeLines.size(); i++) {
        vector<string> tokens;
        processString(nodeLines[i], tokens);
        
        // Should expect vector of 3 tokens formatted as e.g. "node,id,name,continent"
        if (!(tokens.size() == 4))
            throw invalid_argument("Invalid format detected in map file.");
        
        continents.push_back(tokens.at(3));
    }
    
    // Distinct values
    sort(continents.begin(), continents.end());
    vector<string>::iterator it;
    it = unique(continents.begin(), continents.end());
    continents.resize(distance(continents.begin(),it));
    
    cout << endl << "Continents: " << endl;
    
    // Instantiate vector of continent maps
    for (int i = 0; i < continents.size(); i++) {
        Map *a = new Map(new std::string(continents[i]));
        maps.push_back(a);
        cout << continents[i] << endl;
    }
  } catch (invalid_argument& e) {
    std::cerr << e.what() << std::endl;
  }

}

// Reads Node properties from string and constructs Node object
void MapLoader::processNodes(vector<string> nodeLines, vector<Map*> &maps) {
  try {
    cout << endl << "Countries: " << endl;
    for (int i = 0; i < nodeLines.size(); i++) {
      // Split string into tokens by comma delimiter
      vector<string> tokens;
      processString(nodeLines[i], tokens);

      // Should expect vector of 4 tokens formatted as e.g. "node,id,name,continent"
      if (!(tokens.size() == 4))
        throw invalid_argument("Invalid format detected in map file.");

      // Add node to map
      Node *node = new Node(stoi(tokens.at(1)), tokens.at(2));

      // Set continent for node
      for (int i = 0; i < maps.size(); i++) {
        if (*maps[i]->getName() == tokens.at(3)) {
          graph->addCountry(node, *maps[i]->getName());
          cout << *node << endl;
        }
      }
    }
  } catch (invalid_argument& e) {
    std::cerr << e.what() << std::endl;
  }
}

// Reads Edge properties from string and constructs Edge object
void MapLoader::processEdges(vector<string> edgeLines) {
  try {
    cout << endl << "Edges: " << endl;

    for (int i = 0; i < edgeLines.size(); i++) {
      // Split string into tokens by comma delimiter
      vector<string> tokens;
      processString(edgeLines[i], tokens);

      // Should expect vector of 4 tokens formatted as e.g. "edge,source,destination,type"
      if (tokens.size() != 4)
        throw invalid_argument("Invalid format for edge detected in map file.");

      // Add edge to map

      Node *source = graph->getNode((stoi(tokens.at(1))));
      Node *destination = graph->getNode((stoi(tokens.at(2))));

      if (source == nullptr || destination == nullptr)
        throw invalid_argument("One of the nodes being referenced in the edges does not exist.");

      Edge *edge = new Edge(tokens.at(1) + "_" + tokens.at(2),
                            source, destination,
                            tokens.at(3));
      graph->addEdge(edge);

      // Display edge
      cout << *edge << endl << endl;
    }
  } catch (invalid_argument& e) {
    std::cerr << e.what() << std::endl;
  }
}

// Splits string by delimiter into tokens
void MapLoader::processString(string line, vector<string> &tokens) {
   char str[line.length() + 1];
    
   for (int j = 0; j < sizeof(str); j++) {
        str[j] = line[j];
    }
    
    char * pch;
    pch = strtok(str,",");
    
    while (pch != NULL)
    {
        tokens.push_back(pch);
        pch = strtok(NULL, ",");
    }
}

