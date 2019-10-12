#include "MapLoader.h"

MapLoader::MapLoader(const std::string& filepath) {
    this->filepath = new std::string(filepath);
    this->filename = new std::string(extractFilename(*this->filepath));
    mapfile = new std::ifstream();
    mapfile->open(filepath);
    if (!mapfile->is_open())
        std::cout << "Unable to open file";
    map = new Map(this->filename);
}

MapLoader::~MapLoader() {
    if (mapfile->is_open())
        mapfile->close();
    delete mapfile;
    delete filename;
    delete filepath;
    delete map;
}

bool MapLoader::validateMap() {
    std::string line;
    std::regex start_nodes("^start.*nodes$");
    std::regex start_edges("^start.*edges$");
    std::regex end_group("^end$");
    bool nodes = false, edges = false;
    while ( std::getline (*mapfile, line) )
    {
        if (line.empty())
            continue;
        else if (std::regex_match(line, end_group)) {
            edges = false;
            nodes = false;
        } else if (nodes) {
            if (!validateNode(line))
                return false;
        }
        else if (std::regex_match(line, start_nodes))
            nodes = true;
        else if (edges) {
            if (!validateEdge(line))
                return false;
        }
        else if (std::regex_match(line, start_edges))
            edges = true;
    }
    return true;
}

bool MapLoader::validateNode(const std::string& nodeLine) {
    try {
        std::regex regex_node("^([0-9]+), (.*), (.*)$");
        std::smatch matches;
        if (std::regex_match(nodeLine, matches, regex_node))
            map->addContinent(matches[3].str(), new Node(std::stoi(matches[1].str()), matches[2].str()));
    } catch (...) {
        return false;
    }
    return true;
}

bool MapLoader::validateEdge(const std::string& edgeLine) {
    try {
        std::regex regex_node("^([0-9]+),([0-9]+),(.*)$");
        std::smatch matches;
        if (std::regex_match(edgeLine, matches, regex_node))
            map->addEdge(new Edge(new std::string("EDGE_" + matches[1].str() + "_" + matches[2].str()),
                    map->getNode(std::stoi(matches[1].str())),
                    map->getNode(std::stoi(matches[2].str())),
                    new std::string(matches[3].str())));
    } catch (...) {
        return false;
    }
    return true;
}

std::string MapLoader::extractFilename(std::string path) {
    // Remove directory if present.
    // Do this before extension removal incase directory has a period character.
    const size_t last_slash_idx = path.find_last_of("\\/");
    if (std::string::npos != last_slash_idx)
        path.erase(0, last_slash_idx + 1);

    // Remove extension if present.
    const size_t period_idx = path.rfind('.');
    if (std::string::npos != period_idx)
        path.erase(period_idx);
    return path;
}

