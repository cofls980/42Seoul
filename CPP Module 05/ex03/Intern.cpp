#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern& ref)
{
	*this = ref;
}

Intern& Intern::operator=(const Intern& ref)
{
	*this = ref;
	return (*this);
}

Intern::~Intern()
{}

Form* Intern::Shrubbery(std::string targetForm)
{
	Form *f = new ShrubberyCreationForm(targetForm);
	return (f);
}

Form* Intern::Robotomy(std::string targetForm)
{
	Form *f = new RobotomyRequestForm(targetForm);
	return (f);
}

Form* Intern::Presidential(std::string targetForm)
{
	Form *f = new PresidentialPardonForm(targetForm);
	return (f);
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