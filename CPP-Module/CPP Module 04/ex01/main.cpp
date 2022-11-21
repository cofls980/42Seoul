#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <string>

int main()
{
	{
		std::cout << "* Use Brain with Cat *" << std::endl;
		Cat *c = new Cat();
		c->getBrain()->setIdea(0, "nice to meet you");
		std::cout << c->getBrain()->getIdea(0) << std::endl;
		delete c;
	}
	std::cout << std::endl;
	{
		std::cout << "* Use Brain with Dog *" << std::endl;
		Dog *d = new Dog();
		d->getBrain()->setIdea(0, "nice to meet you");
		d->getBrain()->setIdea(1, "This object's type is [Dog]");
		std::cout << d->getBrain()->getIdea(1) << std::endl;
		std::cout << d->getBrain()->getIdea(50) << std::endl;
		std::cout << d->getBrain()->getIdea(-1) << std::endl;
		std::cout << d->getBrain()->getIdea(105) << std::endl;
		delete d;
	}
	std::cout << std::endl;
	{
		std::cout << "* Animal array *" << std::endl;
		const int num = 6;
		const Animal* arr[num];

		for (int i = 0;i < num / 2;i++)
		{
			arr[i] = new Dog();
		}
		for (int i = num / 2;i < num;i++)
		{
			arr[i] = new Cat();
		}
		std::cout << std::endl;
		for (int i = 0;i < num;i++)
		{
			std::cout << arr[i]->getType() << ": ";
			arr[i]->makeSound();
			delete arr[i];
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "* Normal *" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();
		
		delete meta;
		delete j;
		delete i;
	}
	std::cout << std::endl;
	{
		std::cout << "* Wrong *" << std::endl;
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();

		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		meta->makeSound();
		
		delete meta;
		delete i;
	}
	system("leaks brain");
	return 0;
}