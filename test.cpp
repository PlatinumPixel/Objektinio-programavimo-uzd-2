#include <cassert> 
#include "bibl.h"
#include "Vektorius.h"
#include <iostream>
#include "stud.h"
#include <stdexcept>

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


template<typename T>
void assertVektoriusEquals(const Vektorius<T>& v, const std::vector<T>& expected) {
    assert(v.size() == expected.size());
    for (size_t i = 0; i < v.size(); ++i) {
        assert(v[i] == expected[i]);
    }
}

void frontBackTest() {
    Vektorius<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    assert(v.front() == 10);
    assert(v.back() == 30);

    v.front() = 5;
    v.back() = 35;
    assertVektoriusEquals(v, {5, 20, 35});

    Vektorius<int> empty_v;
    try {
        (void)empty_v.front();
        assert(false); // Should not reach here
    } catch (const std::out_of_range&) {}
    try {
        (void)empty_v.back();
        assert(false); // Should not reach here
    } catch (const std::out_of_range&) {}
    std::cout << "frontBackTest sekmingas!\n";
}

void dataTest() {
    Vektorius<int> v2;
    v2.push_back(100);
    v2.push_back(200);
    v2.push_back(300);

    int* raw_data = v2.storage();
    assert(raw_data[0] == 100);
    assert(raw_data[1] == 200);
    assert(raw_data[2] == 300);
    std::cout << "dataTest sekmingas!\n";
}

void insertTest() {
    Vektorius<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.insert(v.begin() + 2, 3);
    assertVektoriusEquals(v, {1, 2, 3, 4});

    int value = 5;
    v.insert(v.end(), std::move(value));
    assertVektoriusEquals(v, {1, 2, 3, 4, 5});

    v.insert(v.begin() + 1, 3, 10);
    assertVektoriusEquals(v, {1, 10, 10, 10, 2, 3, 4, 5});

    std::vector<int> range = {6, 7, 8};
    v.insert(v.end(), range.begin(), range.end());
    assertVektoriusEquals(v, {1, 10, 10, 10, 2, 3, 4, 5, 6, 7, 8});
    std::cout << "insertTest sekmingas!\n";
}

void EmplaceTest() {
    Vektorius<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(4);
    v1.emplace(v1.begin() + 2, 3);
    assertVektoriusEquals(v1, {1, 2, 3, 4});

    Vektorius<std::string> v2;
    v2.push_back("Hello");
    v2.push_back("World");
    v2.emplace(v2.begin() + 1, "Beautiful");
    assertVektoriusEquals(v2, {"Hello", "Beautiful", "World"});

    Vektorius<std::pair<int, std::string>> v3;
    v3.emplace(v3.begin(), 1, "One");
    v3.emplace(v3.end(), 2, "Two");
    assert(v3.size() == 2);
    assert(v3[0] == std::make_pair(1, std::string("One")));
    assert(v3[1] == std::make_pair(2, std::string("Two")));
    std::cout << "EmplaceTest sekmingas!\n";
}

void ResizeTest() {
    Vektorius<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.resize(6);
    assert(v1.size() == 6);
    assert(v1[0] == 1 && v1[1] == 2 && v1[2] == 3);

    v1.resize(2);
    assert(v1.size() == 2);
    assert(v1[0] == 1 && v1[1] == 2);

    Vektorius<std::string> v2;
    v2.resize(3);
    assert(v2.size() == 3);
    assert(v2[0] == "" && v2[1] == "" && v2[2] == "");
    std::cout << "ResizeTest sekmingas!\n";
}

void atTest() {
    Vektorius<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    assert(v.at(0) == 10);
    assert(v.at(1) == 20);
    assert(v.at(2) == 30);

    v.at(1) = 50;
    assert(v.at(1) == 50);

    const Vektorius<int> const_v = v;
    assert(const_v.at(0) == 10);
    assert(const_v.at(1) == 50);
    assert(const_v.at(2) == 30);

    try {
        (void)v.at(3);
        assert(false);
    } catch (const std::out_of_range&) {}
    std::cout << "atTest sekmingas!\n";
}

void beginEndTest() {
    Vektorius<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    std::vector<int> forward;
    for (auto it = v.begin(); it != v.end(); ++it) forward.push_back(*it);
    assert(forward == std::vector<int>({10, 20, 30}));

    std::vector<int> reverse;
    for (auto it = v.rbegin(); it != v.rend(); ++it) reverse.push_back(*it);
    assert(reverse == std::vector<int>({30, 20, 10}));

    const Vektorius<int> const_v = v;
    std::vector<int> cforward;
    for (auto it = const_v.cbegin(); it != const_v.cend(); ++it) cforward.push_back(*it);
    assert(cforward == std::vector<int>({10, 20, 30}));

    std::vector<int> creverse;
    for (auto it = const_v.crbegin(); it != const_v.crend(); ++it) creverse.push_back(*it);
    assert(creverse == std::vector<int>({30, 20, 10}));
    std::cout << "beginEndTest sekmingas!\n";
}

void operatorTest() {
    Vektorius<int> v1, v2, v3;
    v1.push_back(1); v1.push_back(2); v1.push_back(3);
    v2.push_back(1); v2.push_back(2); v2.push_back(3);
    v3.push_back(1); v3.push_back(2);

    assert(v1 == v2);
    assert(!(v1 != v2));
    assert(!(v1 == v3));
    assert(v1 != v3);

    Vektorius<int> v4, v5;
    v4.push_back(1); v4.push_back(2); v4.push_back(3);
    v5.push_back(1); v5.push_back(2); v5.push_back(4);

    assert(v4 < v5);
    assert(v4 <= v5);
    assert(!(v5 < v4));
    assert(!(v5 <= v4));

    assert(v5 > v4);
    assert(v5 >= v4);
    assert(!(v4 > v5));
    assert(!(v4 >= v5));

    Vektorius<int> v6, v7;
    v6.push_back(1); v6.push_back(2);
    v7.push_back(1); v7.push_back(2); v7.push_back(3);

    assert(v6 < v7);
    assert(v6 <= v7);
    assert(v7 > v6);
    assert(v7 >= v6);
    assert(!(v6 > v7));
    assert(!(v6 >= v7));
    std::cout << "operatorTest sekmingas!\n";
}

void testStudVector() {
    Vektorius<stud> students;

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

    students.push_back(s1);
    students.push_back(s2);

    assert(students.size() == 2);
    assert(students[0].getVardas() == "John");
    assert(students[1].getPavarde() == "Smith");

    students[0].addTarpPazymys(10);
    students[0].calculateGalutinis();
    assert(students[0].getVardas() == "John");

    students.push_back(stud("Alice", "Johnson"));
    students.back().addTarpPazymys(9);
    students.back().addTarpPazymys(10);
    students.back().setEgzaminas(9);
    students.back().calculateGalutinis();
    assert(students.size() == 3);
    assert(students.back().getVardas() == "Alice");

    students.erase(students.begin() + 1);
    assert(students.size() == 2);
    assert(students[1].getVardas() == "Alice");
    std::cout << "testStudVector sekmingas!\n";
}

void test() {
    testDefaultConstructor();
    testSettersAndGetters();
    testCopyConstructor();
    testMoveConstructor();
    testCopyAssignment();
    testMoveAssignment();
    testOutput();
    //testInput();          //Užkomentuotas kad butu automatizuoti testai
    frontBackTest();
    dataTest();
    insertTest();
    EmplaceTest();
    ResizeTest();
    atTest();
    beginEndTest();
    operatorTest();
    testStudVector();
    std::cout << "\nAll tests passed!\n";
}