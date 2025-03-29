#include "bibl.h"

void failoNusk (vector <stud> &A){
    string failas;

    cout << "Iveskite failo pavadinima (pvz. kursiokai.txt)" << endl;
    while(true){
        cin >> failas;
        if (!(std::filesystem::exists(failas))){
            cout << "Toks failas neegzistuoja, pabandykite vel" << endl;
            continue; 
        }
        break;
    }
    
    string eil;
    Timer t;

    std::ifstream df(failas);
    getline(df,eil);

    while(getline(df,eil)){
        stud temp;
        int paz;
        std::istringstream line(eil);

        line >> temp.vard >> temp.pava;
        
        while (line >> paz){
            temp.tarp.push_back(paz);
            temp.tarpsum+=paz;
        }
        
        temp.tarpsum-=temp.tarp.back();
        temp.egz=temp.tarp.back();
        temp.tarp.pop_back();

        std::sort(temp.tarp.begin(),temp.tarp.end());
        
        temp.tarpvid=double(temp.tarpsum/temp.tarp.size());
        
        if (temp.tarp.size()%2==0){
            temp.tarpmed=(temp.tarp[(temp.tarp.size()/2)-1]+temp.tarp[(temp.tarp.size()/2)])/2;
        }
        else temp.tarpmed=temp.tarp[(temp.tarp.size()/2)];
    
        temp.galutinisvid=(temp.tarpvid*0.4)+(temp.egz*0.6);
        temp.galutinismed=temp.tarpmed*0.4+temp.egz*0.6;
        A.push_back(temp);
    }
    cout << "Perskaityt ir suskaiciuot vidurkius uztruko " << t.elapsed() << endl;
    df.close();
}