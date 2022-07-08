#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>
//#include <sstream>

class Brain
{
private:
	std::string ideas[100];

public:
	Brain();
	Brain(const Brain& ref);
	Brain& operator=(const Brain& ref);
	~Brain();

	void setIdea(int index, std::string idea);
	std::string getIdea(int index) const;
};

#endif