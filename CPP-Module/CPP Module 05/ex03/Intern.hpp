#ifndef INTERN_H
#define INTERN_H

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

class Form;

class Intern
{
private:
	Form* Shrubbery(std::string targetForm);
	Form* Robotomy(std::string targetForm);
	Form* Presidential(std::string targetForm);

public:
	Intern();
	Intern(const Intern& ref);
	Intern& operator=(const Intern& ref);
	~Intern();

	Form* makeForm(std::string formName, std::string targetForm);

	class DoesNotExistException : public std::exception
	{
	public:
		const char * what() const throw();
	};
};

#endif