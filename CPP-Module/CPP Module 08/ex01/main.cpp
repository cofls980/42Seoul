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
		for (int i = 1;i <= 12000;i++)
			t.push_back(i + 5);
		sp.addManyNumber(t.begin(), t.end());
		std::cout << sp.getArray().at(3) << std::endl;
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
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Span sp = Span(0);
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	Span sp = Span(5);
	sp.addNumber(1);
	Span sa;
	sa = sp;

	std::cout << "elements: ";
	for (int i = 0; i < (int)sp.getArray().size();i++)
		std::cout << sp.getArray()[i] << " ";
	std::cout << std::endl;
	std::cout << "size: " << sp.getArray().size() << ", max: " << sp.getSize() << std::endl;
	
	std::cout << "elements: ";
	for (int i = 0; i < (int)sa.getArray().size();i++)
		std::cout << sa.getArray()[i] << " ";
	std::cout << std::endl;
	std::cout << "size: " << sa.getArray().size() << ", max: " << sp.getSize() << std::endl;
	sp.addNumber(2);
	
	std::cout << "elements: ";
	for (int i = 0; i < (int)sp.getArray().size();i++)
		std::cout << sp.getArray()[i] << " ";
	std::cout << std::endl;
	std::cout << "size: " << sp.getArray().size() << ", max: " << sp.getSize() << std::endl;
	
	std::cout << "elements: ";
	for (int i = 0; i < (int)sa.getArray().size();i++)
		std::cout << sa.getArray()[i] << " ";
	std::cout << std::endl;
	std::cout << "size: " << sa.getArray().size() << ", max: " << sp.getSize() << std::endl;
	return (0);
}