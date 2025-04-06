#include "bibl.h"

void pusrankis(vector <stud> &A){
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution <int> dist(0,10);
    string vardas;
    string pavard;

    cout << "Iveskite studento Varda ir pa ";
    cin >> vardas >> pavard;
    stud temp(vardas,pavard);
    for (int i=0;i<dist(mt);i++){
        int paz=dist(mt);
        temp.addTarpPazymys(paz);
    }
    temp.setEgzaminas(dist(mt));

    temp.calculateGalutinis();
    A.push_back(temp); 
}