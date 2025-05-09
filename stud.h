#ifndef STUD_H
#define STUD_H

#include "std.h"
#include <numeric>
#include "Zmogus.h"

class stud : public Zmogus {
private:
    vector<int> tarp;
    double tarpvid = 0;
    double tarpmed = 0;
    double egz = 0;
    double galutinisvid = 0;
    double galutinismed = 0;

public:
    // Constructors
    stud() : Zmogus() {}

    stud(const string& vardas, const string& pavarde) : Zmogus(vardas, pavarde) {}

    stud(std::istringstream& line) {
        int paz;
        line >> vard >> pava;
        while (line >> paz) {
            addTarpPazymys(paz);
        }
        if (!tarp.empty()) {
            egz = tarp.back();
            tarp.pop_back();
        }
    }

    // Copy constructor
    stud(const stud& kitas) : Zmogus(kitas) {
        tarp = kitas.tarp;
        egz = kitas.egz;
        galutinisvid = kitas.galutinisvid;
        galutinismed = kitas.galutinismed;
    }

    // Move constructor
    stud(stud&& kitas) noexcept : Zmogus(std::move(kitas)) {
        tarp = std::move(kitas.tarp);
        egz = kitas.egz;
        galutinisvid = kitas.galutinisvid;
        galutinismed = kitas.galutinismed;

        kitas.egz = 0;
        kitas.galutinisvid = 0.0;
        kitas.galutinismed = 0.0;
    }

    // Destructor
    ~stud() {
        tarp.clear();
        tarp.shrink_to_fit();
    }

    // Copy assignment operator
    stud& operator=(const stud& kitas) {
        if (this != &kitas) {
            Zmogus::operator=(kitas); // Call base class assignment operator
            tarp = kitas.tarp;
            egz = kitas.egz;
            galutinisvid = kitas.galutinisvid;
            galutinismed = kitas.galutinismed;
        }
        return *this;
    }

    // Move assignment operator
    stud& operator=(stud&& kitas) noexcept {
        if (this != &kitas) {
            Zmogus::operator=(std::move(kitas)); // Call base class move assignment operator
            tarp = std::move(kitas.tarp);
            egz = kitas.egz;
            galutinisvid = kitas.galutinisvid;
            galutinismed = kitas.galutinismed;

            kitas.egz = 0;
            kitas.galutinisvid = 0.0;
            kitas.galutinismed = 0.0;
        }
        return *this;
    }

    // Setter methods
    void addTarpPazymys(int paz) {
        if (tarp.capacity() == 0) tarp.reserve(10);
        tarp.push_back(paz);
    }
    inline void setEgzaminas(double egzaminas) { egz = egzaminas; }
    inline void setVid(double vid) { galutinisvid = vid; }
    inline void setMed(double med) { galutinismed = med; }

    // Getter methods
    vector<int>& getTarp() { return tarp; }
    double getEgz() const { return egz; }
    double getGalutinisVid() const { return galutinisvid; }
    double getGalutinisMed() const { return galutinismed; }

    // Calculate final grades
    void calculateGalutinis() {
        if (!tarp.empty()) {
            tarpvid = accumulate(tarp.begin(), tarp.end(), 0) / double(tarp.size());
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

    // Overloaded operators
    friend std::ostream& operator<<(std::ostream& out, const stud& a) {
        out << std::left << setw(20) << a.getVardas() << setw(15) << a.getPavarde()
            << setw(18) << std::fixed << std::setprecision(2) << a.getGalutinisVid() << " " << a.getGalutinisMed() << endl;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, stud& a) {
        in >> a.vard >> a.pava;
        cout << "Veskite studento namu darbo pazymius arba N, kad sustoti ";
        string input;
        while (true) {
            try {
                in >> input;
                if (input == "N" || input == "n") break;
                int paz = std::stoi(input);
                if (paz < 0 || paz > 10) {
                    throw "Ivestas neteisingas simbolis";
                }
                a.addTarpPazymys(paz);
            } catch (const std::invalid_argument&) {
                cout << "Ivestas neteisingas simbolis" << endl;
                continue;
            } catch (const char* x) {
                cout << x << endl;
                continue;
            }
        }

        cout << "Iveskite studento egzamino rezultata ";
        while (true) {
            try {
                in >> input;
                int egz = std::stoi(input);
                if (egz < 0 || egz > 10) {
                    throw "Ivestas neteisingas simbolis";
                }
                a.setEgzaminas(egz);
                break;
            } catch (const std::invalid_argument&) {
                cout << "Ivestas neteisingas simbolis" << endl;
                continue;
            } catch (const char* x) {
                cout << x << endl;
                continue;
            }
        }
        return in;
    }
};

#endif