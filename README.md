# Gazebo-Map-Forge

Gazebo-Map-Forge helps you create, edit, and convert maps for Gazebo simulations. This repo uses Jupyter Notebook (Python) for map design and C++ for exporting maps to code.

## Quick Start

1. **Clone**
   ```sh
   git clone https://github.com/brunoSnickers/Gazebo-Map-Forge.git
   cd Gazebo-Map-Forge
   ```

2. **Install dependencies**
   - Requires Python 3 and Jupyter.
   - Install Python requirements:
     ```sh
     pip install ...
     ```

3. **Create or edit a map**
   - Start Jupyter:
     ```sh
     jupyter notebook
     ```
   - Open the notebook(s) for map creation. Follow inline instructions. Save your map file (usually `.yaml` or `.json`).

4. **Generate C++ code**
   - Use the script to convert your map to C++:
     ```sh
     python scripts/generate_cpp.py --input mymap.yaml --output map.cpp
     ```
   - You can also edit your map.txt and regenerate as needed.

5. **Use the generated C++**
   - Include the generated C++ file in your Gazebo project as needed.

## Notes

- All main workflows are in the Jupyter notebooks and scripts directory.
- Edit maps in the notebooks or directly in the source file before code generation.
- No guarantees—use, edit, and adapt as needed.
