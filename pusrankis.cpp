#include "bibl.h"

void pusrankis(vector <stud> &A){
    stud temp;  
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution <int> dist(0,10);
    cout << "Iveskite studento Varda ir pavarde ";
    cin >> temp.vard >> temp.pava;
    for (int i=0;i<dist(mt);i++){
        int paz=dist(mt);
        temp.tarp.push_back(paz);
        temp.tarpsum+=paz;
    }
    std::sort(temp.tarp.begin(),temp.tarp.end());
    temp.egz=dist(mt);

    temp.tarpvid=double(temp.tarpsum/temp.tarp.size());
    if (temp.tarp.size()%2==0){
        temp.tarpmed=(temp.tarp[(temp.tarp.size()/2)-1]+temp.tarp[(temp.tarp.size()/2)])/2;
    }
    else temp.tarpmed=temp.tarp[(temp.tarp.size()/2)];

    temp.galutinisvid=(temp.tarpvid*0.4)+(temp.egz*0.6);
    temp.galutinismed=temp.tarpmed*0.4+temp.egz*0.6;
    A.push_back(temp); 
}