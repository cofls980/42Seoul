#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Shrubbery", 145, 137)
{
	this->target = "in shrubbery";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref) : Form(ref.target, 145, 137)
{
	this->target = ref.target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref) //
{
	this->target = ref.target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form(target, 145, 137)
{
	this->target = target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > Form::getGradeExecute())
		throw Form::GradeTooLowException();
	std:: string t = this->target;
	std::string file = t.append("_shrubbery");
	std::ofstream ofs(file.data(), std::ios::out | std::ios::trunc);
	if (ofs.fail())
		throw ;
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

const char * ShrubberyCreationForm::FileCreationFailException::what() const throw()
{
	return ("Fail to create file.");
}