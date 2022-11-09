#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include <cstddef>
#include "../utils/iterator_traits.hpp"
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
		
		private:
			pointer _ptr;

		public:
			vector_iterator(pointer p = 0) : _ptr(p) {}
			vector_iterator(const vector_iterator& x) : _ptr(x._ptr) {}
			~vector_iterator() {}
			vector_iterator& operator= (const vector_iterator& x) {
				if (this != &x) {
					_ptr = x._ptr;
				}
				return (*this);
			}

			reference operator*() const {return (*_ptr);}
			pointer operator->() const {return (_ptr);}

			vector_iterator& operator++() {
				++_ptr;
				return (*this);
			}
			vector_iterator operator++(int) {
				vector_iterator it = *this;
				++_ptr;
				return (it);
			}
			vector_iterator& operator--() {
				--_ptr;
				return (*this);
			}
			vector_iterator operator--(int) {
				vector_iterator it = *this;
				--_ptr;
				return (it);
			}

			reference operator[](difference_type n) {return (*(_ptr + n));}

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

			friend vector_iterator operator+(const difference_type& n, const vector_iterator& it) {return (it + n);}
			friend difference_type operator-(const vector_iterator& it1, const vector_iterator& it2) {return (it1._ptr - it2._ptr);}

			friend bool operator==(const vector_iterator& left, const vector_iterator& right) {return (left._ptr == right._ptr);}
			friend bool operator!=(const vector_iterator& left, const vector_iterator& right) {return (left._ptr != right._ptr);}
			friend bool operator<(const vector_iterator& left, const vector_iterator& right) {return (left._ptr < right._ptr);}
			friend bool operator<=(const vector_iterator& left, const vector_iterator& right) {return (left._ptr <= right._ptr);}
			friend bool operator>(const vector_iterator& left, const vector_iterator& right) {return (left._ptr > right._ptr);}
			friend bool operator>=(const vector_iterator& left, const vector_iterator& right) {return (left._ptr >= right._ptr);}
	};
}

#endif