#include "s21_vector.h"
#include <vector>
#include <iostream>
// using namespace std;
using namespace s21;


// todo : operation = 

int main() {

    s21::Vector<double> v1(3);
    std::cout<<v1.size()<<" "<<v1.capacity()<<std::endl; 
    v1.push_back(913.12);
    std::cout<<v1.size()<<" "<<v1.capacity()<<std::endl; 
    s21::Vector<double>::VectorIterator it1(v1.end());
    // --it1;
    std::cout<<(*it1)<<std::endl;

    return 0;
}

// ВЫВОД ВЕКТОРА НА ЭКРАН
template <typename T>
void s21::Vector<T>::print_vector() const {
    for (int i = 0; i < size(); i++)
        std::cout<<at(i)<<" ";
    std::cout<<std::endl;
}

// БАЗОВЫЙ КОНСТРУКТОР
template <typename T>
s21::Vector<T>::Vector() : size_(0), capacity_(0), arr_(nullptr) {;}

// ПАРАМЕТРИЗИРОВАННЫЙ КОНСТРУКТОР
template <typename T>
s21::Vector<T>::Vector(int init_size) {
    arr_ = new T[init_size]();
    size_ = init_size;
    capacity_ = init_size;
}

// КОНСТРУКТОР КОПИРОВАНИЯ
template <typename T>
s21::Vector<T>::Vector(const Vector& other) : Vector(other.size_) {
    std::copy(arr_, arr_ + size_, other.arr_);
}

// КОНСТРУКТОР ПЕРЕМЕЩЕНИЯ
template <typename T>
s21::Vector<T>::Vector(Vector&& other) :
size_(other.size_), capacity_(other.capacity_), arr_(other.arr_) {
    other.arr_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
}

// ДЕСТРУКТОР
template <typename T>
s21::Vector<T>::~Vector() {
    remove_vector_();
}

// ПУСТ ЛИ ВЕКТОР
template <typename T>
bool s21::Vector<T>::empty() const {
    return arr_ == nullptr;
}

// ИНДЕКСАЦИЯ
template <typename T>
T& s21::Vector<T>::at(unsigned long int i) const {
    if (i >= size_) throw std::out_of_range("Out of range");
    return arr_[i];
}

// ПЕРЕГРУЗКА ОПЕРАТОРА ИНДЕКСАЦИИ
template <typename T>
T& s21::Vector<T>:: operator [] (unsigned long int i) const { return at(i); }

// ПОЛУЧЕНИЕ РАЗМЕРА ВЕКТОРА
template <typename T>
unsigned long int s21::Vector<T>::size() const { return size_; }


// ПОЛУЧЕНИЕ ВЫДЕЛЕННОЙ ПАМЯТИ ПОД ДАННЫЕ В ВЕКТОРЕ
template <typename T>
unsigned long int s21::Vector<T>::capacity() const { return capacity_; }

// ДОБАВЛЕНИЕ НОВОГО ЭЛ-ТА В КОНЕЦ ВЕКТОРА
template <typename T>
void s21::Vector<T>::push_back(T data) {
    if (size_ == capacity_)
        resize(size_ * 2);
    at(size_++) = data;
}

// УДАЛЕНИЕ ПОСЛЕДНЕГО ЭЛ-ТА ВЕКТОРА
template <typename T>
void s21::Vector<T>::pop_back() {size_--; }

// ЧИСТКА ВЕКТОРА
template<typename T>
void s21::Vector<T>::remove_vector_() {
    if (arr_) delete [] arr_;
}

// ВОЗВРАЩАЕТ ИТЕРАТОР УКАЗЫВАЮЩИЙ НА НАЧАЛО ВЕКТОРА
template<typename T>
typename::Vector<T>::VectorIterator s21::Vector<T>::begin() const {
    s21::Vector<T>::VectorIterator new_iter(arr_, 0, capacity());
    return new_iter;
}

// ВОЗВРАЩАЕТ ИТЕРАТОР УКАЗЫВАЮЩИЙ НА НАЧАЛО ВЕКТОРА
template<typename T>
typename::Vector<T>::VectorIterator s21::Vector<T>::end() const {
    s21::Vector<T>::VectorIterator new_iter(arr_ + size(), size(), capacity());
    return new_iter;
}

// РЕСАЙЗ ВЕКТОРА
template <typename T>
void s21::Vector<T>::resize(unsigned long int new_size) {
    s21::Vector<T> tmp(new_size);
    int size_iter = new_size < size_ ? new_size : size_;
    std::copy(arr_, arr_ + size_iter, tmp.arr_);
    remove_vector_();
    arr_ = tmp.arr_, capacity_ = tmp.capacity_;
    tmp.arr_ = nullptr;
}

// ============= ITERATOR ================

// БАЗОВЫЙ КОНСТРУКТОР ИТЕРАТОРА
template <class T>
s21::Vector<T>::VectorIterator::VectorIterator() : p_data_(nullptr), position_(0U), size_of_vector_(0U) {;}

// Параметризированный конструктор вызываемый только методом begin() и end()
template <class T>
s21::Vector<T>::VectorIterator::VectorIterator(T* data, size_t position, size_t size_of_vector)
: p_data_(data), position_(position), size_of_vector_(size_of_vector) {;}

// Конструктор копирования
template <class T>
s21::Vector<T>::VectorIterator::VectorIterator(const VectorIterator& other)
:VectorIterator(other.p_data_, other.position_, other.size_of_vector_) {;}

// Деструктор
template <class T>
s21::Vector<T>::VectorIterator::~VectorIterator(){;}

// получение элемента, на который указывает итератор
template <class T>
T& s21::Vector<T>::VectorIterator::operator * () const {
    return *p_data_;
}

// перемещение итератора вперед для обращения к следующему элементу
template <class T>
void s21::Vector<T>::VectorIterator::operator ++ () {
    p_data_ ++, position_ ++;
}

// перемещение итератора назад для обращения к предыдущему элементу
template <class T>
void s21::Vector<T>::VectorIterator::operator -- () {
    p_data_ --, position_ --;
}

// два итератора равны, если они указывают на один и тот же элемент
template <class T>
bool s21::Vector<T>::VectorIterator::operator == (const VectorIterator& other) const {
    return p_data_ == other.p_data_;
}

// два итератора не равны, если они указывают на разные элементы
template <class T>
bool s21::Vector<T>::VectorIterator::operator != (const VectorIterator& other) const {
    return p_data_ != other.p_data_;
}