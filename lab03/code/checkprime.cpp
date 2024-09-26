#include <iostream>

using namespace std;

bool check_prime(int x) {
    //check if x is prime number (x>1)
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}


int main() {
    int x; //Assume x >= 2
    cin >> x;
    cout << boolalpha << check_prime(x) << endl;
    return 0;
}