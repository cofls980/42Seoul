#ifndef ITER_H
#define ITER_H

#include <iostream>

template <typename T>
void print(const T& a)
{
	std::cout << a << std::endl;
}

template <typename T>
void iter(T *arr, size_t n, void (*f)(const T&))
{
	for (size_t i = 0;i < n;i++)
	{
		f(arr[i]);
	}
}

#endif