#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "iterator.hpp"

//	TOODO
//	- iterator
//	- push_back
//	- at

namespace ft {
	template < class T, class Alloc = std::allocator<T> > class vector : private iterator<T> {

		protected:
		typedef T value_type;

		typedef Alloc allocator_type;
		//typedef typename allocator_type::value_type value_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef typename allocator_type::size_type size_type;
		typedef typename ft::iterator<value_type> iterator;
		/*typedef allocator_type::reference				value_type&;
		typedef allocator_type::const_reference			const value_type&;
		typedef allocator_type::pointer					value_type*;
		typedef allocator_type::const_pointer			const value_type*;
		typedef std::allocator<value_type>				allocator_type;*/

		public:
		// 생성자
		explicit vector (const allocator_type& alloc = allocator_type()) {/*empty*/} // default
		//const ft::vector<T, Alloc>::allocator_type &alloc = typename ft::vector<T, Alloc>::allocator_type()
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()); // fill
		template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()); // range
		vector (const vector& x); // copy

		// 소멸자
		~vector() {}

		// 복사 생성자
		vector& operator= (const vector& x);

		//------iterators------//
	
		// begin
		iterator begin();
		/*const_iterator begin() const;

		// end
		iterator end();
		const_iterator end() const;

		// rbegin
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;

		// rend
		reverse_iterator rend();
		const_reverse_iterator rend() const;*/

		//------capacity------//
		// size
		size_type size() const;

		// max_size
		size_type max_size() const;

		// resize
		void resize (size_type n, value_type val = value_type());

		// capacity
		size_type capacity() const;

		// empty
		bool empty() const;

		// reserve
		void reserve (size_type n);

		//------element access------//
		// operator[]
		reference operator[] (size_type n);
		const_reference operator[] (size_type n) const;

		// at
		/*reference at (size_type n) {
			return (0);
		}*/
		const_reference at (size_type n) const;

		// front
		reference front();
		const_reference front() const;

		// back
		reference back();
		const_reference back() const;

		//------modifiers------//
		// assign
		template <class InputIterator>  void assign (InputIterator first, InputIterator last); // range
		void assign (size_type n, const value_type& val); // fill

		// push_back
		void push_back (const value_type& val) {}

		// pop_back
		void pop_back();

		// insert
		/*iterator insert (iterator position, const value_type& val); // single element
		void insert (iterator position, size_type n, const value_type& val); // fill
		template <class InputIterator>    void insert (iterator position, InputIterator first, InputIterator last); // range

		// erase
		iterator erase (iterator position);iterator erase (iterator first, iterator last);*/

		// swap
		/*void swap (vector& x);

		// clear
		void clear();

		//------allocator------//
		// get_allocator
		allocator_type get_allocator() const;

		//------non-member function overloads------//
		// relational operators
		template <class T, class Alloc>  bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
			return (lhs == rhs);
		}
		template <class T, class Alloc>  bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
			return (lhs != rhs);
		}
		template <class T, class Alloc>  bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
			return (lhs < rhs);
		}
		template <class T, class Alloc>  bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
			return (lhs <= rhs);
		}
		template <class T, class Alloc>  bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
			return (lhs > rhs);
		}
		template <class T, class Alloc>  bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
			return (lhs >= rhs);
		}

		// swap
		//template <class T, class Alloc>  void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);*/

	};
}



#endif