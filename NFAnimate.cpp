// File: NFAnimate.cpp
// Created on: April 14th, 2025
// Author: Jared Arroyo Ruiz

// This code is a simple implementation to find the neighbors of cell.

// All code was created following Anya E. Vostinar's Neighbor Finder Lab

// Setting up Environment
#include "emp/web/Animate.hpp" // Provides the Animate class for creating animations
#include "emp/web/web.hpp"     // Provides web utilities for creating and managing web elements
#include "emp/math/math.hpp"   // Provides mathematical utilities, such as modular arithmetic

emp::web::Document doc{"target"};

class NFAnimator : public emp::web::Animate {

    // Define constants for the size of each cell and the grid dimensions
    const int cellSize = 25; // Size of each cell in pixels
    const int num_h_boxes = 10; // Number of cells in the grid's height
    const int num_w_boxes = 15; // Number of cells in the grid's width
    const double width{double(num_w_boxes) * cellSize}; // Total width of the canvas
    const double height{double(num_h_boxes) * cellSize}; // Total height of the canvas
    // Create a canvas element with specified width and height
    emp::web::Canvas canvas{width, height, "canvas"};
    
    public:

    // Constructor for the NFAnimator class
    NFAnimator() {

        // Add the canvas to the document
        doc << canvas;

        // Add a toggle button to the document
        doc << GetToggleButton("Toggle");

        // Add a step button to the document
        doc << GetStepButton("Step");
        
        // Initialize the grid by drawing white cells with black borders
        for(int x = 0; x < num_w_boxes; x++) {

            for(int y = 0; y < num_h_boxes; y++) {

                // Draw each cell as a white rectangle with a black border
                canvas.Rect(x * cellSize, y * cellSize, cellSize, cellSize, "white", "black");

            }
        }

    }

    /**
     * @brief Identifies all 8 neighbors of a cell.
     * 
     * This function identifes the 8
     * neighboring cells in the immediate vicinity 
     * of the cell at (x, y) and makes the cell red.
     * 
     * @param x The x-coordinate of the cell.
     * @param y The y-coordinate of the cell.
     */
    void FindNeighbors(int x, int y) {

        // Highlight the selected cell in black
        canvas.Rect(x * cellSize, y * cellSize, cellSize, cellSize, "black", "black");

        // Iterate through the 3x3 neighborhood around the cell
        for (int i = x - 1; i <= x + 1; i++) {

            for (int j = y - 1; j <= y + 1; j++) {

                // Skip the cell itself
                if (i == x && j == y) {
                    continue; // Move to the next iteration
                }
            
                // Wrap around the grid boundaries using modular arithmetic
                int wrapped_i = emp::Mod(i, num_w_boxes); // Ensure the column index stays within bounds
                int wrapped_j = emp::Mod(j, num_h_boxes); // Ensure the row index stays within bounds

                // Highlight the neighbor cell in red with a black border
                canvas.Rect(wrapped_i * cellSize, wrapped_j * cellSize, cellSize, cellSize, "red", "black");
            }
        }
    }  
};

// Create an instance of the NFAnimator class
NFAnimator animator;

int main() {
    // Call the FindNeighbors function to highlight the neighbors of the cell at (3, 3)
    animator.FindNeighbors(3, 3);

    // Return 0 to indicate successful program termination
    return 0;
}