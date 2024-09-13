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