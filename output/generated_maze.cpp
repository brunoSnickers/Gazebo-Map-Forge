#include <iostream>
#include <list>
#include "maze_generator.h"

void MazeGenerator::generateMaze()
{
    Mazepolygon poly1;
    poly1.coordinates.push_back({2.00f, 1.00f});
    poly1.coordinates.push_back({2.00f, 1.40f});
    poly1.coordinates.push_back({1.60f, 1.40f});
    poly1.coordinates.push_back({1.60f, 2.00f});
    poly1.coordinates.push_back({1.00f, 2.00f});
    poly1.coordinates.push_back({1.00f, 1.00f});
    polygons.push_back(poly1);

    std::cout << "Maze generated!" << std::endl;
}
