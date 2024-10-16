# Lab 05 Designing Recursive Function and C++ Class

## Important Notes
- **Please finish the problems in the contest "Lab05" in OJ by the end of this week (2024-10-20 23:59:59).**
- 
## Our Goal in Lab 05
In this lab, you will deepen your understanding of recursive function design and gain foundational knowledge of C++ classes.

# Recap: Recursion

Recursion is a programming technique where a function calls itself to solve a problem. It typically involves two main parts:

**Base Case**: This is the condition that stops the recursion. It prevents the function from calling itself indefinitely.

**Recursive Case**: This part of the function contains the call to itself, allowing it to break down the problem into smaller, more manageable pieces.

Recursion can simplify complex problems, such as calculating factorials, traversing trees, and solving puzzles. Defining a clear base case is essential to ensure that your recursive function terminates properly and operates correctly.

A standard recursive function is structured as follows:

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

## Types of Recursion in C++

There are three types of recursion: **tail recursion**, **head recursion**, and **tree recursion**. They are distinguished by the position of the recursive invocation and the number of times it occurs.
You can review the sample code for each type below to better understand their features and application scenarios.


**Tail recursion example: check whether a string is a palindrome**
In tail recursion, only recursive call is present at the end of the function. 

This problem can be addressed using the following tail recursive function.

**Hint**: A palindrome is a word, phrase, number, or other sequence of characters that reads the same forward and backward (ignoring spaces, punctuation, and capitalization). For example:
Words: "radar," "level," "civic"
Phrases: "A man, a plan, a canal, Panama!"
Numbers: 121, 12321

In this example, we will focus solely on the case where the input string is a word.


```c++
// Recursive function to check if a string is a palindrome
bool isPalindrome(const std::string & text, int start, int end) {
    // Base case: when start >= end, the string is a palindrome
    if (start >= end)
      return true;

    // Recursive case: check if the characters at start and end indices are equal,
    // and recursively check the remaining characters
    if (text[start] != text[end])
      return false;

    return isPalindrome(text, start + 1, end - 1);
}
```


**Head recursion example: head recursion version of factorial**

In head recursion, the recursive call is present at the start of the function and only a single recursive call is used.

Here, we demonstrate how to compute the factorial using both head recursion and tail recursion. It is important to note that the following programs are provided for illustrative purposes only. It is not advisable to use recursive functions to solve every problem, especially for specific types of recursion.

```c++
// Tail recursive version of factorial
int tail_factorial(int n){
    if (n == 0){
        return 1;
    }else{
        return n * tail_factorial(n - 1);
    }
}
    
// Head recursive version of factorial
int head_factorial(int n, int num=1){
    if (n > 0){
        return head_factorial(n - 1, num * n);
    }else{
        return num;
    }
}
```


**Tree recursion example: find the maximum elements in an array**

In tree recursion, there are multiple recursive calls present in the body of the function. While tracing tree recursion, we get a tree-like structure where multiple recursive calls branch from one function. 

This problem can be addressed using the following tree recursive function.

```c++
// Recursive function to find the maximum element in the array
int findMax(vector<int> nums, int start, int end) {
    // Base case: when there is only one element, it is the maximum
    if (start == end)
    return nums[start];

    // Recursive case: divide the array in half and find the maximum in each half,
    // then return the maximum of the two halves
    int mid = (start + end) / 2;
    int max1 = findMax(nums, start, mid);
    int max2 = findMax(nums, mid + 1, end);
    
    // Return the larger maximum value of two subarraies
    return (max1 > max2) ? max1 : max2;
}
```

## Applications of Recursion

Recursion has numerous applications in computer science and programming. Here are some of the most common uses:

**Solving Problems**: Common examples include calculating Fibonacci sequences, computing factorials, reversing arrays, and solving the Tower of Hanoi.

**Backtracking**: This technique involves exploring different solutions and undoing them if they fail. Recursive algorithms are frequently employed in backtracking scenarios.

**Searching and Sorting Algorithms**: Many algorithms, such as binary search and quicksort, utilize recursion to break problems into smaller sub-problems.

**Tree and Graph Traversal**: Recursive methods are commonly used to traverse trees and graphs, particularly in depth-first search and breadth-first search.

**Mathematical Computations**: Recursion is widely applied in various mathematical computations, including the factorial function and Fibonacci sequence.

**Dynamic Programming**: This technique addresses optimization problems by decomposing them into smaller sub-problems, often employing recursive algorithms.

# Class Basic

C++ is an object-oriented programming language.

In C++, everything is associated with classes and objects, each having its own attributes and methods. For instance, in real life, a car can be considered an object. A car has attributes like weight and color, and methods such as drive and brake.

Attributes and methods are essentially variables and functions that belong to a class, often referred to as "class members."

A class is a user-defined data type that serves as an object constructor, acting as a "blueprint" for creating objects in our program.

## Example: Create a class

To create a class, use the `class` keyword. The code below creates a class called `MyClass`.

```c++
class MyClass {       // The class
    public:             // Access specifier
        int myNum;        // Attribute (int variable)
        string myString;  // Attribute (string variable)
};
```

## Example: Create an object
In C++, an object is instantiated from a class. Having already defined the class named `MyClass`, we can now create objects from it.

To create an object of `MyClass`, specify the class name followed by the object name.

To access the class attributes (e.g., `myNum` and `myString`), use the dot syntax (.) with the object:


```c++
class MyClass {       // The class
    public:             // Access specifier
        int myNum;        // Attribute (int variable)
        string myString;  // Attribute (string variable)
};

int main() {
    MyClass myObj;  // Create an object of MyClass

    // Access attributes and set values
    myObj.myNum = 15; 
    myObj.myString = "Some text";

    // Print attribute values
    cout << myObj.myNum << "\n";
    cout << myObj.myString;
    return 0;
}
```


## Example: Constructors

A constructor in C++ is a special method that is automatically invoked when an object of a class is created.

To define a constructor, use the **same name** as the class, followed by parentheses `()`:

```c++
class MyClass {     // The class
    public:           // Access specifier
        MyClass() {     // Constructor
        cout << "Hello World!";
      }
};

int main() {
    MyClass myObj;    // Create an object of MyClass (this will call the constructor)
    return 0;
}
```

## Reference:

**GeeksforGeeks**
https://www.geeksforgeeks.org/cpp-recursion/

**W3Schools**
https://www.w3schools.com/cpp/cpp_classes.asp