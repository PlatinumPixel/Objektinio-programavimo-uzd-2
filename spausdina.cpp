#include "bibl.h"

void spausdina(vector <stud> A){
    cout << "Vardas              Pavarde        Galutinis(vid.) / Galutinis(med.)" << endl;
    cout << "--------------------------------------------------------------------" << endl;
for (int i=0;i<A.size();i++){
    cout << std::left << setw(20) << A[i].getVardas() << setw(15) << A[i].getPavarde()
         << setw(18) << std::fixed << std::setprecision(2) << A[i].getGalutinisVid() << " " << A[i].getGalutinisMed() << endl;
}

}

void spausdinaFaila(vector <stud> &A, string failas){
    std::ofstream rf (failas);
    rf << "Vardas              Pavarde        Galutinis(vid.) / Galutinis(med.)" << endl;
    rf << "--------------------------------------------------------------------" << endl;
for (int i=0;i<A.size();i++){
    rf << std::left << setw(20) << A[i].getVardas() << setw(15) << A[i].getPavarde()
         << setw(18) << std::fixed << std::setprecision(2) << A[i].getGalutinisVid() << " " << A[i].getGalutinisMed() << endl;
}

}
