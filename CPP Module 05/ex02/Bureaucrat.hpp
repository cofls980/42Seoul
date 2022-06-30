#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	std::string name;
	int grade;

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& ref);
	Bureaucrat& operator=(const Bureaucrat& ref);
	virtual ~Bureaucrat();
	Bureaucrat(std::string name, int grade);

	std::string getName() const;
	int getGrade() const;

	void gradeIncrement(int plus);
	void gradeDecrement(int minus);

	void signForm(Form& form);

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