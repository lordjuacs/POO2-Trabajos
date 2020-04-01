#include <iostream>
#include "CVector.h"
using namespace std;
int main() {
    CVector<int>efe(5);

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
        cout << efe._array[i] << endl;



    return 0;
}
