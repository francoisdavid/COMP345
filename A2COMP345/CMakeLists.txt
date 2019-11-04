# cmake_minimum_required(VERSION <specify CMake version here>)
project(A2COMP345)

set(CMAKE_CXX_STANDARD 14)

add_executable(Maps "Part1-2/Map.cpp" "Part1-2/Map.h" "Part1-2/MapDriver.cpp" "Part1-2/Army.h" "Part1-2/City.h")
add_executable(MapLoader "Part1-2/MapLoader.cpp" "Part1-2/MapLoader.h" "Part1-2/Map.cpp" "Part1-2/Map.h")
add_executable(Player "Part1-2/Player.cpp" "Part1-2/Player.h")
add_executable(Cards_Deck "Part1-2/Cards.cpp" "Part1-2/Cards.h")
add_executable(Biding_Facility "Part1-2/BidingFacility.cpp" "Part1-2/BidingFacility.h")