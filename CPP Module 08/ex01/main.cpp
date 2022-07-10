#include "Span.hpp"

int main(void)
{
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl;
	{
		Span sp = Span(12000);
		std::vector<int> t;
		for (int i = 0;i < 12000;i++)
			t.push_back(i);
		sp.addManyNumber(t.begin(), t.end());
		std::cout << sp.getSize() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Span sp = Span(3);
		sp.addNumber(1);
		sp.addNumber(3);
		sp.addNumber(5);
		sp.addNumber(7);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Span sp = Span(1);
		sp.addNumber(1);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}