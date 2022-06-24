#include "FragTrap.hpp"

int main(void)
{
	{
		FragTrap s("Alice");

		s.attack("Trudy1");
		s.beRepaired(30);
	}
	{
		ClapTrap c("Cloud");

		c.attack("Trudy2");
		c.beRepaired(10);
	}
	{
		FragTrap s("Bob");

		s.attack("Trudy3");
		s.highFivesGuys();
		s.beRepaired(10);
	}
}