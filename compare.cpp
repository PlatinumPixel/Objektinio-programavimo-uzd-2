#include "bibl.h"

void compare(Vektorius <stud> &A){
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

void compare(Vektorius <stud> &A,double &time){
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
    return a.getVardas()<b.getVardas();
  }
  
  bool compPavard(stud &a, stud &b){
    return a.getPavarde()<b.getPavarde();
  }
  
  bool compVid(stud &a, stud &b){
    return a.getGalutinisVid()<b.getGalutinisVid();
  }
  
  bool compMed(stud &a, stud &b){
    return a.getGalutinisMed()<b.getGalutinisMed();
  }
