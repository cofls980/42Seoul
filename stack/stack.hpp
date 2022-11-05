#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include "../vector/vector.hpp"

/*
std::vector -> ft::vector
*/

/*
컨테이너 어댑터: 기존 컨테이너의 인터페이스를 제한하여 만든 기능이 제한되거나 변형된 컨테이너
				반복자를 지원하지 않으므로 STL 알고리즘에서는 사용할 수 없다.
	- 종류: stack, queue, priority_queue
*/

namespace ft {
	template <class T, class Container = ft::vector<T> > 
	class stack {
		public:
		typedef T value_type;
		typedef Container container_type;
		typedef unsigned long size_type;

		container_type _cont;

		explicit stack (const container_type& ctnr = container_type())
		{
			this->_cont = ctnr;
		}

		bool empty() const
		{
			return (this->size() == 0);
		}

		size_type size() const
		{
			return (this->_cont.size());
		}

		value_type& top()
		{
			return (this->_cont.back());
		}
		 
		const value_type& top() const
		{
			return (this->_cont.back());
		}

		void push (const value_type& val)
		{
			this->_cont.push_back(val);
		}

		void pop()
		{
			this->_cont.pop_back();
		}

		friend bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{
			return (lhs._cont == rhs._cont);
		}
		friend bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{
			return (lhs._cont != rhs._cont);
		}
		friend bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{
			return (lhs._cont < rhs._cont);
		}
		friend bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{
			return (lhs._cont <= rhs._cont);
		}
		friend bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{
			return (lhs._cont > rhs._cont);
		}
		friend bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{
			return (lhs._cont >= rhs._cont);
		}
	};
}

#endif