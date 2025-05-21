#ifndef ZMOGUS_H
#define ZMOGUS_H

#include "std.h"
#include <numeric>

class Zmogus {
public:
    // Default constructor
    Zmogus() = default;

    Zmogus(const string& vard, const string& pava) : vard(vard), pava(pava) {}

    // Virtual destructor
    virtual ~Zmogus() = default;

    // Copy constructor
    Zmogus(const Zmogus& other)
        : vard(other.vard), pava(other.pava) {}

    // Copy assignment operator
    Zmogus& operator=(const Zmogus& other) {
        if (this != &other) {
            vard = other.vard;
            pava = other.pava;
        }
        return *this;
    }

    // Move constructor
    Zmogus(Zmogus&& other) noexcept
        : vard(std::move(other.vard)), pava(std::move(other.pava)) {}

    // Move assignment operator
    Zmogus& operator=(Zmogus&& other) noexcept {
        if (this != &other) {
            vard = std::move(other.vard);
            pava = std::move(other.pava);
        }
        return *this;
    }

    inline void setvard(const string& vardas) { vard = vardas; }
    inline void setpava(const string& pavard) { pava = pavard; }

    inline string getVardas() const { return vard; }
    inline string getPavarde() const { return pava; }

    // Kad clase butu abstrakti, reikia padaryti virtual function
    virtual void addTarpPazymys(int paz) = 0;
protected:
   
    string vard;  
    string pava; 
};

#endif // ZMOGUS_H