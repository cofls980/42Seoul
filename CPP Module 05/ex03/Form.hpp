#ifndef FORM_H
#define FORM_H

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string name;
	bool isSigned;
	int gradeSign;
	int gradeExecute;

public:
	Form();
	Form(const Form& ref);
	Form& operator=(const Form& ref);
	~Form();
	Form(std::string name, int gradeSign, int gradeExecute);

	std::string getName() const;
	bool getIsSigned() const;
	int getGradeSign() const;
	int getGradeExecute() const;

	void beSigned(Bureaucrat& ref);

	virtual void execute(Bureaucrat const & executor) const = 0;
	
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

std::ostream& operator<<(std::ostream& out, const Form& ref);

#endif