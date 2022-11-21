#ifndef FORM_H
#define FORM_H

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string name;
	const int gradeSign;
	const int gradeExecute;
	bool isSigned;

public:
	Form();
	Form(const Form& ref);
	Form& operator=(const Form& ref);
	~Form();
	Form(std::string _name, int _gradeSign, int _gradeExecute);

	std::string getName() const;
	int getGradeSign() const;
	int getGradeExecute() const;
	bool getIsSigned() const;

	void beSigned(const Bureaucrat& ref);
	
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