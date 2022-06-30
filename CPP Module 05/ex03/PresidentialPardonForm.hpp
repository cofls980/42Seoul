#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include <iostream>
#include <cstdlib>
#include "Form.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class PresidentialPardonForm : public Form
{
private:
	std::string target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& ref);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& ref);
	~PresidentialPardonForm();
	PresidentialPardonForm(std::string target);

	virtual void execute(Bureaucrat const & executor) const;
};

#endif