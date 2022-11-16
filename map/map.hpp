#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <limits>
#include "map_iterator.hpp"
#include "../utils/reverse_iterator.hpp"
#include "../utils/pair.hpp"
#include "../utils/make_pair.hpp"
#include "../utils/is_integral.hpp"
#include "../utils/enable_if.hpp"
#include "../utils/equal.hpp"
#include "../utils/less.hpp"
#include "../utils/lexicographical_compare.hpp"

namespace ft {
	template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map {
		private:
			enum Color {
				RED,
				BLACK
			};
			struct node {
				ft::pair<const Key, T> _value;
				node *left;
				node *right;
				node *parent;
				bool is_nil;
				Color color;

				node() : _value(), left(0), right(0), parent(0), is_nil(true), color(BLACK) {}
				node(const ft::pair<const Key, T> &val) : _value(val), left(0), right(0), parent(0), is_nil(true), color(BLACK) {}
				~node() {};
			};
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef typename ft::pair<const key_type, mapped_type> value_type;
			typedef Compare key_compare;
			class value_compare : std::binary_function<value_type,value_type,bool>
			{
				friend class map;
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {}
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef typename allocator_type::difference_type difference_type;
			typedef typename allocator_type::size_type size_type;

			typedef typename ft::map_iterator<node, value_type> iterator;
			typedef typename ft::map_iterator<const node, const value_type> const_iterator;
			typedef typename ft::reverse_iterator<iterator> reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;

		private:
			typedef node * node_pointer;
			typedef typename allocator_type::template rebind<node>::other node_alloc;

			size_type _size;
			key_compare _key_compare;
			node_pointer _root;
			node_pointer _leaf;
			allocator_type _pair_alloc;
			node_alloc _node_alloc;

		public:
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _size(0), _key_compare(comp), _pair_alloc(alloc) {
				_leaf = _node_alloc.allocate(1);
				_node_alloc.construct(_leaf, node());
				_root = _leaf;
			}
			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
				 : _size(0), _key_compare(comp), _pair_alloc(alloc) {
				_leaf = _node_alloc.allocate(1);
				_node_alloc.construct(_leaf, node());
				_root = _leaf;
				insert(first, last);
			}
			map (const map& x) : _size(0), _key_compare(x._key_compare), _pair_alloc(x._pair_alloc), _node_alloc(x._node_alloc) {
				_leaf = _node_alloc.allocate(1);
				_node_alloc.construct(_leaf, node());
				_root = _leaf;
				insert(x.begin(), x.end());
			}

			~map() {
				clear();
				_node_alloc.destroy(_leaf);
				_node_alloc.deallocate(_leaf, 1);
			}

			map& operator= (const map& x) {
				if (this != &x) {
					clear();
					_node_alloc.destroy(_leaf);
					_node_alloc.deallocate(_leaf, 1);
					_size = 0;
					_key_compare = x._key_compare;
					_pair_alloc = x._pair_alloc;
					_node_alloc = x._node_alloc;
					_leaf = _node_alloc.allocate(1);
					_node_alloc.construct(_leaf, node());
					_root = _leaf;
					insert(x.begin(), x.end());
				}
				return (*this);
			}

			iterator begin() {
				node *tmp = _root;
				while (tmp && !tmp->is_nil && !tmp->left->is_nil) {
					tmp = tmp->left;
				}
				return (iterator(tmp));
			}
			const_iterator begin() const {
				node *tmp = _root;
				while (tmp && !tmp->is_nil && !tmp->left->is_nil) {
					tmp = tmp->left;
				}
				return (const_iterator(tmp));
			}
			iterator end() {
				return (iterator(_leaf));
			}
			const_iterator end() const {
				return (const_iterator(_leaf));
			}
			reverse_iterator rbegin() {return (reverse_iterator(end()));}
			const_reverse_iterator rbegin() const {return (const_reverse_iterator(end()));}
			reverse_iterator rend() {return (reverse_iterator(begin()));}
			const_reverse_iterator rend() const {return (const_reverse_iterator(begin()));}

			bool empty() const {return (_size == 0);}
			size_type size() const {return (_size);}
			size_type max_size() const {
				return _node_alloc.max_size();
			}

			mapped_type& operator[] (const key_type& k) {
				ft::pair<iterator, bool> p = insert(ft::make_pair(k, mapped_type()));
				return (p.first->second);
			}

			ft::pair<iterator,bool> insert (const value_type& val) {
				ft::pair<iterator, bool> res = insert_node(val);
				if (res.second)
					_size++;
				return (res);
			}
			iterator insert (iterator position, const value_type& val) {
				(void) position;
				return (insert(val).first);
			}
			template <class InputIterator>
			void insert (InputIterator first, InputIterator last) {
				for (InputIterator it = first;it != last;++it) {
					insert(ft::make_pair(it->first, it->second));
				}
			}

			void erase (iterator position) {
				if (position == end()) {
					return ;
				}
				erase(position->first);
			}
			size_type erase (const key_type& k) {
				if (delete_node(k)) {
					_size--;
					if (_size == 0) {
						_root = _leaf;
					}
					return (1);
				}
				return (0);
			}
			void erase (iterator first, iterator last) {
				for (iterator it = first;it != last;) {
					iterator tmp_it = it;
					it++;
					erase(tmp_it);
				}
			}

			void swap (map& x) {
				if (this == &x) {
					return ;
				}
				std::swap(_size, x._size);
				std::swap(_key_compare, x._key_compare);
				std::swap(_root, x._root);
				std::swap(_leaf, x._leaf);
				std::swap(_pair_alloc, x._pair_alloc);
				std::swap(_node_alloc, x._node_alloc);
			}

			void clear() {
				if (begin() != end()) {
					erase(begin(), end());
				}
				_root = _leaf;
				_size = 0;
			}

			key_compare key_comp() const {
				return (_key_compare);
			}
			value_compare value_comp() const {
				return (value_compare(key_comp()));
			}

			iterator find (const key_type& k) {
				node *tmp = _root;
				while (tmp && tmp != _leaf) {
					bool comp_result = _key_compare(tmp->_value.first, k);
					if (!comp_result && !_key_compare(k, tmp->_value.first)) {
						return (iterator(tmp));
					} else if (comp_result) {
						tmp = tmp->right;
					} else {
						tmp = tmp->left;
					}
				}
				return (end());
			}
			const_iterator find (const key_type& k) const {
				node *tmp = _root;
				while (tmp && tmp != _leaf) {
					bool comp_result = _key_compare(tmp->_value.first, k);
					if (!comp_result && !_key_compare(k, tmp->_value.first)) {
						return (const_iterator(tmp));
					} else if (comp_result) {
						tmp = tmp->right;
					} else {
						tmp = tmp->left;
					}
				}
				return (end());
			}

			size_type count (const key_type& k) const {
				return (find(k) == end() ? 0 : 1);
			}

			iterator lower_bound (const key_type& k) {
				for (iterator it = begin(); it != end();it++) {
					if (!_key_compare(it->first, k)) {
						return (it);
					}
				}
				return (end());
			}
			const_iterator lower_bound (const key_type& k) const {
				for (const_iterator it = begin(); it != end();it++) {
					if (!_key_compare(it->first, k)) {
						return (it);
					}
				}
				return (end());
			}

			iterator upper_bound (const key_type& k) {
				for (iterator it = begin(); it != end();it++) {
					if (_key_compare(k, it->first)) {
						return (it);
					}
				}
				return (end());
			}
			const_iterator upper_bound (const key_type& k) const {
				for (const_iterator it = begin(); it != end();it++) {
					if (_key_compare(k, it->first)) {
						return (it);
					}
				}
				return (end());
			}

			pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
				return (ft::pair<const_iterator,const_iterator>(lower_bound(k), upper_bound(k)));
			}
			pair<iterator,iterator> equal_range (const key_type& k) {
				return (ft::pair<iterator,iterator>(lower_bound(k), upper_bound(k)));
			}

			allocator_type get_allocator() const {return (_node_alloc);}
		
		private:
			node_pointer make_node(const value_type& val) {
				node_pointer new_node = _node_alloc.allocate(1);
				_node_alloc.construct(new_node, node(val));
				new_node->is_nil = false;
				new_node->color = RED;
				new_node->parent = 0;
				new_node->left = _leaf;
				new_node->right = _leaf;
				return (new_node);
			}

			node_pointer tree_minimum(node_pointer x) {
				while (x && x != _leaf && !x->left->is_nil) {
					x = x->left;
				}
				return x;
			}
			node_pointer tree_maximum(node_pointer x) {
				while (x && x != _leaf && !x->right->is_nil) {
					x = x->right;
				}
				return x;
			}
			
			node_pointer find_key(key_type key) {
				node_pointer tmp = _root;
				node_pointer parent = 0;

				while (tmp != 0 && !tmp->is_nil && tmp->_value.first != key) {
					parent = tmp;
					if (_key_compare(key, parent->_value.first)) {
						tmp = parent->left;
					} else {
						tmp = parent->right;
					}
				}
				return tmp;
			}

			ft::pair<iterator,bool> insert_node(const value_type& val) {
				node_pointer tmp = find_key(val.first);
				if (tmp && !tmp->is_nil)
					return (ft::make_pair(iterator(tmp), false));

				node_pointer new_node = make_node(val);
				tmp = _root;

				if (tmp == _leaf) {
					_root = new_node;
				} else {
					while (tmp != _leaf) {
						if (_key_compare(tmp->_value.first, val.first)) {
							if (tmp->right == _leaf) {
								tmp->right = new_node;
								new_node->parent = tmp;
								break;
							}
							tmp = tmp->right;
						} else {
							if (tmp->left == _leaf) {
								tmp->left = new_node;
								new_node->parent = tmp;
								break;
							}
							tmp = tmp->left;
						}
					}
				}
				if (new_node->parent && new_node->parent->parent) {
					insert_fix(new_node);
				}
				if (new_node == tree_maximum(_root)) {
					_leaf->parent = new_node;
				}
				if (new_node->parent == 0) {
					new_node->color = BLACK;
				}
				return (ft::make_pair(iterator(new_node), true));
			}

			void insert_fix(node_pointer node) {
				while (node != _root && node->parent->color == RED) {
					node_pointer grand = node->parent->parent;
					node_pointer uncle = (node->parent == grand->left) ? grand->right : grand->left;
					bool side = (node->parent == grand->left) ? true : false;

					if (uncle && uncle->color == RED) {
						node->parent->color = BLACK;
						uncle->color = BLACK;
						grand->color = RED;
						node = grand;
					} else {
						if (node == (side ? node->parent->right : node->parent->left)) {
							node = node->parent;
							side ? rotate_left(node) : rotate_right(node);
						}
						node->parent->color = BLACK;
						grand->color = RED;
						side ? rotate_right(grand) : rotate_left(grand);
					}
				}
				_root->color = BLACK;
			}
			bool delete_node(key_type key) {
				node_pointer tmp = find_key(key);
				if (!tmp || tmp->is_nil)
					return false;
				else
				{
					node_pointer x, y;
					Color original_color = tmp->color;

					if (tmp->left == _leaf) {
						x = tmp->right;
						transplant(tmp, tmp->right);
					} else if (tmp->right == _leaf) {
						x = tmp->left;
						transplant(tmp, tmp->left);
					} else {
						y = tree_minimum(tmp->right);
						original_color = y->color;
						x = y->right;
						if (y->parent == tmp) {
							x->parent = y;
						} else {
							transplant(y, y->right);
							y->right = tmp->right;
							y->right->parent = y;
						}
						transplant(tmp, y);
						y->left = tmp->left;
						y->left->parent = y;
						y->color = tmp->color;
					}
					_node_alloc.destroy(tmp);
					_node_alloc.deallocate(tmp, 1);
					if (original_color == BLACK) {
						delete_fix(x);
					}
					_leaf->parent = tree_maximum(_root);
					
				}
				return true;
			}

			void delete_fix(node_pointer node) {
				node_pointer sibling; 

				while (node != _root && node->color == BLACK) {
					if (node == node->parent->left) {
						sibling = node->parent->right;
						if (sibling->color == RED) {
							sibling->color = BLACK;
							node->parent->color = RED;
							rotate_left(node->parent);
							sibling = node->parent->right;
						}
						if (sibling->left->color == BLACK && sibling->right->color == BLACK) {
							sibling->color = RED;
							node = node->parent;
						} else {
							if (sibling->right->color == BLACK)
							{
								sibling->left->color = BLACK;
								sibling->color = RED;
								rotate_right(sibling);
								sibling = node->parent->right;
							}
							sibling->color = node->parent->color;
							node->parent->color = BLACK;
							sibling->right->color = BLACK;
							rotate_left(node->parent);
							node = _root;
						}
					} else {
						sibling = node->parent->left;
						if (sibling->color == RED) {
							sibling->color = BLACK;
							node->parent->color = RED;
							rotate_right(node->parent);
							sibling = node->parent->left;
						}
						if (sibling->left->color == BLACK && sibling->right->color == BLACK)
						{
							sibling->color = RED;
							node = node->parent;
						} else {
							if (sibling->left->color == BLACK)
							{
								sibling->right->color = BLACK;
								sibling->color = RED;
								rotate_left(sibling);
								sibling = node->parent->left;
							}
							sibling->color = node->parent->color;
							node->parent->color = BLACK;
							sibling->left->color = BLACK;
							rotate_right(node->parent);
							node = _root;
						}
					}
				}
				node->color = BLACK;
				_root->color = BLACK;
			}

			void transplant(node_pointer u, node_pointer v) {
				if (u->parent == 0) {
					_root = v;
				} else if (u == u->parent->left) {
					u->parent->left = v;
				} else {
					u->parent->right = v;
				}
				v->parent = u->parent;
			}
			void rotate_left(node_pointer x) {
				node_pointer y;

				y = x->right;
				x->right = y->left;
				if (y->left != _leaf) {
					y->left->parent = x;
				}
				y->parent = x->parent;

				if (!x->parent) {
					_root = y;
				} else if (x == x->parent->left) {
					x->parent->left = y;
				} else {
					x->parent->right = y;
				}
				x->parent = y;
				y->left = x;
			}
			void rotate_right(node_pointer y) {
				node_pointer x;

				x = y->left;
				y->left = x->right;
				if (x->right != _leaf) {
					x->right->parent = y;
				}
				x->parent = y->parent;

				if (!y->parent) {
					_root = x;
				} else if (y == y->parent->left) {
					y->parent->left = x;
				} else {
					y->parent->right = x;
				}
				y->parent = x;
				x->right = y;
			}
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator== ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
		if (lhs.size() != rhs.size()) {
			return (false);
		}
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator!= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
		return (!(lhs == rhs));
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator<  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), lhs.value_comp()));
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator<= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
		return (!(rhs < lhs));
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator>  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
		return (rhs < lhs);
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator>= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
		return (!(lhs < rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y) {
		x.swap(y);
	}
}

#endif