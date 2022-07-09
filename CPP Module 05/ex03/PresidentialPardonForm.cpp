#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("presidential pardon", 25, 5), target("in_presidential")
{
	std::cout << "PPF default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref) : Form(ref.target, 25, 5), target(ref.getTarget())
{
	std::cout << "PPF copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& ref)
{
	std::cout << "PPF copy assignment operator called" << std::endl;
	this->target = ref.getTarget();
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PPF destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string _target) : Form("presidential pardon", 25, 5), target(_target)
{
	std::cout << "PPF constructor called" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
	return this->target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == false)
		throw Form::NotSignedException();
	if (executor.getGrade() > this->getGradeExecute())
		throw Form::GradeTooLowException();
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}