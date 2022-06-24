#include "ScavTrap.hpp"

int main(void)
{
	{
		ScavTrap s("Alice");

		s.attack("Trudy1");
		s.beRepaired(30);
	}
	{
		ClapTrap c("Cloud");

		c.attack("Trudy2");
		c.beRepaired(10);
	}
	{
		ScavTrap s("Bob");

		s.attack("Trudy3");
		s.guardGate();
		s.beRepaired(10);
	}
}