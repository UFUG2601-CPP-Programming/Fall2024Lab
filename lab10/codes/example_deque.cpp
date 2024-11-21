#include <iostream>
#include <deque>

int main() {
    // Create a deque to store integers
    std::deque<int> myDeque;

    // Adding elements at the end of the deque
    myDeque.push_back(10);
    myDeque.push_back(20);

    // Adding elements at the front of the deque
    myDeque.push_front(0);
    myDeque.push_front(-10);

    // Accessing elements
    std::cout << "First element: " << myDeque.front() << std::endl;
    std::cout << "Last element: " << myDeque.back() << std::endl;

    // Iterating over the deque using iterator
    std::cout << "Elements in myDeque: ";
    for (auto it = myDeque.begin(); it != myDeque.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Remove elements from the front and back
    myDeque.pop_front(); // Removes -10
    myDeque.pop_back();  // Removes 20

    // Show the deque after popping elements
    std::cout << "Deque after popping: ";
    for (int elem : myDeque) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Size of the deque
    std::cout << "Current size of the deque: " << myDeque.size() << std::endl;

    return 0;
}