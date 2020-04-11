//
// Created by utec on 4/4/20.
//

#include "vector_utec.h"
#include <utility>

utec::beta::vector_utec::vector_utec(size_t n):
    size_(n),
    capacity_(n == 0 ? 1 : n),
    data_(new int[n]) {}

utec::beta::vector_utec::vector_utec(const utec::vector_utec &other):
    size_(other.size_),
    capacity_(other.capacity_),
    data_(new int[other.capacity_])
{

    for(size_t i = 0; i < size_; ++i)
        data_[i] = other.data_[i];
}

utec::vector_utec &utec::beta::vector_utec::operator=(const utec::vector_utec &other)
{
    // Copy basic values
    capacity_ = other.capacity_;
    size_ = other.size_;
    if (this == &other)
        return *this;

    // Changed!!!
    delete [] data_;

    // Copy Array
    data_ = new int[capacity_];
    for(size_t i = 0; i < size_; ++i)
        data_[i] = other.data_[i];

    return *this;
}

utec::beta::vector_utec::~vector_utec() {
    size_ = capacity_ = 0;
    delete [] data_;
}

void utec::beta::vector_utec::push_back(int item) {
    if (size_ + 1 >= capacity_) {
        capacity_ *= 2;
        int* aux = new int[capacity_];
        for(size_t i = 0; i < size_; ++i)
            aux[i] = data_[i];
        delete [] data_;
        data_ = aux;
    }
    data_[size_++] = item;
}

void utec::beta::vector_utec::pop_back() {
    if (size_ == 0) return;
    if (size_ - 1 <= capacity_ / 4) {
        capacity_ /= 2;
        int* aux = new int[capacity_];
        for(size_t i = 0; i < size_ - 1; ++i)
            aux[i] = data_[i];
        delete [] data_;
        data_ = aux;
    }
    --size_;
}

void utec::beta::vector_utec::insert(size_t index, int item) {
    if (size_ + 1 > capacity_) {
        capacity_ *= 2;
        int* aux = new int[capacity_];

        size_t j = 0, i = 0;
        while (i < index)
            aux[j++] = data_[i++];
        aux[j++] = item;
        while (i < size_)
            aux[j++] = data_[i++];
        delete [] data_;
        data_ = aux;
    }
    else {
        size_t i = size_;
        while (i++ > index)
            data_[i+1] = data_[i];
        data_[index] = item;
    }
    ++size_;
}

void utec::beta::vector_utec::erase(size_t index) {

}

int &utec::beta::vector_utec::operator[](size_t index) {
    return data_[index];
}

const int &utec::beta::vector_utec::operator[](size_t index) const {
    return data_[index];
}

size_t utec::beta::vector_utec::size() const {
    return size_;
}

utec::beta::vector_utec::vector_utec(utec::vector_utec &&other) noexcept :
        size_(std::move(other.size_)),
        capacity_(std::move(other.capacity_)),
        data_(std::move(other.data_))
{
    other.data_ = nullptr;
}


utec::vector_utec &utec::beta::vector_utec::operator=(utec::vector_utec &&other) noexcept {
    delete [] data_;
    size_ = std::move(other.size_);
    capacity_ = std::move(other.capacity_);
    data_ = std::move(other.data_);
    other.data_ = nullptr;
    return *this;
}
