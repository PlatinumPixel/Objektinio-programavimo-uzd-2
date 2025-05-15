#include "Vektorius.h"
#include <iostream>
#include <vector>

int main() {
    ManoVektorius<int> v;




    /////////////////////////////////////////////////Insert tests/////////////////////////////////////////////////////
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
    ////////////////////////////////////////Emplace tests/////////////////////////////////////////////////////
    // Test 1: Emplace a single integer
    std::cout << "Test 1: Emplace a single integer\n";
    ManoVektorius<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(4);
    v1.emplace(v1.begin() + 2, 3); // Emplace 3 at position 2
    for (size_t i = 0; i < v1.size(); ++i) {
        std::cout << v1[i] << " ";
    }
    std::cout << "\nExpected: 1 2 3 4\n\n";

    // Test 2: Emplace a string
    std::cout << "Test 2: Emplace a string\n";
    ManoVektorius<std::string> v2;
    v2.push_back("Hello");
    v2.push_back("World");
    v2.emplace(v2.begin() + 1, "Beautiful"); // Emplace "Beautiful" at position 1
    for (size_t i = 0; i < v2.size(); ++i) {
        std::cout << v2[i] << " ";
    }
    std::cout << "\nExpected: Hello Beautiful World\n\n";

    // Test 3: Emplace with multiple arguments (e.g., a pair)
    std::cout << "Test 3: Emplace a pair\n";
    ManoVektorius<std::pair<int, std::string>> v3;
    v3.emplace(v3.begin(), 1, "One"); // Emplace pair (1, "One") at the beginning
    v3.emplace(v3.end(), 2, "Two");  // Emplace pair (2, "Two") at the end
    for (size_t i = 0; i < v3.size(); ++i) {
        std::cout << "(" << v3[i].first << ", " << v3[i].second << ") ";
    }
    std::cout << "\nExpected: (1, One) (2, Two)\n";
    return 0;
}