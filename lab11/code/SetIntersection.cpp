//
// Created by Mingyu on 24-11-28.
//
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

int main() {
    std::set<int> set1 = {1, 2, 3, 4};
    std::set<int> set2 = {3, 4, 5, 6};

    std::vector<int> intersectionResult;

    std::set_intersection(set1.begin(), set1.end(),
                          set2.begin(), set2.end(),
                          std::back_inserter(intersectionResult));

    std::cout << "Intersection: ";
    for (int num : intersectionResult) {
        std::cout << num << " ";
    }

    return 0;
}