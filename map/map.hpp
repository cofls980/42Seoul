#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "map_iterator.hpp"
#include "avl_tree.hpp"
//#include "../utils/reverse_iterator.hpp"
#include "../utils/utils.hpp"

namespace ft {
	template<class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map {
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef typename ft::pair<const key_type, mapped_type> value_type;
			typedef Compare key_compare;
			//typedef value_compare
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef typename ft::avl_tree<key_type, value_type, key_compare>::iterator iterator;
			typedef typename ft::avl_tree<key_type, const value_type, key_compare>::const_iterator const_iterator;
			// typedef typename ft::reverse_iterator<iterator> reverse_iterator;
			// typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
			// typedef typename ft::iterator_traits<pointer>::difference_type difference_type;
			typedef typename allocator_type::size_type size_type;
			typedef typename ft::avl_tree<key_type, value_type, key_compare> tree;

			tree _tree;
			size_type _size;
			key_compare _comp;
			allocator_type _alloc;


			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(comp), _size(0), _comp(comp), _alloc(alloc) {}
			// template <class InputIterator>
			// map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {

			// }
			map (const map& x) {
				_tree = x._tree;
				_size = x._size;
				_comp = x._comp;
				_alloc = x._alloc;
			}

			~map() {}

			map& operator= (const map& x) {
				if (*this != x) {
					_tree = x._tree;
					_size = x._size;
					_comp = x._comp;
					_alloc = x._alloc;
				}
				return (*this);
			}

			//-----iterators-----//
			// iterator begin() {return ();}
			// const_iterator begin() const {return ();}
			// iterator end();
			// const_iterator end() const;
			// reverse_iterator rbegin();
			// const_reverse_iterator rbegin() const;
			// reverse_iterator rend();
			// const_reverse_iterator rend() const;

			//-----capacity-----//
			bool empty() const {return (_size == 0);}
			size_type size() const {return (_size);}
			size_type max_size() const {return (allocator_type().max_size());}

			//-----element access-----//
			// mapped_type& operator[] (const key_type& k) {
			// 	// k의 값이 존재하면 값 반환
			// 	// k값이 없으면 키가 k인 새로운 노드를 추가하고 mapped value를 reference로 반환
			// 	// _size 늘림.
			// }

			//-----modifiers-----//ft::pair<iterator,bool>
			void insert (const value_type& val) { //LL, RR, LR, RL
				//val이 존재하면 insert하지 말고
				_tree.insert_node(val);
				/*ft::pair<iterator,bool> result = _tree.insert_node(val);
				if (result.second == true) {
					_size++;
				}
				return (result);*/
			}
			// iterator insert (iterator position, const value_type& val) {
			// }
			// template <class InputIterator>
			// void insert (InputIterator first, InputIterator last);

			void erase (const key_type& k) {
				_tree.erase_key(k);
			}

			// void erase (iterator position) {
			// 	_tree.erase_node(position);
			// }
			// size_type erase (const key_type& k) {
			// 	iterator it = find(k);
			// 	_tree.erase_node(it);
			// }
			// void erase (iterator first, iterator last);

			// void swap (map& x);

			// void clear();

			//-----observers-----//
			// key_compare key_comp() const;
			// value_compare value_comp() const;

			//-----operations-----//
			// iterator find (const key_type& k) {}
			// const_iterator find (const key_type& k) const;

			// size_type count (const key_type& k) const;

			// iterator lower_bound (const key_type& k);
			// const_iterator lower_bound (const key_type& k) const;

			// iterator upper_bound (const key_type& k);
			// const_iterator upper_bound (const key_type& k) const;

			// pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
			// pair<iterator,iterator> equal_range (const key_type& k);

			//-----allocator-----//
			allocator_type get_allocator() const {return (_alloc);}
	};
	/* ? 필요한가
	template <class Key, class T, class Compare, class Alloc>
	bool operator== ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs );
	template <class Key, class T, class Compare, class Alloc>
	bool operator!= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs );
	template <class Key, class T, class Compare, class Alloc>
	bool operator<  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs );
	template <class Key, class T, class Compare, class Alloc>
	bool operator<= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs );
	template <class Key, class T, class Compare, class Alloc>
	bool operator>  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs );
	template <class Key, class T, class Compare, class Alloc>
	bool operator>= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs );

	template <class Key, class T, class Compare, class Alloc>
	void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y);*/
}

#endif