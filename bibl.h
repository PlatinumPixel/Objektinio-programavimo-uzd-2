# ifndef BIBL_H
# define BIBL_H


#include "stud.h"
#include "std.h"
#include "Vektorius.h"
#include "Zmogus.h"
#include "Timer.h"


void spausdina(Vektorius <stud> );
void rankinis(Vektorius <stud> &);
void pusrankis(Vektorius <stud> &);
void automatiskas (Vektorius <stud> &);
void compare(Vektorius <stud> &, double &);
void compare(Vektorius <stud> &);
void failoNusk (Vektorius <stud> &);
void failoGen();
void rusiavimas();
void spausdinaFaila(Vektorius <stud> &A, string);
void test();

bool compVardas(stud &, stud &);
bool compPavard(stud &, stud &);
bool compVid(stud &, stud &);
bool compMed(stud &, stud &);

extern string Vard[5];
extern string Pava[5];


# endif