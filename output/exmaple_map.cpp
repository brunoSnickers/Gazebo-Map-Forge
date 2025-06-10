
#include <iostream>
#include <list>

#include "maze_generator.h"

void MazeGenerator::generateMaze()
{
    // this is just a static example to show how the polygons and solution graph can be used
    // in a real application, you would replace this with actual maze generation logic
    // and use the polygons and solution graph to represent the maze structure

    // Create some walls as example
    MazeCoordinate coord1 = {2.5f, 2.5f};
    MazeCoordinate coord2 = {2.5f, -2.5f};
    MazeCoordinate coord3 = {-2.5f, -2.5f};
    MazeCoordinate coord4 = {-2.5f, 2.5f};

    // insert the coordinates into a polygon
    Mazepolygon poly;
    poly.coordinates.push_back(coord1);
    poly.coordinates.push_back(coord2);
    poly.coordinates.push_back(coord3);
    poly.coordinates.push_back(coord4);

    // instert the polygon into the list of polygons
    polygons.push_back(poly);



    
    // create some shape inside
    MazeCoordinate innerCoord1 = {0.5f, 0.5f};
    MazeCoordinate innerCoord2 = {1.0f, -1.0f};
    MazeCoordinate innerCoord3 = {1.25f, 1.25f};
    MazeCoordinate innerCoord4 = {-1.0f, 1.5f};
    MazeCoordinate innerCoord5 = {-1.25f, -0.5f};

    // insert the coordinates into a polygon
    Mazepolygon innerPoly;
    innerPoly.coordinates.push_back(innerCoord1);
    innerPoly.coordinates.push_back(innerCoord2);
    innerPoly.coordinates.push_back(innerCoord3);
    innerPoly.coordinates.push_back(innerCoord4);
    innerPoly.coordinates.push_back(innerCoord5);

    // instert the polygon into the list of polygons
    polygons.push_back(innerPoly);




    // Create a solution graph node
    SolutionGraphNode node1, node2, node3, node4;

    node1.coordinate = {3.0f, 3.0f};
    node2.coordinate = {3.0f, -3.0f};
    node3.coordinate = {-3.0f, -3.0f};
    node4.coordinate = {-3.0f, 3.0f};

    node1.neighbors.push_back(&node2);
    node1.neighbors.push_back(&node4);

    node2.neighbors.push_back(&node1);
    node2.neighbors.push_back(&node3);

    node3.neighbors.push_back(&node4);
    node3.neighbors.push_back(&node2);

    node4.neighbors.push_back(&node1);
    node4.neighbors.push_back(&node3);

    solutionGraph.push_back(node1);
    solutionGraph.push_back(node2);
    solutionGraph.push_back(node3);
    solutionGraph.push_back(node4);

    std::cout << "Maze generated!" << std::endl;
}
