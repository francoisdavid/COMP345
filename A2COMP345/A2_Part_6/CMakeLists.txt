cmake_minimum_required(VERSION 3.15)
project(Part1_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Part1_2
        Maps/another_working_example.map
        Maps/bad_file_extension.map.txt
        Maps/bad_format_edges.map
        Maps/bad_format_nodes.map
        Maps/MAP1.map
        Maps/Map_expected_format_invalid.map
        Maps/Map_expected_format_valid.map
        Maps/not_referenced_node.map
        Maps/Untitled.txt
        Army.cpp
        Army.h
        BidingFacility.cpp
        BidingFacility.h
        Cards.cpp
        Cards.h
        City.cpp
        City.h
        Part12Driver.cpp
        Map.cpp
        Map.h
        MapLoader.cpp
        MapLoader.h
        Part5Driver.cpp
        Player.cpp
        Player.h)
