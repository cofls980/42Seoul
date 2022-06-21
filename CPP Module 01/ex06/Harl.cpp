#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
	std::cout << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
	std::cout << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*fp[4])(void);

	fp[0] = &Harl::debug;
	fp[1] = &Harl::info;
	fp[2] = &Harl::warning;
	fp[3] = &Harl::error;

	int num;
	std::string complain[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0;i < 4;i++)
	{
		if (level.compare(complain[i]) == 0)
		{
			num = i;
			break ;
		}
	}
	switch (num)
	{
		case 0:
				(this->*fp[0])();
		case 1:
			(this->*fp[1])();
		case 2:
			(this->*fp[2])();
		case 3:
			(this->*fp[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}