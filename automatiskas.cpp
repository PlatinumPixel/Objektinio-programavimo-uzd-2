#include "bibl.h"

string Vard[5] {"Jonas", "Vytautas", "Antanas", "Tomas", "Juozas"};
string Pava[5] {"Kazlauskas", "Stankevicius", "Petrauskas", "Janauskas", "Zukauskas"};

void automatiskas (vector <stud> &A){
    stud temp;  

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> vardui(0,4);
    std::uniform_int_distribution<int> pazymiui(0,10);

    temp.vard=Vard[vardui(mt)];
    temp.pava=Pava[vardui(mt)];


    for (int i=0;i<pazymiui(mt);i++){
        int paz=pazymiui(mt);
        temp.tarp.push_back(paz);
        temp.tarpsum+=paz;
    }
    std::sort(temp.tarp.begin(),temp.tarp.end());
    temp.egz=pazymiui(mt);

    temp.tarpvid=double(temp.tarpsum/temp.tarp.size());
    if (temp.tarp.size()%2==0){
        temp.tarpmed=(temp.tarp[(temp.tarp.size()/2)-1]+temp.tarp[(temp.tarp.size()/2)])/2;
    }
    else temp.tarpmed=temp.tarp[(temp.tarp.size()/2)];

    temp.galutinisvid=(temp.tarpvid*0.4)+(temp.egz*0.6);
    temp.galutinismed=temp.tarpmed*0.4+temp.egz*0.6;
    A.push_back(temp); 
}