#ifndef SRC_S21_ARRAY_H_
#define SRC_S21_ARRAY_H_
#include <stddef.h>

#include <initializer_list>
#include <iostream>

namespace s21 {
template <typename T, size_t N>
class Array {
public:
    using value_type = T;
    using reference = T &;
    using const_reference = const T &;
    using iterator = T *;
    using const_iterator = const T *;
    using size_type = size_t;

private:
    size_type size_;
    value_type data_[N];

public:
    // FUNCTIONS
    Array() : size_(N) { ; }

    Array(std::initializer_list<value_type> const &items) : Array() {
        if (size_ < items.size()) throw std::out_of_range("Too many initializers for s21::array");
        size_type i = 0;
        for (auto it = items.begin(); it != items.end(); it++, i++) {
            data_[i] = *it;
        }
    }

    Array(const Array &other) : Array() { std::copy(other.cbegin(), other.cend(), data_); }

    Array(Array &&other) : Array() { std::move(other.cbegin(), other.cend(), data_); }

    ~Array() { ; }

    void operator=(Array &other) { std::copy(other.cbegin(), other.cend(), data_); }

    void operator=(Array &&other) { std::move(other.cbegin(), other.cend(), data_); }

    // ELEMENT ACCESS

    reference at(size_type pos) {
        if (!(pos < size())) throw std::out_of_range("Out of range");
        return data_[pos];
    }

    reference operator[](size_type pos) { return data_[pos]; }
    const_reference front() const { return data_[0]; }
    const_reference back() const { return data_[size_ - 1]; }
    iterator data() noexcept { return begin(); }

    // CAPACITY
    bool empty() const noexcept { return cbegin() == cend(); }
    size_type size() const noexcept { return size_; }
    size_type max_size() const noexcept { return size(); }

    // MODIFIERS

    void swap(Array &other) { std::swap(*this, other); }

    void fill(const_reference value) {
        for (size_type i = 0; i < size_; i++) data_[i] = value;
    }

    iterator begin() noexcept { return data_; }

    iterator end() noexcept { return &data_[size_]; }

    const_iterator cbegin() const noexcept { return data_; }

    const_iterator cend() const noexcept { return &data_[size_]; }
};
}  // namespace s21
#endif  // SRC_S21_ARRAY_H_
