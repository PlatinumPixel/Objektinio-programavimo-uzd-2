#include <iostream> 
#include "bibl.h"
#include <vector>
using namespace std; 


int main(){  
 
unsigned int sz = 10000; // 100000, 1000000, 10000000, 100000000
Timer t;
int count = 0;


std::vector<unsigned int> v1;

for (int i = 1; i <= sz; ++i) {
    // if(v1.capacity() == v1.size()) {
    //     count++;
    // }
    v1.push_back(i);
}
cout << "std::vector uzpildymo laikas: " << t.elapsed() << " sek." << endl;
//cout << "std::vector resize kartu: " << count << endl;
t.reset();
count = 0;

Vektorius <unsigned int> v2;

for (int i = 1; i <= sz; ++i){
    // if(v2.capacity() == v2.size()) {
    //     count++;
    // }
    v2.push_back(i);
}

cout << "Vektorius uzpildymo laikas: " << t.elapsed() << " sek." << endl;
//cout << "Vektoriaus resize kartu: " << count << endl;
 return 0;
}