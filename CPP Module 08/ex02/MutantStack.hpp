#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <iostream>
#include <stack>
#include <list>

template<typename T>
class MutantStack : public std::stack<T>
{
/*private:
	std::deque<T> dq;*/
public:
	MutantStack();
	MutantStack(const MutantStack& ref);
	MutantStack& operator=(const MutantStack& ref);
	~MutantStack();

	typedef typename std::deque<T>::iterator iterator;

	iterator begin();
	iterator end();
};

template<typename T>
MutantStack<T>::MutantStack()
{}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& ref)
{
	*this = ref;
}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& ref)
{
	*this = ref;
	return (*this);
}

template<typename T>
MutantStack<T>::~MutantStack()
{}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin()); //c는 deque 컨테이너의 protected 멤버이다.
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

#endif