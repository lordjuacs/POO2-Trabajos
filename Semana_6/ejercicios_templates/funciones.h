//
// Created by joaquin_ramirez on 5/16/20.
//

#ifndef EJERCICIOS_TEMPLATES_FUNCIONES_H
#define EJERCICIOS_TEMPLATES_FUNCIONES_H

#include <iostream>
using namespace std;




template<typename ... Types>
auto suma (Types ... args) {
return (args + ...);
}



template <typename T>
void print(T arg) {
    cout << arg;
}
template <typename T, typename... Params>
void print(T first_arg, Params... args) {
    print(first_arg);
    cout << ' ';
    print(args ...);
}




template<typename ... Params>
void print2(Params ... params){
    (cout << ... << params);}
#endif //EJERCICIOS_TEMPLATES_FUNCIONES_H
