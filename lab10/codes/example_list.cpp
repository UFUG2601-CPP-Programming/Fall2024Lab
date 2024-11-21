#include <iostream>
#include <list>

int main() {
    // Create a list to store integers
    std::list<int> myList;

    // Adding elements to the list
    myList.push_back(10);  // Add to the end
    myList.push_back(20);  // Add to the end
    myList.push_front(5);  // Add to the front

    // Accessing elements (indirectly, since list does not support direct access)
    std::cout << "First element: " << myList.front() << std::endl;
    std::cout << "Last element: " << myList.back() << std::endl;

    // Iterating over the list using a range-based for loop
    std::cout << "Elements in myList: ";
    for (int elem : myList) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Iterating with iterators (bidirectional)
    std::cout << "Elements (via iterators): ";
    for (std::list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Removing an element
    myList.remove(10);  // Remove all occurrences of '10'

    // Show the list after removal
    std::cout << "List after removing 10: ";
    for (int elem : myList) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Size of the list
    std::cout << "Current size of the list: " << myList.size() << std::endl;

    return 0;
}