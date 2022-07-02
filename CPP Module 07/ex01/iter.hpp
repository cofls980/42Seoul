#ifndef ITER_H
#define ITER_H

#include <iostream>

template <typename T>
void print(T a);

template <typename T, typename Func>
void iter(T *a, size_t b, Func func);

#endif