#include <iostream>
#include <array>
#include <algorithm> // For std::sort

int main() {
    // Create an std::array to store 5 integers
    std::array<int, 5> myArray = {2, 4, 1, 5, 3};

    // Accessing elements using operator[]
    std::cout << "Element at index 2: " << myArray[2] << std::endl;

    // Iterating over the array using a range-based for loop
    std::cout << "Elements in myArray (original order): ";
    for (int elem : myArray) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Sorting the array using std::sort
    std::sort(myArray.begin(), myArray.end());

    // Displaying the array after sorting
    std::cout << "Elements in myArray (sorted): ";
    for (int elem : myArray) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Using size() to get the number of elements in the array
    std::cout << "Size of the array: " << myArray.size() << std::endl;

    // Access elements with .at() - which includes bounds checking
    try {
        std::cout << "Element at index 4: " << myArray.at(4) << std::endl;  // Should be fine
        std::cout << "Element at index 5: " << myArray.at(5) << std::endl;  // Will throw an exception
    } catch (const std::out_of_range& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}