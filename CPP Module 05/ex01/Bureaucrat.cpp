#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	this->name = "Default";
	this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->name = name;
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& ref)
{
	this->name = ref.name;
	this->grade = ref.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref)
{
	this->name = ref.name;
	this->grade = ref.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{}

std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::gradeIncrement(int plus)
{
	if (this->grade - plus < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade -= plus;
}

void Bureaucrat::gradeDecrement(int minus)
{
	if (this->grade + minus > 150)
		throw Bureaucrat::GradeTooHighException();
	this->grade += minus;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& ref)
{
	out << ref.getName() << ", bureaucrat grade ";
	out << ref.getGrade() << ".";
	return (out);
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

void Bureaucrat::signForm(Form& form)
{
	if (form.getIsSigned())
	{
		std::cout << this->getName() << " couldn't sign " << form.getName();
		std::cout << " because it was signed" << std::endl;
	}
	else
	{
		try
		{
			form.beSigned(*this);
			std::cout << this->getName() << " signed " << form.getName() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << this->getName() << " couldn't sign " << form.getName();
			std::cout << " because " << e.what() << std::endl;
		}
		
	}
	
}