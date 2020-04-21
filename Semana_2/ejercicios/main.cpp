#include "funciones.h"

int main() {
    //ej1
    vector<double> v1 = {1,2,3};
    auto ini = cbegin(v1);
    auto fin = cend(v1);
    auto elemento_si = find(ini, fin, 2);
    auto elemento_no = find(ini, fin, 4);
    assert(elemento_si != fin);
    assert(elemento_no == fin);

    //ej2
    int first[] = {1,2,3,4,5};
    int second[] = {1,2,3,4,5};
    vector<int>v2(10);
    merge(first, first + 5, second, second + 5, v2.begin());
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



    return 0;
}
