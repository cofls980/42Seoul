#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat b("chaekim", 2);
	std::cout << b;
	std:: cout << b.getName() << std::endl;
	std:: cout << b.getGrade() << std::endl;
	b.gradeIncrement(3);
}