//
// Created by joaquin_ramirez on 4/1/20.
//

#ifndef CLASE_QUICKSORT_QUICK_TEMPLATE_H
#define CLASE_QUICKSORT_QUICK_TEMPLATE_H
#include <string>
#include <fstream>
#include <iostream>
#include <utility>
using namespace std;
//#include <glob.h>
//template
template <typename T>
class quick{
private:
    T* _data;
    size_t  _size;
public:
    quick();
    virtual ~quick();
    int partition(T *data, int start, int end);
    void quick_sort(T* data, int start, int end);
    void operator <<(const string& file_name);
    void operator >>(const string& file_name);

};

template<typename T>
quick<T>::quick():_data(nullptr), _size(0){

}

template<typename T>
quick<T>::~quick() {
    delete [] _data;
    _data = nullptr;
}

template<typename T>
int quick<T>::partition(T *data, int start, int end) {
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

template<typename T>
void quick<T>::quick_sort(T *data, int start, int end) {
    //condicion inicial
    if(start >= end) return;
    //condicion recursiva
    auto pi = partition(data, start, end);
    quick_sort(data, start, pi - 1);
    quick_sort(data, pi + 1, end);
}

template<typename T>
void quick<T>::operator>>(const string &file_name) {
    ifstream in("../" + file_name);
    if(!in.is_open())
    {
        cerr << "ERROR: archivo no se pudo abrir";
        return ;
    }

    //leer el contenido

    T x{};
    while (in >> x)//va a leer linea por linea
    {

        T* aux = new T[_size + 1];
        for(int i = 0; i < _size; i++){
            aux[i] = _data[i];
        }
        aux[_size] = x;
        delete [] _data;
        _data = aux;
        _size++;
    }

    //Cierro el archivo
    in.close();


    quick_sort(_data, 0, _size - 1);

}

template<typename T>
void quick<T>::operator<<(const string &file_name) {
    ofstream out( "../" + file_name);
    for(int f = 0; f < _size; f++){
        out << _data[f] << endl;
    }
    //delete [] qs._data;

}

#endif //CLASE_QUICKSORT_QUICK_TEMPLATE_H
