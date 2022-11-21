#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include <cstdlib>
#include "Form.hpp"

class Bureaucrat;

class RobotomyRequestForm : public Form
{
private:
	std::string target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& ref);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& ref);
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm(std::string _target);

	std::string getTarget() const;

	virtual void execute(Bureaucrat const & executor) const;
};

#endif