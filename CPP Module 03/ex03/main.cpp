#include "DiamondTrap.hpp"

int main(void)
{
	{
		DiamondTrap s("Alice");

		s.attack("Trudy1");
		s.beRepaired(30);
	}
	{
		ClapTrap c("Cloud");

		c.attack("Trudy2");
		c.beRepaired(10);
	}
	{
		DiamondTrap s("Bob");

		s.attack("Trudy3");
		s.highFivesGuys();
		s.beRepaired(10);
	}
}