#include "funciones.h"

int main() {
    //ej1
    vector<double> v1 = {1,2,3};
    auto ini1 = cbegin(v1);
    auto fin1 = cend(v1);
    auto elemento_si = my_find(ini1, fin1, 2);
    auto elemento_no = my_find(ini1, fin1, 4);
    assert(elemento_si != fin1);
    assert(elemento_no == fin1);

    //ej2
    int first2[] = {1,2,3,4,5};
    int second2[] = {1,2,3,4,5};
    vector<int>v2(10);
    my_merge(first2, first2 + 5, second2, second2 + 5, v2.begin());
    cout << "Ej 2:Elementos nuevo vector:" << endl;
    for(auto element:v2)
        cout << element << endl;
    cout << endl;

    //ej3
    list<int>list31 = {2,24,76};
    list<int>list32 = {1,2,24,25};
    list<int>list33(2);
    my_intersection(list31.begin(), list31.end(), list32.begin(), list32.end(), list33.begin());
    cout << "Ej 3: Elementos  lista interseccion" << endl;
    for(auto& elem:list33)
        cout << elem << endl;
    cout << endl;

    //ej4
    list<int>list41 = {1,2,4,7};
    list<int>list42 = {3,4,5};
    list<int>list43(6);
    my_union(list41.begin(), list41.end(), list42.begin(), list42.end(), list43.begin());
    cout << "Ej 4: Elementos  lista union" << endl;
    for(auto& elem:list43)
        cout << elem << endl;
    cout << endl;

    //ej5
    list<int>list51 = {2,4,7,9,22};
    int value1 = 1;
    my_insert_sorted(list51, value1);
    cout << "Ej 5: Insertando un numero menor a todos" << endl;
    for(auto& elem:list51)
        cout << elem << endl;
    cout << endl;

    list<int>list52 = {2,4,7,9,22};
    int value2 = 24;
    my_insert_sorted(list52, value2);
    cout << "Ej 5: Insertando un numero mayor a todos" << endl;
    for(auto& elem:list52)
        cout << elem << endl;
    cout << endl;

    list<int>list53 = {2,4,7,9,22};
    int value3 = 3;
    my_insert_sorted(list53, value3);
    cout << "Ej 5: Insertando un numero dentro del rango" << endl;
    for(auto& elem:list53)
        cout << elem << endl;
    cout << endl;

    list<int>list54 = {2,4,7,9,22};
    int value4 = 22;
    my_insert_sorted(list54, value4);
    cout << "Ej 5: Insertando un numero ya presente --> no cambia la lista" << endl;
    for(auto& elem:list54)
        cout << elem << endl;
    cout << endl;

    //ej6
    list<int>list61 = {1,2,1,3,4,1,5,6,7};
    auto new_end_61 = my_remove(begin(list61), end(list61), 1);
    cout << "Ej 6: Removiendo value de la lista" << endl;
    for(auto it = begin(list61); it !=new_end_61;++it){
        cout << *it<< endl;
    }

    //ej7
    list<int>list71 = {1,2,3,4,5,6,7,8,9,10};
    list<int>list72(10);
    my_copy(begin(list71), end(list71), begin(list72));
    cout << "Ej 7: Copiando una lista a otra" << endl;
    for(auto& elem:list72)
        cout << elem << endl;
    cout << endl;

    //ej8
    list<int>list81 = {1,2,3,4,5};
    auto print_squared = [](const int& n) {
        cout << pow(n,2) << endl;
    };
    cout << "Ej 8: Aplicando un print con for_each" << endl;
    my_for_each(cbegin(list81), cend(list81), print_squared);
    cout << endl;

    //ej9
    list<int>list91 = {2,3,4,5,6,7};
    list<int>list92(6);
    auto cube = [](int& n) {
    n = pow(n,3);
    return n;
    };
    cout << "Ej 9: Aplicando cubo a una lista y almacenando en otra" << endl;
    my_transform(begin(list91), end(list91),begin(list92), cube);
    for(auto& elem:list92)
        cout << elem << endl;
    cout << endl;

    //ej10


    return 0;
}
