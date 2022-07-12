#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template <typename T>
class Array
{
private:
	T *arr;
	unsigned int n;

public:
	Array();
	Array(unsigned int _n);
	Array(const Array<T>& ref);
	Array<T>& operator=(const Array<T>& ref);
	~Array();

	T& operator[](const unsigned int index);

	const T& operator[](const unsigned int index) const;

	const unsigned int& size() const;

	class OutOfBoundsException : public std::exception
	{
	public:
		const char * what() const throw()
		{
			return ("index is out of range.");
		}
	};
};

template<typename T>
Array<T>::Array()
{
	this->arr = NULL;
	this->n = 0;
}

template<typename T>
Array<T>::Array(unsigned int _n)
{
	if (_n == 0)
	{
		this->arr = NULL;
		this->n = 0;
	}
	else
	{
		this->arr = new T[_n];
		this->n = _n;
		for (unsigned int i = 0;i < this->n;i++)
			this->arr[i] = 0;
	}
}

template<typename T>
Array<T>::Array(const Array<T>& ref)
{
	this->n = ref.size();
	this->arr = new T[this->n];
	for (unsigned int i = 0;i < this->n;i++)
		this->arr[i] = ref.arr[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& ref)
{
	if (this->arr)
		delete [] this->arr;
	this->n = ref.size();
	this->arr = new T[this->n];
	for (unsigned int i = 0;i < this->n;i++)
		this->arr[i] = ref.arr[i];
	return (*this);
}

template<typename T>
Array<T>::~Array()
{
	if (this->arr)
		delete [] this->arr;
}

template<typename T>
T& Array<T>::operator[](const unsigned int index)
{
	if (index < 0 || index >= this->n)
		throw Array::OutOfBoundsException();
	return (this->arr[index]);
}

template<typename T>
const T& Array<T>::operator[](const unsigned int index) const
{
	if (index < 0 || index >= this->n)
		throw Array::OutOfBoundsException();
	return (this->arr[index]);
}

template<typename T>
const unsigned int& Array<T>::size() const
{
	return (this->n);
}

#endif