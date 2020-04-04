#include <iostream>
using namespace std;
//funcion
int calcular_pentagono(int n)
{
    int suma = 0;
    if(n==1)
        return 1;
    else
    {
        suma = (n-1)*5;
        suma+= calcular_pentagono(n-1);

    }
    return suma;
}
//main
int main() {
    int n;
    do {
        cout << "N:";
        cin >> n;
    }while(n<1);
    for(int i = 1; i <= n; i++){
        cout << calcular_pentagono(i) << endl;
    }
    return 0;
}