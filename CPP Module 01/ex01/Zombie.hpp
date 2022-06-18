#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie {

private:
	std::string name;

public:
	Zombie();
	void init(std::string name);
	void announce(void);
	~Zombie();
};

Zombie*	zombieHorde(int N, std::string name);

#endif