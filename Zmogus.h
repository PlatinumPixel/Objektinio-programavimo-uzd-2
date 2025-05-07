#ifndef STUD_H
#define STUD_H

#include "std.h"
#include <numeric>

class zmogus {
private:
    string vard;
    string pava;
public:
    // Construktoriai
    zmogus() {
     vard="";
     pava="";
    };

    zmogus(const string& vard, const string& pava) : vard(vard), pava(pava) {}


    // Setteriai
    inline void setvard(const string& vardas) { vard = vardas; }
    inline void setpava(const string& pavard) { pava = pavard; }

    // Getteriai
    inline string getVardas() const { return vard; }
    inline string getPavarde() const { return pava; }

};

#endif