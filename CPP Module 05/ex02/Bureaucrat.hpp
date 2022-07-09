#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string name;
	int grade;

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& ref);
	Bureaucrat& operator=(const Bureaucrat& ref);
	~Bureaucrat();
	Bureaucrat(std::string _name, int _grade);

	const std::string getName() const;
	int getGrade() const;

	void gradeIncrement();
	void gradeDecrement();
	
	void signForm(Form& form) const;

	void executeForm(Form const & form);

	class GradeTooHighException : public std::exception
	{
	public:
		const char * what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char * what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& ref);

#endif