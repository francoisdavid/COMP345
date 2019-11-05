# cmake_minimum_required(VERSION <specify CMake version here>)
project(A2COMP345)

set(CMAKE_CXX_STANDARD 14)

AUX_SOURCE_DIRECTORY(Part1-2 A2)

add_executable(Maps "Part1-2/Map.cpp" "Part1-2/Map.h" "Part1-2/MapDriver.cpp" "Part1-2/Army.h" "Part1-2/City.h")
add_executable(MapLoader "Part1-2/MapLoader.cpp" "Part1-2/MapLoader.h" "Part1-2/Map.cpp" "Part1-2/Map.h")
add_executable(Player "Part1-2/Player.cpp" "Part1-2/Player.h")
add_executable(Cards_Deck "Part1-2/Cards.cpp" "Part1-2/Cards.h" Part1-2/Part5Driver.cpp "Part1-2/BidingFacility.cpp" "Part1-2/BidingFacility.h" "Part1-2/Player.cpp" "Part1-2/Player.h" "Part1-2/Army.h" "Part1-2/Army.cpp" "Part1-2/BidingFacility.cpp" "Part1-2/BidingFacility.h" "Part1-2/City.h" "Part1-2/City.cpp")
list(REMOVE_ITEM A2 "Part1-2/MapDriver.cpp")
add_executable(Part5 ${A2})
add_executable(DemoConnectedGraph "Part1-2/Map.h" "Part1-2/Map.cpp" "Part1-2/MapDriver.cpp")