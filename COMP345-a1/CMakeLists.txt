# cmake_minimum_required(VERSION <specify CMake version here>)
project(COMP345-a1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Maps "Task 1/MapDriver.cpp" "Task 1/Map.cpp" "Task 1/Map.h")
add_executable(Cards_Deck "Task 4/cardsDriver.cpp" "Task 4/Cards.cpp" "Task 4/Cards.hpp")