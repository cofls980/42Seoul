#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include <cstdlib>
#include "Form.hpp"

class Bureaucrat;

class PresidentialPardonForm : public Form
{
private:
	std::string target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& ref);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& ref);
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm(std::string _target);

	std::string getTarget() const;

	virtual void execute(Bureaucrat const & executor) const;
};

#endif