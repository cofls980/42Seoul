#include "FragTrap.hpp"

int main(void)
{
	{
		FragTrap s("Alice");

		std::cout << "name: " << s.getName() << std::endl;
		std::cout << "hit point: " << s.getHitPoint() << std::endl;
		std::cout << "energy point: " << s.getEnergyPoint() << std::endl;
		std::cout << "attack damage: " << s.getAttackDamage() << std::endl;
		s.attack("Trudy1");
		s.beRepaired(30);
		s.takeDamage(50);
		s.takeDamage(50);
		s.highFivesGuys();
	}
	std::cout << std::endl;
	{
		ClapTrap c("Cloud");

		c.attack("Trudy2");
		c.beRepaired(10);
	}
	std::cout << std::endl;
	{
		FragTrap s("Bob");

		s.attack("Trudy3");
		s.highFivesGuys();
		s.beRepaired(10);
	}
}