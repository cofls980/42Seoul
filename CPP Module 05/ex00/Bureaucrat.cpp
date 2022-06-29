#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
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
	try
	{
		if (this->grade - plus < 1)
			throw Bureaucrat::GradeTooHighException();
		this->grade -= plus;
	}
	catch(const std::exception& e)
	{
		//std::cout << e.what() << std::endl;
		//std::cerr << e.what() << '\n';
	}
}

void Bureaucrat::gradeDecrement(int minus)
{
	try
	{
		if (this->grade + minus > 150)
			throw Bureaucrat::GradeTooHighException();
		this->grade += minus;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		//std::cerr << e.what() << '\n';
	}
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& ref)
{
	out << ref.getName() << ", bureaucrat grade ";
	out << ref.getGrade() << "." << std::endl;
	return (out);
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
{
	std::cout << "Grade too high" << std::endl;
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{
	std::cout << "Grade too low" << std::endl;
}