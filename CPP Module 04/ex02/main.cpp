#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <string>

int main()
{
	{
		std::cout << "* Use Brain with Cat *" << std::endl;
		Brain b;
		b.setIdea(0, "nice to meet you");
		Cat *c = new Cat();
		c->setBrain(b);
		std::cout << c->getBrain()->getIdea(0) << std::endl;
		delete c;
	}
	std::cout << std::endl;
	{
		std::cout << "* Use Brain with Dog *" << std::endl;
		Brain b;
		b.setIdea(1, "This object's type is [Dog]");
		Dog *d = new Dog();
		d->setBrain(b);
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
		//const Animal* meta = new Animal();
		const Animal* j = new Dog();//업캐스팅이 어떻게 적용되는지
		const Animal* i = new Cat();//dog, cat 부분집합
		//예를 들어 Animal 배열에 각 인덱스에 서로 다른 동물들을 인서트하고 싶은 경우, 이렇게 이와같은 경우를 생각했을 때 사용됨.

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();//Animal 포인터를 사용하여 각 재정의된 동물 울음소리가 잘 출력되는지 확인 용도
		j->makeSound();//업캐스팅돼서 어떻게 이렇게 나오는지
		//meta->makeSound();
		
		//delete meta;
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
	return 0;
}