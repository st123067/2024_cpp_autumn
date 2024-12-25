// array_template.cpp
#ifndef ARRAY_TEMPLATE_CPP
#define ARRAY_TEMPLATE_CPP

#include "Header.h"

template <typename T>
Array<T>::Array() {}

template <typename T>
Array<T>::Array(T* b) {
    size = N;
    array = new T[size];
    for (int i = 0; i < size; ++i) {
        array[i] = b[i];
    }
}

template <typename T>
Array<T>::~Array() {
    delete[] array;
}

template <typename T>
void Array<T>::Show() const {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
T Array<T>::Minimum() const {
    T min = array[0];
    for (int i = 1; i < size; ++i) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

#endif
