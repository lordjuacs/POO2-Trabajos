//
// Created by joaquin_ramirez on 4/11/20.
//

#include "linked_list.h"
using namespace std;
#include <utility>

utec::first::linked_list_t::linked_list_t(const utec::linked_list_t &other) {
    if(other.size() == 0) {
        head_ = tail_ = nullptr;
        size_ = 0;
    }
    else {
        size_ = 1;
        size_t index = other.size_;
        auto current = other.head_;
        head_ = new node_t{current->value_, nullptr};
        tail_ = head_;
        while (--index) {
            current = current->next_;
            this->push_back(current->value_);
        }
    }
}

utec::linked_list_t &utec::first::linked_list_t::operator=(const utec::linked_list_t &other) {
    if(other.size_ == 0){
        head_ = tail_ = nullptr;
        size_ = 0;
        return *this;
    }
    else if(this == &other){
        return *this;
    }
    while(--size_)
        pop_front();
    size_ = 1;
    size_t index = other.size_;
    auto current = other.head_;
    head_ = new node_t{current->value_, nullptr};
    tail_ = head_;
    while (--index) {
        current = current->next_;
        this->push_back(current->value_);
    }

    return *this;
}

utec::first::linked_list_t::linked_list_t(utec::linked_list_t &&other) noexcept {
    size_ = move(other.size());
    head_ = move(other.head_);
    tail_ = move(other.tail_);
    other.size_ = 0;
    other.head_ = nullptr;
    other.tail_ = nullptr;


}

utec::linked_list_t &utec::first::linked_list_t::operator=(utec::linked_list_t &&other) noexcept {
    auto current = head_;
    while( current != nullptr ) {
        auto next = current->next_;
        delete current;
        current = next;
    }
    head_ = nullptr;
    size_ = 0;

    size_ = move(other.size());
    head_ = move(other.head_);
    tail_ = move(other.tail_);
    other.size_ = 0;
    other.head_ = nullptr;
    other.tail_ = nullptr;


    //to do
    return *this;
}

utec::first::linked_list_t:: ~linked_list_t() {
    auto current = head_;
    while( current != nullptr ) {
        auto next = current->next_;
        delete current;
        current = next;
    }

    head_ = tail_ = nullptr;
    size_ = 0;
    assert(head_ == tail_);
    assert(size_ == 0);
}

void utec::first::linked_list_t::push_front(int value) {
    /*auto node = new node_t{value, head_};
    head_ = node;
    */
    head_ = new node_t{value, head_};
    if(tail_ == nullptr)
        tail_ = head_;
    size_++;
}

void utec::first::linked_list_t::push_back(int value) {
    auto last = new node_t{value, nullptr};
    if(head_ == nullptr){
        head_ = tail_ = last;
        size_++;
        return;
    }
    auto current = head_;
    size_t index = size_ - 1;
    while(index--)
        current = current->next_;
    current->next_ = last;
    tail_ = last;
    size_++;
}

void utec::first::linked_list_t::insert(size_t index, int value) {
    if(head_ == tail_){
        head_ = new node_t{value, tail_};
        if(tail_ == nullptr)
            tail_ = head_;
    }
    else{
        exacto(index - 1)->next_ = new node_t{value, exacto(index)};
    }
    size_++;

}

void utec::first::linked_list_t::pop_front() {
    if(head_ == tail_) {
        delete head_;
        head_ = tail_ = nullptr;
        size_ = 0;
    }
    else{
        auto next = head_->next_;
        delete head_;
        head_ = next;
        size_--;
    }
}

void utec::first::linked_list_t::pop_back() {
    if(head_ == tail_){
        delete head_;
        head_ = tail_ = nullptr;
        size_ = 0;
    }
    else {
        auto current = head_;
        size_t index = size_ - 1;
        while (index--)
            current = current->next_;
        current->next_ = nullptr;
        tail_ = current;
        size_--;
    }
}

void utec::first::linked_list_t::erase(size_t index) {
    if(head_ == tail_){
        delete head_;
        head_ = tail_ = nullptr;
        size_ = 0;
    }
    else if(index == 0) {
        pop_front();
    }
    else if(index == size_ - 1) {
        pop_back();
    }
    else{
        delete exacto(index);
        exacto(index - 1)->next_ = exacto(index + 1);
        size_--;
    }
}

int &utec::first::linked_list_t::item(size_t index) {
    auto current = head_;
    while(index--)
        current = current->next_;
    return current->value_;
}

const int &utec::first::linked_list_t::item(size_t index) const {
    auto current = head_;
    while(index--)
        current = current->next_;
    return current->value_;
}

size_t utec::first::linked_list_t::size() const{
    return size_;
}

utec::node_t *utec::first::linked_list_t::exacto(size_t index) const  {
    auto current = head_;
    while (index--)
        current = current->next_;
    return current;
}
