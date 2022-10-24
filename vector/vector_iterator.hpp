#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include <cstddef>
#include "iterator_traits.hpp"
/*
	random_access_iterator
*/
namespace ft {

	template<class T, class Pointer = T*, class Reference = T&>
	class vector_iterator {
		
		public:
			typedef typename ft::iterator_traits<T*>::value_type value_type;
			typedef typename ft::iterator_traits<T*>::pointer pointer;
			typedef typename ft::iterator_traits<T*>::reference reference;
			typedef typename ft::iterator_traits<T*>::difference_type difference_type;
			typedef typename ft::iterator_traits<T*>::iterator_category iterator_category;
			pointer _pointer;

		public:
			vector_iterator() : _pointer(0) {}
			vector_iterator(const pointer& p) {
				this->_pointer = p;
			}
			vector_iterator(const vector_iterator& x) {
				if (*this != x)
					this->_pointer = x._pointer;
			}
			vector_iterator& operator= (const vector_iterator& x) {
				if (*this != x)
					this->_pointer = x._pointer;
				return *this;
			}
			~vector_iterator() {}

			//-------------operators
			bool operator==(const vector_iterator& x) {
				return this->_pointer == x._pointer;
			}
			bool operator!=(const vector_iterator& x) {
				return !(*this == x);
			}

			reference operator*() const {
				return *(this->_pointer);
			}
			/**reference opterator->() {
				return *this;
			}*/
			//*a = t
			vector_iterator& operator++() { //전위
				_pointer++;
				return *this;
			}
			vector_iterator operator++(int) {//후위
				vector_iterator it = *this;
				_pointer++;
				return it;
			}
			vector_iterator& operator--() {
				_pointer--;
				return *this;
			}
			vector_iterator operator--(int) {
				vector_iterator it = *this;
				_pointer--;
				return it;
			}

			vector_iterator& operator+(difference_type n) { // +=
				difference_type m = n;
				if (n >= 0) while (m--) ++(*this);
				else while (m++) --(*this);
				return (*this);
			}
			friend vector_iterator operator+(const vector_iterator& x, difference_type n) {
				vector_iterator temp = x;
				return temp += n;
			}
			/*friend iterator operator+(difference_type n, const iterator& x) {
				iterator temp = x;
				return temp += n;
			}*/

			vector_iterator& operator-(difference_type n) {
				return (*this) += -n;
			}
			friend vector_iterator operator-(const vector_iterator& x, difference_type n) {
				vector_iterator temp = x;
				return temp -= n;
			}
			/*friend difference_type opreator-(const iterator& a, const iterator& b) {
				//a+n==b
				difference_type n;
				return n;
			}*/

			reference operator[](difference_type n) {
				vector_iterator it = *this;
				//return *(n + it);
				return *(it + n);
			}

			friend bool operator<(const vector_iterator& a, const vector_iterator& b) {
				return (b - a > 0);
			}
			friend bool operator>(const vector_iterator& a, const vector_iterator& b) {
				return (b < a);
			}
			friend bool operator<=(const vector_iterator& a, const vector_iterator& b) {
				return !(a > b);
			}
			friend bool operator>=(const vector_iterator& a, const vector_iterator& b) {
				return !(a < b);
			}
	};
}

#endif