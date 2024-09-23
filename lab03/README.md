# Lab 03 C++ Loop Function and Vector

## Important Notes
- **Please finish the problems in the contest "Lab03" in OJ by the end of this week (2024-9-30 23:59:59).**

## Our Goal in Lab 03
In this lab, you should learn how to use loop function and vector.


### C++ Loops: The for Loop
Loops in programming allow us to execute a block of code repeatedly until a specified condition is met. The for loop is one of the most commonly used loops in C++. It's especially handy when you know in advance how many times you want to execute a block of code.

```cpp
//Syntax of a for Loop
for (initialization; condition; update) {
// Code to execute on each iteration
}
```

Initialization: Typically used to initialize a counter variable.
Condition: The loop continues as long as this condition evaluates to true.
Update: Executes at the end of each loop iteration, usually to update the counter variable.
Example: Printing Numbers from 1 to 5

```cpp
#include <iostream>

int main() {
    for (int i = 1; i <= 5; ++i) {
        std::cout << i << " ";
    }
    return 0;
}

```


### C++ Vectors
Vectors in C++ are sequence containers representing arrays that can change in size. They are part of the C++ Standard Template Library (STL). Vectors use contiguous storage locations for their elements, which means that their elements can be accessed not only through iterators but also using offsets on regular pointers to elements.

Creating a Vector
```c++
#include <vector>

std::vector<int> myVector;
```

Example: Initializing a Vector and Printing its Elements
```c++
#include <iostream>
#include <vector>

int main() {
// Initializing a vector with some elements
std::vector<int> myVector = {1, 2, 3, 4, 5};

    // Using a for loop to iterate through the vector and print its elements
    for (int i = 0; i < myVector.size(); ++i) {
        std::cout << myVector[i] << " ";
    }

    return 0;
}
```

### C++ Functions
Functions in C++ are building blocks of reusable code that can be executed multiple times throughout a program. They allow you to encapsulate a task into a single, self-contained unit of code which makes your program more modular and easier to understand and maintain.

Basic Syntax of a Function
```c++
returnType functionName(parameter1, parameter2, ...) {
// Body of the function
}
```

**returnType**: The data type of the value the function returns. If the function doesn't return a value, this is specified as void.

**functionName**: The name of the function. Function names should be relevant to the task they perform.

**parameters**: Optional list of parameters the function takes as input. Parameters allow you to pass data into your function.

Example: A Simple Function to Add Two Numbers

```c++
#include <iostream>

// Function declaration
int add(int num1, int num2) {
    return num1 + num2;
}

int main() {
    int result = add(5, 3); // Function call
    std::cout << "The sum is " << result << std::endl;
    return 0;
}

```

## Code Example
**The examples in the code folder may help you solve Lab problems**