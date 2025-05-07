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
      int paz;
      line >> vard >> pava;
      while (line >> paz){
        addTarpPazymys(paz);
      }
      egz=tarp.back();
      tarp.pop_back();
    }

    //Copy constructor
    stud(const stud& kitas) {
      vard = kitas.vard;
      pava = kitas.pava;
      tarp = kitas.tarp;
      egz = kitas.egz;
      galutinisvid = kitas.galutinisvid;
      galutinismed = kitas.galutinismed;
  }

    //Move constructor
    stud(stud&& kitas) noexcept {
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
    inline void setvard(const string& vardas) { vard = vardas; }
    inline void setpava(const string& pavard) { pava = pavard; }
    void addTarpPazymys(int paz) {
        if (tarp.capacity() == 0) tarp.reserve(10);
        tarp.push_back(paz);
    }
    inline void setEgzaminas(double egzaminas) { egz = egzaminas; }
    inline void setVid(double vid) { galutinisvid = vid; }
    inline void setMed(double med) { galutinisvid = med; }

    // Getteriai
    inline string getVardas() const { return vard; }
    inline string getPavarde() const { return pava; }
    double getEgz() const { return egz; }
    vector<int>& getTarp() { return tarp; }
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
    stud& operator=(stud&& kitas) noexcept {
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
    friend std::ostream& operator<<(std::ostream& out, const stud &a) {
      cout << std::left << setw(20) << a.getVardas() << setw(15) << a.getPavarde()
      << setw(18) << std::fixed << std::setprecision(2) << a.getGalutinisVid() << " " << a.getGalutinisMed() << endl;
      return out;
    }
    friend std::istream& operator>>(std::istream& in, stud &a) {
      in >> a.vard >> a.pava;
      cout << "Veskite studento namu darbo pazymius arba N, kad sustoti ";
      string input;
      while (true){
          try{
              in >> input;
              if (input == "N" || input == "n") break;
              int paz = std::stoi(input);
              if (paz < 0 || paz > 10){
                  throw "Ivestas neteisingas simbolis";
              }
              a.addTarpPazymys(paz);
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
              in >> input;
              int egz = std::stoi(input);
              if (egz < 0 || egz > 10){
                  throw "Ivestas neteisingas simbolis";
              }
              a.setEgzaminas(egz);
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
     return in;
    }

};

#endif