#include <iostream>
#include <vector>

int main() {
    // Create a vector to store integers
    std::vector<int> myVector;

    // Adding elements to the vector
    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);

    // Accessing elements using the [] operator
    std::cout << "Element at index 0: " << myVector[0] << std::endl;
    std::cout << "Element at index 1: " << myVector[1] << std::endl;
    std::cout << "Element at index 2: " << myVector[2] << std::endl;

    // Iterating over the vector using a range-based for loop
    std::cout << "Elements in myVector: ";
    for (int elem : myVector) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Accessing elements using the .at() method which includes bounds checking
    try {
        std::cout << "Element at index 3: " << myVector.at(3) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "An exception occurred: " << e.what() << std::endl;
    }

    // Size of the vector
    std::cout << "The vector size is: " << myVector.size() << std::endl;

    // Removing the last element
    myVector.pop_back();
    std::cout << "The vector size after pop_back: " << myVector.size() << std::endl;

    // Clear all elements
    myVector.clear();
    std::cout << "The vector size after clear: " << myVector.size() << std::endl;

    return 0;
}