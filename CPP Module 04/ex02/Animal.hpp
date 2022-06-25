#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(const Animal& ref);
	Animal& operator=(const Animal& ref);
	virtual ~Animal();

	virtual std::string getType() const = 0;
	virtual void makeSound() const = 0;
};

#endif