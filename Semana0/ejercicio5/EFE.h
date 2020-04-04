//
// Created by J on 29-Mar-20.
//

#ifndef TEST_EFE_H
#define TEST_EFE_H

template <typename T>
class EFE{
private:
    T value;
public:
    EFE();
};

template <typename T>EFE<T>::EFE() {value = 0;}

#endif //TEST_EFE_H
