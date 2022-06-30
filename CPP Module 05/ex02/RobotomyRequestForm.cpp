#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("Robotomy", 72, 45)
{
	this->target = "in robotomy";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref) : Form(ref.target, 72, 45)
{
	this->target = ref.target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& ref) //
{
	this->target = ref.target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form(target, 72, 45)
{
	this->target = target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > Form::getGradeExecute())
		throw Form::GradeTooLowException();
	std::cout << "[ DRILL NOISES ]" << std::endl;
	srand((unsigned int)time(NULL));
	if (rand() % 2)
		std::cout << this->target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->target << " has not been robotomized successfully" << std::endl;
}