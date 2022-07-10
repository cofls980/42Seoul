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
	Array() : arr(NULL), n(0) {}
	Array(unsigned int _n) : arr(new T[_n]), n(_n) {}
	Array(const Array<T>& ref)
	{
		this->n = ref.size();
		this->arr = new T[this->n];
		for (unsigned int i = 0;i < this->n;i++)
			this->arr[i] = ref.arr[i];
	}
	Array<T>& operator=(const Array<T>& ref)
	{
		if (this->arr)
			delete [] this->arr;
		this->n = ref.size();
		this->arr = new T[this->n];
		for (unsigned int i = 0;i < this->n;i++)
			this->arr[i] = ref.arr[i];
		return (*this);
	}
	~Array()
	{
		if (this->arr)
			delete [] this->arr;
	}

	T& operator[](const unsigned int index)
	{
		if (index < 0 || index >= this->n)
			throw OutOfBoundsException();
		return (this->arr[index]);
	}

	unsigned int size() const
	{
		return (this->n);
	}

	class OutOfBoundsException : public std::exception
	{
	public:
		const char * what() const throw()
		{
			return ("index is out of range.");
		}
	};
};

#endif