#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie zombie(name);
	Zombie *zom = &zombie;
	return (zom);
}