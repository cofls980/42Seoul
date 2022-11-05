#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include <cstddef>
#include "iterator_traits.hpp"
/*
	random_access_iterator
*/
namespace ft {

	template<class T>
	class vector_iterator {
		
		public:
			typedef typename ft::iterator_traits<T*>::value_type value_type;
			typedef typename ft::iterator_traits<T*>::pointer pointer;
			typedef typename ft::iterator_traits<T*>::reference reference;
			typedef typename ft::iterator_traits<T*>::difference_type difference_type;
			typedef typename ft::iterator_traits<T*>::iterator_category iterator_category;
		
		protected:
			pointer _ptr;

		public:
			vector_iterator() : _ptr(0) {}
			vector_iterator(const pointer& p) : _ptr(p) {}
			vector_iterator(const vector_iterator& x) : _ptr(x._ptr) {}
			vector_iterator& operator= (const vector_iterator& x) {
				if (*this == x)
					return (*this);
				_ptr = x._ptr;
				return (*this);
			}
			~vector_iterator() {}

			//-------------operators
			reference operator*() const {return (*_ptr);}
			pointer operator->() const {return (_ptr);}

			vector_iterator& operator++() {
				_ptr++;
				return (*this);
			}
			vector_iterator operator++(int) {
				vector_iterator it(*this);
				_ptr++;
				return (it);
			}
			vector_iterator& operator--() {
				_ptr--;
				return (*this);
			}
			vector_iterator operator--(int) {
				vector_iterator it(*this);
				_ptr--;
				return (it);
			}

			vector_iterator operator+(difference_type n) const {return (_ptr + n);}
			vector_iterator operator-(difference_type n) const {return (_ptr - n);}

			vector_iterator& operator+=(difference_type n) {
				_ptr += n;
				return (*this);
			}
			vector_iterator& operator-=(difference_type n) {
				_ptr -= n;
				return (*this);
			}

			reference operator[](difference_type n) {return (*(_ptr + n));}
	};

	template<class T1, class T2>
	bool operator==(const vector_iterator<T1>& left, const vector_iterator<T2>& right) {
		return (&(*left) == &(*right));
	}
	template<class T1, class T2>
	bool operator!=(const vector_iterator<T1>& left, const vector_iterator<T2>& right) {
		return (&(*left) != &(*right));
	}
	template<class T1, class T2>
	bool operator<(const vector_iterator<T1>& left, const vector_iterator<T2>& right) {
		return (&(*left) < &(*right));
	}
	template<class T1, class T2>
	bool operator>(const vector_iterator<T1>& left, const vector_iterator<T2>& right) {
		return (&(*left) > &(*right));
	}
	template<class T1, class T2>
	bool operator>=(const vector_iterator<T1>& left, const vector_iterator<T2>& right) {
		return (&(*left) >= &(*right));
	}
	template<class T1, class T2>
	bool operator<=(const vector_iterator<T1>& left, const vector_iterator<T2>& right) {
		return (&(*left) <= &(*right));
	}
	// 추가?
	template<class T>
	ft::vector_iterator<T> operator+(const typename vector_iterator<T>::difference_type& n, const vector_iterator<T>& it) {
		return (it + n);
	}
	template<class T1, class T2>
	typename ft::vector_iterator<T1>::difference_type operator-(const vector_iterator<T1>& it1, const vector_iterator<T2>& it2) {
		return (&(*it1) - &(*it2));
	}
}

#endif