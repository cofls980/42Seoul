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
	Array()
	{
		this->arr = NULL;
		this->n = 0;
	}
	Array(unsigned int n)
	{
		if (n == 0)
		{
			this->arr = NULL;
			this->n = 0;
		}
		else
		{
			this->arr = new T[n];
			this->n = n;
		}
		//display *arr
	}
	Array(const Array& ref)
	{
		*this = ref;
	}
	Array& operator=(const Array& ref)
	{
		if (this->arr)
			delete [] this->arr;
		this->arr = new T[ref.n];
		this->n = ref.n;
		for (unsigned int i = 0;i < ref.n;i++)
		{
			this->arr[i] = ref.arr[i];
		}
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
			return ("index is out of bounds.");
		}
	};
};

#endif