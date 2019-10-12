# cmake_minimum_required(VERSION <specify CMake version here>)
project(COMP345-a1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Maps "Task 1/MapDriver.cpp" "Task 1/Map.cpp" "Task 1/Map.h")
add_executable(MapLoader "Task 2/MapLoaderDriver.cpp" "Task 2/MapLoader.cpp" "Task 2/MapLoader.h" "Task 1/Map.cpp" "Task 1/Map.h")
add_executable(Player "Task 3/PlayerDriver.cpp" "Task 3/Player.cpp" "Task 3/Player.h")
add_executable(Cards_Deck "Task 4/cardsDriver.cpp" "Task 4/Cards.cpp" "Task 4/Cards.hpp")
add_executable(Biding_Facility "Task 5/BidingFacility.cpp" "Task 5/main.cpp" "Task 5/BidingFacility.hpp")