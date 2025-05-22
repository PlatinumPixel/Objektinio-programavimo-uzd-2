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



void test() {
    testDefaultConstructor();
    testSettersAndGetters();
    testCopyConstructor();
    testMoveConstructor();
    testCopyAssignment();
    testMoveAssignment();
    testOutput();
    //testInput();          //Užkomentuotas kad butu automatizuoti testai
    std::cout << "\nAll tests passed!\n";
}