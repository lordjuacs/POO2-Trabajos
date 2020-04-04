#include <iostream>
#include "CVector.h"
using namespace std;
using namespace utec;
int main() {
    /*CVector<int>efe(5);

    for(int i = 0; i < 5; i++)
        efe._array[i] = 3;

    for(int i = 0; i < 5; i++)
        cout << efe._array[i] << endl;
    cout << endl;

    //efe.push_back(4);
    efe.insert(0, 7);
    for(int i = 0; i < 6; i++)
        cout << efe._array[i] << endl;
    cout << endl;

    efe.erase(0);
    for(int i = 0; i < 5; i++)
        cout << efe._array[i] << endl;*/
    utec::CVector<float>a1(1);
    for(int i = 0; i < 1; i++){
        cout << "N: "; cin >>a1[i];
    }

    utec::CVector<float>a2(1);
    for(int i = 0; i < 1; i++){
        cout << "N: "; cin >>a2[i];
    }

    CVector<float>c = (a1 + a2);

    for(int i = 0; i < c.getSize() ;i++)
        cout << c[i] << endl;

    return 0;
}
