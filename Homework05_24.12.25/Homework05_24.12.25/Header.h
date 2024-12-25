#ifndef ARRAY_TEMPLATE_H
#define ARRAY_TEMPLATE_H

#include <iostream>
#define N 10

template <typename T>
class Array {
private:
    int size = 0;
    T* array = nullptr;

public:
    Array();
    explicit Array(T* b);
    ~Array();

    void Show() const;
    T Minimum() const;
};

#include "Source1.cpp"

#endif
