#include "bibl.h"

void rankinis(vector <stud> &A){
    stud temp; 
    string input; 

    cout << "Iveskite studento Varda ir pavarde ";
    cin >> temp.vard >> temp.pava;

    cout << "Veskite studento namu darbo pazymius arba N, kad sustoti ";
    
    while (true){
        try{
            cin >> input;
            if (input == "N" || input == "n") break;
            int grade = std::stoi(input);
            if (grade < 0 || grade > 10){
                throw "Ivestas neteisingas simbolis";
            }
            temp.tarp.push_back(grade);
            temp.tarpsum += grade;
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

    std::sort(temp.tarp.begin(), temp.tarp.end());

    cout << "Iveskite studento egzamino rezultata ";
    while (true){
        try{
            cin >> input;
            int egz = std::stoi(input);
            if (egz < 0 || egz > 10){
                throw "Ivestas neteisingas simbolis";
            }
            temp.egz = egz;
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

    temp.tarpvid = double(temp.tarpsum / temp.tarp.size());
    if (temp.tarp.size() % 2 == 0){
        temp.tarpmed = (temp.tarp[(temp.tarp.size() / 2) - 1] + temp.tarp[temp.tarp.size() / 2]) / 2;
    }
    else {
        temp.tarpmed = temp.tarp[temp.tarp.size() / 2];
    }

    temp.galutinisvid = (temp.tarpvid * 0.4) + (temp.egz * 0.6);
    temp.galutinismed = temp.tarpmed * 0.4 + temp.egz * 0.6;
    A.push_back(temp);    
}
