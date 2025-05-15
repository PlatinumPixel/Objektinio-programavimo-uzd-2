#include "Vektorius.h"
#include <iostream>
#include <vector>

int main() {
    ManoVektorius<int> v;

    // Test 1: Insert a single element
    std::cout << "Test 1: Insert a single element\n";
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.insert(v.begin() + 2, 3); // Insert 3 at position 2
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << "\nExpected: 1 2 3 4\n\n";

    // Test 2: Insert a single element using move semantics
    std::cout << "Test 2: Insert a single element using move semantics\n";
    int value = 5;
    v.insert(v.end(), std::move(value)); // Insert 5 at the end
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << "\nExpected: 1 2 3 4 5\n\n";

    // Test 3: Insert multiple copies of an element
    std::cout << "Test 3: Insert multiple copies of an element\n";
    v.insert(v.begin() + 1, 3, 10); // Insert three 10s at position 1
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << "\nExpected: 1 10 10 10 2 3 4 5\n\n";

    // Test 4: Insert a range of elements
    std::cout << "Test 4: Insert a range of elements\n";
    std::vector<int> range = {6, 7, 8};
    v.insert(v.end(), range.begin(), range.end()); // Insert range at the end
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << "\nExpected: 1 10 10 10 2 3 4 5 6 7 8\n";

    return 0;
}