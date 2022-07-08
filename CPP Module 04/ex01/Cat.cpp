#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& ref) : Animal(ref)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = ref.getType();
}

Cat& Cat::operator=(const Cat& ref)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	this->type = ref.getType();
	return *this;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "MEOW!" << std::endl;
}

Brain *Cat::getBrain() const
{
	return this->brain;
}

void Cat::setBrain(Brain &brain)
{
	*(this->brain) = brain; // 아래처럼하면 brain이 먼저 소멸될 경우 소멸된 객체를 다시 소멸하려해서 오류남.
	//this->brain = &brain;
}