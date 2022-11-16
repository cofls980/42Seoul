#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include "../vector/vector.hpp"

namespace ft {
	template <class T, class Container = ft::vector<T> > 
	class stack {
		public:
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

		protected:
			container_type c;

		public:
			explicit stack (const container_type& ctnr = container_type()) : c(ctnr) {}
			stack( const stack& other ) : c(other.c) {}
			~stack() {}
			stack& operator=( const stack& other ) {
				if (this != &other) {
					c = other.c;
				}
				return (*this);
			}

			bool empty() const {return (c.empty());}

			size_type size() const {return (c.size());}

			value_type& top() {return (c.back());}
			
			const value_type& top() const {return (c.back());}

			void push (const value_type& val) {c.push_back(val);}

			void pop() {c.pop_back();}

			friend bool operator== (const stack& lhs, const stack& rhs) {return (lhs.c == rhs.c);}
			friend bool operator!= (const stack& lhs, const stack& rhs) {return (lhs.c != rhs.c);}
			friend bool operator< (const stack& lhs, const stack& rhs) {{return (lhs.c < rhs.c);}}
			friend bool operator<= (const stack& lhs, const stack& rhs) {{return (lhs.c <= rhs.c);}}
			friend bool operator> (const stack& lhs, const stack& rhs) {{return (lhs.c > rhs.c);}}
			friend bool operator>= (const stack& lhs, const stack& rhs) {{return (lhs.c >= rhs.c);}}
	};
}

#endif