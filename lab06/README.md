# Lab 06 Advanced Class and Basic Compilation

## Advanced Class

### Constructor

In C++, constructors are special member functions of a class that are executed whenever new objects of that class are created. They serve the primary purpose of initializing objects. Constructors are unique because they have the same name as the class and do not have a return type. Here are the different types of constructors in C++:

* Default Constructor: A default constructor is one that can be called with no arguments. It either has no parameters or has parameters that all have default values. If no user-defined constructor exists, the compiler provides a default constructor.

```cpp
class Example {
public:
    Example() {
        // Initialize with default values
    }
};
```

* Parameterized Constructor: A parameterized constructor has parameters and is used to provide different values to distinct objects. Such constructors allow you to initialize objects with specific values right upon creation.

```cpp
class Example {
public:
    int x;
    Example(int val) : x(val) {  // Initialize x with val
    }
};
```

* Copy Constructor (optional): A copy constructor is used to initialize an object using another object of the same class. It is usually passed as a reference to avoid infinite recursion and is often used implicitly when an object is passed by value or returned by value.

* Move Constructor (C++11 and later) (optional): A move constructor enables the resources owned by a temporary object to be moved rather than copied. It takes an r-value reference to an object of the same class and is used to optimize resource management, reducing unnecessary copying.

* Delegating Constructor (C++11 and later): Delegating constructors allow a constructor to call another constructor in the same class to initialize the object, which helps in reducing code duplication across multiple constructors.

```cpp
class Example {
public:
    int x, y;
    Example(int val) : x(val), y(val) {}  // Primary constructor
    Example() : Example(0) {}  // Delegating constructor
};
```

* Explicit Constructor (optional): Explicit constructors prevent the compiler from using the constructor for implicit conversions. They are declared with the keyword explicit and are only considered for direct initialization.

```cpp
class Example {
public:
    int x;
    explicit Example(int val) : x(val) {}
};

int main() {
    Example obj = 10;  // Error: cannot convert int to Example implicitly
    Example obj2(10);  // OK: direct initialization is allowed
}
```

#### Default Constructor

> Most default constructors initialize the data fields to zero, but not always.

In C++, a default constructor can be explicitly defined to initialize data fields to specific values, including zero. However, it's not mandatory for a default constructor to initialize fields to zero. It depends on the logic and requirements of the application. Here's an example where the default constructor does not initialize the data fields to zero but to other specific values:

```cpp
#include <iostream>
#include <string>

class Person {
public:
    std::string name;
    int age;

    // Default constructor initializing fields to non-zero values
    Person() : name("John Doe"), age(30) {
        // Here, the name is initialized to "John Doe" and age to 30
        // These are not zero but specific default values.
    }

    void display() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    // Creating an object of Person using the default constructor
    Person person;
    person.display();  // Outputs: Name: John Doe, Age: 30

    return 0;
}
```

## Basic Compilation

### Separated Compilation

In C++, separate compilation is a common practice where the declaration and implementation of a class are split across different files. This approach enhances the compilation efficiency of large projects and also makes the code more organized and manageable. Here’s a simple example of separate compilation in C++:

1. Suppose we have a simple Person class. We'll place the class declaration in a header file and the implementation in a source file.

* Person.h - Header file containing the declaration of the Person class.
* Person.cpp - Source file containing the implementation of the Person class.
* main.cpp - Main program file that uses the Person class.

2. Person.h (Header file):

The header file contains the declaration of the Person class. We use preprocessor directives to prevent the header file from being included multiple times.

```cpp
// Person.h
#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person {
private:
    std::string name;
    int age;

public:
    Person();  // Default constructor
    Person(const std::string& name, int age);  // Parameterized constructor
    void display() const;  // Member function to display information
};

#endif // PERSON_H
```

3. Person.cpp (Source file):

The source file includes the implementation of the Person class member functions.

```cpp
// Person.cpp
#include "Person.h"

// Default constructor implementation
Person::Person() : name("Unknown"), age(0) {}

// Parameterized constructor implementation
Person::Person(const std::string& name, int age) : name(name), age(age) {}

// Member function to display information implementation
void Person::display() const {
    std::cout << "Name: " << name << ", Age: " << age << std::endl;
}
```

4. main.cpp (Main program file):

The main program file uses the Person class.

```cpp
// main.cpp
#include "Person.h"

int main() {
    Person person1("Alice", 30);
    Person person2("Bob", 25);

    person1.display();
    person2.display();

    return 0;
}
```

5. Compiling and Linking

In the command line, you can use g++ or another compiler to compile and link these files. Here’s how to do it in one command:

```bash
g++ -o main main.cpp Person.cpp
```

This command compiles main.cpp and Person.cpp and links them into an executable named main. Ensure that all files are in the same directory or provide the correct file paths.

### Makefile (optinal)

To compile and manage the project described previously, involving separate compilation for a C++ project with a Person class, we can create a Makefile that simplifies the build process. This Makefile will handle the compilation of multiple source files and ensure that only changed files are recompiled, increasing efficiency.

Here’s a simple Makefile that compiles the project with Person.h, Person.cpp, and main.cpp into an executable named main.

```makefile
# Compiler settings - Can change to clang++ if required
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Build target executable:
TARGET = main

# Object files:
OBJS = main.o Person.o

# Rule to link the program
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile the main program
main.o: main.cpp Person.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Rule to compile the Person class
Person.o: Person.cpp Person.h
	$(CXX) $(CXXFLAGS) -c Person.cpp

# Clean up
clean:
	rm -f $(TARGET) $(OBJS)

# Phony targets
.PHONY: clean
```

#### Explanation of the Makefile:
##### Variables:
* CXX: Specifies the C++ compiler. For example, `g++` or `clang++`.
* CXXFLAGS: Compiler flags used in compilation. `-Wall` enables all warnings, and `-std=c++11` specifies the C++ standard.
* TARGET: The name of the final executable.
* OBJS: List of object files to be generated from the source files.
##### Rules:
* The first rule `$(TARGET): $(OBJS)` tells make how to link the program. It depends on the object files listed in `OBJS`.
* main.o: `main.cpp` `Person.h` compiles `main.cpp` into `main.o`, ensuring it recompiles if `main.cpp` or `Person.h` changes.
* Person.o: `Person.cpp` `Person.h` compiles `Person.cpp` into `Person.o`, ensuring it recompiles if `Person.cpp` or `Person.h` changes.
##### clean:
* The clean rule is used to remove all generated files, allowing a clean rebuild of the project. It removes the executable and all object files.
##### Phony Targets:
* .PHONY: clean ensures that clean is treated as a phony target, meaning it does not represent a file name and its recipe should be executed unconditionally when called.

#### Usage:
1. To build the project, simply navigate to the directory containing the Makefile and type make or make all. This will compile the necessary source files and link them into an executable named main.

2. To clean up the build (remove all object files and the executable), type make clean.