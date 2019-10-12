#ifndef MapLoader_h
#define MapLoader_h

#include "../Task 1/Map.h"

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
    Map* graph;
    
    // Methods
    void validateFile(string);
    void getLines(string, string, vector<string>&);
    void processNodes(vector<string>, vector<Map*>&);
    void processEdges(vector<string>);
    void processString(string, vector<string> &);
    void processContinents(vector<string>, vector<Map*>&);
};

#endif // MapLoader_h
