#include "Span.hpp"

Span::Span()
{
	this->maximum = 0;
}

Span::Span(unsigned int N)
{
	this->maximum = N;
}

Span::Span(const Span& ref)
{
	*this = ref;
}

Span& Span::operator=(const Span& ref)
{
	this->arr = ref.arr;
	this->maximum = ref.maximum;
	return (*this);
}

Span::~Span()
{}

void Span::addNumber(int element)
{
	if (this->arr.size() < this->maximum)
		this->arr.push_back(element);
	else
		throw FullStoredException();
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
	if (arr.empty() || arr.size() == 1)
		throw NoSpanFoundException();
	std::vector<int> tmp = arr;
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
	if (arr.empty() || arr.size() == 1)
		throw NoSpanFoundException();
	std::vector<int> tmp = arr;
	std::sort(tmp.begin(), tmp.end());
	return (tmp.back() - tmp.front());
}