#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat a("aa", 151);
		std::cout << a;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b("chaekim", 2);
		std::cout << b;
		std:: cout << b.getName() << std::endl;
		std:: cout << b.getGrade() << std::endl;
		b.gradeIncrement(3);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat c("cc", 10);
		std::cout << c;
		std:: cout << c.getName() << std::endl;
		std:: cout << c.getGrade() << std::endl;
		c.gradeIncrement(3);
		std::cout << c;
		c.gradeDecrement(20);
		std::cout << c;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}