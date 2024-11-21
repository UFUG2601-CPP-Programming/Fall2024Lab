#include <iostream>
#include <forward_list>

int main() {
    // Create a forward list to store integers
    std::forward_list<int> myForwardList;

    // Adding elements to the list
    myForwardList.push_front(30); // Add to the front
    myForwardList.push_front(20); // Add to the front
    myForwardList.push_front(10); // Add to the front

    // Since forward_list does not provide direct access to elements
    // other than the first one, we use iterators to access and display elements
    std::cout << "Elements in myForwardList: ";
    for (int elem : myForwardList) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Removing elements, since there's no remove_if we use remove to delete a specific element
    myForwardList.remove(20); // Removes all occurrences of '20'

    // Showing the list after removal
    std::cout << "List after removing 20: ";
    for (int elem : myForwardList) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Inserting elements after the first element
    auto it = myForwardList.before_begin(); // Gets iterator to the "element" before the first
    myForwardList.insert_after(it, 5); // Insert '5' at the beginning

    // Show the list after insertion
    std::cout << "List after inserting 5 at the beginning: ";
    for (int elem : myForwardList) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}