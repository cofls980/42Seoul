#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <cstdlib>

class Span
{
private:
	std::vector<int> _arr;
	unsigned int _size;

public:
	Span();
	Span(const Span& ref);
	Span& operator=(const Span& ref);
	~Span();
	Span(unsigned int N);

	void addNumber(int element);
	void addManyNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

	int shortestSpan();
	int longestSpan();

	std::vector<int> getArray() const;
	unsigned int getSize() const;

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