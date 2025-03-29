#include "bibl.h"

void compare(vector <stud> &A){
    while(true){
        cout << "1 - Pagal Varda " << endl;
        cout << "2 - Pagal Pavarde " << endl;
        cout << "3 - Pagal pazymiu vidurki " << endl;
        cout << "4 - Pagal pazymiu mediana " << endl;
        int input;
        try {
            if (!(cin>>input)||input<1 || input>4){
                cin.clear();
                cin.ignore();
                throw "Ivestas neteisingas simbolis";
            }
            switch(input){
                case 1:
                    std::sort(A.begin(),A.end(), compVardas);
                    break;

                case 2:
                    std::sort(A.begin(),A.end(), compPavard);
                    break;

                case 3:
                    std::sort(A.begin(),A.end(), compVid);
                    break;

                case 4:
                    std::sort(A.begin(),A.end(), compMed);
                    break;
            }
            break;
        }
        catch (char const *x){
            cout << x << endl;
            continue;
            cout << "Pagal ka isrusiuoti duomenis?" << endl;
        }
    }
}

void compare(vector <stud> &A,double &time){
    Timer laik;
    while(true){
        cout << "1 - Pagal Varda " << endl;
        cout << "2 - Pagal Pavarde " << endl;
        cout << "3 - Pagal pazymiu vidurki " << endl;
        cout << "4 - Pagal pazymiu mediana " << endl;
        int input;
        try {
            if (!(cin>>input)||input<1 || input>4){
                cin.clear();
                cin.ignore();
                throw "Ivestas neteisingas simbolis";
            }
            laik.reset();
            switch(input){
                case 1:
                    std::sort(A.begin(),A.end(), compVardas);
                    break;

                case 2:
                    std::sort(A.begin(),A.end(), compPavard);
                    break;

                case 3:
                    std::sort(A.begin(),A.end(), compVid);
                    break;

                case 4:
                    std::sort(A.begin(),A.end(), compMed);
                    break;
            }
            time+=laik.elapsed();
            break;
        }
        catch (char const *x){
            cout << x << endl;
            continue;
            cout << "Pagal ka isrusiuoti duomenis?" << endl;
        }
    }
}


void compare(std::list <stud> &A,double &time){
    Timer laik;
    while(true){
        cout << "1 - Pagal Varda " << endl;
        cout << "2 - Pagal Pavarde " << endl;
        cout << "3 - Pagal pazymiu vidurki " << endl;
        cout << "4 - Pagal pazymiu mediana " << endl;
        int input;
        try {
            if (!(cin>>input)||input<1 || input>4){
                cin.clear();
                cin.ignore();
                throw "Ivestas neteisingas simbolis";
            }
            laik.reset();
            switch(input){
                case 1:
                    A.sort(compVardas);
                    break;

                case 2:
                    A.sort(compPavard);
                    break;

                case 3:
                    A.sort(compVid);
                    break;

                case 4:
                    A.sort(compMed);
                    break;
            }
            time+=laik.elapsed();
            break;
        }
        catch (char const *x){
            cout << x << endl;
            continue;
            cout << "Pagal ka isrusiuoti duomenis?" << endl;
        }
    }
}

void compare(std::deque <stud> &A,double &time){
    Timer laik;
    while(true){
        cout << "1 - Pagal Varda " << endl;
        cout << "2 - Pagal Pavarde " << endl;
        cout << "3 - Pagal pazymiu vidurki " << endl;
        cout << "4 - Pagal pazymiu mediana " << endl;
        int input;
        try {
            if (!(cin>>input)||input<1 || input>4){
                cin.clear();
                cin.ignore();
                throw "Ivestas neteisingas simbolis";
            }
            laik.reset();
            switch(input){
                case 1:
                    std::sort(A.begin(),A.end(), compVardas);
                    break;

                case 2:
                    std::sort(A.begin(),A.end(), compPavard);
                    break;

                case 3:
                    std::sort(A.begin(),A.end(), compVid);
                    break;

                case 4:
                    std::sort(A.begin(),A.end(), compMed);
                    break;
            }
            time+=laik.elapsed();
            break;
        }
        catch (char const *x){
            cout << x << endl;
            continue;
            cout << "Pagal ka isrusiuoti duomenis?" << endl;
        }
    }
}

bool compVardas(stud &a, stud &b){
    return a.vard<b.vard;
}

bool compPavard(stud &a, stud &b){
    return a.pava<b.pava;
}

bool compVid(stud &a, stud &b){
    return a.galutinisvid<b.galutinisvid;
}

bool compMed(stud &a, stud &b){
    return a.galutinismed<b.galutinismed;
}