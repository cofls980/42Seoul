#include "Zombie.hpp"

Zombie::Zombie()
{
	this->name = "";
}

void	Zombie::init(std::string name)
{
	this->name = name;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": ";
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "DESTROY " << this->name << std::endl;
}