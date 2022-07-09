#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat a("low", 151);
		std::cout << a;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat a("high", 0);
		std::cout << a;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat b("chaekim", 1);
		std::cout << b;
		b.gradeIncrement();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat c("cc", 150);
		std::cout << c;
		c.gradeIncrement();
		std::cout << c;
		c.gradeDecrement();
		std::cout << c;
		c.gradeDecrement();
		std::cout << c;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}