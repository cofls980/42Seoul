#include "Bureaucrat.hpp"
#include "Form.hpp"

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
	std::cout << std::endl;
	std::cout << "* EX01 *" << std::endl;
	try
	{
		Form a("form", 2, 5);
		Bureaucrat b("tester", 25);
		b.signForm(a);
		std::cout << b <<std::endl;
		std::cout << a << std::endl;
		for (int i = 0;i < 24;i++)
			b.gradeIncrement();
		b.signForm(a);
		std::cout << b <<std::endl;
		std::cout << a << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}