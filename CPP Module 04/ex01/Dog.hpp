#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *brain;

public:
	Dog();
	Dog(const Dog& ref);
	Dog& operator=(const Dog& ref);
	virtual ~Dog();

	virtual void makeSound() const;

	Brain *getBrain() const;
	void setBrain(Brain &brain);
};

#endif