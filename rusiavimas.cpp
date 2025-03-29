#include "bibl.h"

void rusiavimas(){
    string failas;
    vector <stud> visi;
    vector <stud> nuskriausti;
    vector <stud> kietiakai;
    bool vid;
    double visaTrukme=0;
    cout << "Iveskite failo pavadinima (pvz. kursiokai.txt)" << endl;
    while(true){
        cin >> failas;
        if (!(std::filesystem::exists(failas))){
            cout << "Toks failas neegzistuoja, pabandykite vel" << endl;
            continue; 
        }
        break;
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

    if (vid==1){
        for (int i=0;i<visi.size();i++){
            if (visi[i].galutinisvid<5.0){
                nuskriausti.push_back(visi[i]);
            }
            else kietiakai.push_back(visi[i]); 
        }
    }   
    else{ 
        for (int i=0;i<visi.size();i++){
            if (visi[i].galutinismed<5.0){
                nuskriausti.push_back(visi[i]);
            } 
            else kietiakai.push_back(visi[i]); 
        }
    }
    visi.clear();

    visaTrukme+=t.elapsed();
    cout << "Mokinius isrusiuoti i atskirus konteinerius uztruko " << t.elapsed() << endl;
    double trukme=0;
    
    
    cout << "Pagal ka isrikiuoti nuskriaustu duomenis?" << endl;
    compare(nuskriausti,trukme);
    cout << "Pagal ka isrikiuoti kietiaku duomenis?" << endl;
    compare(kietiakai,trukme);
    visaTrukme+=trukme;
    cout << "Duomenis isrikiuoti uztruko " << trukme << endl;

    t.reset();
    spausdinaFaila(nuskriausti,"nuskriausti "+failas);
    spausdinaFaila(kietiakai,"kietiakai "+failas);
    visaTrukme+=t.elapsed();
    cout << "Duomenis atspausdinti uztruko "<< t.elapsed()<< endl;
    cout << "Isviso uztruko: "<< visaTrukme<< endl;  
}

