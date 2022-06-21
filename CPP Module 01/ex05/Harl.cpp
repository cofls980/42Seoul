#include "Harl.hpp"

Harl::Harl(/* args */)
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*fp[4])(void);

	fp[0] = &Harl::debug;
	fp[1] = &Harl::info;
	fp[2] = &Harl::warning;
	fp[3] = &Harl::error;

	std::string complain[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0;i < 4;i++)
	{
		if (level.compare(complain[i]) == 0)
		{
			(this->*fp[i])();
			return ;
		}
	}
	std::cout << "Think about the level!" << std::endl;
}