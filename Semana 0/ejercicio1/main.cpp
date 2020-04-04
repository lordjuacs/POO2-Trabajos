#include <iostream>
#include <vector>
using namespace std;

void buscar_impar(vector<float>lista)
{
    for(int i = 0; i < lista.size(); i++){
        int count = 0;

        for(int j = 0; j < lista.size(); j++){
            if(lista[i] == lista[j])
                count++;
        }
        if(count % 2 != 0) {
            cout << "--> " << lista[i] << endl;
            return;
        }
    }
}
int main() {
    buscar_impar({20, 1, 1, 2, 2, 3, 3, 5, 5, 4, 20, 4, 5});
    return 0;
}
