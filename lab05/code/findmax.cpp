// Recursive function to find the maximum element in an array
#include <iostream>
#include <vector>

using namespace std;

// Recursive function to find the maximum element in the array
int findMax(vector<int> nums, int start, int end) {
    // Base case: when there is only one element, it is the maximum
    if (start == end)
    return nums[start];

    // Recursive case: divide the array in half and find the maximum in each half,
    // then return the maximum of the two halves
    int mid = (start + end) / 2;
    int max1 = findMax(nums, start, mid);
    int max2 = findMax(nums, mid + 1, end);
    
    // Return the larger maximum value from two subarraies
    return (max1 > max2) ? max1 : max2;
}

int main() {
    vector<int> nums = { 9, 2, 4, 0, 2, 2, 3, 4, 5, 7 }; // Initializing an array with elements
    int size = sizeof(nums) / sizeof(nums[0]); // Calculating the size of the array

    // Find the maximum elements in the array using recursion
    int max = findMax(nums, 0, size - 1);

    std::cout << "Maximum element: " << max << std::endl; // Display the maximum element

    return 0; 
}