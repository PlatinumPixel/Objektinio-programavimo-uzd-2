#include <cassert> 
#include "bibl.h"

void testDefaultConstructor() {
    stud s;
    assert(s.getVardas() == "");
    assert(s.getPavarde() == "");
    assert(s.getGalutinisVid() == 0);
    assert(s.getGalutinisMed() == 0);
    std::cout << "Default konstruktoriaus testas sekmingas!.\n";
}

void testSettersAndGetters() {
    stud s;
    s.setvard("Jonas");
    s.setpava("Jonaitis");
    s.setEgzaminas(9.5);
    s.setVid(8.0);
    s.setMed(8.5);
    
    assert(s.getVardas() == "Jonas");
    assert(s.getPavarde() == "Jonaitis");
    assert(s.getEgz() == 9.5);
    assert(s.getGalutinisVid() == 8);
    assert(s.getGalutinisMed() == 8.5);
    std::cout << "Setters ir getters testas sekmingas!\n";
}

void testCopyConstructor() {
    stud original;
    original.setvard("Petras");
    original.setpava("Petraitis");
    original.getTarp().push_back(10);
    original.setEgzaminas(9);
    
    stud copy(original);
    assert(copy.getVardas() == "Petras");
    assert(copy.getTarp()[0] == 10);
    std::cout << "Copy konstruktoriaus testas sekmingas!\n";
}

void testMoveConstructor() {
    stud temp;
    temp.setvard("Move");
    temp.getTarp().push_back(7);
    
    stud moved(std::move(temp));
    assert(moved.getVardas() == "Move");
    assert(moved.getTarp()[0] == 7);
    std::cout << "Move konstruktoriaus testas sekmingas!\n";
}

void testCopyAssignment() {
    stud s1;
    s1.setpava("Kebabas");
    
    stud s2;
    s2 = s1;
    assert(s2.getPavarde() == "Kebabas");
    std::cout << "Copy assignment testas sekmingas!\n";
}

void testMoveAssignment() {
    stud s1;
    s1.setpava("Moved");
    
    stud s2;
    s2 = std::move(s1);
    assert(s2.getPavarde() == "Moved");
    std::cout << "Move assignment testas sekmingas!\n";
}

void testOutput() {
    stud original;
    original.setvard("Petras");
    original.setpava("Petraitis");
    original.getTarp().push_back(10);
    original.setEgzaminas(9);
    original.calculateGalutinis();
    cout << original;
    std::cout << "Output testas sekmingas!\n";
}

void testInput() {
    stud original;
    cout << "iveskite varda ir pavarde\n";
    cin >> original;
    original.calculateGalutinis();
    cout << original;
    std::cout << "Input testas sekmingas!\n";
}


#include "Vektorius.h"
#include <iostream>
#include "stud.h"
#include <stdexcept>

void frontBackTest(){
        try {
        // Test 1: Access front and back on a non-empty vector
        std::cout << "Test 1: Access front and back on a non-empty vector\n";
        Vektorius<int> v;
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
        Vektorius<int> empty_v;
        std::cout << "Front element: " << empty_v.front() << "\n"; // Should throw an exception
        std::cout << "Back element: " << empty_v.back() << "\n";   // Should throw an exception
    } catch (const std::out_of_range& e) {
        std::cerr << "Caught exception: " << e.what() << "\n";
    }
}

void dataTest(){
        // Test 1: Access raw data pointer
    std::cout << "\nTest 4: Access raw data pointer\n";
    Vektorius<int> v2;
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
    Vektorius<int> v;
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
    Vektorius<int> v1;
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
    Vektorius<std::string> v2;
    v2.push_back("Hello");
    v2.push_back("World");
    v2.emplace(v2.begin() + 1, "Beautiful"); // Emplace "Beautiful" at position 1
    for (size_t i = 0; i < v2.size(); ++i) {
        std::cout << v2[i] << " ";
    }
    std::cout << "\nExpected: Hello Beautiful World\n\n";

    // Test 3: Emplace with multiple arguments (e.g., a pair)
    std::cout << "Test 3: Emplace a pair\n";
    Vektorius<std::pair<int, std::string>> v3;
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
    Vektorius<int> v1;
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
    Vektorius<std::string> v2;
    v2.resize(3); // Resize to a larger size
    std::cout << "After resize: ";
    for (size_t i = 0; i < v2.size(); ++i) {
        std::cout << "\"" << v2[i] << "\" ";
    }
    std::cout << "\nSize: " << v2.size() << ", Capacity: " << v2.capacity() << "\n";
    
}

void testStudVector() {
    // Test 1: Add students to the vector
    std::cout << "Test 1: Add students to the vector\n";
    Vektorius<stud> students;

    // Create student objects
    stud s1("John", "Doe");
    s1.addTarpPazymys(8);
    s1.addTarpPazymys(9);
    s1.setEgzaminas(10);
    s1.calculateGalutinis();

    stud s2("Jane", "Smith");
    s2.addTarpPazymys(7);
    s2.addTarpPazymys(6);
    s2.setEgzaminas(8);
    s2.calculateGalutinis();

    // Add students to the vector
    students.push_back(s1);
    students.push_back(s2);

    // Display students
    for (size_t i = 0; i < students.size(); ++i) {
        std::cout << students[i];
    }
    std::cout << "Expected:\nJohn                Doe            9.20 9.20\nJane                Smith          7.20 7.20\n\n";

    // Test 2: Modify a student's grades
    std::cout << "Test 2: Modify a student's grades\n";
    students[0].addTarpPazymys(10);
    students[0].calculateGalutinis();

    // Display updated student
    std::cout << "Updated student:\n" << students[0];
    std::cout << "Expected:\nJohn                Doe            9.60 9.60\n\n";

    // Test 3: Add a student using emplace_back
    std::cout << "Test 3: Add a student using emplace_back\n";
    students.push_back(stud("Alice", "Johnson"));
    students.back().addTarpPazymys(9);
    students.back().addTarpPazymys(10);
    students.back().setEgzaminas(9);
    students.back().calculateGalutinis();

    // Display all students
    for (size_t i = 0; i < students.size(); ++i) {
        std::cout << students[i];
    }
    std::cout << "Expected:\nJohn                Doe            9.60 9.60\nJane                Smith          7.20 7.20\nAlice               Johnson        9.20 9.20\n\n";

    // Test 4: Remove a student
    std::cout << "Test 4: Remove a student\n";
    students.erase(students.begin() + 1); // Remove the second student (Jane Smith)

    // Display remaining students
    for (size_t i = 0; i < students.size(); ++i) {
        std::cout << students[i];
    }
    std::cout << "Expected:\nJohn                Doe            9.60 9.60\nAlice               Johnson        9.20 9.20\n";
}


void atTest(){
        try {
        // Test 1: Access valid elements
        std::cout << "Test 1: Access valid elements\n";
        Vektorius<int> v;
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
        const Vektorius<int> const_v = v;
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
    Vektorius<int> v;
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
    const Vektorius<int> const_v = v;
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
    std::cout << "\nExpected: 30 20 10\n\n";
}

void operatorTest(){
        // Test 1: Equality and inequality operators
    std::cout << "Test 1: Equality and inequality operators\n";
    Vektorius<int> v1, v2, v3;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);

    v3.push_back(1);
    v3.push_back(2);

    std::cout << "v1 == v2: " << (v1 == v2 ? "true" : "false") << "\n"; // Expected: true
    std::cout << "v1 != v2: " << (v1 != v2 ? "true" : "false") << "\n"; // Expected: false
    std::cout << "v1 == v3: " << (v1 == v3 ? "true" : "false") << "\n"; // Expected: false
    std::cout << "v1 != v3: " << (v1 != v3 ? "true" : "false") << "\n"; // Expected: true
    std::cout << "\n";

    // Test 2: Less than and less than or equal operators
    std::cout << "Test 2: Less than and less than or equal operators\n";
    Vektorius<int> v4, v5;
    v4.push_back(1);
    v4.push_back(2);
    v4.push_back(3);

    v5.push_back(1);
    v5.push_back(2);
    v5.push_back(4);

    std::cout << "v4 < v5: " << (v4 < v5 ? "true" : "false") << "\n";   // Expected: true
    std::cout << "v4 <= v5: " << (v4 <= v5 ? "true" : "false") << "\n"; // Expected: true
    std::cout << "v5 < v4: " << (v5 < v4 ? "true" : "false") << "\n";   // Expected: false
    std::cout << "v5 <= v4: " << (v5 <= v4 ? "true" : "false") << "\n"; // Expected: false
    std::cout << "\n";

    // Test 3: Greater than and greater than or equal operators
    std::cout << "Test 3: Greater than and greater than or equal operators\n";
    std::cout << "v5 > v4: " << (v5 > v4 ? "true" : "false") << "\n";   // Expected: true
    std::cout << "v5 >= v4: " << (v5 >= v4 ? "true" : "false") << "\n"; // Expected: true
    std::cout << "v4 > v5: " << (v4 > v5 ? "true" : "false") << "\n";   // Expected: false
    std::cout << "v4 >= v5: " << (v4 >= v5 ? "true" : "false") << "\n"; // Expected: false
    std::cout << "\n";

    // Test 4: Comparison of vectors with different sizes
    std::cout << "Test 4: Comparison of vectors with different sizes\n";
    Vektorius<int> v6, v7;
    v6.push_back(1);
    v6.push_back(2);

    v7.push_back(1);
    v7.push_back(2);
    v7.push_back(3);

    std::cout << "v6 < v7: " << (v6 < v7 ? "true" : "false") << "\n";   // Expected: true
    std::cout << "v6 <= v7: " << (v6 <= v7 ? "true" : "false") << "\n"; // Expected: true
    std::cout << "v7 > v6: " << (v7 > v6 ? "true" : "false") << "\n";   // Expected: true
    std::cout << "v7 >= v6: " << (v7 >= v6 ? "true" : "false") << "\n"; // Expected: true
    std::cout << "v6 > v7: " << (v6 > v7 ? "true" : "false") << "\n";   // Expected: false
    std::cout << "v6 >= v7: " << (v6 >= v7 ? "true" : "false") << "\n"; // Expected: false
}

void test() {
    testDefaultConstructor();
    testSettersAndGetters();
    testCopyConstructor();
    testMoveConstructor();
    testCopyAssignment();
    testMoveAssignment();
    testOutput();
    testInput();
    insertTest();
    EmplaceTest();
    ResizeTest();
    atTest();
    dataTest();
    frontBackTest();
    beginEndTest();
    operatorTest();
    testStudVector();
    std::cout << "\nAll tests passed!\n";
}