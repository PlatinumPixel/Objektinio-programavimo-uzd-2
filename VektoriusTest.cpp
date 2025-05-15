#include "std.h"
#include "Vektorius.h"
#include <iostream>

int main(){

ManoVektorius<int> v;
for (int i = 0; i < 5; i++) {
    v.push_back(i);
}
    cout << endl;

    v.erase(v.begin()+1);
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }

return 0;
}