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

   git clone https://github.com/sakshiBhegade/Recursive-TilingProblem-Visualizer.git
   
2.**Navigate to the Project Directory**:
  cd Recursive-TilingProblem-Visualizer

3.**Compile the Code**:
Use your C++ compiler to build the program. If you're using g++, you can compile it with the following command:
   ```shell
   g++ main.cpp -o tiling_problem -lSDL2 -lSDL2_image
  
This command compiles the main.cpp source file and links it with the SDL2 and SDL2_image libraries. Make sure you have these libraries installed on your system. Adjust the compilation command according to your system's C++ compiler and library configuration if necessary.

