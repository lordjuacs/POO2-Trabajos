//
// Created by joaquin_ramirez on 3/31/20.
//

#ifndef EJERCICIO6_CVECTOR_H
#define EJERCICIO6_CVECTOR_H
using namespace std;

#include <glob.h>
namespace utec {
    template<typename T>
    class CVector {
    private:
        T *_array;
        size_t _size;
    public:
        CVector() : _array(nullptr), _size(0) {};

        CVector(CVector <T> &vec);

        CVector(size_t size);

        int getSize(){return _size;};

        void push_back(T num);

        void pop_back();

        void insert(int index, T num);

        void erase(int index);

        T &operator[](int index);
        CVector<T> operator +(CVector<T> &a);

        virtual ~CVector();
    };


    template<typename T>
    CVector<T>::CVector(CVector <T> &vec) {
        _size = vec._size;
        _array = new T[_size];
        for (int i = 0; i < vec._size; i++)
            _array[i] = vec[i];
    }

    template<typename T>
    CVector<T>::CVector(size_t size) {
        _size = size;
        _array = nullptr;
        _array = new T[_size];
        for (int i = 0; i < _size; i++)
            _array[i] = 0;
    }


    template<typename T>
    CVector<T>::~CVector() {
        delete[] _array;
        _array = nullptr;
        _size = 0;
    }

    template<typename T>
    void CVector<T>::push_back(T num) {
        T *aux = nullptr;
        aux = new T[_size + 1];
        for (int i = 0; i < _size; i++)
            aux[i] = _array[i];
        aux[_size] = num;
        delete[] _array;
        _array = aux;
        _size++;
    }

    template<typename T>
    void CVector<T>::pop_back() {
        T *aux = nullptr;
        aux = new T[_size - 1];
        for (int i = 0; i < _size - 1; i++)
            aux[i] = _array[i];
        delete[] _array;
        _array = aux;
        _size--;
    }

    template<typename T>
    void CVector<T>::insert(int index, T num) {
        T *aux = nullptr;
        aux = new T[_size + 1];
        for (int i = 0; i < index; i++)
            aux[i] = _array[i];
        aux[index] = num;

        for (int i = index; i < _size; i++)
            aux[i + 1] = _array[i];
        delete[] _array;
        _array = aux;
        _size++;
    }

    template<typename T>
    void CVector<T>::erase(int index) {
        T *aux = nullptr;
        aux = new T[_size - 1];
        for (int i = 0; i < index; i++)
            aux[i] = _array[i];

        for (int i = index; i < _size - 1; i++)
            aux[i] = _array[i + 1];
        delete[] _array;
        _array = aux;
        _size++;
    }

    template<typename T>
    T &CVector<T>::operator[](int index) {
        if(index < 0 or index >= _size)
            cerr << "Indice: " << index <<" Indice fuera del rango del vector" << endl;
        return *(_array + index);
    }

    template<typename T>
    CVector<T> CVector<T>::operator+(CVector<T> &a) {
        CVector<T>c(_size + a._size);
        for(int i = 0; i < _size; i++) {
            c[i] = _array[i];

        }
        for(int i = 0; i < a._size; i++)
            c[i + _size] = a._array[i];
        return c;
    }






}
#endif //EJERCICIO6_CVECTOR_H
