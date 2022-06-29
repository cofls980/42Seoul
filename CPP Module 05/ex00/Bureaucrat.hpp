#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>

class Bureaucrat
{
	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException();
	};
	private:
		std::string name;
		int grade;

	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& ref);
		Bureaucrat& operator=(const Bureaucrat& ref);
		~Bureaucrat();
		Bureaucrat(std::string name, int grade);

		std::string getName() const;
		int getGrade() const;

		void gradeIncrement(int plus);
		void gradeDecrement(int minus);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& ref);

#endif