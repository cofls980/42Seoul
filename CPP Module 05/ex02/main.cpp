#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat a("aa", 27);
		Form *f = new ShrubberyCreationForm("home");
		std::cout << a << std::endl;
		a.signForm(*f);
		a.signForm(*f);
		a.executeForm(*f);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat a("aa", 100);
		Form *f = new RobotomyRequestForm("robot");
		std::cout << a << std::endl;
		a.signForm(*f);
		a.gradeIncrement(20);
		a.gradeIncrement(20);
		a.signForm(*f);
		a.executeForm(*f);
		a.gradeIncrement(20);
		a.executeForm(*f);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat a("aa", 6);
		Form *f = new PresidentialPardonForm("pardon");
		std::cout << a << std::endl;
		std::cout << *f << std::endl;
		a.signForm(*f);
		a.signForm(*f);
		a.executeForm(*f);
		a.gradeIncrement(2);
		a.executeForm(*f);
		std::cout << a << std::endl;
		std::cout << *f << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}