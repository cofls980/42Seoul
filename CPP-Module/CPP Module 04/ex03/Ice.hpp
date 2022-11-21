#ifndef ICE_H
#define ICE_H

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : virtual public AMateria
{
private:
public:
	Ice();
	Ice(const Ice& ref);
	Ice& operator=(const Ice& ref);
	~Ice();

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif