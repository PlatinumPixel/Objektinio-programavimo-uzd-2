
#include "Vektorius.h"
#include <iostream>

#include <stdexcept>

void frontBackTest(){
        try {
        // Test 1: Access front and back on a non-empty vector
        std::cout << "Test 1: Access front and back on a non-empty vector\n";
        ManoVektorius<int> v;
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);

        std::cout << "Front element: " << v.front() << "\n"; // Should print 10
        std::cout << "Back element: " << v.back() << "\n";   // Should print 30
        std::cout << "\n";

        // Test 2: Modify front and back
        std::cout << "Test 2: Modify front and back\n";
        v.front() = 5;  // Modify the first element
        v.back() = 35;  // Modify the last element
        for (size_t i = 0; i < v.size(); ++i) {
            std::cout << v[i] << " ";
        }
        std::cout << "\nExpected: 5 20 35\n\n";

        // Test 3: Access front and back on an empty vector
        std::cout << "Test 3: Access front and back on an empty vector\n";
        ManoVektorius<int> empty_v;
        std::cout << "Front element: " << empty_v.front() << "\n"; // Should throw an exception
        std::cout << "Back element: " << empty_v.back() << "\n";   // Should throw an exception
    } catch (const std::out_of_range& e) {
        std::cerr << "Caught exception: " << e.what() << "\n";
    }
}

void dataTest(){
        // Test 1: Access raw data pointer
    std::cout << "\nTest 4: Access raw data pointer\n";
    ManoVektorius<int> v2;
    v2.push_back(100);
    v2.push_back(200);
    v2.push_back(300);

    int* raw_data = v2.storage();
    std::cout << "Raw data pointer: " << raw_data << "\n";
    std::cout << "Elements via raw pointer: ";
    for (size_t i = 0; i < v2.size(); ++i) {
        std::cout << raw_data[i] << " ";
    }
    std::cout << "\nExpected: 100 200 300\n";
}


void insertTest(){
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
}

void EmplaceTest(){
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
    std::cout << "\nExpected: (1, One) (2, Two)\n";\
}

void ResizeTest(){
    ////////////////////////////////////////resize tests/////////////////////////////////////////////////////
        // Test 1: Resize to a larger size
    std::cout << "Test 1: Resize to a larger size\n";
    ManoVektorius<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    std::cout << "Before resize: ";
    for (size_t i = 0; i < v1.size(); ++i) {
        std::cout << v1[i] << " ";
    }
    std::cout << "\nSize: " << v1.size() << ", Capacity: " << v1.capacity() << "\n";

    v1.resize(6); // Resize to a larger size
    std::cout << "After resize: ";
    for (size_t i = 0; i < v1.size(); ++i) {
        std::cout << v1[i] << " ";
    }
    std::cout << "\nSize: " << v1.size() << ", Capacity: " << v1.capacity() << "\n\n";

    // Test 2: Resize to a smaller size
    std::cout << "Test 2: Resize to a smaller size\n";
    v1.resize(2); // Resize to a smaller size
    std::cout << "After resize: ";
    for (size_t i = 0; i < v1.size(); ++i) {
        std::cout << v1[i] << " ";
    }
    std::cout << "\nSize: " << v1.size() << ", Capacity: " << v1.capacity() << "\n\n";

    // Test 3: Resize an empty vector
    std::cout << "Test 3: Resize an empty vector\n";
    ManoVektorius<std::string> v2;
    v2.resize(3); // Resize to a larger size
    std::cout << "After resize: ";
    for (size_t i = 0; i < v2.size(); ++i) {
        std::cout << "\"" << v2[i] << "\" ";
    }
    std::cout << "\nSize: " << v2.size() << ", Capacity: " << v2.capacity() << "\n";
    
}

void atTest(){
        try {
        // Test 1: Access valid elements
        std::cout << "Test 1: Access valid elements\n";
        ManoVektorius<int> v;
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);

        std::cout << "Element at index 0: " << v.at(0) << "\n"; // Should print 10
        std::cout << "Element at index 1: " << v.at(1) << "\n"; // Should print 20
        std::cout << "Element at index 2: " << v.at(2) << "\n"; // Should print 30
        std::cout << "\n";

        // Test 2: Modify elements using non-const `at`
        std::cout << "Test 2: Modify elements using non-const `at`\n";
        v.at(1) = 50; // Modify the element at index 1
        for (size_t i = 0; i < v.size(); ++i) {
            std::cout << v.at(i) << " ";
        }
        std::cout << "\nExpected: 10 50 30\n\n";

        // Test 3: Access elements using const `at`
        std::cout << "Test 3: Access elements using const `at`\n";
        const ManoVektorius<int> const_v = v;
        std::cout << "Element at index 0: " << const_v.at(0) << "\n"; // Should print 10
        std::cout << "Element at index 1: " << const_v.at(1) << "\n"; // Should print 50
        std::cout << "Element at index 2: " << const_v.at(2) << "\n"; // Should print 30
        std::cout << "\n";

        // Test 4: Access out-of-range element
        std::cout << "Test 4: Access out-of-range element\n";
        std::cout << "Element at index 3: " << v.at(3) << "\n"; // Should throw an exception
    } catch (const std::out_of_range& e) {
        std::cerr << "Caught exception: " << e.what() << "\n";
    }
}

void beginEndTest(){  
    // Test 1: Forward iteration using `begin` and `end`
    std::cout << "Test 1: Forward iteration using `begin` and `end`\n";
    ManoVektorius<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    std::cout << "Elements: ";
    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\nExpected: 10 20 30\n\n";

    // Test 2: Reverse iteration using `rbegin` and `rend`
    std::cout << "Test 2: Reverse iteration using `rbegin` and `rend`\n";
    std::cout << "Elements: ";
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\nExpected: 30 20 10\n\n";

    // Test 3: Constant forward iteration using `cbegin` and `cend`
    std::cout << "Test 3: Constant forward iteration using `cbegin` and `cend`\n";
    const ManoVektorius<int> const_v = v;
    std::cout << "Elements: ";
    for (auto it = const_v.cbegin(); it != const_v.cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\nExpected: 10 20 30\n\n";

    // Test 4: Constant reverse iteration using `crbegin` and `crend`
    std::cout << "Test 4: Constant reverse iteration using `crbegin` and `crend`\n";
    std::cout << "Elements: ";
    for (auto it = const_v.crbegin(); it != const_v.crend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\nExpected: 30 20 10\n\n";}

int main() {
    insertTest();
    EmplaceTest();
    ResizeTest();
    atTest();
    dataTest();
    frontBackTest();
    beginEndTest();
    return 0;
}

