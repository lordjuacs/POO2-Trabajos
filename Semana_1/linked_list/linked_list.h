//
// Created by joaquin_ramirez on 4/11/20.
//
#ifndef LINKED_LIST_LINKED_LIST_H
#define LINKED_LIST_LINKED_LIST_H

#include <iostream>
#include <cstddef>
#include <cassert>
#include <string>
namespace utec
{

    struct node_t {
        int value_ = 0;
        node_t* next_ = nullptr;
    };
    inline namespace first {

        class linked_list_t {
        private:
            node_t* head_ = nullptr;
            node_t* tail_ = nullptr;
            size_t size_ = 0;
        public:
            //constructors
            linked_list_t() = default;
            linked_list_t(const linked_list_t& other);                          //copy, 100% new
            linked_list_t&operator=(const linked_list_t& other);              //copy, already exists
            linked_list_t(linked_list_t&& other) noexcept;                  //move, 100% new
            linked_list_t&operator=(linked_list_t&& other) noexcept;        //move, already exists

            //destroyers
            virtual ~linked_list_t();

            //add operations
            void push_front(int value);
            void push_back(int value);
            void insert(size_t index, int value);

            //remove operations
            void pop_front();
            void pop_back();
            void erase(size_t index);

            //traversal operations
            int& item(size_t index);                                        //
            const int& item(size_t index) const;                             // READ ONLY
            node_t* exacto(size_t index) const;

            //get size of list
            size_t size() const;

        };
    }
}
#endif //LINKED_LIST_LINKED_LIST_H
