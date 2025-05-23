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
        cout << "7 - Veikimo laiko testavimas su vector, list ir deque " << endl;
        cout << "8 - Baigti darba ir spausdinti " << endl;
        try {
            if (!(cin>>input)||input<1 || input>8){
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
                    while ((true)){
                        cout << "Iveskite kuri duomenu tipa testuoti " << endl;
                        cout << "1 - Vector " << endl;
                        cout << "2 - List " << endl;
                        cout << "3 - Deque " << endl;
                        try {
                            if (!(cin>>input)||input<1 || input>3){
                                cin.clear();
                                cin.ignore();
                                throw "Ivestas neteisingas simbolis";
                            } 
                        
                        switch(input){
                            case 1:
                                TestVector();
                                return 0;
            
                            case 2:
                                TestList();
                                return 0;
            
                            case 3:
                                TestDeque();
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
                case 8:
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
