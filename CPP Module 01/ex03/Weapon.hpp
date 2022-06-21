#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon { // reference & pointer 생각

private:
	std::string type;

public:
	Weapon();
	Weapon(std::string type);
	std::string getType() const; // const reference
	void setType(std::string type);
	~Weapon();
};

#endif