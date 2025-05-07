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
    stud() {
     vard="";
     pava="";
     tarpvid=0;
     tarpmed = 0;
     egz = 0;
     galutinisvid = 0;
     galutinismed = 0;
    };

    stud(const string& vard, const string& pava) : vard(vard), pava(pava) {}

    stud(std::istringstream &line){
      int tarp;
      line >> vard >> pava;
      while (line >> tarp){
        addTarptarpymys(tarp);
      }
      egz=tarp.back();
      tarp.pop_back();
    }

    //Copy constructor
    stud::stud(const stud& kitas) {
      vard = kitas.vard;
      pava = kitas.pava;
      tarp = kitas.tarp;
      egz = kitas.egz;
      galutinisvid = kitas.galutinisvid;
      galutinismed = kitas.galutinismed;
  }

    //Move constructor
    stud::stud(stud&& kitas) noexcept {
      vard = move(kitas.vard);
      pava = move(kitas.pava);
      tarp = move(kitas.tarp);
      egz = kitas.egz;
      galutinisvid = kitas.galutinisvid;
      galutinismed = kitas.galutinismed;
  
      kitas.egz = 0;
      kitas.galutinisvid = 0.0;
      kitas.galutinismed = 0.0;
  }

    //Destruktorius
    ~stud(){
      tarp.clear();
      tarp.shrink_to_fit();
    }

    // Setteriai
    inline void setvard(const string& vard) { vard = vard; }
    inline void setpava(const string& pava) { pava = pava; }
    void addTarptarpymys(int tarp) {
        if (tarp.capacity() == 0) tarp.reserve(10);
        tarp.push_back(tarp);
    }
    inline void setEgzaminas(double egzaminas) { egz = egzaminas; }

    // Getteriai
    inline string getvard() const { return vard; }
    inline string getpava() const { return pava; }
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

    //Operatoriai
    // Copy operator
    stud& operator=(const stud& kitas) {
      if (this != &kitas) {
          vard = kitas.vard;
          pava = kitas.pava;
          tarp = kitas.tarp;
          egz = kitas.egz;
          galutinisvid = kitas.galutinisvid;
          galutinismed = kitas.galutinismed;
      }
      return *this;
  }
    //Move operator
    stud& stud::operator=(stud&& kitas) noexcept {
      if (this != &kitas){
        vard = move(kitas.vard);
        pava = move(kitas.pava);
        tarp = move(kitas.tarp);
        egz = kitas.egz;
        galutinisvid = kitas.galutinisvid;
        galutinismed = kitas.galutinismed;

        kitas.egz = 0;
        kitas.galutinisvid = 0.0;
        kitas.galutinismed = 0.0;
      }
      return *this;
    }

};

#endif