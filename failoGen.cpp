#include "bibl.h"

void failoGen(){
    string failas;
    int kiek;
    int pazkiek;
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution <int> pazymiui(0,10);
    Timer t;
    
    cout << "Iveskite failo pavadinima (pvz. kursiokai)" << endl;
    cin >> failas;
    cout << "Iveskite kiek sugeneruoti studentu" << endl;
    cin >> kiek;
    cout << "Iveskite kiek pazymiu tures studentai (neskaiciuojant egzamino)" << endl;
    cin >> pazkiek;
    
    t.reset();
    std::stringstream eil;

    std::ofstream rf(failas+".txt");

    eil <<std::left <<setw(15)<< "Vardas"<< setw(15) << "Pavarde" ; 
    for (int i=1;i<=pazkiek;i++){
        eil  << "ND"<< setw(5) <<std::to_string(i);
    }
    eil <<  "Egz." << "\n";

    rf << eil.str();

    eil.str("");
    
    for (int i=1;i<=kiek;i++){
        eil<<setw(15) <<"Vardas" + to_string(i) <<setw(15)<< "Pavarde" + to_string(i);
        for (int j=0;j<pazkiek;j++){
            eil << setw(7) << pazymiui(mt); 
        }
        eil << setw(7) << pazymiui(mt) << "\n";
        rf << eil.str();
        eil.str("");
    }
    rf.close();
    cout << "failu kurimas ir jo uzdarymas uztruko " << t.elapsed() << endl;
}