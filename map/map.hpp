#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "map_iterator.hpp"
#include "../utils/reverse_iterator.hpp"
#include "../utils/utils.hpp"

namespace ft {
	template<class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T>>>
	class map {
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef std::pair<const key_type, mapped_type>> value_type;
			typedef Compare key_compare;
			//typedef value_compare
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef typename ft::map_iterator<value_type> iterator;
			typedef typename ft::map_iterator<const value_type> const_iterator;
			typedef typename ft::reverse_iterator<iterator> reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
			typedef typename ft::iterator_traits<pointer>::difference_type difference_type;
			typedef typename allocator_type::size_type size_type;

			key_compare _comp;

			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {}
			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {}
			map (const map& x) {}

			~map();

			map& operator= (const map& x) {
				if (*this != x) {}
				return (*this);
			}

			iterator begin();const_iterator begin() const;
	};
}

#endif