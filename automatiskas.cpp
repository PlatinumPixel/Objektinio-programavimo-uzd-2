#include "bibl.h"

string Vard[5] {"Jonas", "Vytautas", "Antanas", "Tomas", "Juozas"};
string Pava[5] {"Kazlauskas", "Stankevicius", "Petrauskas", "Janauskas", "Zukauskas"};

void automatiskas (vector <stud> &A){
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> vardui(0,4);
    std::uniform_int_distribution<int> pazymiui(0,10);

    cout << "Iveskite studento Varda ir pavarde ";
    stud temp(Vard[vardui(mt)],Pava[vardui(mt)]);


    for (int i=0;i<pazymiui(mt);i++){
        int paz=pazymiui(mt);
        temp.addTarpPazymys(paz);
    }
    temp.setEgzaminas(pazymiui(mt));

    temp.calculateGalutinis();
    A.push_back(temp); 
}