#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat& ref);
	Cat& operator=(const Cat& ref);
	virtual ~Cat();

	virtual void makeSound() const;
};

#endif