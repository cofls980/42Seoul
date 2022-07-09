#include "Form.hpp"

Form::Form() : name("FORM_Default"), gradeSign(150), gradeExecute(150), isSigned(false)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const Form& ref) : name(ref.getName()), gradeSign(ref.getGradeSign()), gradeExecute(ref.getGradeExecute()), isSigned(ref.getIsSigned())
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& ref) 
{
	std::cout << "Form copy assignment operator called" << std::endl;
	this->isSigned = ref.getIsSigned();
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(std::string _name, int _gradeSign, int _gradeExecute) : name(_name), gradeSign(_gradeSign), gradeExecute(_gradeExecute), isSigned(false)
{
	std::cout << "Form constructor called" << std::endl;
	if (gradeSign < 1 || gradeExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeSign > 150 || gradeExecute > 150)
		throw Form::GradeTooLowException();
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

void Form::beSigned(const Bureaucrat& ref)
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
	return ("a grade is too high");
}

const char * Form::GradeTooLowException::what() const throw()
{
	return ("a grade is too low");
}

const char * Form::NotSignedException::what() const throw()
{
	return ("a form is not signed");
}