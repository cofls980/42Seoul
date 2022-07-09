#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include <fstream>
#include <string>
#include "Form.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public Form
{
private:
	std::string target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& ref);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& ref);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm(std::string _target);

	std::string getTarget() const;

	virtual void execute(Bureaucrat const & executor) const;
};

#endif