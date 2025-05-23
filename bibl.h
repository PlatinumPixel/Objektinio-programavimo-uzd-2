# ifndef BIBL_H
# define BIBL_H


#include "stud.h"
#include "std.h"
#include "Timer.h"


void spausdina(vector <stud> );
void rankinis(vector <stud> &);
void pusrankis(vector <stud> &);
void automatiskas (vector <stud> &);
void compare(vector <stud> &, double &);
void compare(vector <stud> &);
void compare(std::list <stud> &A,double &time);
void compare(std::deque <stud> &A,double &time);
void failoNusk (vector <stud> &);
void failoGen();
void rusiavimas();
void spausdinaFaila(vector <stud> &A, string);
void spausdinaFaila(std::list <stud> &A, string);
void spausdinaFaila(std::deque <stud> &A, string);

void TestVector();
void TestList();
void TestDeque();

bool compVardas(stud &, stud &);
bool compPavard(stud &, stud &);
bool compVid(stud &, stud &);
bool compMed(stud &, stud &);

extern string Vard[5];
extern string Pava[5];


# endif