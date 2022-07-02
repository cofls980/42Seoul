#ifndef SPAN_H
#define SPAN_H

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <cstdlib>

class Span
{
private:
	std::vector<int> arr;
	unsigned int maximum;

public:
	Span();
	Span(unsigned int N);
	Span(const Span& ref);
	Span& operator=(const Span& ref);
	~Span();

	void addNumber(int element);

	int shortestSpan();
	int longestSpan();

	template<typename T>
	void addManyNumber(T &c)
	{
		if (c.size() > this->maximum - this->arr.size())
			throw FullStoredException();
		typename T::iterator iter = c.begin();
		for (;iter != c.end();iter++)
		{
			this->arr.push_back(*iter);
		}
	}

	class FullStoredException : public std::exception
	{
	public:
		const char * what() const throw();
	};

	class NoSpanFoundException : public std::exception
	{
	public:
		const char * what() const throw();
	};
};

#endif