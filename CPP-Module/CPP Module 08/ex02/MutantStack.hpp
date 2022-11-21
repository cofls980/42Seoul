#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack();
	MutantStack(const MutantStack& ref);
	MutantStack& operator=(const MutantStack& ref);
	~MutantStack();

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin();
	iterator end();

	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	reverse_iterator rbegin();
	reverse_iterator rend();

	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	const_iterator cbegin();
	const_iterator cend();

	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
	const_reverse_iterator crbegin();
	const_reverse_iterator crend();
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
	if (this != &ref)
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

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return this->c.rbegin();
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return this->c.rend();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin()
{
	return (this->c.begin()); //c는 deque 컨테이너의 protected 멤버이다.
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend()
{
	return (this->c.end());
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crbegin()
{
	return this->c.rbegin();
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crend()
{
	return this->c.rend();
}

#endif