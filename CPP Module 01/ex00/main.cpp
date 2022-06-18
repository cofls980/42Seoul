#include "Zombie.hpp"

int main(void)
{
	Zombie zombie("Foo");
	zombie.announce();

	randomChump("Marry");

	Zombie *zz = newZombie("Harry");
	(*zz).announce();

	return (0);
}