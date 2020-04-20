#include <iostream>
#include <vector>
using namespace std;
template <typename Iterator, typename Object>
Iterator find(Iterator start, Iterator end, const Object& x){
    for(auto& it = start; it != end; ++it)
        if(*it == x)
            return it;
    return end;
}

int main() {
    vector<double> v1 = {1,2,3};
    auto ini = cbegin(v1);
    auto fin = cend(v1);
    auto elemento_si = find(ini, fin, 2);
    auto elemento_no = find(ini, fin, 4);


    return 0;
}
