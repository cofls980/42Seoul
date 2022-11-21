#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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
	std::cout << "* ShrubberyCreationForm *" << std::endl;
	try
	{
		Bureaucrat tester("tester", 27);
		ShrubberyCreationForm scf("home");
		std::cout << tester << std::endl;
		tester.executeForm(scf);
		tester.signForm(scf);
		tester.executeForm(scf);
		std::cout << tester << std::endl;
		std::cout << scf << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "* RobotomyRequestForm *" << std::endl;
	try
	{
		Bureaucrat tester("tester", 100);
		RobotomyRequestForm rrf("robotomy");
		std::cout << tester << std::endl;
		tester.signForm(rrf);
		for (int i = 0;i < 50;i++)
			tester.gradeIncrement();
		tester.signForm(rrf);
		tester.executeForm(rrf);
		for (int i = 0;i < 30;i++)
			tester.gradeIncrement();
		tester.executeForm(rrf);
		std::cout << tester << std::endl;
		std::cout << rrf << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "* PresidentialPardonForm *" << std::endl;
	try
	{
		Bureaucrat tester("tester", 6);
		PresidentialPardonForm ppf("pardon");
		std::cout << tester << std::endl;
		std::cout << ppf << std::endl;
		tester.signForm(ppf);
		tester.executeForm(ppf);
		tester.gradeIncrement();
		tester.executeForm(ppf);
		std::cout << tester << std::endl;
		std::cout << ppf << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}