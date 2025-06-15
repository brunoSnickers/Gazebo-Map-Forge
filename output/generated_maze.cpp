#include <iostream>
#include <list>
#include "maze_generator.h"

void MazeGenerator::generateMaze()
{
    // --- Straßenpolygone ---
    // road0
    Mazepolygon road0;
        road0.coordinates.push_back({5.00f, 1.85f});
        road0.coordinates.push_back({5.85f, 1.85f});
        road0.coordinates.push_back({5.85f, 1.00f});
        road0.coordinates.push_back({5.85f, 0.85f});
        road0.coordinates.push_back({6.00f, 0.85f});
        road0.coordinates.push_back({7.00f, 0.85f});
        road0.coordinates.push_back({7.15f, 0.85f});
        road0.coordinates.push_back({7.15f, 1.00f});
        road0.coordinates.push_back({7.15f, 1.15f});
        road0.coordinates.push_back({7.00f, 1.15f});
        road0.coordinates.push_back({6.15f, 1.15f});
        road0.coordinates.push_back({6.15f, 2.00f});
        road0.coordinates.push_back({6.15f, 2.15f});
        road0.coordinates.push_back({6.00f, 2.15f});
        road0.coordinates.push_back({5.00f, 2.15f});
        road0.coordinates.push_back({4.15f, 2.15f});
        road0.coordinates.push_back({4.15f, 3.00f});
        road0.coordinates.push_back({4.15f, 4.00f});
        road0.coordinates.push_back({4.15f, 5.00f});
        road0.coordinates.push_back({4.15f, 6.00f});
        road0.coordinates.push_back({4.15f, 7.00f});
        road0.coordinates.push_back({4.15f, 8.00f});
        road0.coordinates.push_back({4.15f, 8.85f});
        road0.coordinates.push_back({5.00f, 8.85f});
        road0.coordinates.push_back({5.85f, 8.85f});
        road0.coordinates.push_back({5.85f, 8.00f});
        road0.coordinates.push_back({5.85f, 7.85f});
        road0.coordinates.push_back({6.00f, 7.85f});
        road0.coordinates.push_back({6.85f, 7.85f});
        road0.coordinates.push_back({6.85f, 7.00f});
        road0.coordinates.push_back({6.85f, 6.85f});
        road0.coordinates.push_back({7.00f, 6.85f});
        road0.coordinates.push_back({8.00f, 6.85f});
        road0.coordinates.push_back({9.00f, 6.85f});
        road0.coordinates.push_back({9.15f, 6.85f});
        road0.coordinates.push_back({9.15f, 7.00f});
        road0.coordinates.push_back({9.15f, 8.00f});
        road0.coordinates.push_back({9.15f, 8.15f});
        road0.coordinates.push_back({9.00f, 8.15f});
        road0.coordinates.push_back({8.15f, 8.15f});
        road0.coordinates.push_back({8.15f, 9.00f});
        road0.coordinates.push_back({8.15f, 9.85f});
        road0.coordinates.push_back({9.00f, 9.85f});
        road0.coordinates.push_back({9.85f, 9.85f});
        road0.coordinates.push_back({9.85f, 9.00f});
        road0.coordinates.push_back({9.85f, 8.00f});
        road0.coordinates.push_back({9.85f, 7.00f});
        road0.coordinates.push_back({9.85f, 6.15f});
        road0.coordinates.push_back({9.00f, 6.15f});
        road0.coordinates.push_back({8.85f, 6.15f});
        road0.coordinates.push_back({8.85f, 6.00f});
        road0.coordinates.push_back({8.85f, 5.85f});
        road0.coordinates.push_back({9.00f, 5.85f});
        road0.coordinates.push_back({9.85f, 5.85f});
        road0.coordinates.push_back({9.85f, 5.00f});
        road0.coordinates.push_back({9.85f, 4.00f});
        road0.coordinates.push_back({9.85f, 3.00f});
        road0.coordinates.push_back({9.85f, 2.15f});
        road0.coordinates.push_back({9.00f, 2.15f});
        road0.coordinates.push_back({8.85f, 2.15f});
        road0.coordinates.push_back({8.85f, 2.00f});
        road0.coordinates.push_back({8.85f, 1.85f});
        road0.coordinates.push_back({9.00f, 1.85f});
        road0.coordinates.push_back({9.85f, 1.85f});
        road0.coordinates.push_back({9.85f, 1.00f});
        road0.coordinates.push_back({9.85f, 0.15f});
        road0.coordinates.push_back({9.00f, 0.15f});
        road0.coordinates.push_back({8.00f, 0.15f});
        road0.coordinates.push_back({7.00f, 0.15f});
        road0.coordinates.push_back({6.00f, 0.15f});
        road0.coordinates.push_back({5.00f, 0.15f});
        road0.coordinates.push_back({4.15f, 0.15f});
        road0.coordinates.push_back({4.15f, 1.00f});
        road0.coordinates.push_back({4.15f, 1.15f});
        road0.coordinates.push_back({4.00f, 1.15f});
        road0.coordinates.push_back({3.85f, 1.15f});
        road0.coordinates.push_back({3.85f, 1.00f});
        road0.coordinates.push_back({3.85f, 0.15f});
        road0.coordinates.push_back({3.00f, 0.15f});
        road0.coordinates.push_back({2.00f, 0.15f});
        road0.coordinates.push_back({1.15f, 0.15f});
        road0.coordinates.push_back({1.15f, 1.00f});
        road0.coordinates.push_back({1.15f, 2.00f});
        road0.coordinates.push_back({1.15f, 3.00f});
        road0.coordinates.push_back({1.15f, 4.00f});
        road0.coordinates.push_back({1.15f, 4.85f});
        road0.coordinates.push_back({2.00f, 4.85f});
        road0.coordinates.push_back({2.15f, 4.85f});
        road0.coordinates.push_back({2.15f, 5.00f});
        road0.coordinates.push_back({2.15f, 5.85f});
        road0.coordinates.push_back({3.00f, 5.85f});
        road0.coordinates.push_back({3.85f, 5.85f});
        road0.coordinates.push_back({3.85f, 5.00f});
        road0.coordinates.push_back({3.85f, 4.00f});
        road0.coordinates.push_back({3.85f, 3.00f});
        road0.coordinates.push_back({3.85f, 2.00f});
        road0.coordinates.push_back({3.85f, 1.85f});
        road0.coordinates.push_back({4.00f, 1.85f});
    polygons.push_back(road0);

    // --- Löcher (Innenflächen) ---
    // hole0
    Mazepolygon hole0;
        hole0.coordinates.push_back({4.85f, 1.00f});
        hole0.coordinates.push_back({4.85f, 0.85f});
        hole0.coordinates.push_back({5.00f, 0.85f});
        hole0.coordinates.push_back({5.15f, 0.85f});
        hole0.coordinates.push_back({5.15f, 1.00f});
        hole0.coordinates.push_back({5.15f, 1.15f});
        hole0.coordinates.push_back({5.00f, 1.15f});
        hole0.coordinates.push_back({4.85f, 1.15f});
    polygons.push_back(hole0);

    // hole1
    Mazepolygon hole1;
        hole1.coordinates.push_back({3.00f, 4.85f});
        hole1.coordinates.push_back({3.15f, 4.85f});
        hole1.coordinates.push_back({3.15f, 5.00f});
        hole1.coordinates.push_back({3.15f, 5.15f});
        hole1.coordinates.push_back({3.00f, 5.15f});
        hole1.coordinates.push_back({2.85f, 5.15f});
        hole1.coordinates.push_back({2.85f, 5.00f});
        hole1.coordinates.push_back({2.85f, 4.85f});
    polygons.push_back(hole1);

    // hole2
    Mazepolygon hole2;
        hole2.coordinates.push_back({3.00f, 0.85f});
        hole2.coordinates.push_back({3.15f, 0.85f});
        hole2.coordinates.push_back({3.15f, 1.00f});
        hole2.coordinates.push_back({3.15f, 2.00f});
        hole2.coordinates.push_back({3.15f, 3.00f});
        hole2.coordinates.push_back({3.15f, 3.15f});
        hole2.coordinates.push_back({3.00f, 3.15f});
        hole2.coordinates.push_back({2.00f, 3.15f});
        hole2.coordinates.push_back({1.85f, 3.15f});
        hole2.coordinates.push_back({1.85f, 3.00f});
        hole2.coordinates.push_back({1.85f, 2.00f});
        hole2.coordinates.push_back({1.85f, 1.85f});
        hole2.coordinates.push_back({2.00f, 1.85f});
        hole2.coordinates.push_back({2.85f, 1.85f});
        hole2.coordinates.push_back({2.85f, 1.00f});
        hole2.coordinates.push_back({2.85f, 0.85f});
    polygons.push_back(hole2);

    // hole3
    Mazepolygon hole3;
        hole3.coordinates.push_back({2.15f, 1.00f});
        hole3.coordinates.push_back({2.15f, 1.15f});
        hole3.coordinates.push_back({2.00f, 1.15f});
        hole3.coordinates.push_back({1.85f, 1.15f});
        hole3.coordinates.push_back({1.85f, 1.00f});
        hole3.coordinates.push_back({1.85f, 0.85f});
        hole3.coordinates.push_back({2.00f, 0.85f});
        hole3.coordinates.push_back({2.15f, 0.85f});
    polygons.push_back(hole3);

    // hole4
    Mazepolygon hole4;
        hole4.coordinates.push_back({3.00f, 4.15f});
        hole4.coordinates.push_back({2.85f, 4.15f});
        hole4.coordinates.push_back({2.85f, 4.00f});
        hole4.coordinates.push_back({2.85f, 3.85f});
        hole4.coordinates.push_back({3.00f, 3.85f});
        hole4.coordinates.push_back({3.15f, 3.85f});
        hole4.coordinates.push_back({3.15f, 4.00f});
        hole4.coordinates.push_back({3.15f, 4.15f});
    polygons.push_back(hole4);

    // hole5
    Mazepolygon hole5;
        hole5.coordinates.push_back({2.15f, 4.00f});
        hole5.coordinates.push_back({2.15f, 4.15f});
        hole5.coordinates.push_back({2.00f, 4.15f});
        hole5.coordinates.push_back({1.85f, 4.15f});
        hole5.coordinates.push_back({1.85f, 4.00f});
        hole5.coordinates.push_back({1.85f, 3.85f});
        hole5.coordinates.push_back({2.00f, 3.85f});
        hole5.coordinates.push_back({2.15f, 3.85f});
    polygons.push_back(hole5);

    // hole6
    Mazepolygon hole6;
        hole6.coordinates.push_back({4.85f, 4.85f});
        hole6.coordinates.push_back({5.00f, 4.85f});
        hole6.coordinates.push_back({6.00f, 4.85f});
        hole6.coordinates.push_back({6.15f, 4.85f});
        hole6.coordinates.push_back({6.15f, 5.00f});
        hole6.coordinates.push_back({6.15f, 5.15f});
        hole6.coordinates.push_back({6.00f, 5.15f});
        hole6.coordinates.push_back({5.00f, 5.15f});
        hole6.coordinates.push_back({4.85f, 5.15f});
        hole6.coordinates.push_back({4.85f, 5.00f});
    polygons.push_back(hole6);

    // hole7
    Mazepolygon hole7;
        hole7.coordinates.push_back({4.85f, 4.15f});
        hole7.coordinates.push_back({4.85f, 4.00f});
        hole7.coordinates.push_back({4.85f, 3.85f});
        hole7.coordinates.push_back({5.00f, 3.85f});
        hole7.coordinates.push_back({5.85f, 3.85f});
        hole7.coordinates.push_back({5.85f, 3.00f});
        hole7.coordinates.push_back({5.85f, 2.85f});
        hole7.coordinates.push_back({6.00f, 2.85f});
        hole7.coordinates.push_back({7.00f, 2.85f});
        hole7.coordinates.push_back({8.00f, 2.85f});
        hole7.coordinates.push_back({8.15f, 2.85f});
        hole7.coordinates.push_back({8.15f, 3.00f});
        hole7.coordinates.push_back({8.15f, 3.15f});
        hole7.coordinates.push_back({8.00f, 3.15f});
        hole7.coordinates.push_back({7.00f, 3.15f});
        hole7.coordinates.push_back({6.15f, 3.15f});
        hole7.coordinates.push_back({6.15f, 4.00f});
        hole7.coordinates.push_back({6.15f, 4.15f});
        hole7.coordinates.push_back({6.00f, 4.15f});
        hole7.coordinates.push_back({5.00f, 4.15f});
    polygons.push_back(hole7);

    // hole8
    Mazepolygon hole8;
        hole8.coordinates.push_back({7.00f, 2.15f});
        hole8.coordinates.push_back({6.85f, 2.15f});
        hole8.coordinates.push_back({6.85f, 2.00f});
        hole8.coordinates.push_back({6.85f, 1.85f});
        hole8.coordinates.push_back({7.00f, 1.85f});
        hole8.coordinates.push_back({7.85f, 1.85f});
        hole8.coordinates.push_back({7.85f, 1.00f});
        hole8.coordinates.push_back({7.85f, 0.85f});
        hole8.coordinates.push_back({8.00f, 0.85f});
        hole8.coordinates.push_back({8.15f, 0.85f});
        hole8.coordinates.push_back({8.15f, 1.00f});
        hole8.coordinates.push_back({8.15f, 2.00f});
        hole8.coordinates.push_back({8.15f, 2.15f});
        hole8.coordinates.push_back({8.00f, 2.15f});
    polygons.push_back(hole8);

    // hole9
    Mazepolygon hole9;
        hole9.coordinates.push_back({4.85f, 3.00f});
        hole9.coordinates.push_back({4.85f, 2.85f});
        hole9.coordinates.push_back({5.00f, 2.85f});
        hole9.coordinates.push_back({5.15f, 2.85f});
        hole9.coordinates.push_back({5.15f, 3.00f});
        hole9.coordinates.push_back({5.15f, 3.15f});
        hole9.coordinates.push_back({5.00f, 3.15f});
        hole9.coordinates.push_back({4.85f, 3.15f});
    polygons.push_back(hole9);

    // hole10
    Mazepolygon hole10;
        hole10.coordinates.push_back({4.85f, 8.15f});
        hole10.coordinates.push_back({4.85f, 8.00f});
        hole10.coordinates.push_back({4.85f, 7.85f});
        hole10.coordinates.push_back({5.00f, 7.85f});
        hole10.coordinates.push_back({5.15f, 7.85f});
        hole10.coordinates.push_back({5.15f, 8.00f});
        hole10.coordinates.push_back({5.15f, 8.15f});
        hole10.coordinates.push_back({5.00f, 8.15f});
    polygons.push_back(hole10);

    // hole11
    Mazepolygon hole11;
        hole11.coordinates.push_back({4.85f, 7.15f});
        hole11.coordinates.push_back({4.85f, 7.00f});
        hole11.coordinates.push_back({4.85f, 6.00f});
        hole11.coordinates.push_back({4.85f, 5.85f});
        hole11.coordinates.push_back({5.00f, 5.85f});
        hole11.coordinates.push_back({5.15f, 5.85f});
        hole11.coordinates.push_back({5.15f, 6.00f});
        hole11.coordinates.push_back({5.15f, 7.00f});
        hole11.coordinates.push_back({5.15f, 7.15f});
        hole11.coordinates.push_back({5.00f, 7.15f});
    polygons.push_back(hole11);

    // hole12
    Mazepolygon hole12;
        hole12.coordinates.push_back({6.85f, 3.85f});
        hole12.coordinates.push_back({7.00f, 3.85f});
        hole12.coordinates.push_back({8.00f, 3.85f});
        hole12.coordinates.push_back({8.15f, 3.85f});
        hole12.coordinates.push_back({8.15f, 4.00f});
        hole12.coordinates.push_back({8.15f, 4.15f});
        hole12.coordinates.push_back({8.00f, 4.15f});
        hole12.coordinates.push_back({7.00f, 4.15f});
        hole12.coordinates.push_back({6.85f, 4.15f});
        hole12.coordinates.push_back({6.85f, 4.00f});
    polygons.push_back(hole12);

    // hole13
    Mazepolygon hole13;
        hole13.coordinates.push_back({6.85f, 6.15f});
        hole13.coordinates.push_back({6.85f, 6.00f});
        hole13.coordinates.push_back({6.85f, 5.85f});
        hole13.coordinates.push_back({7.00f, 5.85f});
        hole13.coordinates.push_back({7.85f, 5.85f});
        hole13.coordinates.push_back({7.85f, 5.00f});
        hole13.coordinates.push_back({7.85f, 4.85f});
        hole13.coordinates.push_back({8.00f, 4.85f});
        hole13.coordinates.push_back({8.15f, 4.85f});
        hole13.coordinates.push_back({8.15f, 5.00f});
        hole13.coordinates.push_back({8.15f, 6.00f});
        hole13.coordinates.push_back({8.15f, 6.15f});
        hole13.coordinates.push_back({8.00f, 6.15f});
        hole13.coordinates.push_back({7.00f, 6.15f});
    polygons.push_back(hole13);

    // hole14
    Mazepolygon hole14;
        hole14.coordinates.push_back({7.00f, 5.15f});
        hole14.coordinates.push_back({6.85f, 5.15f});
        hole14.coordinates.push_back({6.85f, 5.00f});
        hole14.coordinates.push_back({6.85f, 4.85f});
        hole14.coordinates.push_back({7.00f, 4.85f});
        hole14.coordinates.push_back({7.15f, 4.85f});
        hole14.coordinates.push_back({7.15f, 5.00f});
        hole14.coordinates.push_back({7.15f, 5.15f});
    polygons.push_back(hole14);

    // hole15
    Mazepolygon hole15;
        hole15.coordinates.push_back({6.00f, 5.85f});
        hole15.coordinates.push_back({6.15f, 5.85f});
        hole15.coordinates.push_back({6.15f, 6.00f});
        hole15.coordinates.push_back({6.15f, 7.00f});
        hole15.coordinates.push_back({6.15f, 7.15f});
        hole15.coordinates.push_back({6.00f, 7.15f});
        hole15.coordinates.push_back({5.85f, 7.15f});
        hole15.coordinates.push_back({5.85f, 7.00f});
        hole15.coordinates.push_back({5.85f, 6.00f});
        hole15.coordinates.push_back({5.85f, 5.85f});
    polygons.push_back(hole15);

    // hole16
    Mazepolygon hole16;
        hole16.coordinates.push_back({9.15f, 1.15f});
        hole16.coordinates.push_back({9.00f, 1.15f});
        hole16.coordinates.push_back({8.85f, 1.15f});
        hole16.coordinates.push_back({8.85f, 1.00f});
        hole16.coordinates.push_back({8.85f, 0.85f});
        hole16.coordinates.push_back({9.00f, 0.85f});
        hole16.coordinates.push_back({9.15f, 0.85f});
        hole16.coordinates.push_back({9.15f, 1.00f});
    polygons.push_back(hole16);

    // hole17
    Mazepolygon hole17;
        hole17.coordinates.push_back({9.15f, 4.85f});
        hole17.coordinates.push_back({9.15f, 5.00f});
        hole17.coordinates.push_back({9.15f, 5.15f});
        hole17.coordinates.push_back({9.00f, 5.15f});
        hole17.coordinates.push_back({8.85f, 5.15f});
        hole17.coordinates.push_back({8.85f, 5.00f});
        hole17.coordinates.push_back({8.85f, 4.85f});
        hole17.coordinates.push_back({9.00f, 4.85f});
    polygons.push_back(hole17);

    // hole18
    Mazepolygon hole18;
        hole18.coordinates.push_back({9.15f, 2.85f});
        hole18.coordinates.push_back({9.15f, 3.00f});
        hole18.coordinates.push_back({9.15f, 4.00f});
        hole18.coordinates.push_back({9.15f, 4.15f});
        hole18.coordinates.push_back({9.00f, 4.15f});
        hole18.coordinates.push_back({8.85f, 4.15f});
        hole18.coordinates.push_back({8.85f, 4.00f});
        hole18.coordinates.push_back({8.85f, 3.00f});
        hole18.coordinates.push_back({8.85f, 2.85f});
        hole18.coordinates.push_back({9.00f, 2.85f});
    polygons.push_back(hole18);

    // hole19
    Mazepolygon hole19;
        hole19.coordinates.push_back({8.85f, 9.15f});
        hole19.coordinates.push_back({8.85f, 9.00f});
        hole19.coordinates.push_back({8.85f, 8.85f});
        hole19.coordinates.push_back({9.00f, 8.85f});
        hole19.coordinates.push_back({9.15f, 8.85f});
        hole19.coordinates.push_back({9.15f, 9.00f});
        hole19.coordinates.push_back({9.15f, 9.15f});
        hole19.coordinates.push_back({9.00f, 9.15f});
    polygons.push_back(hole19);

    std::cout << "Maze generated!" << std::endl;
}
