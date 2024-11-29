//
// Created by Mingyu on 24-11-28.
//
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main() {
    std::set<int> set1 = {1, 2, 3, 4};
    std::set<int> set2 = {3, 4, 5, 6};

    std::vector<int> unionResult;

    std::set_union(set1.begin(), set1.end(),
                   set2.begin(), set2.end(),
                   std::back_inserter(unionResult));

    std::cout << "Union: ";
    for (int num : unionResult) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}