//
// Created by joaquin_ramirez on 4/20/20.
//
#include <iostream>
#include <vector>
#include <list>
#include <cassert>
#include <ctime>
#include <algorithm>
using namespace std;
#ifndef EJERCICIOS_FUNCIONES_H
#define EJERCICIOS_FUNCIONES_H

//ej1
template <typename Iterator, typename Object>
Iterator mfind(Iterator start, Iterator end, const Object& x){
    for(auto& it = start; it != end; ++it)
        if(*it == x)
            return it;
    return end;
}

//ej2
template <typename InputIt1, typename InputIt2, typename OutputIt>
OutputIt mmerge(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, OutputIt d_first){
    while (true) {
        if (first1==last1)
            return copy(first2,last2,d_first);
        *d_first++ = *first1++;
    }
}

//ej3
template <typename InputIt1, typename InputIt2, typename OutputIt>
OutputIt intersection(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, OutputIt d_first){
    while (first1!=last1 and first2!=last2)
    {
        if (*first1<*first2)
            first1++;
        else if (*first2<*first1)
            first2++;
        else {
            *d_first++ = *first1++;
            first2++;
        }
    }
    return d_first;
}
//ej4
template <typename InputIt1, typename InputIt2, typename OutputIt>
OutputIt united(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, OutputIt d_first){
    while(first1 != last1 and first2 != last2) {
            if (*first1 < *first2) {
                *d_first++ = *first1++;
            }
            else if (*first2 < *first1) {
                *d_first++ = *first2++;
            }
            else {
                *d_first++ = *first1++;
                ++first2;

            }
            if(first1 == last1){
                while(first2 != last2)
                    *d_first++ = *first2++;
            }
            else if(first2 == last2){
                while(first1 != last1)
                    *d_first++ = *first1++;
            }
    }
    return d_first;
}

//ej5
template< typename type, template<typename ...> class Container>
void insert_sorted(Container<type> &cont, type value){
    //asumiendo que la lista ya esta ordenada
    auto temp = *(begin(cont));
    auto it = ++begin(cont);
    if(value < temp){
        cont.insert(begin(cont), value);
        return;
    }
    else if(value > *rbegin(cont)) {
        cont.push_back(value);
        return;
    }

    for(;it != end(cont);++it){
        if(temp < value and value < *it) {
            cont.insert(it, value);
            return;
        }
        temp = *it;
    }
}




#endif //EJERCICIOS_FUNCIONES_H
