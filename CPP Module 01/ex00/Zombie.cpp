#include "Zombie.hpp"

Zombie::Zombie(std::string _name) : name(_name)
{}

void	Zombie::announce(void)
{
	std::cout << this->name << ": ";
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "DESTROY " << this->name << std::endl;
}