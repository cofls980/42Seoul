#include "Span.hpp"

Span::Span()
{
	this->_size = 0;
}

Span::Span(unsigned int N)
{
	this->_size = N;
}

Span::Span(const Span& ref)
{
	this->_size = ref.getSize();
	this->_arr = ref.getArray();
}

Span& Span::operator=(const Span& ref)
{
	if (this != &ref)
	{
		this->_arr.clear();
		this->_size = ref.getSize();
		this->_arr = ref.getArray();
	}
	return (*this);
}

Span::~Span()
{}

std::vector<int> Span::getArray() const
{
	return this->_arr;
}

unsigned int Span::getSize() const
{
	return this->_size;
}

void Span::addNumber(int element)
{
	if (this->_arr.size() < this->getSize())
		this->_arr.push_back(element);
	else
		throw Span::FullStoredException();
}

void Span::addManyNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	std::vector<int>::iterator iter;
	for (iter = begin;iter != end;iter++)
	{
		if (this->_arr.size() == this->getSize())
			throw Span::FullStoredException();
		this->_arr.push_back(*iter);
	}
}

const char * Span::FullStoredException::what() const throw()
{
	return ("Elements of maximum size are already stored.");
}

const char * Span::NoSpanFoundException::what() const throw()
{
	return ("There are no numbers stored or only one.");
}

int Span::shortestSpan()
{
	if (this->_arr.empty() || this->_arr.size() == 1)
		throw Span::NoSpanFoundException();
	std::vector<int> tmp = this->_arr;
	std::sort(tmp.begin(), tmp.end());
	int gap = -1;
	for (unsigned int i = 0;i < tmp.size() - 1;i++)
	{
		if (gap == -1 || tmp[i + 1] - tmp[i] < gap)
			gap = tmp[i + 1] - tmp[i];
	}
	return (gap);
}

int Span::longestSpan()
{
	if (this->_arr.empty() || this->_arr.size() == 1)
		throw Span::NoSpanFoundException();
	int min = *std::min_element(this->_arr.begin(), this->_arr.end());
	int max = *std::max_element(this->_arr.begin(), this->_arr.end());
	return (max - min);
}