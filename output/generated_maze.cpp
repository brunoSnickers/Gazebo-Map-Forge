#include <iostream>
#include <list>
#include "maze_generator.h"

void MazeGenerator::generateMaze()
{
    // --- Wände ---

    // Kurve 1
    Mazepolygon poly0;
    poly.coordinates.push_back({1.00f, 1.00f});
    poly.coordinates.push_back({2.00f, 1.00f});
    poly.coordinates.push_back({2.00f, 2.00f});
    poly.coordinates.push_back({1.00f, 2.00f});
    poly.coordinates.push_back({0.50f, 1.50f});
    polygons.push_back(poly0);

    // Kurve 2
    Mazepolygon poly1;
    poly.coordinates.push_back({1.00f, -1.00f});
    poly.coordinates.push_back({1.00f, 0.00f});
    poly.coordinates.push_back({0.00f, 0.00f});
    poly.coordinates.push_back({0.00f, -1.00f});
    poly.coordinates.push_back({0.50f, -1.50f});
    polygons.push_back(poly1);

    // Kurve 3
    Mazepolygon poly2;
    poly.coordinates.push_back({-1.00f, -1.00f});
    poly.coordinates.push_back({-2.00f, -1.00f});
    poly.coordinates.push_back({-2.00f, -2.00f});
    poly.coordinates.push_back({-1.00f, -2.00f});
    poly.coordinates.push_back({-0.50f, -1.50f});
    polygons.push_back(poly2);

    // Kurve 4
    Mazepolygon poly3;
    poly.coordinates.push_back({-1.00f, 1.00f});
    poly.coordinates.push_back({-1.00f, 0.00f});
    poly.coordinates.push_back({-0.00f, -0.00f});
    poly.coordinates.push_back({0.00f, 1.00f});
    poly.coordinates.push_back({-0.50f, 1.50f});
    polygons.push_back(poly3);

    // (Optional) Lösungspfad (einfacher Kreis)
    SolutionGraphNode node1, node2, node3, node4;
    node1.coordinate = {2.0f, 2.0f};
    node2.coordinate = {2.0f, -2.0f};
    node3.coordinate = {-2.0f, -2.0f};
    node4.coordinate = {-2.0f, 2.0f};

    node1.neighbors.push_back(&node2);
    node2.neighbors.push_back(&node3);
    node3.neighbors.push_back(&node4);
    node4.neighbors.push_back(&node1);

    solutionGraph.push_back(node1);
    solutionGraph.push_back(node2);
    solutionGraph.push_back(node3);
    solutionGraph.push_back(node4);

    std::cout << "Maze generated!" << std::endl;
}
