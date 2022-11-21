#include "ClapTrap.hpp"

int main(void)
{
	{
		ClapTrap a("Alice");

		a.attack("Trudy");
		a.beRepaired(7);
		a.takeDamage(5);
		a.beRepaired(5);
		a.takeDamage(5);
		a.beRepaired(2);
		a.takeDamage(10);
		a.attack("Trudy");
		a.beRepaired(10);
	}
	std::cout << std::endl;
	{
		ClapTrap a;
		ClapTrap b("Bob");
		ClapTrap c("Alice");

		a = c;
		b.beRepaired(7);
		b.attack("Trudy");
		b.takeDamage(10);
		b.beRepaired(10);
		a.attack("Emily");
		a.takeDamage(2);
		a.beRepaired(10);
	}
	return (0);
}