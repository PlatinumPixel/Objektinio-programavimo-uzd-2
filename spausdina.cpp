#include "bibl.h"

void spausdina(Vektorius <stud> A){
    cout << "Vardas              Pavarde        Galutinis(vid.) / Galutinis(med.)" << endl;
    cout << "--------------------------------------------------------------------" << endl;
for (int i=0;i<A.size();i++){
    cout << A[i];
}

}

void spausdinaFaila(Vektorius <stud> &A, string failas){
    std::ofstream rf (failas);
    rf << "Vardas              Pavarde        Galutinis(vid.) / Galutinis(med.)" << endl;
    rf << "--------------------------------------------------------------------" << endl;
for (int i=0;i<A.size();i++){
    rf << A[i];
}

}
