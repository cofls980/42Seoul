#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0;i < 100;i++)
	{
		this->ideas[i] = "";
	}
}

Brain::Brain(const Brain& ref)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0;i < 100;i++)
	{
		this->ideas[i] = ref.getIdea(i);
	}
}

Brain& Brain::operator=(const Brain& ref)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	for (int i = 0;i < 100;i++)
	{
		this->ideas[i] = ref.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int index, std::string idea)
{
	if (0 <= index && index < 100)
	{
		this->ideas[index] = idea;
	}
	else
		std::cout << "Wrong Index" << std::endl;
}

std::string Brain::getIdea(int index) const
{
	if (0 <= index && index < 100)
		return this->ideas[index];
	return "Wrong Index";
}