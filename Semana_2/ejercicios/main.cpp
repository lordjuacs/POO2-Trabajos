#include "funciones.h"
#include <vector>
int main() {
    //ej1
    vector<double> v1 = {1,2,3};
    auto ini = cbegin(v1);
    auto fin = cend(v1);
    auto elemento_si = find(ini, fin, 2);
    auto elemento_no = find(ini, fin, 4);


    //ej2
    int first[] = {1,2,3,4,5};
    int second[] = {1,2,3,4,5};
    vector<int>v2(10);
    merge(first, first + 5, second, second + 5, v2.begin());
    cout << "Elementos nuevo vector:" << endl;
    for(auto element:v2)
        cout << element << endl;

    //ej3

    return 0;
}
