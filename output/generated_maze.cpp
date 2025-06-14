// Automatisch generiert aus ASCII-Karte

#include <iostream>
#include <list>
#include "maze_generator.h"
void MazeGenerator::generateMaze() {

// poly0
Mazepolygon poly0;
    poly0.coordinates.push_back({0.10f, 0.90f});
    poly0.coordinates.push_back({0.90f, 0.90f});
    poly0.coordinates.push_back({0.90f, 0.10f});
    poly0.coordinates.push_back({0.10f, 0.10f});
    poly0.coordinates.push_back({0.10f, 0.90f});
polygons.push_back(poly0);

// poly1
Mazepolygon poly1;
    poly1.coordinates.push_back({1.10f, 0.90f});
    poly1.coordinates.push_back({1.90f, 0.90f});
    poly1.coordinates.push_back({1.90f, 0.10f});
    poly1.coordinates.push_back({1.10f, 0.10f});
    poly1.coordinates.push_back({1.10f, 0.90f});
polygons.push_back(poly1);

// poly2
Mazepolygon poly2;
    poly2.coordinates.push_back({0.10f, 1.90f});
    poly2.coordinates.push_back({0.90f, 1.90f});
    poly2.coordinates.push_back({0.90f, 1.10f});
    poly2.coordinates.push_back({0.10f, 1.10f});
    poly2.coordinates.push_back({0.10f, 1.90f});
polygons.push_back(poly2);

// poly3
Mazepolygon poly3;
    poly3.coordinates.push_back({1.10f, 1.90f});
    poly3.coordinates.push_back({1.90f, 1.90f});
    poly3.coordinates.push_back({1.90f, 1.10f});
    poly3.coordinates.push_back({1.10f, 1.10f});
    poly3.coordinates.push_back({1.10f, 1.90f});
polygons.push_back(poly3);

std::cout << "Maze generated!" << std::endl;

}
