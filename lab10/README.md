# Lab 10 C++ Template and Sequential Containers

## Basic Syntax and Examples of Template

### Function Templates

Function templates are used to create functions that can accept any data type as arguments. Here’s how you can define a basic function template:

```cpp
template<typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}
```
Example Usage:

```cpp
int x = 10, y = 20;
swap(x, y);  // works with integers

double m = 5.5, n = 10.5;
swap(m, n);  // works with doubles
```
### Class Templates

Class templates are similar to function templates but are used for classes. Here is a simple example of a class template:

```cpp
template<typename T>
class Box {
public:
    T value;
    void setValue(T v) { value = v; }
    T getValue() { return value; }
};
```

Example Usage:

```cpp
Box<int> intBox;
intBox.setValue(123);
Box<string> stringBox;
stringBox.setValue("Hello World");
```

### Template Parameters

Templates can have more than one parameter, and those parameters can be of different kinds:

- **Type Parameters**: Typically declared as typename T or class T.
- **Non-type Parameters**: These could be values like integers.

Example with Non-type Parameter:

```cpp
template<typename T, int size>
class FixedArray {
    T arr[size];
public:
    T& operator[](int index) {
        return arr[index];
    }
    int getSize() { return size; }
};
```
### Template specialization
Template specialization allows you to customize the behavior of a template for a specific data type or scenario.



```cpp
// General template
template <typename T>
class Logger {
public:
    void log(const T& value) {
        std::cout << "Logging value: " << value << std::endl;
    }
};

// Specialized template for `double`
template <>
class Logger<double> {
public:
    void log(const double& value) {
        // Log with 2 decimal places
        std::cout << "Logging double: " << std::fixed << std::setprecision(2) << value << std::endl;
    }
};

// Specialized template for `std::string`
template <>
class Logger<std::string> {
public:
    void log(const std::string& value) {
        std::cout << "Logging string: \"" << value << "\"" << std::endl;
    }
};
```

In this example, we have a general template for the `Logger` class that logs any type of value. We then specialize the template for `double` (as we want `double` values to be logged with 2 decimal places) and for `std::string` (as we want strings to be logged with quotes).

The compiler will choose the specialized version of the template when the type matches the specialization. 

More detailed example can be found in the [example_template_specialization.cpp](codes/example_template_specialization.cpp) file.

## Introduction to Sequential Containers in C++

### Types of Sequential Containers

There are several types of sequential containers, each with unique characteristics and suitable use cases:

- **std::vector**
   - **Characteristics**: Dynamically resizable array. Provides fast random access but potentially slow insertion and deletion except at the end.
   - **Common Uses**: Ideal for situations where fast access to elements by index is needed and modifications (insert/delete) are primarily at the end of the container.

**Example**:

```cpp
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
```

- **std::deque**
  - **Characteristics**: Double-ended queue that allows fast insertion and deletion at both the beginning and the end.
  - **Common Uses**: Useful when you need to add or remove elements from both ends of the container, like in a queue used in a breadth-first search algorithm.

**Example**:

```cpp
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
```

- **std::list**
  - **Characteristics**: Doubly linked list that allows fast insertion and deletion at any point in the list.
  - **Common Uses**: Best for scenarios where elements are frequently inserted and removed from the middle of the container.

**Example**:

```cpp
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
```

- **std::forward_list**
  - **Characteristics**: Singly linked list, more memory efficient than std::list but can only iterate forward.
  - **Common Uses**: Useful for memory-constrained environments where simple, sequential access is needed and insertion/removal is frequent.

**Example**

```cpp
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
```

- **std::array**
  - **Characteristics**: Container for a fixed size array of elements. Size must be known at compile-time.
  - **Common Uses**: When the number of elements is fixed and known at compile time, and when overhead of dynamic size management of std::vector is unwanted.

**Example**

```cpp
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
```

