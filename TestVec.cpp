#include "bibl.h"
#include <algorithm>
#include <iterator>

bool vid;


void TestVector(){
    string failas;
    vector <stud> visi;
    vector <stud> nuskriausti;
    vector <stud> kietiakai;
    
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
    df.close();
    visaTrukme+=t.elapsed();
    cout << "Duomenis nuskaityti uztruko " << visaTrukme << endl;
    t.reset();


    /* 1 strategija
    for (int i=0;i<visi.size();i++){
        if (vid==1 && visi[i].galutinisvid<5.0){
            nuskriausti.push_back(visi[i]);
        }
        else if(vid==0 && visi[i].galutinismed<5.0) {
             nuskriausti.push_back(visi[i]);
             
            }
            else kietiakai.push_back(visi[i]);
        }
    visi.clear();
    */

    
    /* 2 strategija
    auto it = std::partition(visi.begin(), visi.end(), [](const stud &s)
    {
        return s.galutinisvid >= 5.0; // Keep students with an average >= 5.0
    });
    nuskriausti.insert(nuskriausti.end(), it, visi.end());
    visi.erase(it, visi.end());
    */

    std::remove_copy_if(visi.begin(), visi.end(), std::back_inserter(nuskriausti), [](const stud &s) {
        return s.galutinisvid >= 5.0;
    });

    visi.erase(std::remove_if(visi.begin(), visi.end(), [](const stud &s) {
        return s.galutinisvid < 5.0;
    }), visi.end());
    
    visaTrukme+=t.elapsed();
    cout << "Mokinius isrusiuoti i atskirus konteinerius uztruko " << t.elapsed() << endl;
    

    double trukme=0;
    cout << "Pagal ka isrikiuoti kietiaku duomenis?" << endl;
    compare(nuskriausti,trukme);
    cout << "Pagal ka isrikiuoti kietiaku duomenis?" << endl;
    compare(visi,trukme);
    visaTrukme+=trukme;
    cout << "Duomenis isrikiuoti uztruko " << trukme << endl;
    t.reset();

    //visi.shrink_to_fit();



    //     spausdinimas del patikrinimo ar programa istikruju veikia    
    //    spausdinaFaila(nuskriausti,"nuskriausti "+failas);
    //  spausdinaFaila(visi,"kietiakai "+failas);
    cout << "Isviso uztruko: "<< visaTrukme<< endl;

}
