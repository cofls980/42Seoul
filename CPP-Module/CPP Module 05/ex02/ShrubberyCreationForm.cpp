#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("shrubbery creation", 145, 137), target("in_shrubbery")
{
	std::cout << "SCF default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref) : Form(ref.getTarget(), 145, 137), target(ref.getTarget())
{
	std::cout << "SCF copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref)
{
	std::cout << "SCF copy assignment operator called" << std::endl;
	this->target = ref.getTarget();
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "SCF destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : Form("shrubbery creation", 145, 137), target(_target)
{
	std::cout << "SCF constructor called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return this->target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == false)
		throw Form::NotSignedException();
	if (executor.getGrade() > this->getGradeExecute())
		throw Form::GradeTooLowException();
	std::string file = this->getTarget() + "_shrubbery";
	std::ofstream ofs(file.c_str(), std::ios::out | std::ios::trunc);
	if (ofs.fail())
	{
		std::cout << "the file open error" << std::endl;
		return ;
	}
	std::string tree = "\
     ccee88oo\n\
  C8O8O8Q8PoOb o8oo\n\
 dOB69QO8PdUOpugoO9bD\n\
CgggbU8OU qOp qOdoUOdcb\n\
    6OuU  /p u gcoUodpP\n\
      \\\\\\//  /douUP\n\
        \\\\\\////\n\
         |||/\\\n\
         |||\\/\n\
         |||||\n\
   .....//||||\\....\n";
	ofs << tree;
	ofs.close();
}