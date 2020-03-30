//
// Created by J on 3/28/2020.
//
#include "utility"
#include "funciones.h"

int partition(int *data, int start, int end){
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

void quick_sort(int* data, int start, int end){
    //condicion inicial
    if(start >= end) return;
    //condicion recursiva
    auto pi = partition(data, start, end);
    quick_sort(data, start, pi - 1);
    quick_sort(data, pi + 1, end);
}