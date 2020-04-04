#include "funciones.h"


int main() {

    int* arr = new int[5] {3,2,1,8,6};

    quick_sort(arr, 0, 4);

    for(int i = 0; i <5; i++){
        cout << arr[i] << endl;
    }

    return 0;
}
