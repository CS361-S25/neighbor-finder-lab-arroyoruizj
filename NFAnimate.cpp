#include "emp/web/Animate.hpp"
#include "emp/web/web.hpp"
#include "emp/math/math.hpp"

emp::web::Document doc{"target"};

class NFAnimator : public emp::web::Animate {

    emp::web::Canvas canvas{100, 100, "canvas"};
    
    public:

        NFAnimator() {
            doc << canvas;
            
            for(int x = 0; x < 10; x++) {

                for(int y = 0; y < 10; y++) {

                    canvas.Rect(x * 10, y * 10, 10, 10, "white", "black");

                }
            }

        }

        void FindNeighbors(int x, int y) {
            // This function will find the neighbors of a cell
            // and update the canvas accordingly
            canvas.Rect(x * 10, y * 10, 10, 10, "black", "black");
        }

        

};

NFAnimator animator;

int main() {

    animator.FindNeighbors(5, 5);
    animator.Step();
    
}