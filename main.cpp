#include "bibl.h"

vector <stud> A;

int main(){  
    int input;
    string failas;
    while ((true)){
        cout << "Iveskite skaiciu kokiu budu norite ivesti duomenis " << endl;
        cout << "1 - Iveskite visus duomenis rankiniu budu " << endl;
        cout << "2 - Iveskite varda ir pavarde rankniu budu " << endl;
        cout << "3 - Sugeneruoti visus duomenis automatiskai " << endl;
        cout << "4 - Paiimti duomenis is failo " << endl;
        cout << "5 - Sugeneruoti nauja duomenu faila " << endl;
        cout << "6 - Surusiuoti faila i vargsiukus ir kietiakus " << endl;        
        cout << "7 - Baigti darba ir spausdinti " << endl;
        try {
            if (!(cin>>input)||input<1 || input>7){
                cin.clear();
                cin.ignore();
                throw "Ivestas neteisingas simbolis";
            } 
        
            switch(input){
                case 1:
                    rankinis(A);
                    break;

                case 2:
                    pusrankis(A);
                    break;

                case 3:
                    int n;
                    cout << "Iveskite kiek mokiniu generuoti" << endl;
                    cin >> n;
                    for (int i=0;i<n;i++){
                        automatiskas(A);        
                    }
                    break;

                case 4:
                    failoNusk(A);
                    break;
                
                case 5:
                    failoGen();
                    break;

                case 6:
                    rusiavimas();
                    break;

                case 7:
                    cout << "Pagal ka isrusiuoti duomenis?" << endl;
                    compare(A);
                    spausdina(A);
                    return 0;
                default:
                    cout << "Ivedete neteisinga simobli, pabandykit vel! :)" << endl;
                    break;
        }
        }   
        catch (char const *x){
            cout << x << endl;
            continue;
        }
    
    }
 return 0;
}
