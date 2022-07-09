#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("robotomy request", 72, 45), target("in_robotomy")
{
	std::cout << "RRF default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref) : Form(ref.target, 72, 45), target(ref.getTarget())
{
	std::cout << "RRF copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& ref)
{
	std::cout << "RRF copy assignment operator called" << std::endl;
	this->target = ref.getTarget();
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RRF destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string _target) : Form("robotomy request", 72, 45), target(_target)
{
	std::cout << "RRF constructor called" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
	return this->target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == false)
		throw Form::NotSignedException();
	if (executor.getGrade() > this->getGradeExecute())
		throw Form::GradeTooLowException();
	std::cout << "[ DRILL NOISES ]" << std::endl;
	srand(time(NULL));
	if (rand() % 2)
		std::cout << this->target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->target << " has not been robotomized successfully" << std::endl;
}