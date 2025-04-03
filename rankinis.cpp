#include "bibl.h"

void rankinis(vector <stud> &A){
    string input;
    string vardas;
    string pavard;

    cout << "Iveskite studento Varda ir pavarde ";
    cin >> vardas >> pavard;
    stud temp(vardas,pavard);

    cout << "Veskite studento namu darbo pazymius arba N, kad sustoti ";
    
    while (true){
        try{
            cin >> input;
            if (input == "N" || input == "n") break;
            int paz = std::stoi(input);
            if (paz < 0 || paz > 10){
                throw "Ivestas neteisingas simbolis";
            }
            temp.addTarpPazymys(paz);
        }
        catch (const std::invalid_argument&){
            cout << "Ivestas neteisingas simbolis" << endl;
            continue;
        }
        catch (const char *x){
            cout << x << endl;
            continue;
        }
    }

    cout << "Iveskite studento egzamino rezultata ";
    while (true){
        try{
            cin >> input;
            int egz = std::stoi(input);
            if (egz < 0 || egz > 10){
                throw "Ivestas neteisingas simbolis";
            }
            temp.setEgzaminas(egz);
            break;
        }
        catch (const std::invalid_argument&){
            cout << "Ivestas neteisingas simbolis" << endl;
            continue;
        }
        catch (const char *x){
            cout << x << endl;
            continue;
        }
    }

    temp.calculateGalutinis();
    A.push_back(temp);    
}
