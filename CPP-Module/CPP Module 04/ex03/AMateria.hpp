#ifndef AMATERIA_H
#define AMATERIA_H

#include <iostream>
#include "ICharacter.hpp" // I로 시작하는 헤더파일은 인터페이스

class AMateria
{
protected:
	std::string type;

public:
	AMateria();
	AMateria(const AMateria& ref);
	AMateria& operator=(const AMateria& ref);
	AMateria(std::string const &type);
	~AMateria();

	std::string const& getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif