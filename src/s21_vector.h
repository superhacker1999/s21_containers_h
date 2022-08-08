#include <iostream>

namespace s21 {
template <typename T>
class Vector {
    private:
        unsigned long int size_;  // КОЛ-ВО ЗНАЧЕНИЙ В ВЕКТОРЕ
        unsigned long int capacity_;  // ВЫДЕЛЕННО ПАМЯТИ ПОД 
        T* arr_;  // УКАЗАТЕЛЬ НА ГОЛОВУ ВЕКТОРА
    
    public:
        class VectorIterator;
        // trash
        void print_vector() const;
        // constructors and destructor:
        Vector();
        Vector(int init_size);
        Vector(const Vector& other);
        Vector(Vector&& other);
        ~Vector();

        using value_type = T;
        using reference = T &;
        using const_reference = const T &;
        using iterator = T *;
        using const_iterator = const T *;
        using size_type = size_t;


        // main methods:
        VectorIterator begin() const;
        VectorIterator end() const;
        bool empty() const;
        T& at(unsigned long int i) const;
        T& operator [] (unsigned long int i) const;
        unsigned long int size() const;
        unsigned long int capacity() const;
        void push_back(T data);
        void pop_back();
        void resize(unsigned long int new_size);

        private:
        // internal methods:
        void remove_vector_();
};

template <class T>
class Vector<T>::VectorIterator {
    private:
        T* p_data_;
        size_t position_;
        size_t size_of_vector_;
    public:
        VectorIterator();  // базовый конструктор
        VectorIterator(const VectorIterator& other);  // конструктор копирования
        VectorIterator(T* data, size_t position, size_t size_of_vector); // базовый конструктор, вызываемый только методом begin() и end()
        ~VectorIterator();

        T& operator * () const;
        void operator ++ ();
        void operator -- ();
        bool operator == (const VectorIterator& other) const;
        bool operator != (const VectorIterator& other) const;
        
        
};
}

