#include <iostream>
#include <list>
#include "maze_generator.h"

void MazeGenerator::generateMaze()
{
    // --- Stra�enpolygone ---
    // road0
    Mazepolygon road0;
        road0.coordinates.push_back({1.00f, 3.15f});
        road0.coordinates.push_back({0.15f, 3.15f});
        road0.coordinates.push_back({0.15f, 4.00f});
        road0.coordinates.push_back({0.15f, 5.00f});
        road0.coordinates.push_back({0.15f, 6.00f});
        road0.coordinates.push_back({0.15f, 7.00f});
        road0.coordinates.push_back({0.15f, 8.00f});
        road0.coordinates.push_back({0.15f, 9.00f});
        road0.coordinates.push_back({0.15f, 9.85f});
        road0.coordinates.push_back({1.00f, 9.85f});
        road0.coordinates.push_back({2.00f, 9.85f});
        road0.coordinates.push_back({3.00f, 9.85f});
        road0.coordinates.push_back({4.00f, 9.85f});
        road0.coordinates.push_back({5.00f, 9.85f});
        road0.coordinates.push_back({6.00f, 9.85f});
        road0.coordinates.push_back({7.00f, 9.85f});
        road0.coordinates.push_back({8.00f, 9.85f});
        road0.coordinates.push_back({8.85f, 9.85f});
        road0.coordinates.push_back({8.85f, 9.00f});
        road0.coordinates.push_back({8.85f, 8.00f});
        road0.coordinates.push_back({8.85f, 7.00f});
        road0.coordinates.push_back({8.85f, 6.15f});
        road0.coordinates.push_back({8.00f, 6.15f});
        road0.coordinates.push_back({7.00f, 6.15f});
        road0.coordinates.push_back({6.00f, 6.15f});
        road0.coordinates.push_back({5.00f, 6.15f});
        road0.coordinates.push_back({4.00f, 6.15f});
        road0.coordinates.push_back({3.85f, 6.15f});
        road0.coordinates.push_back({3.85f, 6.00f});
        road0.coordinates.push_back({3.85f, 5.00f});
        road0.coordinates.push_back({3.85f, 4.85f});
        road0.coordinates.push_back({4.00f, 4.85f});
        road0.coordinates.push_back({5.00f, 4.85f});
        road0.coordinates.push_back({5.85f, 4.85f});
        road0.coordinates.push_back({5.85f, 4.00f});
        road0.coordinates.push_back({5.85f, 3.00f});
        road0.coordinates.push_back({5.85f, 2.00f});
        road0.coordinates.push_back({5.85f, 1.85f});
        road0.coordinates.push_back({6.00f, 1.85f});
        road0.coordinates.push_back({7.00f, 1.85f});
        road0.coordinates.push_back({7.15f, 1.85f});
        road0.coordinates.push_back({7.15f, 2.00f});
        road0.coordinates.push_back({7.15f, 3.00f});
        road0.coordinates.push_back({7.15f, 4.00f});
        road0.coordinates.push_back({7.15f, 4.85f});
        road0.coordinates.push_back({8.00f, 4.85f});
        road0.coordinates.push_back({9.00f, 4.85f});
        road0.coordinates.push_back({9.85f, 4.85f});
        road0.coordinates.push_back({9.85f, 4.00f});
        road0.coordinates.push_back({9.85f, 3.00f});
        road0.coordinates.push_back({9.85f, 2.00f});
        road0.coordinates.push_back({9.85f, 1.15f});
        road0.coordinates.push_back({9.00f, 1.15f});
        road0.coordinates.push_back({8.00f, 1.15f});
        road0.coordinates.push_back({7.00f, 1.15f});
        road0.coordinates.push_back({6.00f, 1.15f});
        road0.coordinates.push_back({5.00f, 1.15f});
        road0.coordinates.push_back({4.00f, 1.15f});
        road0.coordinates.push_back({3.00f, 1.15f});
        road0.coordinates.push_back({2.00f, 1.15f});
        road0.coordinates.push_back({1.15f, 1.15f});
        road0.coordinates.push_back({1.15f, 2.00f});
        road0.coordinates.push_back({1.15f, 3.00f});
        road0.coordinates.push_back({1.15f, 3.15f});
    polygons.push_back(road0);

    // --- L�cher (Innenfl�chen) ---
    // hole0
    Mazepolygon hole0;
        hole0.coordinates.push_back({3.85f, 9.15f});
        hole0.coordinates.push_back({3.85f, 9.00f});
        hole0.coordinates.push_back({3.85f, 8.00f});
        hole0.coordinates.push_back({3.85f, 7.00f});
        hole0.coordinates.push_back({3.85f, 6.85f});
        hole0.coordinates.push_back({4.00f, 6.85f});
        hole0.coordinates.push_back({5.00f, 6.85f});
        hole0.coordinates.push_back({6.00f, 6.85f});
        hole0.coordinates.push_back({6.15f, 6.85f});
        hole0.coordinates.push_back({6.15f, 7.00f});
        hole0.coordinates.push_back({6.15f, 8.00f});
        hole0.coordinates.push_back({6.15f, 9.00f});
        hole0.coordinates.push_back({6.15f, 9.15f});
        hole0.coordinates.push_back({6.00f, 9.15f});
        hole0.coordinates.push_back({5.00f, 9.15f});
        hole0.coordinates.push_back({4.00f, 9.15f});
    polygons.push_back(hole0);

    // hole1
    Mazepolygon hole1;
        hole1.coordinates.push_back({3.15f, 9.15f});
        hole1.coordinates.push_back({3.00f, 9.15f});
        hole1.coordinates.push_back({2.00f, 9.15f});
        hole1.coordinates.push_back({1.00f, 9.15f});
        hole1.coordinates.push_back({0.85f, 9.15f});
        hole1.coordinates.push_back({0.85f, 9.00f});
        hole1.coordinates.push_back({0.85f, 8.00f});
        hole1.coordinates.push_back({0.85f, 7.00f});
        hole1.coordinates.push_back({0.85f, 6.85f});
        hole1.coordinates.push_back({1.00f, 6.85f});
        hole1.coordinates.push_back({2.00f, 6.85f});
        hole1.coordinates.push_back({3.00f, 6.85f});
        hole1.coordinates.push_back({3.15f, 6.85f});
        hole1.coordinates.push_back({3.15f, 7.00f});
        hole1.coordinates.push_back({3.15f, 8.00f});
        hole1.coordinates.push_back({3.15f, 9.00f});
    polygons.push_back(hole1);

    // hole2
    Mazepolygon hole2;
        hole2.coordinates.push_back({2.00f, 6.15f});
        hole2.coordinates.push_back({1.00f, 6.15f});
        hole2.coordinates.push_back({0.85f, 6.15f});
        hole2.coordinates.push_back({0.85f, 6.00f});
        hole2.coordinates.push_back({0.85f, 5.00f});
        hole2.coordinates.push_back({0.85f, 4.00f});
        hole2.coordinates.push_back({0.85f, 3.85f});
        hole2.coordinates.push_back({1.00f, 3.85f});
        hole2.coordinates.push_back({2.00f, 3.85f});
        hole2.coordinates.push_back({2.15f, 3.85f});
        hole2.coordinates.push_back({2.15f, 4.00f});
        hole2.coordinates.push_back({2.15f, 4.85f});
        hole2.coordinates.push_back({3.00f, 4.85f});
        hole2.coordinates.push_back({3.15f, 4.85f});
        hole2.coordinates.push_back({3.15f, 5.00f});
        hole2.coordinates.push_back({3.15f, 6.00f});
        hole2.coordinates.push_back({3.15f, 6.15f});
        hole2.coordinates.push_back({3.00f, 6.15f});
    polygons.push_back(hole2);

    // hole3
    Mazepolygon hole3;
        hole3.coordinates.push_back({2.85f, 4.00f});
        hole3.coordinates.push_back({2.85f, 3.00f});
        hole3.coordinates.push_back({2.85f, 2.00f});
        hole3.coordinates.push_back({2.85f, 1.85f});
        hole3.coordinates.push_back({3.00f, 1.85f});
        hole3.coordinates.push_back({4.00f, 1.85f});
        hole3.coordinates.push_back({5.00f, 1.85f});
        hole3.coordinates.push_back({5.15f, 1.85f});
        hole3.coordinates.push_back({5.15f, 2.00f});
        hole3.coordinates.push_back({5.15f, 3.00f});
        hole3.coordinates.push_back({5.15f, 4.00f});
        hole3.coordinates.push_back({5.15f, 4.15f});
        hole3.coordinates.push_back({5.00f, 4.15f});
        hole3.coordinates.push_back({4.00f, 4.15f});
        hole3.coordinates.push_back({3.00f, 4.15f});
        hole3.coordinates.push_back({2.85f, 4.15f});
    polygons.push_back(hole3);

    // hole4
    Mazepolygon hole4;
        hole4.coordinates.push_back({2.15f, 1.85f});
        hole4.coordinates.push_back({2.15f, 2.00f});
        hole4.coordinates.push_back({2.15f, 3.00f});
        hole4.coordinates.push_back({2.15f, 3.15f});
        hole4.coordinates.push_back({2.00f, 3.15f});
        hole4.coordinates.push_back({1.85f, 3.15f});
        hole4.coordinates.push_back({1.85f, 3.00f});
        hole4.coordinates.push_back({1.85f, 2.00f});
        hole4.coordinates.push_back({1.85f, 1.85f});
        hole4.coordinates.push_back({2.00f, 1.85f});
    polygons.push_back(hole4);

    // hole5
    Mazepolygon hole5;
        hole5.coordinates.push_back({6.85f, 6.85f});
        hole5.coordinates.push_back({7.00f, 6.85f});
        hole5.coordinates.push_back({8.00f, 6.85f});
        hole5.coordinates.push_back({8.15f, 6.85f});
        hole5.coordinates.push_back({8.15f, 7.00f});
        hole5.coordinates.push_back({8.15f, 8.00f});
        hole5.coordinates.push_back({8.15f, 9.00f});
        hole5.coordinates.push_back({8.15f, 9.15f});
        hole5.coordinates.push_back({8.00f, 9.15f});
        hole5.coordinates.push_back({7.00f, 9.15f});
        hole5.coordinates.push_back({6.85f, 9.15f});
        hole5.coordinates.push_back({6.85f, 9.00f});
        hole5.coordinates.push_back({6.85f, 8.00f});
        hole5.coordinates.push_back({6.85f, 7.00f});
    polygons.push_back(hole5);

    // hole6
    Mazepolygon hole6;
        hole6.coordinates.push_back({8.00f, 1.85f});
        hole6.coordinates.push_back({9.00f, 1.85f});
        hole6.coordinates.push_back({9.15f, 1.85f});
        hole6.coordinates.push_back({9.15f, 2.00f});
        hole6.coordinates.push_back({9.15f, 3.00f});
        hole6.coordinates.push_back({9.15f, 4.00f});
        hole6.coordinates.push_back({9.15f, 4.15f});
        hole6.coordinates.push_back({9.00f, 4.15f});
        hole6.coordinates.push_back({8.00f, 4.15f});
        hole6.coordinates.push_back({7.85f, 4.15f});
        hole6.coordinates.push_back({7.85f, 4.00f});
        hole6.coordinates.push_back({7.85f, 3.00f});
        hole6.coordinates.push_back({7.85f, 2.00f});
        hole6.coordinates.push_back({7.85f, 1.85f});
    polygons.push_back(hole6);

    std::cout << "Maze generated!" << std::endl;
}
