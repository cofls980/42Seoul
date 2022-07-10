#include "MutantStack.hpp"

int main(void)
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "_______________________________" << std::endl;
	std::list<int> llist;
	llist.push_back(5);
	llist.push_back(17);
	std::cout << llist.back() << std::endl;
	llist.pop_back();
	std::cout << llist.size() << std::endl;
	llist.push_back(3);
	llist.push_back(5);
	llist.push_back(737);
	llist.push_back(0);
	std::list<int>::iterator it1 = llist.begin();
	std::list<int>::iterator ite1 = llist.end();
	++it1;
	--it1;
	while (it1 != ite1)
	{
		std::cout << *it1 << std::endl;
		++it1;
	}
	std::cout << std::endl;
	{
		MutantStack<int> m;
		for (int i = 0;i < 10;i++)
			m.push(i);
		MutantStack<int>::reverse_iterator rit = m.rbegin();
		MutantStack<int>::reverse_iterator rite = m.rend();
		--rite;
		std::cout << *rit << std::endl;
		std::cout << *rite << std::endl;
	}
	return (0);
}