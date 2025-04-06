#include "bibl.h"

void rusiavimas(){
    string failas;
    vector <stud> visi;
    vector <stud> nuskriausti;
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
        std::istringstream line(eil);
        stud temp(line);
        temp.calculateGalutinis();
        visi.push_back(std::move(temp));

    }
    df.close();
    visaTrukme+=t.elapsed();
    cout << "Duomenis nuskaityti uztruko " << visaTrukme << endl;
    t.reset();

    if (vid==1){
        for (int i=0;i<visi.size();i++){
            std::remove_copy_if(visi.begin(), visi.end(), std::back_inserter(nuskriausti), [](const stud &s) {
                return s.getGalutinisVid() >= 5.0;
            });
        
            visi.erase(std::remove_if(visi.begin(), visi.end(), [](const stud &s) {
                return s.getGalutinisVid() < 5.0;
            }), visi.end());
        }
    }   
    else{ 
        for (int i=0;i<visi.size();i++){
            std::remove_copy_if(visi.begin(), visi.end(), std::back_inserter(nuskriausti), [](const stud &s) {
                return s.getGalutinisMed() >= 5.0;
            });
        
            visi.erase(std::remove_if(visi.begin(), visi.end(), [](const stud &s) {
                return s.getGalutinisMed() < 5.0;
            }), visi.end());
        }
    }

    visaTrukme+=t.elapsed();
    cout << "Mokinius isrusiuoti i atskirus konteinerius uztruko " << t.elapsed() << endl;
    double trukme=0;
    
    
    cout << "Pagal ka isrikiuoti nuskriaustu duomenis?" << endl;
    compare(nuskriausti,trukme);
    cout << "Pagal ka isrikiuoti kietiaku duomenis?" << endl;
    compare(visi,trukme);
    visaTrukme+=trukme;
    cout << "Duomenis isrikiuoti uztruko " << trukme << endl;

    t.reset();
    spausdinaFaila(nuskriausti,"nuskriausti "+failas);
    spausdinaFaila(visi,"kietiakai "+failas);
    visaTrukme+=t.elapsed();
    cout << "Duomenis atspausdinti uztruko "<< t.elapsed()<< endl;
    cout << "Isviso uztruko: "<< visaTrukme<< endl;  
}

