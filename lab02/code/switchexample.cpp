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