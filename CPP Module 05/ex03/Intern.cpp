#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& ref)
{
	std::cout << "Intern copy constructor called" << std::endl;
	(void)ref;
}

Intern& Intern::operator=(const Intern& ref)
{
	std::cout << "Intern copy assignment operator called" << std::endl;
	(void)ref;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Form* Intern::Shrubbery(std::string targetForm)
{
	return new ShrubberyCreationForm(targetForm);
}

Form* Intern::Robotomy(std::string targetForm)
{
	return new RobotomyRequestForm(targetForm);
}

Form* Intern::Presidential(std::string targetForm)
{
	return new PresidentialPardonForm(targetForm);
}

Form* Intern::makeForm(std::string formName, std::string targetForm)
{
	Form* (Intern::*fp[3])(std::string);

	fp[0] = &Intern::Shrubbery;
	fp[1] = &Intern::Robotomy;
	fp[2] = &Intern::Presidential;

	std::string targets[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0;i < 3;i++)
	{
		if (formName.compare(targets[i]) == 0)
		{
			std::cout << "Intern creates " << formName << std::endl;
			Form *res = (this->*fp[i])(targetForm);
			return res;
		}
	}
	throw Intern::DoesNotExistException();
	return (0);
}

const char * Intern::DoesNotExistException::what() const throw()
{
	return ("Name does not exist.");
}