#include "bibl.h"

void spausdina(vector <stud> A){
    cout << "Vardas              Pavarde        Galutinis(vid.) / Galutinis(med.)" << endl;
    cout << "--------------------------------------------------------------------" << endl;
for (int i=0;i<A.size();i++){
    cout << std::left << setw(20) << A[i].vard << setw(15) << A[i].pava
         << setw(18) << std::fixed << std::setprecision(2) << A[i].galutinisvid << " " << A[i].galutinismed << endl;
}

}

void spausdinaFaila(vector <stud> &A, string failas){
    std::ofstream rf (failas);
    rf << "Vardas              Pavarde        Galutinis(vid.) / Galutinis(med.)" << endl;
    rf << "--------------------------------------------------------------------" << endl;
for (int i=0;i<A.size();i++){
    rf << std::left << setw(20) << A[i].vard << setw(15) << A[i].pava
         << setw(18) << std::fixed << std::setprecision(2) << A[i].galutinisvid << " " << A[i].galutinismed << endl;
}

}

void spausdinaFaila(std::list <stud> &A, string failas){
    std::ofstream rf (failas);
    rf << "Vardas              Pavarde        Galutinis(vid.) / Galutinis(med.)" << endl;
    rf << "--------------------------------------------------------------------" << endl;
for (int i=0;i<A.size();i++){

}
for (stud temp: A){
    rf << std::left << setw(20) << temp.vard << setw(15) << temp.pava
         << setw(18) << std::fixed << std::setprecision(2) << temp.galutinisvid << " " << temp.galutinismed << endl;
}

}

void spausdinaFaila(std::deque <stud> &A, string failas){
    std::ofstream rf (failas);
    rf << "Vardas              Pavarde        Galutinis(vid.) / Galutinis(med.)" << endl;
    rf << "--------------------------------------------------------------------" << endl;
for (int i=0;i<A.size();i++){
    rf << std::left << setw(20) << A[i].vard << setw(15) << A[i].pava
         << setw(18) << std::fixed << std::setprecision(2) << A[i].galutinisvid << " " << A[i].galutinismed << endl;
}

}