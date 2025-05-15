#include "bibl.h"

void rankinis(Vektorius <stud> &A){
    string input;
    string vardas;
    string pavard;
    stud temp;
    cout << "Iveskite studento Varda ir pavarde ";
    cin >> temp;
    temp.calculateGalutinis();
    A.push_back(temp);    
}
