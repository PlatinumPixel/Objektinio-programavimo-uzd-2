#include "bibl.h"
#include "list"

void TestList(){
    string failas;
    std::list <stud> visi;
    std::list <stud> nuskriausti;
    std::list <stud> kietiakai;
    bool vid;
    double visaTrukme=0;
    cout << "Iveskite failo pavadinima (pvz. kursiokai.txt)" << endl;
    while(true){
        try{
            cin >> failas;
            if (!(std::filesystem::exists(failas))){
                cin.clear();
                cin.ignore();
                throw "Toks failas neegzistuoja, pabandykite vel";
            }
            break;
        }
        catch (char const *x){
            cout << x << endl;
            continue;
        }
    }

    while(true){
        cout << "Pagal ka atrinkti studentus?" << endl;
        cout << "1 - Pagal pazymiu vidurki " << endl;
        cout << "2 - Pagal pazymiu mediana " << endl;
        int input;
        try {
            if (!(cin>>input)||input<1 || input>2){
                cin.clear();
                cin.ignore();
                throw "Ivestas neteisingas simbolis";
            }
            switch(input){
                case 1:
                    vid=1;
                    break;

                case 2:
                    vid=0;
                    break;
            }
        break;
        }
        catch (char const *x){
            cout << x << endl;
            continue;
        }
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

        visi.push_back(temp);

    }

    visaTrukme+=t.elapsed();
    cout << "Duomenis nuskaityti uztruko " << visaTrukme << endl;
    t.reset();


    /* 1 strategija
    for (stud temp: visi){
        if (vid==1 && temp.galutinisvid<5.0){
            nuskriausti.push_back(temp);
        }
        else if(vid==0 && temp.galutinismed<5.0) {
             nuskriausti.push_back(temp);
            }
            else kietiakai.push_back(temp);
        }
    visi.clear();
    */




    // 2 strategija
    visi.remove_if([&](const stud &s) {
        if (vid == 1) {
            if (s.galutinisvid < 5.0) {
                nuskriausti.push_back(s);
                return true; // Remove from visi
            }
        } 
        else {
            if (s.galutinismed < 5.0) {
                nuskriausti.push_back(s);
                return true; // Remove from visi
            }
        }
        return false; // Keep in visi
    });


    visaTrukme+=t.elapsed();
    cout << "Mokinius isrusiuoti i atskirus konteinerius uztruko " << t.elapsed() << endl;
    double trukme=0;
    
    
    cout << "Pagal ka isrikiuoti nuskriaustu duomenis?" << endl;
    compare(nuskriausti,trukme);
    cout << "Pagal ka isrikiuoti kietiaku duomenis?" << endl;
    compare(visi,trukme);
    visaTrukme+=trukme;
    cout << "Duomenis isrikiuoti uztruko " << trukme << endl;

    //     spausdinimas del patikrinimo ar programa istikruju veikia    
       spausdinaFaila(nuskriausti,"nuskriausti "+failas);
       spausdinaFaila(visi,"kietiakai "+failas);
    cout << "Isviso uztruko: "<< visaTrukme<< endl;
}
