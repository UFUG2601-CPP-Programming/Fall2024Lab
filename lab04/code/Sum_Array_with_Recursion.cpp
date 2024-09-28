#include <iostream>

int sumArray(int arr[], int size) {
    if (size == 0) {
        return 0; // Base case
    } else {
        return arr[size - 1] + sumArray(arr, size - 1); // Recursive call
    }
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int total = sumArray(numbers, size);
    std::cout << "Sum of the array is " << total << std::endl;
    return 0;
}