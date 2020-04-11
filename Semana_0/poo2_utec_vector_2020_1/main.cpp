#include <iostream>
#include "vector_utec.h"

using namespace std;

int main() {
    utec::vector_utec v1{};

    v1.push_back(10);
    v1.push_back(20);

    for (int i = 0; i < v1.size(); ++i)
        cout << v1[i] << endl;
    return 0;
}
