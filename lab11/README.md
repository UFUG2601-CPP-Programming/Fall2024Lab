# C++ Container Tutorial

## std::map
* A std::map is an associative container that stores key-value pairs. It automatically orders its elements by key.

### Data Struct and Feature
* Underlying Data Structure: std::map is typically implemented as a balanced binary search tree (like a Red-Black Tree).
* Ordering: It stores elements in a sorted order based on the keys. This means you can iterate over the elements in ascending order of keys.
### Time Complexity
* Insertion, deletion, and access operations have a time complexity of O(log n) because of the tree structure.
* Memory Usage: Generally uses more memory than std::unordered_map due to the tree nodes and pointers required for maintaining the tree structure.
* Use Case: Suitable when you need the elements to be in a specific order or need to perform range queries.

### Basic Operations
* Insert: Add a key-value pair.
* Access: Retrieve the value associated with a key.
* Erase: Remove an element by key.
* Find: Check if a key exists.
* Example
```c++
#include <iostream>
#include <map>

int main() {
std::map<int, std::string> mapExample;

    // Insert elements
    mapExample[1] = "One";
    mapExample[2] = "Two";

    // Access elements
    std::cout << "Key 1: " << mapExample[1] << std::endl;

    // Find an element
    if (mapExample.find(2) != mapExample.end()) {
        std::cout << "Key 2 found." << std::endl;
    }

    // Erase an element
    mapExample.erase(1);

    return 0;
}
```


## std::unordered_map
* An std::unordered_map is an associative container that stores key-value pairs. It does not maintain any particular order.

### Data Struct and Feature
* Underlying Data Structure: std::unordered_map is implemented using a hash table.
* Ordering: It does not maintain any order of the elements. The order of elements can seem arbitrary and can change as the hash table is rehashed.
### Time Complexity:
* Average case time complexity for insertion, deletion, and access operations is O(1) due to the hash table, but it can degrade to O(n) in the worst case if many keys hash to the same value (hash collisions).
* Memory Usage: Generally uses less memory per element compared to std::map, but uses extra memory for the hash table structure.
* Use Case: Suitable when you need fast access and order doesn't matter.

### Basic Operations
* Insert: Add a key-value pair.
* Access: Retrieve the value associated with a key.
* Erase: Remove an element by key.
* Find: Check if a key exists.
* Example
```c++
#include <iostream>
#include <unordered_map>

int main() {
std::unordered_map<int, std::string> unorderedMapExample;

    // Insert elements
    unorderedMapExample[1] = "One";
    unorderedMapExample[2] = "Two";

    // Access elements
    std::cout << "Key 1: " << unorderedMapExample[1] << std::endl;

    // Find an element
    if (unorderedMapExample.find(2) != unorderedMapExample.end()) {
        std::cout << "Key 2 found." << std::endl;
    }

    // Erase an element
    unorderedMapExample.erase(1);

    return 0;
}
```

## std::set

* A std::set is an associative container that stores unique elements, automatically ordered.

### Data Struct and Feature
* Underlying Data Structure: std::set is typically implemented as a balanced binary search tree (such as a Red-Black Tree).
* Ordering: Elements are stored in a sorted order. This allows you to iterate over the elements in ascending order.
* Time Complexity:
* Insertion, deletion, and lookup operations have a time complexity of O(log n) because of the tree structure.
* Memory Usage: Generally uses more memory than std::unordered_set because of the tree nodes and the additional pointers required for maintaining the tree structure.
* Use Case: Suitable when you need the elements to be in a specific order or need to perform range queries.


### Basic Operations
* Insert: Add an element.
* Erase: Remove an element.
* Find: Check if an element exists.
* Example

```c++
#include <iostream>
#include <set>

int main() {
std::set<int> setExample;

    // Insert elements
    setExample.insert(1);
    setExample.insert(2);

    // Find an element
    if (setExample.find(2) != setExample.end()) {
        std::cout << "Element 2 found." << std::endl;
    }

    // Erase an element
    setExample.erase(1);

    return 0;
}
```

## std::unordered_set

* An std::unordered_set is an associative container that stores unique elements without any particular order.

### Data Struct and Feature
* Underlying Data Structure: std::unordered_set is implemented using a hash table.
* Ordering: It does not maintain any order of the elements. The order of elements can seem arbitrary and can change as the hash table is rehashed.
### Time Complexity:
* Average case time complexity for insertion, deletion, and lookup operations is O(1) because of the hash table. However, it can degrade to O(n) in the worst case if many elements hash to the same value (hash collisions).
* Memory Usage: Generally uses less memory per element compared to std::set, but requires extra memory for the hash table structure.
* Use Case: Suitable when you need fast access and order doesn't matter.

### Basic Operations
* Insert: Add an element.
* Erase: Remove an element.
* Find: Check if an element exists.
* Example
```c++
#include <iostream>
#include <unordered_set>

int main() {
std::unordered_set<int> unorderedSetExample;

    // Insert elements
    unorderedSetExample.insert(1);
    unorderedSetExample.insert(2);

    // Find an element
    if (unorderedSetExample.find(2) != unorderedSetExample.end()) {
        std::cout << "Element 2 found." << std::endl;
    }

    // Erase an element
    unorderedSetExample.erase(1);

    return 0;
}
```
