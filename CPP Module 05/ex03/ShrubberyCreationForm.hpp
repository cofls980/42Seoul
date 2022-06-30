#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include <iostream>
#include <fstream>
#include <string>
#include "Form.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public Form
{
private:
	std::string target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& ref);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& ref);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);

	virtual void execute(Bureaucrat const & executor) const;

	class FileCreationFailException : public std::exception
	{
	public:
		const char * what() const throw();
	};
};

#endif