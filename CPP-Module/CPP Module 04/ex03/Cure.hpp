#ifndef CURE_H
#define CURE_H

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : virtual public AMateria
{
private:
public:
	Cure();
	Cure(const Cure& ref);
	Cure& operator=(const Cure& ref);
	~Cure();

	virtual AMateria* clone() const;
	virtual void use( ICharacter& target);
};

#endif