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
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

		protected:
			container_type _cont;

		public:
			explicit stack (const container_type& ctnr = container_type()) : _cont(ctnr) {}
			stack( const stack& other ) : _cont(other._cont) {}
			~stack() {}
			stack& operator=( const stack& other ) {
				if (this != &other) {
					_cont = other._cont;
				}
				return (*this);
			}

			bool empty() const {return (_cont.empty());}

			size_type size() const {return (_cont.size());}

			value_type& top() {return (_cont.back());}
			
			const value_type& top() const {return (_cont.back());}

			void push (const value_type& val) {_cont.push_back(val);}

			void pop() {_cont.pop_back();}

			friend bool operator== (const stack& lhs, const stack& rhs) {return (lhs._cont == rhs._cont);}
			friend bool operator!= (const stack& lhs, const stack& rhs) {return (lhs._cont != rhs._cont);}
			friend bool operator< (const stack& lhs, const stack& rhs) {{return (lhs._cont < rhs._cont);}}
			friend bool operator<= (const stack& lhs, const stack& rhs) {{return (lhs._cont <= rhs._cont);}}
			friend bool operator> (const stack& lhs, const stack& rhs) {{return (lhs._cont > rhs._cont);}}
			friend bool operator>= (const stack& lhs, const stack& rhs) {{return (lhs._cont >= rhs._cont);}}
	};
}

#endif