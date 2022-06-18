#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie {

private:
	std::string name;

public:
	Zombie(std::string name);
	void announce(void);
	~Zombie();
};

void	randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif