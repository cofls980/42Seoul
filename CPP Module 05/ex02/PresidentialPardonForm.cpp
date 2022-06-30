#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("Presidential", 25, 5)
{
	this->target = "in Presidential";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref) : Form(ref.target, 25, 5)
{
	this->target = ref.target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& ref) //
{
	this->target = ref.target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form(target, 25, 5)
{
	this->target = target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > Form::getGradeExecute())
		throw Form::GradeTooLowException();
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}