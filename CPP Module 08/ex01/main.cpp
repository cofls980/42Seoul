#include "Span.hpp"

int main(void)
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	std::vector<int> t;
	srand((unsigned int)time(NULL));
	for (int i = 0;i < 3;i++)
	{
		t.push_back(rand());
		std::cout << t[i] << ", ";
	}
	std::cout << std::endl;
	Span sp1(6);
	sp1.addManyNumber(t);
	std::cout << sp1.shortestSpan() << std::endl;
	std::cout << sp1.longestSpan() << std::endl;

	return (0);
}