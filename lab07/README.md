# Lab 06 File-IO and String

## Stream IO
### Part 1: Using ifstream
ifstream is a class in the C++ Standard Library used for reading from files. Here's a basic example of how to use it:

```c++
#include <iostream>
#include <fstream>
#include <string>

int main() {
std::ifstream inputFile("example.txt"); // Open the file

    if (!inputFile) {
        std::cerr << "Unable to open file example.txt";
        return 1; // Return with error code
    }

    std::string line;
    while (std::getline(inputFile, line)) { // Read line by line
        std::cout << line << std::endl; // Display each line
    }

    inputFile.close(); // Close the file
    return 0;
}
```
### Explanation:

* We include the necessary headers: <iostream>, <fstream>, and <string>.
* We create an ifstream object named inputFile and attempt to open example.txt.
* We check if the file was opened successfully using if (!inputFile).
* We use a while loop with std::getline to read the file line by line.
* Each line is printed to the console.
* Finally, we close the file using inputFile.close().

### Part 2: Using freopen
freopen is a C-style function used to redirect a file stream. It is often used in competitive programming or specific scenarios where file I/O redirection is needed.


```c++
#include <iostream>
#include <cstdio> // Required for freopen

int main() {
    // Redirect standard input to read from a file
    if (freopen("example.txt", "r", stdin) == nullptr) {
        std::cerr << "Unable to open file example.txt";
        return 1; // Return with error code
    }

    std::string line;
    while (std::getline(std::cin, line)) { // Read line by line from stdin
        std::cout << line << std::endl; // Display each line
    }

    // No need to close stdin, it will close automatically when the program exits

    return 0;
}
```

### Explanation:

* We include the <cstdio> header to use freopen.
* freopen("example.txt", "r", stdin) redirects the standard input (stdin) to read from example.txt.
* We then read from std::cin as if we were reading from standard input, but it's actually reading from the file.
* This method is less common but can be useful in specific scenarios such as competitive programming.

## Binary File I/O with ifstream and ofstream
Let's say we have a simple structure that we want to write to a binary file and then read back.

```c++
#include <iostream>
#include <fstream>

// Define a simple structure
struct Data {
    int id;
    double value;
    char name[50];
};

int main() {
    // Create an instance of Data
    Data writeData = {1, 99.99, "Example"};

    // Write the structure to a binary file
    std::ofstream outputFile("data.bin", std::ios::binary);
    if (!outputFile) {
        std::cerr << "Unable to open file for writing";
        return 1;
    }

    // Write the structure to the file
    outputFile.write(reinterpret_cast<char*>(&writeData), sizeof(writeData));
    outputFile.close();

    // Create a new instance to read the data into
    Data readData;

    // Read the structure from the binary file
    std::ifstream inputFile("data.bin", std::ios::binary);
    if (!inputFile) {
        std::cerr << "Unable to open file for reading";
        return 1;
    }

    // Read the data from the file
    inputFile.read(reinterpret_cast<char*>(&readData), sizeof(readData));
    inputFile.close();

    // Display the read data
    std::cout << "ID: " << readData.id << std::endl;
    std::cout << "Value: " << readData.value << std::endl;
    std::cout << "Name: " << readData.name << std::endl;

    return 0;
}
```
### Explanation:
Structure Definition: We define a simple struct Data with an integer, a double, and a character array. This will be our data that we want to write and read in binary format.

#### Writing to a Binary File:
* We create an ofstream object named outputFile with the std::ios::binary flag to indicate that the file should be treated as binary.
* We use outputFile.write to write the contents of writeData to the file. The reinterpret_cast<char*> is used to cast the structure to a char* pointer, which is necessary for writing binary data.
* We close the file after writing.
#### Reading from a Binary File:

* We create an ifstream object named inputFile with the std::ios::binary flag.
* We use inputFile.read to read the binary data from the file into readData.
* We close the file after reading.
* Display: Finally, we output the contents of readData to verify that the data was correctly written and read.

#### Additional Points:
Binary I/O is often used for performance reasons or when dealing with non-textual data.
Always ensure that the structure's alignment and packing are consistent between writing and reading, especially when dealing with different compilers or platforms.
Be careful with endianness issues if your application is expected to run on different architectures.
This example demonstrates the basics of binary file I/O in C++. You can expand upon it by handling arrays of structures, more complex data types, or error checking as needed.

### Summary
* ifstream is a C++-style way to handle file input, offering better type safety and integration with C++ streams.
* freopen is a C-style approach, allowing you to redirect standard input or output, which can be useful in some scenarios.
* **The code folder contain the example useful for Lab-07**

# String

In C++, the `std::string` class provides a range of convenient functions to handle and manipulate text data. Here are some common operations you can perform with strings:

## 1. Creating and Initializing Strings
- **Creating an empty string**: `std::string s;`
- **Initializing with text**: `std::string s = "Hello";`
- **Copy constructor**: `std::string s2(s);`

## 2. Basic Properties and Methods
- **Length**: Use `s.length()` or `s.size()` to get the number of characters in the string.
- **Check if empty**: `s.empty()` returns `true` if the string is empty.
- **Clear string**: `s.clear()` removes all characters from the string.

## 3. Accessing Characters
- **Access individual character**: `s[i]` or `s.at(i)` retrieves or modifies the character at index `i`. `at` performs bounds checking, while `[]` does not.
- **First and last characters**: `s.front()` retrieves the first character, and `s.back()` retrieves the last character.

## 4. String Concatenation
- **Concatenating strings**: Use the `+` operator: `std::string result = s1 + s2;`
- **Appending strings**: `s += " World";` or `s.append(" World");`

## 5. Substrings
- **Extract a substring**: `s.substr(start, length)` extracts a substring starting from `start` and of specified `length`.

## 6. String Search
- **Find a substring**: `s.find("text")` returns the starting index of the first occurrence of `"text"` or `std::string::npos` if not found.
- **Reverse find**: `s.rfind("text")` finds the last occurrence of `"text"`.

## 7. String Comparison
- **Comparison**: `s.compare(other)` compares `s` with `other`. It returns `0` if they are equal, a positive value if `s` is greater, and a negative value if `s` is smaller.

## 8. String Insertion and Erasure
- **Insert**: `s.insert(pos, "text")` inserts `"text"` at position `pos`.
- **Erase**: `s.erase(pos, len)` removes `len` characters starting from `pos`.

## 9. Conversion to C-Style String
- **Convert to C-string**: Use `s.c_str()` to get a `const char*` pointer to the string's data.

## 10. Example of String Operations
```cpp
#include <iostream>
#include <string>

int main() {
    std::string s = "Hello World";
    std::cout << "Length: " << s.length() << std::endl;
    std::cout << "Substring: " << s.substr(0, 5) << std::endl;
    std::cout << "Position of 'World': " << s.find("World") << std::endl;
    s.insert(5, ",");
    std::cout << "After insertion: " << s << std::endl;
    s.erase(5, 1);
    std::cout << "After erasure: " << s << std::endl;

    return 0;
}

# This code demonstrates various string operations.
