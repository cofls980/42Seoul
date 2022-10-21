#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstddef>
//#include "iterator_traits.hpp"
/*
	random_access_iterator
*/
namespace ft {

	/*template <class Iterator> class iterator_traits {
		public:
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::iterator_category	iterator_category;
	};
	template <class T> class iterator_traits<T*>;
	template <class T> class iterator_traits<const T*>;

	template<typename Iterator>
	class iterator {
		public:
		typedef Iterator	iterator_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer pointer;
		typedef typename ft::iterator_traits<Iterator>::reference reference;
		typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
    };*/

	template<class T, class Pointer = T*, class Reference = T&> // difference_type 필요
	class iterator {
		protected:
			typedef T value_type;
			typedef Pointer pointer;
			typedef Reference reference;
			typedef ptrdiff_t difference_type;
			pointer _pointer;

		public:
			explicit iterator() : _pointer(0) {}
			explicit iterator(pointer _p) : _pointer(_p) {}
			/*iterator& operator= (const iterator& x) {
				this->_allocator = x._allocator;
				this->_size = x._size;
				this->_capacity = x._capacity;
				this->_pointer = this->_allocator.allocate(x._capacity);
				for (int i = 0;i < this->_size;i++) {
					this->_pointer[i] = x._pointer[i];
				}
				//this->_iterator = x._iterator;
				return this;
			}*/

			// operators
			bool operator==(iterator other) {
				return *_pointer == *other;
			}
			bool operator!=(iterator other) {
				return !(*_pointer == *other);
			}
			reference operator*() const {return *(_pointer);}
			//reference opterator->() {}
			//*a = t
			iterator& operator++() { //전위
				_pointer++;
				return *this;
			}
			/*iterator operator++(value_type) {//후위
				iterator it(*this);
				return it;
			}*/
			//*a++
			iterator& operator--() {}
			iterator operator--(value_type) {}
			
			//*a--

			reference operator[](unsigned int n) {
				return _pointer[n];
			}
	};
}

#endif