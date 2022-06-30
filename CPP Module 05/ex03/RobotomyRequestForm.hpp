#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include <iostream>
#include <cstdlib>
#include "Form.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm : public Form
{
private:
	std::string target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& ref);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& ref);
	~RobotomyRequestForm();
	RobotomyRequestForm(std::string target);

	virtual void execute(Bureaucrat const & executor) const;
};

#endif