#ifndef STUD_H
#define STUD_H

#include "std.h"
#include <numeric>

class stud {
private:
    string vard;
    string pava;
    vector<int> tarp;
    double tarpvid = 0;
    double tarpmed = 0;
    double egz = 0;
    double galutinisvid = 0;
    double galutinismed = 0;

public:
    // Construktoriai
    stud() = default;
    stud(const string& vardas, const string& pavarde) : vard(vardas), pava(pavarde) {}
    stud(std::istringstream &line){
      int paz;
      line >> vard >> pava;
      while (line >> paz){
        addTarpPazymys(paz);
      }
      egz=tarp.back();
      tarp.pop_back();
    }

    //Destruktorius
    ~stud(){
      tarp.clear();
      tarp.shrink_to_fit();
    }

    // Setteriai
    inline void setVardas(const string& vardas) { vard = vardas; }
    inline void setPavarde(const string& pavarde) { pava = pavarde; }
    void addTarpPazymys(int paz) {
        if (tarp.capacity() == 0) tarp.reserve(10);
        tarp.push_back(paz);
    }
    inline void setEgzaminas(double egzaminas) { egz = egzaminas; }

    // Getteriai
    inline string getVardas() const { return vard; }
    inline string getPavarde() const { return pava; }
    double getGalutinisVid() const { return galutinisvid; }
    double getGalutinisMed() const { return galutinismed; }

    // Galutinio apskaiciavimas
    void calculateGalutinis() {
      if (!tarp.empty()) {
        tarpvid = accumulate(tarp.begin(),tarp.end(),0) / double(tarp.size());
        std::sort(tarp.begin(), tarp.end());
        if (tarp.size() % 2 == 0) {
            tarpmed = (tarp[tarp.size() / 2 - 1] + tarp[tarp.size() / 2]) / 2.0;
        } else {
            tarpmed = tarp[tarp.size() / 2];
        }
      }
        galutinisvid = (tarpvid * 0.4) + (egz * 0.6);
        galutinismed = (tarpmed * 0.4) + (egz * 0.6);
    }

};

#endif