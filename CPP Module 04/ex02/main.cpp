#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	/*const Animal* arr[10];

	for (int i = 0;i < 5;i++)
	{
		arr[i] = new Dog();
	}
	for (int i = 5;i < 10;i++)
	{
		arr[i] = new Cat();
	}
	for (int i = 0;i < 10;i++)
	{
		std::cout << arr[i]->getType() << ": ";
		arr[i]->makeSound();
		std::cout << std::endl;
		delete arr[i];
	}*/
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	//meta->getType();
	//...
	return 0;
}