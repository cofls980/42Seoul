#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(const Animal& ref);
	Animal& operator=(const Animal& ref);
	virtual ~Animal();

	std::string getType() const; // 둘 다 const가 붙는 이유는 예제에서 const 객체를 사용했기도 하는데
	virtual void makeSound() const;// 이 때 const객체가 아닐 때에도 불려질 수 있도록 const로 지정
};

#endif