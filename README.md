# Tiling Problem Visualization

This repository contains a C++ program that tackles tiling problems using a recursive algorithm and provides visualizations using the SDL (Simple DirectMedia Layer) library.

## Introduction

Tiling problems involve dividing a given grid into smaller tiles or patterns in various ways. This project provides a visual representation of tiling solutions by employing a recursive algorithm. Users can interact with the program by clicking on the grid to mark tiles as empty (black), triggering the algorithm to recalculate and visualize the tiling process.

## Getting Started

### Prerequisites

Before running this program, ensure you have the following prerequisites installed on your system:

- **C++ Compiler**: You need a C++ compiler to build the program.
- **SDL Library**: The program utilizes the SDL library for graphics.
- **SDL_image Library**: This library is used for handling image files.

### Installation

Follow these steps to set up and run the Tiling Problem Visualization program on your local machine:

1. **Clone the Repository**:

   ```shell
   git clone https://github.com/sakshiBhegade/Recursive-TilingProblem-Visualizer.git
   
2.**Navigate to the Project Directory**:
  cd Recursive-TilingProblem-Visualizer

3.**Compile the Code**:
Use your C++ compiler to build the program. If you're using g++, you can compile it with the following command:
```shell
g++ main.cpp -o tiling_problem -lSDL2 -lSDL2_image
  
This command compiles the main.cpp source file and links it with the SDL2 and SDL2_image libraries. Make sure you have these libraries installed on your system. Adjust the compilation command according to your system's C++ compiler and library configuration if necessary.

4.**Run the Program**:
Execute your script run.sh to run the program:
   ```shell
   ./run.sh

The script should launch the program for tiling problem visualization.

5.**Interact with the Program**:
Right-click on the grid to mark tiles as empty (black). The program will recalculate and visualize the tiling based on your input.
Close the application window when you're done.

## Algorithm Details

The tiling algorithm used in this program is a recursive and visually engaging approach to solving tiling problems. It follows these fundamental steps:

1. **Base Case for 2x2 Grids**:
   - When dealing with a 2x2 grid, the algorithm applies specific tile patterns based on the configuration. These patterns are chosen to create aesthetically pleasing and visually interesting results.

2. **Recursive Division for Larger Grids**:
   - For larger grids (greater than 2x2), the algorithm employs a recursive approach.
   - It starts by dividing the given grid into quarters, creating four smaller subgrids.
   - Each of these subgrids is then processed independently using the same algorithm, further dividing them if needed.
   - The algorithm continues to divide the grid into smaller segments until it reaches the base case of a 2x2 grid.

3. **Pattern Placement**:
   - When dividing a grid, the algorithm places patterns in a manner that takes into account the configuration of the grid segments.
   - The placement of patterns is determined based on the relative positions of existing tiles within the grid segments.

4. **Visualization**:
   - As the algorithm progresses and places patterns, the program provides real-time visualization of the tiling process using the SDL library.
   - Users can interact with the visualization by marking tiles as empty (black) with mouse clicks, prompting the algorithm to recalculate and update the display.

5. **Divide-and-Conquer Approach**:
   - The essence of this tiling algorithm lies in its divide-and-conquer strategy. By recursively breaking down the problem into smaller parts and solving each part individually, the algorithm achieves complex and visually appealing tiling arrangements.

This algorithmic approach not only solves tiling problems but also offers an engaging way to explore and create artistic tile arrangements. The combination of recursive division and real-time visualization makes it a versatile tool for tiling enthusiasts and creative minds.
