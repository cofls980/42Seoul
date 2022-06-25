#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *idea;

public:
	Cat();
	Cat(const Cat& ref);
	Cat& operator=(const Cat& ref);
	virtual ~Cat();

	virtual std::string getType() const;
	virtual void makeSound() const;
};

#endif