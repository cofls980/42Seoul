#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *idea;

public:
	Dog();
	Dog(const Dog& ref);
	Dog& operator=(const Dog& ref);
	virtual ~Dog();

	virtual std::string getType() const;
	virtual void makeSound() const;
};

#endif