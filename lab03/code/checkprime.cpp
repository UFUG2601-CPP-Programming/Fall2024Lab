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
    cout << check_prime(19) << endl;
    return 0;
}