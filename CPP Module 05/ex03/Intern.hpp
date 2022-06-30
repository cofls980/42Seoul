#ifndef INTERN_H
#define INTERN_H

#include <iostream>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Form;

class Intern
{
public:
	Intern();
	Intern(const Intern& ref);
	Intern& operator=(const Intern& ref);
	~Intern();

	Form* makeForm(std::string formName, std::string targetForm);
	Form* Shrubbery(std::string targetForm);
	Form* Robotomy(std::string targetForm);
	Form* Presidential(std::string targetForm);

	class DoesNotExistException : public std::exception
	{
	public:
		const char * what() const throw();
	};
};

#endif