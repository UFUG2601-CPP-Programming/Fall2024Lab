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