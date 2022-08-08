#include "s21_list.h"

// базовый конструктор создаем объект с размером 0, и пустыми указателями на next и prev
template <typename T> s21_list<T>::s21_list() : size_(0), capacity_(0), head_(nullptr), tail_(nullptr) { ; }

template <typename T> s21_list<T>::s21_list(int size) {

}