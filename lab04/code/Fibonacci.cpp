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