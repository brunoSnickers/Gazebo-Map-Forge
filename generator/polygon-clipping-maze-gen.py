from shapely.geometry import box
from shapely.ops import unary_union
import os

# ----------------------
# ASCII-Straßenkarte
# ----------------------
ascii_map = [
    "┌┐",
    "└┘"
]

# ----------------------
# Welche Symbole gelten als Straße
# ----------------------
ROAD_SYMBOLS = {'─', '│', '┌', '┐', '└', '┘', '├', '┤', '┬', '┴', '┼', ' '}

# ----------------------
# Parameter
# ----------------------
cell_size = 1.0     # Jede Zelle ist 1x1 groß
margin = 0.1        # Straße ist kleiner als Zelle

def ascii_to_polygons(ascii_map, road_symbols, cell_size=1.0, margin=0.1):
    polygons = []
    rows = len(ascii_map)
    cols = len(ascii_map[0])

    for i, row in enumerate(ascii_map):
        for j, char in enumerate(row):
            if char in road_symbols:
                x = j * cell_size
                y = (rows - i - 1) * cell_size
                poly = box(
                    x + margin,
                    y + margin,
                    x + cell_size - margin,
                    y + cell_size - margin
                )
                polygons.append(poly)
    
    return unary_union(polygons)  # ergibt ein oder mehrere Polygone

def export_polygon_to_cpp(geometry, name_prefix="poly"):
    cpp_lines = []
    cpp_lines.append('#include <iostream>\n#include <list>\n#include "maze_generator.h"\nvoid MazeGenerator::generateMaze() {\n')
    if geometry.geom_type == 'Polygon':
        geoms = [geometry]
    elif geometry.geom_type == 'MultiPolygon':
        geoms = list(geometry.geoms)
    else:
        raise ValueError("Unsupported geometry type:", geometry.geom_type)

    for idx, poly in enumerate(geoms):
        var_name = f"{name_prefix}{idx}"
        cpp_lines.append(f"// {var_name}")
        cpp_lines.append(f"Mazepolygon {var_name};")
        for x, y in poly.exterior.coords:
            cpp_lines.append(f"    {var_name}.coordinates.push_back({{{x:.2f}f, {y:.2f}f}});")
        cpp_lines.append(f"polygons.push_back({var_name});\n")
    cpp_lines.append('std::cout << "Maze generated!" << std::endl;\n')
    cpp_lines.append("}\n")

    return "\n".join(cpp_lines)

def main():
    road_area = ascii_to_polygons(ascii_map, ROAD_SYMBOLS, cell_size, margin)
    cpp_code = export_polygon_to_cpp(road_area, name_prefix="poly")

    with open("output/generated_maze.cpp", "w") as f:
        f.write("// Automatisch generiert aus ASCII-Karte\n\n")
        f.write(cpp_code)

    print("maze.cpp wurde erfolgreich erstellt.")

if __name__ == "__main__":
    main()