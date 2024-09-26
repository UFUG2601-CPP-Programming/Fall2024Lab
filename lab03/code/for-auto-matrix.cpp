#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Initializing a 2D vector with 3 rows and 4 columns
    std::vector<std::vector<int> > matrix = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16}
    };

    // Accessing and printing elements of the 2D vector
    for (auto & i : matrix) {
        for (int j : i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}