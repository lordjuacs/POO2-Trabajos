//
// Created by joaquin_ramirez on 3/31/20.
//

#ifndef EJERCICIO6_CVECTOR_H
#define EJERCICIO6_CVECTOR_H


#include <glob.h>
template <typename T>
class CVector {
public:
    T* _array;
    size_t _size;
public:
    CVector();
    CVector(CVector const &vec);
    CVector(__size_t size);

    void destructor();
    void push_back(T num);
    void pop_back();
    void insert(int index, T num);
    void erase(int index);

    int &operator [](int index);
    virtual ~CVector();
};



template<typename T>
CVector<T>::CVector() {
    _array = nullptr;
    _size = 0;
}

template<typename T>
CVector<T>::CVector(CVector const &vec) {
    _array = new T[vec._size];
    _size = vec._size;
    for(int i = 0; i < vec._size; i++)
        _array[i] = vec[_size];
}

template<typename T>
CVector<T>::CVector(__size_t size) {
    _size = size;
    _array = nullptr;
    _array = new T[_size];
    for(int i = 0; i < _size; i++)
        _array[i] = 0;
}

template<typename T>
void CVector<T>::destructor() {
    delete [] _array;
    _array = nullptr;
    _size = 0;
}

template<typename T>
CVector<T>::~CVector() {
    delete [] _array;
    _array = nullptr;
    _size = 0;
}

template<typename T>
void CVector<T>::push_back(T num) {
    T* aux = nullptr;
    aux = new T[_size + 1];
    for(int i = 0; i < _size; i++)
        aux[i] = _array[i];
    aux[_size] = num;
    delete [] _array;
    _array = aux;
    _size++;
}

template<typename T>
void CVector<T>::pop_back() {
    T* aux = nullptr;
    aux = new T[_size - 1];
    for(int i = 0; i < _size - 1; i++)
        aux[i] = _array[i];
    delete [] _array;
    _array = aux;
    _size--;
}

template<typename T>
void CVector<T>::insert(int index, T num) {
    T* aux = nullptr;
    aux = new T[_size + 1];
    for(int i = 0; i < index; i++)
        aux[i] = _array[i];
    aux[index] = num;

    for(int i = index; i < _size; i++)
        aux[i + 1] = _array[i];
    delete [] _array;
    _array= aux;
    _size++;
}

template<typename T>
void CVector<T>::erase(int index) {
    T* aux = nullptr;
    aux = new T[_size - 1];
    for(int i = 0; i < index; i++)
        aux[i] = _array[i];

    for(int i = index; i < _size - 1; i++)
        aux[i] = _array[i + 1];
    delete [] _array;
    _array= aux;
    _size++;
}

template<typename T>
int &CVector<T>::operator[](int index) {

    return _array[index];
}


#endif //EJERCICIO6_CVECTOR_H
