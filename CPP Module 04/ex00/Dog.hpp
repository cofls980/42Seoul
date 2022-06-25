#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog& ref);
	Dog& operator=(const Dog& ref);
	~Dog();

	virtual std::string getType() const;
	virtual void makeSound() const;
};

#endif