# Lab04 C Array and Recursion

## Our Goal:

Understanding arrays and recursion is fundamental in C programming. Arrays provide a way to handle multiple data items of the same type, while recursion offers a powerful tool for solving problems that can be broken down into simpler, repeatable tasks. Combining these concepts can lead to elegant and efficient solutions.

<!-- C Array -->
##  C Array

In C, an array is a collection of elements of the same data type stored in contiguous memory locations. Arrays allow you to store multiple values under a single variable name, making it easier to manage large amounts of data.

###  Declaring and Initializing Arrays

To declare an array, specify the data type and the number of elements:
```c
dataType arrayName[arraySize];
```
Example:
```c
int numbers[5]; // Declares an array of 5 integers
```
You can also initialize an array at the time of declaration:

```c
int numbers[5] = {1, 2, 3, 4, 5};
```
If you initialize the array upon declaration, you can omit the size:

```c
int numbers[] = {1, 2, 3, 4, 5}; // Compiler determines the size automatically
```

Accessing Array Elements
Array elements are accessed using indices, starting from 0:
```c
printf("%d", numbers[0]); // Accesses the first element
numbers[2] = 10;          // Sets the third element to 10
```

##  Multidimensional Arrays

C supports multidimensional arrays, which are essentially arrays of arrays.

Example: Declaring a 2D Array

```c
int matrix[3][4]; // A 3x4 integer matrix
```

Initializing a 2D Array:
```c
int matrix[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

Accessing Elements:
```c
printf("%d", matrix[0][1]); // Prints the element in the first row, second column
```
<!-- Recursion -->
#  Recursion
Recursion is a programming technique where a function calls itself to solve smaller instances of the same problem. It’s essential to define a base case to prevent infinite recursion.

##  Basic Syntax of a Recursive Function
```c++
returnType functionName(parameters) {
    if (base_case_condition) {
        // Base case: stop recursion
        return some_value;
    } else {
        // Recursive case: function calls itself
        return functionName(modified_parameters);
    }
}
```
Example: Calculating Factorial

The factorial of a non-negative integer n is the product of all positive integers less than or equal to n.

Mathematical Definition:

$0! = 1$


$n! = n \times (n-1)!$

```c++
#include <iostream>

int factorial(int n) {
    if (n == 0) {
        return 1; // Base case
    } else {
        return n * factorial(n - 1); // Recursive call
    }
}

int main() {
    int number = 5;
    std::cout << "Factorial of " << number << " is " << factorial(number) << std::endl;
    return 0;
}
```

Example: Computing Fibonacci Numbers

The Fibonacci sequence is a series where each number is the sum of the two preceding ones.

Mathematical Definition:

$fib(0) = 0$

$fib(1) = 1$

$fib(n) = fib(n - 1) + fib(n - 2)$

```c++
#include <iostream>

int fibonacci(int n) {
    if (n == 0) {
        return 0; // Base case
    } else if (n == 1) {
        return 1; // Base case
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2); // Recursive call
    }
}

int main() {
    int n = 10;
    std::cout << "Fibonacci series of " << n << " numbers: " << std::flush;
    for (int i = 0; i < n; i++) {
        std::cout << fibonacci(i) << " " << std::flush;
    }
    std::cout << std::endl;
    return 0;
}
```

#  Combining Arrays and Resursion

```c++
#include <iostream>

int sumArray(int arr[], int size) {
    if (size == 0) {
        return 0; // Base case
    } else {
        return arr[size - 1] + sumArray(arr, size - 1); // Recursive call
    }
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int total = sumArray(numbers, size);
    std::cout << "Sum of the array is " << total << std::endl;
    return 0;
}
```

#  Conclusion

Base Case: Always ensure that your recursive functions have a valid base case to terminate recursion.

Stack Overflow: Excessive recursion without a proper base case can lead to stack overflow errors.

Efficiency: Recursive solutions may be less efficient than iterative ones due to function call overhead and stack usage.







# HAPPLY CODING!
