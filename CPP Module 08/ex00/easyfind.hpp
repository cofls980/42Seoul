#ifndef EASYFIND_HPP
#define EASYFIND_HPP

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
typename T::iterator easyfind(T &a, int b)
{
	typename T::iterator iter = std::find(a.begin(), a.end(), b);
	if (iter == a.end())
		throw NoOccurrenceException();
	return iter;
}

#endif