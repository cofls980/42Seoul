#include "Contact.hpp"

Contact::Contact(void)
{
	this->first_name = "";
	this->last_name = "";
	this->nickname = "";
	this->phone_number = "";
	this->darkest_secret = "";
}

void	Contact::add(void)
{
	std::string fn, ln, nn, ph, ds;

	std::cout << "FIRST NAME> ";
	std::cin >> fn;
	std::cout << "LAST NAME> ";
	std::cin >> ln;
	std::cout << "NICKNAME> ";
	std::cin >> nn;
	std::cout << "PHONE NUMBER> ";
	std::cin >> ph;
	std::cout << "DARKEST SECRET> ";
	std::cin >> ds;
	this->first_name = fn;
	this->last_name = ln;
	this->nickname = nn;
	this->phone_number = ph;
	this->darkest_secret = ds;
}

void	Contact::display(void)
{
	if (this->first_name.length() > 10)
		std::cout << std::setw(10) << this->first_name.substr(0, 9).append(".") << " | ";
	else
		std::cout << std::setw(10) << this->first_name << " | ";
	if (this->last_name.length() > 10)
		std::cout << std::setw(10) << this->last_name.substr(0, 9).append(".") << " | ";
	else
		std::cout << std::setw(10) << this->last_name << " | ";
	if (this->nickname.length() > 10)
		std::cout << std::setw(10) << this->nickname.substr(0, 9).append(".") << std::endl;
	else
		std::cout << std::setw(10) << this->nickname << std::endl;
}

void	Contact::display_specific_contact(void)
{
	std::cout << "FIRST NAME: " << first_name << std::endl;
	std::cout << "LAST NAME: " << last_name << std::endl;
	std::cout << "NICKNAME: " << nickname << std::endl;
	std::cout << "PHONE NUMBER: " << phone_number << std::endl;
	std::cout << "DARKEST SECRET: " << darkest_secret << std::endl;
}