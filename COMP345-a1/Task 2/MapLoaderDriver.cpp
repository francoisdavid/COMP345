#include "MapLoader.h"

int main() {
    MapLoader* mapLoader = new MapLoader("../valid.map");
    mapLoader->validateMap();
    delete mapLoader;
    return 0;
}