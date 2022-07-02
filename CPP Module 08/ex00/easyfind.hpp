#ifndef EASYFIND_H
#define EASYFIND_H

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>

class NoOccurrenceException : public std::exception
{
public:
	const char * what() const throw()
	{
		return ("no occurrence is found.");
	}
};

template <typename T>
unsigned int easyfind(T &a, int b)
{
	typename T::iterator iter = find(a.begin(), a.end(), b);
	if (iter == a.end())
		throw NoOccurrenceException();
	return *iter;
}

#endif