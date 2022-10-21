#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <limits>
#include "iterator.hpp"
#include "iterator_traits.hpp"

//	TOODO
//	- iterator
//	- vector without iterator

// allocator 사용 이유: 특정 컨테이너에 최적화된 유연한 메모리 사용과 관리를 위해 사용
namespace ft {
	template < class T, class Alloc = std::allocator<T> > class vector {

		protected:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef T* pointer;
		typedef T& reference;
		typedef const T* const_pointer;
		typedef const T& const_reference;
		typedef typename ft::iterator<value_type> iterator;
		//typedef typename iterator_traits<iterator>::difference_type difference_type;
		typedef unsigned int size_type;
		// const_iterator
		// reverse_iterator
		// const_reverse_iterator
		/*typedef typename allocator_type::value_type value_type;
		//typedef typename allocator_type::reference reference;
		//typedef typename allocator_type::const_reference const_reference;
		//typedef typename allocator_type::pointer pointer;
		//typedef typename allocator_type::const_pointer const_pointer;
		//typedef typename allocator_type::size_type size_type;*/
		
		

		pointer _pointer;
		allocator_type _allocator;
		size_type _size;
		size_type _capacity;
		//iterator _iterator;
		//value_type _val;

		public:
		// 생성자
		explicit vector (const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _pointer(0), _allocator(alloc) {} // default
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) { // fill....?
			_allocator = alloc;
			_size = n;
			_capacity = n;
			_pointer = _allocator.allocate(n);
			for (int i = 0;i < n;i++) {
				_pointer[i] = val;
			}
		}
		template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()); // range
		vector (const vector& x) { // copy
			this->_allocator = x._allocator;
			this->_size = x._size;
			this->_capacity = x._capacity;
			this->_pointer = this->_allocator.allocate(x._capacity);
			for (int i = 0;i < this->_size;i++) {
				this->_pointer[i] = x._pointer[i];
			}
			//this->_iterator = x._iterator;
		}

		// 소멸자
		~vector() {
			_allocator.destroy(_pointer);
			_allocator.deallocate(_pointer, _capacity);
		}

		// 복사 대입 생성자
		vector& operator= (const vector& x) {
			this->_allocator = x._allocator;
			this->_size = x._size;
			this->_capacity = x._capacity;
			this->_pointer = this->_allocator.allocate(x._capacity);
			for (int i = 0;i < this->_size;i++) {
				this->_pointer[i] = x._pointer[i];
			}
			//this->_iterator = x._iterator;
			return this;
		}
		
		/*
		//------iterators------//
	
		// begin
		iterator begin();
		const_iterator begin() const;

		// end
		iterator end();
		const_iterator end() const;

		// rbegin
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;

		// rend
		reverse_iterator rend();
		const_reverse_iterator rend() const;
		*/

		
		//------capacity------//
		size_type size() const { return _size; }

		// max_size
		size_type max_size() const { // 컨테이너가 담을 수 있는 최대 원소의 개수
			return std::numeric_limits<unsigned int>::max();
		}

		// resize
		void resize (size_type n, value_type val = value_type()) {
			// 최대 크기 고려
			if (n < _size) {
				//destroy
				_size = n;
			} else if (n > _size) {
				size_type c_tmp = _capacity;
				while (n > _capacity) {
					_capacity *= 2;
				}
				pointer tmp = _allocator.allocate(_capacity);
				for (int i = 0;i < _size;i++) {
					tmp[i] = _pointer[i];
				}
				for (int i = _size;i < n;i++) {
					tmp[i] = val;
				}
				_allocator.destroy(_pointer);
				_allocator.deallocate(_pointer, c_tmp);
				_pointer = tmp;
				_size = n;
			}
		}

		size_type capacity() const { return _capacity; }

		bool empty() const { return (_size == 0); }

		// reserve
		void reserve (size_type n) {
			//최대 크기 고려 a length_error exception is thrown.
			if (n <= _capacity)
				return;
			_capacity = n;
			pointer tmp = _allocator.allocate(_capacity);
			for (int i = 0;i < _size;i++) {
				tmp[i] = _pointer[i];
			}
			_allocator.destroy(_pointer);
			_allocator.deallocate(_pointer, _capacity / 2);
			_pointer = tmp;
		}
		
		//------element access------//
		reference operator[] (size_type n) { return _pointer[n]; }
		const_reference operator[] (size_type n) const { return _pointer[n]; } // 테스트 방법 찾기
		
		// at
		reference at (size_type n) {
			// 범위 내에 있는지 확인
			return _pointer[n];//*this[n] 사용
		}
		//const_reference at (size_type n) const;

		reference front() { return _pointer[0]; }
		const_reference front() const { return _pointer[0]; }

		reference back() { return _pointer[_size - 1]; }
		const_reference back() const { return _pointer[_size - 1]; }
		
		
		//------modifiers------//
		// assign
		//template <class InputIterator>  void assign (InputIterator first, InputIterator last); // range
		void assign (size_type n, const value_type& val) { // fill
			_size = n;
			_allocator.destroy(_pointer);
			if (_capacity < n) {
				//새로 할당
				_allocator.deallocate(_pointer, _capacity);
				_pointer = _allocator.allocate(_capacity);
				_capacity = n;
			}
			for (int i = 0;i < _size;i++) {
				_pointer[i] = val;
			}
		}

		// push_back
		void push_back (const value_type& val) {
			// 최대 고려?안하나..?
			// allocator exception
			if (_pointer == 0) {
				_pointer = _allocator.allocate(1);
				_capacity = 1;
			} else if (_size == _capacity) {
				pointer tmp = _allocator.allocate(_capacity * 2);
				for (int i = 0;i < _size;i++) {
					tmp[i] = _pointer[i];
				}
				_allocator.destroy(_pointer);
				_allocator.deallocate(_pointer, _capacity);
				_pointer = tmp;
				_capacity *= 2;
			}
			_pointer[_size] = val;
			_size++;
		}

		// pop_back
		void pop_back() {
			_allocator.destroy(_pointer + (_size - 1)); // 필요한가
			_size--;
		}
		
		// insert
		//iterator insert (iterator position, const value_type& val); // single element
		//void insert (iterator position, size_type n, const value_type& val); // fill
		//template <class InputIterator>    void insert (iterator position, InputIterator first, InputIterator last); // range

		// erase
		//iterator erase (iterator position);iterator erase (iterator first, iterator last);

		// swap
		void swap (vector& x) {
			// 자기 자신이 매개변수로 들어오면 그냥 return
			// _pointer, _iterator, _size, _capacity ... 아예 다 바뀜
		}

		// clear
		void clear() {
			_size = 0;
			_allocator.destroy(_pointer);
		}

		
		//------allocator------//
		allocator_type get_allocator() const {
			return _allocator;
		}

		//------non-member function overloads------//
		friend bool operator== (const vector& lhs, const vector& rhs) {
			if (lhs.size() != rhs.size())
				return false;
			for (int i = 0;i < lhs.size();i++) {
				if (lhs[i] != rhs[i])
					return false;
			}
			return true;
		}
		friend bool operator!= (const vector& lhs, const vector& rhs) {
			return !(lhs == rhs);
		}

		friend bool operator<  (const vector& lhs, const vector& rhs) {
			int i;
			for (i = 0;i < lhs.size();i++) {
				if (i == rhs.size() || rhs[i] < lhs[i])
					return false;
				else if (lhs[i] < rhs[i])
					return true;
			}
			return (i != rhs.size());
		}
		friend bool operator<= (const vector& lhs, const vector& rhs) {
			return !(rhs < lhs);
		}
		friend bool operator>  (const vector& lhs, const vector& rhs) {
			return (rhs < lhs);
		}
		friend bool operator>= (const vector& lhs, const vector& rhs) {
			return !(lhs < rhs);
		}

		// swap
		friend void swap (vector& x, vector& y);

	};
}



#endif