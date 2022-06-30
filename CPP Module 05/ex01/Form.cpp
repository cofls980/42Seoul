#include "Form.hpp"

Form::Form()
{
	this->name = "FORM";
	this->isSigned = false;
	this->gradeSign = 1;
	this->gradeExecute = 150;
}

Form::Form(const Form& ref)
{
	this->name = ref.name;
	this->isSigned = ref.isSigned;
	this->gradeSign = ref.gradeSign;
	this->gradeExecute = ref.gradeExecute;
}

Form& Form::operator=(const Form& ref)
{
	this->name = ref.name;
	this->isSigned = ref.isSigned;
	this->gradeSign = ref.gradeSign;
	this->gradeExecute = ref.gradeExecute;
	return (*this);
}

Form::~Form()
{}

Form::Form(std::string name, int gradeSign, int gradeExecute)
{
	if (gradeSign < 1 || gradeExecute < 1)
		throw GradeTooHighException();
	else if (gradeSign > 150 || gradeExecute > 150)
		throw GradeTooLowException();
	this->name = name;
	this->isSigned = false;
	this->gradeSign = gradeSign;
	this->gradeExecute = gradeExecute;
}

std::string Form::getName() const
{
	return this->name;
}

bool Form::getIsSigned() const
{
	return this->isSigned;
}

int Form::getGradeSign() const
{
	return this->gradeSign;
}

int Form::getGradeExecute() const
{
	return this->gradeExecute;
}

void Form::beSigned(Bureaucrat& ref)
{
	if (ref.getGrade() <= this->getGradeSign())
		this->isSigned = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const Form& ref)
{
	out << "name - " << ref.getName();
	if (ref.getIsSigned())
		out << " / is signed - signed";
	else
		out << " / is signed - unsigned";
	out << " / grade sign - " << ref.getGradeSign();
	out << " / grade execute - " << ref.getGradeExecute();
	return (out);
}

const char * Form::GradeTooHighException::what() const throw()
{
	return ("grade too high");
}

const char * Form::GradeTooLowException::what() const throw()
{
	return ("grade too low");
}