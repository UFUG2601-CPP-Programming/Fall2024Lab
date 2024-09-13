#include <iostream>
using namespace std;

int main(){

    // Continue Case
    for (int i = 0; i < 10; i++){
        if (i == 5){
            continue;
        }
        cout << i << endl;
    }

    // Break Case
    for (int i = 0; i < 10; i++){
        if (i == 5){
            break;
        }
        cout << i << endl;
    }

    return 0;
}