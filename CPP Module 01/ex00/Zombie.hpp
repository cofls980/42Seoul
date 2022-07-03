#pragma once
#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <iostream>

class Zombie {

private:
	std::string name;

public:
	Zombie();
	Zombie(std::string name);
	void announce(void);
	~Zombie();
};

void	randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif