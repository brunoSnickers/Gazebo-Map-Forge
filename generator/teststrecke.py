import json
import os
import math

# --- Hilfsfunktion zum Laden eines Segments ---
def load_segment(name):
    path = f"segments/{name}.json"
    with open(path) as f:
        return json.load(f)

# --- Hilfsfunktion zum Formatieren als C++ ---
def coord_to_cpp(coord):
    return f'{{{coord[0]:.2f}f, {coord[1]:.2f}f}}'

def polygon_to_cpp(polygon_coords):
    lines = []
    for coord in polygon_coords:
        lines.append(f'    poly.coordinates.push_back({coord_to_cpp(coord)});')
    return "\n".join(lines)

# --- Hilfsfunktion zum Transformieren von Koordinaten ---
def transform_coords(coords, angle_deg, offset):
    angle_rad = math.radians(angle_deg)
    cos_a = math.cos(angle_rad)
    sin_a = math.sin(angle_rad)
    ox, oy = offset
    return [
        [
            cos_a * x - sin_a * y + ox,
            sin_a * x + cos_a * y + oy
        ]
        for x, y in coords
    ]


# Zentren und Winkel für die vier Kurven im Quadrat
centers = [(1, 1), (1, -1), (-1, -1), (-1, 1)]
angles = [0, 90, 180, 270]

segments = []
for i in range(4):
    seg = load_segment("curve_left")
    seg["coordinates"] = transform_coords(seg["coordinates"], angles[i], centers[i])
    segments.append(seg)

cpp_code = """#include <iostream>
#include <list>
#include "maze_generator.h"

void MazeGenerator::generateMaze()
{
"""

cpp_code += "    // --- Wände ---\n"

for i, seg in enumerate(segments):
    coords = seg["coordinates"]
    cpp_code += f"\n    // Kurve {i+1}\n"
    cpp_code += f"    Mazepolygon poly{i};\n"
    cpp_code += polygon_to_cpp(coords) + "\n"
    cpp_code += f"    polygons.push_back(poly{i});\n"

cpp_code += "\n    // (Optional) Lösungspfad (einfacher Kreis)\n"
cpp_code += "    SolutionGraphNode node1, node2, node3, node4;\n"
cpp_code += '    node1.coordinate = {2.0f, 2.0f};\n'
cpp_code += '    node2.coordinate = {2.0f, -2.0f};\n'
cpp_code += '    node3.coordinate = {-2.0f, -2.0f};\n'
cpp_code += '    node4.coordinate = {-2.0f, 2.0f};\n\n'
cpp_code += '    node1.neighbors.push_back(&node2);\n'
cpp_code += '    node2.neighbors.push_back(&node3);\n'
cpp_code += '    node3.neighbors.push_back(&node4);\n'
cpp_code += '    node4.neighbors.push_back(&node1);\n\n'
cpp_code += '    solutionGraph.push_back(node1);\n'
cpp_code += '    solutionGraph.push_back(node2);\n'
cpp_code += '    solutionGraph.push_back(node3);\n'
cpp_code += '    solutionGraph.push_back(node4);\n\n'
cpp_code += '    std::cout << "Maze generated!" << std::endl;\n'
cpp_code += "}\n"

# --- Speichern ---
os.makedirs("output", exist_ok=True)
with open("output/generated_maze.cpp", "w") as f:
    f.write(cpp_code)

print("✅ Fertige Teststrecke exportiert nach output/generated_maze.cpp")