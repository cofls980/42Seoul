#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat a("aa", 151);
		std::cout << a << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat b("chaekim", 2);
		std::cout << b << std::endl;
		std:: cout << b.getName() << std::endl;
		std:: cout << b.getGrade() << std::endl;
		b.gradeIncrement(3);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat c("cc", 10);
		std::cout << c << std::endl;
		std:: cout << c.getName() << std::endl;
		std:: cout << c.getGrade() << std::endl;
		c.gradeIncrement(3);
		std::cout << c << std::endl;
		c.gradeDecrement(20);
		std::cout << c << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Form a("aa", 2, 5);
		Bureaucrat b("bb", 25);
		b.signForm(a);
		std::cout << b <<std::endl;
		std::cout << a << std::endl;
		b.gradeIncrement(13);
		b.signForm(a);
		std::cout << b <<std::endl;
		std::cout << a << std::endl;
		b.gradeIncrement(10);
		b.signForm(a);
		std::cout << b <<std::endl;
		std::cout << a << std::endl;
		b.signForm(a);
		std::cout << b <<std::endl;
		std::cout << a << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
}