#include <iostream>
#include <fstream> //para manejar archivos
using namespace std;

int main() {

    //abrir el archivo
    //para q abra y escriba -> fstream file("in.txt", ios::in|ios::out);
    ifstream in("in.txt");

    //fstream file;
    //...
    in.open("../in.txt", ios::in);

    //validacion
    if(!in.is_open())
    {
        cout << "ERROR: archivo no se pudo abrir";
        return 0;
    }

    //leer el contenido
    int x;
    int i = 1;
    int* arr = nullptr;
    size_t size = 0;

    while (in >> x)//va a leer linea por linea
    {
        int* aux = new int[size + 1];
        for(int i = 0; i < size; i++){
           aux[i] = arr[i];
        }
        aux[size] = x;
        delete [] arr;
        arr = aux;
        size++;
    }

    //Cierro el archivo
    in.close();
    //grabar contenido
    ofstream out("../out.txt");
    for(int f = 0; f < size; f++){
        out << arr[f] << endl;
    }
    delete [] arr;

    return 0;
}
