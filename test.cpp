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

void testStudCopyConstructor() {
    stud s1;
    s1.setvard("Jonas");
    s1.setpava("Jonaitis");
    s1.addTarpPazymys(8);
    s1.setEgzaminas(9);
    s1.calculateGalutinis();

    stud s2(s1);

    assert(s2.getVardas() == "Jonas");
    assert(s2.getPavarde() == "Jonaitis");
    assert(s2.getTarp() == s1.getTarp());
    assert(s2.getEgz() == 9);
    assert(s2.getGalutinisVid() == s1.getGalutinisVid());
    assert(s2.getGalutinisMed() == s1.getGalutinisMed());
}

void testStudCopyAssignment() {
    stud s1;
    s1.setvard("Petras");
    s1.setpava("Petraitis");
    s1.addTarpPazymys(7);
    s1.setEgzaminas(8);
    s1.calculateGalutinis();

    stud s2;
    s2 = s1;

    assert(s2.getVardas() == "Petras");
    assert(s2.getPavarde() == "Petraitis");
    assert(s2.getTarp() == s1.getTarp());
    assert(s2.getEgz() == 8);
    assert(s2.getGalutinisVid() == s1.getGalutinisVid());
    assert(s2.getGalutinisMed() == s1.getGalutinisMed());
}

void testStudMoveConstructor() {
    stud s1;
    s1.setvard("Ona");
    s1.setpava("Onaite");
    s1.addTarpPazymys(10);
    s1.setEgzaminas(10);
    s1.calculateGalutinis();

    stud s2(std::move(s1)); 

    assert(s2.getVardas() == "Ona");
    assert(s2.getPavarde() == "Onaite");
    assert(s2.getEgz() == 10);

}

void testStudMoveAssignment() {
    stud s1;
    s1.setvard("Ieva");
    s1.setpava("Ievaite");
    s1.addTarpPazymys(6);
    s1.setEgzaminas(7);
    s1.calculateGalutinis();

    stud s2;
    s2 = std::move(s1); 

    assert(s2.getVardas() == "Ieva");
    assert(s2.getPavarde() == "Ievaite");
    assert(s2.getEgz() == 7);

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
    testStudCopyConstructor();
    testStudCopyAssignment();
    testStudMoveConstructor();
    testStudMoveAssignment();
    testOutput();
    testInput();
    
    std::cout << "\nAll tests passed!\n";
}