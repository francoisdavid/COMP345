#ifndef MapLoader_h
#define MapLoader_h

#include "Map.h"

using namespace std;

class MapLoader {
    
public:
    
    // Constructors/Destructor
    MapLoader();
    MapLoader(string);
    ~MapLoader();
    
    // Methods
    void processMap();
    
private:
    
    // Properties
    string filePath;
    
    // Methods
    static void validateFile(string);
    static void getLines(string, string, vector<string>&);
    static void processNodes(vector<string>, vector<Map>&);
    static void processEdges(vector<string>);
    static void processString(string, vector<string> &);
    static bool getEdgeType(string);
    static void processContinents(vector<string>, vector<Map>&);
};

#endif // MapLoader_h
