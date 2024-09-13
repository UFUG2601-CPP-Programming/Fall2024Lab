#include <iostream>
using namespace std;

int main(){

    // Use for-loop

    // int sum = 0;
    // for (int number = 1; number <= 100; ++number) {
    //     sum += number;
    // }

    // Use while-do

    // int sum = 0, number = 1;
    // while (number <= 100) {
    //     sum += number;
    //     ++number;
    // }

    // Use do-while

    int sum = 0, number = 1;
    do {
        sum += number;
        ++number;
    } while (number <= 100);

    cout << sum << endl;

}