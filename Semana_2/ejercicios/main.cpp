#include "funciones.h"

int main() {
    //ej1
    vector<double> v1 = {1,2,3};
    auto ini = cbegin(v1);
    auto fin = cend(v1);
    auto elemento_si = mfind(ini, fin, 2);
    auto elemento_no = mfind(ini, fin, 4);
    assert(elemento_si != fin);
    assert(elemento_no == fin);

    //ej2
    int first[] = {1,2,3,4,5};
    int second[] = {1,2,3,4,5};
    vector<int>v2(10);
    mmerge(first, first + 5, second, second + 5, v2.begin());
    cout << "Ej 2:Elementos nuevo vector:" << endl;
    for(auto element:v2)
        cout << element << endl;
    cout << endl;

    //ej3
    list<int>list1 = {2,24,76};
    list<int>list2 = {1,2,24,25};
    list<int>list3(2);
    intersection(list1.begin(), list1.end(),list2.begin(), list2.end(), list3.begin());
    cout << "Ej 3: Elementos  lista interseccion" << endl;
    for(auto& elem:list3)
        cout << elem << endl;
    cout << endl;

    //ej4
    list<int>list21 = {1,2,4,7};
    list<int>list22 = {3,4,5};
    list<int>list23(6);
    united(list21.begin(), list21.end(),list22.begin(), list22.end(), list23.begin());
    cout << "Ej 4: Elementos  lista union" << endl;
    for(auto& elem:list23)
        cout << elem << endl;
    cout << endl;

    list<int>list31 = {2,4,7,9,22};
    int value1 = 1;
    insert_sorted(list31, value1);
    cout << "Ej 5: Insertando un numero menor a todos" << endl;
    for(auto& elem:list31)
        cout << elem << endl;
    cout << endl;

    list<int>list32 = {2,4,7,9,22};
    int value2 = 24;
    insert_sorted(list32, value2);
    cout << "Ej 5: Insertando un numero mayor a todos" << endl;
    for(auto& elem:list32)
        cout << elem << endl;
    cout << endl;

    list<int>list33 = {2,4,7,9,22};
    int value3 = 3;
    insert_sorted(list33, value3);
    cout << "Ej 5: Insertando un numero dentro del rango" << endl;
    for(auto& elem:list33)
        cout << elem << endl;
    cout << endl;


    return 0;
}
