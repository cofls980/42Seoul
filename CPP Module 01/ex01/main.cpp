#include "Zombie.hpp"

int main(void)
{
	Zombie zombie("TOO");
	zombie.announce();

	int num = 3;
	Zombie *zombies = zombieHorde(num, "Foo");
	for (int i = 0;i < num;i++)
	{
		zombies[i].announce();
	}
	delete [] zombies;
	return (0);
}