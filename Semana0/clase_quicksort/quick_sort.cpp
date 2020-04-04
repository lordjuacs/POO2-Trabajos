//
// Created by joaquin_ramirez on 3/30/20.
//

#include "quick_sort.h"
#include <utility>
using namespace std;
quick_sort_t::quick_sort_t():_data(nullptr), _size(0) {
}

quick_sort_t::~quick_sort_t() {
    delete [] _data;
    _data = nullptr;
}

/*
 * Operador unario
 * bool activo = falase;
 * if (!activo)
 *      ....
 *
 * Operador binario
 * int x = 20; int y = 30;
 *
 * auto z = x + y;
 *
 *
 * Operador ternario
 */

int quick_sort_t:: partition(int *data, int start, int end){
    auto pivot = data[end];
    auto pi = start;
    for(int j = start; j < end; j++){
        if(data[j] <= pivot){
            swap(data[pi], data[j]);
            pi++;
        }
    }
    swap(data[pi], data[end]);
    return pi;
}

void quick_sort_t:: quick_sort(int* data, int start, int end){
    //condicion inicial
    if(start >= end) return;
    //condicion recursiva
    auto pi = partition(data, start, end);
    quick_sort(data, start, pi - 1);
    quick_sort(data, pi + 1, end);
}
quick_sort_t &operator>>(quick_sort_t &qs, const string &file_name) {
    //abrir el archivo
    //para q abra y escriba -> fstream file("in.txt", ios::in|ios::out);
    ifstream in("../" + file_name);//tmb corre ifstream in; pero hay que poner el in.open de abajo. si se borra el in.open, hay q poner ifstream in("../" + file_name);

    //fstream file;
    //...

    //validacion
    if(!in.is_open())
    {
        cerr << "ERROR: archivo no se pudo abrir";
        return qs;
    }

    //leer el contenido

    int x;
    while (in >> x)//va a leer linea por linea
    {

        int* aux = new int[qs._size + 1];
        for(int i = 0; i < qs._size; i++){
            aux[i] = qs._data[i];
        }
        aux[qs._size] = x;
        delete [] qs._data;
        qs._data = aux;
        qs._size++;
    }

    //Cierro el archivo
    in.close();


    qs.quick_sort(qs._data, 0, qs._size - 1);
    return qs;
}

quick_sort_t &operator<<(quick_sort_t &qs, const string &file_name) {
    ofstream out( "../" + file_name);
    for(int f = 0; f < qs._size; f++){
        out << qs._data[f] << endl;
    }
    //delete [] qs._data;
    return qs;
}


