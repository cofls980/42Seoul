#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat& ref);
	Cat& operator=(const Cat& ref);
	~Cat();

	virtual std::string getType() const;
	virtual void makeSound() const;
};

#endif