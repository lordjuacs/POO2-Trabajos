//
// Created by joaquin_ramirez on 6/5/20.
//

#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H

//
// Created by joaquin_ramirez on 5/30/20.
//

#ifndef LAB_HEAP_H
#define LAB_HEAP_H

#include <sstream>
#include <iostream>
#include <vector>
#include <cassert>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;

template<typename T>
class max_heap {
private:

    vector<T> nodes = {};

    // Get index
    int left_child_index(int parent) {
        return 2 * parent + 1;
    }

    int right_child_index(int parent) {
        return 2 * parent + 2;
    }

    int parent_index(int child) {
        return (child - 1) / 2;
    }

    // Get existence
    bool left_child_exist(int index) {
        return left_child_index(index) < nodes.size();
    }

    bool right_child_exist(int index) {
        return right_child_index(index) < nodes.size();
    }

    bool parent_exist(int index) {
        return parent_index(index) >= 0;
    }

    // Get value
    T left_child_value(int index) {
        return nodes[left_child_index(index)];
    }

    T right_child_value(int index) {
        return nodes[right_child_index(index)];
    }

    T parent_value(int index) {
        return nodes[parent_index(index)];
    }


    // Swap
    void swap(int one, int two) {
        T temp = nodes[one];
        nodes[one] = nodes[two];
        nodes[two] = temp;
    }

    void percolate_down(size_t start = 0) {
        int index = start;
        while (left_child_exist(index)) {
            int biggest_index = left_child_index(index);
            if (right_child_exist(index) and right_child_value(index) > left_child_value(index))
                biggest_index = right_child_index(index);

            if (nodes[index] < nodes[biggest_index])
                swap(biggest_index, index);

            index = biggest_index;
        }
    };

    void percolate_up() {
        int index = (nodes.size() - 1);
        while (parent_exist(index) and parent_value(index) < nodes[index]) {
            swap(parent_index(index), index);
            index = parent_index(index);
        }
    };

    void percolate_up(int index) {
        while (parent_exist(index) and parent_value(index) < nodes[index]) {
            swap(parent_index(index), index);
            index = parent_index(index);
        }
    };
public:
    max_heap() = default;
    max_heap(T value) {
        nodes = {value};
    }
    max_heap(const max_heap& another) = default;

    string remove_star(string text){
        max_heap<T>out;

        stringstream eliminado;
        for (int i = 0; text[i] != '\0'; i++) {
            if (text[i] == '*'){
                if (!out.is_empty()) {
                    eliminado <<  out.nodes[0] << " ";
                    out.top();
                } else
                    return "Too many *";
            }
            else{
                out.push(text[i]);
                percolate_down();
            }
        }
        this->nodes = out.nodes;
        return eliminado.str();
    }

    // Get Heap
    string get_heap() {
        stringstream heap;
        for (int i = 0; i < nodes.size(); i++) {
            heap <<  nodes[i] << " ";
        }
        return heap.str();
    }

    // Find
    T find_value(int index){
        if(index >= 0 and index < nodes.size()) {
            return nodes[index];
        }
    };

    // Push
    void push(T value){
        nodes.push_back(value);
        this->percolate_up();
    };

    // Pop
    void pop(){
        nodes.pop_back();
    };

    // Remove from index
    void remove(int index){
        swap(index, (nodes.size()-1));
        nodes.pop_back();
        this->percolate_down();
    }

    // Remove from value
    void remove_v(T value){
        auto it = nodes.begin();
        do {
            it = find(it, nodes.end(), value);
        } while (it != nodes.end());
    }

    // Top -- remove head
    void top(){
        swap(0, (nodes.size()-1));
        nodes.pop_back();
        this->percolate_down();
    };

    // Replace
    void replace(T value1, T value2){
        auto pos = find(begin(nodes), end(nodes), value1);
        while(pos != end(nodes)){
            *pos = value2;
            pos = find(begin(nodes), end(nodes), value1);
        }
        this->percolate_down();
    };



    // Empty
    bool is_empty() const{
        return nodes.size() == 0;
    };

    // Size
    size_t size() const{
        return nodes.size();
    };

    void dfs(){

    };

    void print(){
        size_t num_level = 0 ;
        size_t item_per_level = 1 ;
        size_t already_level = 0 ;
        cout << "Max Heap";
        for(auto i = 0; i < nodes.size(); ++i)
        {
            if(already_level == 0 ) // start of a new num_level
                cout << endl <<"level #" << num_level << " : " ;

            cout << nodes[i] << " " ;
            ++already_level ;

            if(already_level == item_per_level) // completed this num_level
            {
                ++num_level ;
                item_per_level *= 2 ;
                already_level = 0 ;
            }
        }

        cout << endl ;

    }

    bool erase_index(int index){
        if(index >=0 and index < nodes.size()){
            nodes.erase(nodes.begin() + index);
            this->percolate_down();
            return true;
        }
        return false;
    }

    void remove_value(T value){
        nodes.erase(begin(nodes),find(begin(nodes), end(nodes), value));
        this->percolate_down();
    }

    max_heap operator+(const max_heap& other){
        max_heap out;
        auto first = begin(nodes);
        while(first != end(nodes)){
            out.push(*first);
            ++first;
        }
        auto second = begin(other);
        while(second != end(other.nodes)){
            out.push(*second);
            ++second;
        }
        out.percolate_down();
        return out;
    };
    max_heap operator+=(const max_heap& other){
        auto second = begin(other);
        while(second != end(other.nodes)){
            nodes.push(*second);
        }
        this->percolate_down();
    }
    // Max child
    T max_child(size_t index){
        if (!this->is_empty() & right_child_exist(index))
            return nodes[right_child_index(index)];
        else
            return T();
    };


    string remove_sequence(string text){
        stringstream eliminado;
        for (int i = 0; text[i] != '\0'; i++) {
            if (text[i] == '*'){
                if (!this->is_empty()) {
                    eliminado <<  nodes[0] << " ";
                    this->top();
                } else
                    return "Too many *";
            }
        }
        return eliminado.str();
    }
};





#endif //LAB_HEAP_H
#endif //HEAP_HEAP_H