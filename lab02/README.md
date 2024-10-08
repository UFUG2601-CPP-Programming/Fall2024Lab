# Lab 02 C++ Flow Control

## Important Notes
- **Please finish the problems in the contest "Lab02" in OJ by the end of this week (2024-9-22 23:59:59).**

## Our Goal in Lab 02
In this lab, you should learn how to use control syntax, such as `if-else`,`switch`, to implement simple decision-making processes.



## Introduction
There are three basic flow control constructs - sequential, conditional (or decision), and loop (or iteration). 
The **sequential** structure: the execution process is from the top to the bottom line by line. 
The **conditional** structure is using if-else statement to verify whether a statement satisfys some specific condition and then make choose. 
The **loop** structure is used to execute some logic operation repeatedly.

In this lab, we will primarily focus on the conditional structure for flow control in C++. You will learn how to use `if-else` statements, and `switch` statements.

## Sequential Flow Control
A program is a sequence of instructions. **Sequential flow** is the most common and straight-forward, where programming statements are executed in the order that they are written  from top to bottom in a sequential manner. 

All the programs you have written up to this point in the lab follow a sequential flow, where each instruction is executed once and only once in the order they are placed in the code.

## Conditional Flow Control
There are a few types of conditionals, `if`, `if-else`, nested-if (`if-elseif-elseif-...-else`), `switch-case`, and *conditional expression*.

### Example 1: if-else
A sample code that provides feedback to students based on their input grade is shown below:

```cpp
#include <iostream>

using namespace std;

int main(){
    // Define an integer variable "mark" to store the inputted mark.
    int mark;
    
    // Print a prompt for the user to input their grade.
    cout << "Input your mark [0-100]: ";
    
    // Get the input mark from the terminal and store it in the variable "mark"
    cin >> mark;
    
    // Use an "if-else" statement to provide different feedback based on the mark.
    if (mark >= 60) {
        // Provide feedback for a mark of 60 and above 
        cout << "Congratulation!" << endl;
        cout << "Keep it up!" << endl;
    } else {
        // Provide feedback for a mark below 60
        cout << "Try Harder!" << endl;
    }   
    return 0;
}
```

**NOTE**

If you are familiar with all the course material, you should realize that the `if-else` statement in the previous program can be rewritten using the conditional operator as follows:

```cpp
cout << (mark >= 60) ? "Congratulation!\nKeep it up!" :  "Try Harder!" << endl;
```

### Example 2: nested if
At times, the number of possible situations is more than two. In such cases, nested if statements should be used. A sample program that assigns letter grades to students based on their input marks is shown below:

```cpp
#include <iostream>
using namespace std;
int main(){
    // Define an integer variable "mark" to store the inputted mark.
    int mark;
    // Print a prompt for the user to input their grade.
    cout << "Input your mark [0-100]: ";
    // Get the input mark from the terminal and store it in the variable "mark"
    cin >> mark;
    // Use "nested-if" statements to give grades based on the input mark
    if (mark >= 90) {
        // Give "A" when the input mark is in the range [90, 100]
        cout << "A" << endl;
    } else if (mark >= 80) {
        // Give "B" when the input mark is in the range [80, 90)
        cout << "B" << endl;
    } else if (mark >= 70) {
        // Give "C" when the input mark is in the range [70, 80)
        cout << "C" << endl;
    } else if (mark >= 60) {
        // Give "D" when the input mark is in the range [60,70)
        cout << "D" << endl;
    } else {
        // Give "F" when the input mark is in the range [0, 60)
        cout << "F" << endl;
    }
    return 0;
}
```

**NOTE**

In general, nested if-else statements involve having an `if` statement inside another `if-else` statement. They are used when implementing multiple layers of conditions (conditions within conditions). In C++, any number of nesting levels are allowed. The previous program demonstrates an example where another `if-else` statement is used within the `else` block. 


### Example 3: switch-case
When a program needs to take different actions based on the value of a specific variable (condition) which is limited to several discrete values, the `switch-case` statement could be used. Below is a sample program that performs four different computations based on the user input operator.

```cpp
#include <iostream>
using namespace std;
int main(){
    // Define a char variable "oper" to store user input operator
    char oper;
    // Define three integer variables "num1", "num2", and "result" 
    // to store two operand numbers and the computation result, respectively
    int num1 = 233, num2 = 666, result = 0;
    // Print a prompt for the user to input an operator
    cout << "Input a char [+ - / *]: ";
    // Get the input operator from the terminal and store it in the variable "oper"
    cin >> oper;
    // Use a switch statement to perform different computations on 'num1' and 'num2' 
    // based on the input operator 'oper'
    switch (oper) {
        // When the input operator is "+", compute num1 + num2
        case '+':
            result = num1 + num2;
            // A break statement is necessary here 
            // to prevent unexpected results from being generated
            break; 
        // When the input operator is "-", compute num1 - num2
        case '-':
            result = num1 - num2;
            break;
        // When the input operator is "*", compute num1 * num2
        case '*':
            result = num1 * num2;
            break;
        // When the input operator is "/", compute num1 / num2
        case '/':
            result = num1 / num2;
            break;
        // If the user inputs a symbol other than "+", "-", "*", or "/", 
        // output a hint for an unknown operator.
        default:
            cout << "Unknown operator" << endl;
    }
    // Print the computation result based on the user input operator
    cout << num1 << oper << num2 << "=" << result << endl; 
    return 0;
}
```

**NOTE**
1. When C++ encounters a `break` keyword, it exits the `switch-case` statement. Although the `break` keyword is not mandatory in a `switch-case` statement, it is essential to include it when a match is found to ensure the correct behavior. To observe the impact, you can try removing the `break` statement from the previous program.
   
2. The `default` keyword specifies code to execute if there is no case match. Like the `break` keyword, although the `default` keyword is not required in a `switch-case` statement, it is advisable to include it to handle unexpected values of the condition variable.

### Additional Contents
Here is some well-designed online C++ lab material on conditional structure for flow control, featuring interesting exercises and sample codes.

**LabEx**
https://labex.io/tutorials/cpp-c-flow-control-178536

**BigC++**
https://horstmann.com/bigcpp/labs/BigC_ch4.htm

**W3Schools**
https://www.w3schools.com/CPP/cpp_conditions.asp

