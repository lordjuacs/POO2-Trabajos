//
// Created by joaquin_ramirez on 4/20/20.
//
#include <iostream>
using namespace std;
#ifndef EJERCICIOS_FUNCIONES_H
#define EJERCICIOS_FUNCIONES_H

//ej1
template <typename Iterator, typename Object>
Iterator find(Iterator start, Iterator end, const Object& x){
    for(auto& it = start; it != end; ++it)
        if(*it == x)
            return it;
    return end;
}
//ej2
template <typename InputIt1, typename InputIt2, typename OutputIt>
OutputIt merge(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, OutputIt d_first){
    while (true) {
        if (first1==last1)
            return copy(first2,last2,d_first);
        if (first2==last2)
            return copy(first1,last1,d_first);
        *d_first++ = *first1++;
    }
}


#endif //EJERCICIOS_FUNCIONES_H
