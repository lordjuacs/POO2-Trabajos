//
// Created by joaquin_ramirez on 3/30/20.
//

#ifndef CLASE_QUICKSORT_QUICK_SORT_H
#define CLASE_QUICKSORT_QUICK_SORT_H

#include <string>
#include <fstream>
#include <iostream>
#include <utility>
using namespace std;
//#include <glob.h>
//normal
class quick_sort_t{
private:
    int* _data;
    size_t  _size;
public:
    quick_sort_t();
    virtual ~quick_sort_t();
    int partition(int *data, int start, int end);
    void quick_sort(int* data, int start, int end);
    friend quick_sort_t&operator <<(quick_sort_t& qs, const string& file_name);
    friend quick_sort_t&operator >>(quick_sort_t& qs, const string& file_name);

};




#endif //CLASE_QUICKSORT_QUICK_SORT_H
