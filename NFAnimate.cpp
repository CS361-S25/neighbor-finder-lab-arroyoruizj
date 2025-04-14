#include "emp/web/Animate.hpp"
#include "emp/web/web.hpp"
#include "emp/math/math.hpp"

emp::web::Document doc{"target"};

class NFAnimator : public emp::web::Animate {

    double gridSize = 100;
    int cellSize = 10;

    emp::web::Canvas canvas{gridSize, gridSize, "canvas"};
    
    
    public:
        
        

        NFAnimator() {

            doc << canvas;
            
            for(int x = 0; x < cellSize; x++) {

                for(int y = 0; y < cellSize; y++) {

                    canvas.Rect(x * cellSize, y * cellSize, cellSize, cellSize, "white", "black");

                }
            }

        }

        void FindNeighbors(int x, int y) {
            // This function will find the neighbors of a cell
            // and update the canvas accordingly
            int leftmost = emp::Mod(x - 1, cellSize);
            int rightmost = emp::Mod(x + 2, cellSize);

            // Might need to revisti this for loop if off by one
            for (int i = leftmost; i < rightmost + 1; i++) {

                for (int j = y - 1; j < y + 2; j++) {

                    canvas.Rect(i * cellSize, j * cellSize, cellSize, cellSize, "red", "black");

                }
            }

            canvas.Rect(x * cellSize, y * cellSize, cellSize, cellSize, "black", "black");
        }
};

NFAnimator animator;

int main() {

    animator.FindNeighbors(5, 5);
    animator.Step();
    
}