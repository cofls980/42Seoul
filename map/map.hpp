#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <limits>
#include "map_iterator.hpp"
#include "../utils/reverse_iterator.hpp"
#include "../utils/utils.hpp"
//ft::greater도 만들어야할까
namespace ft {//std?
	template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map {
		private:
			struct node {
				ft::pair<const Key, T> _value;
				node *left;
				node *right;
				node *parent;

				node() : _value(), left(0), right(0), parent(0) {}
				node(const ft::pair<const Key, T> &val) : _value(val), left(0), right(0), parent(0) {}
			};
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef typename ft::pair<const key_type, mapped_type> value_type;
			typedef Compare key_compare;
			class value_compare : binary_function<value_type,value_type,bool>
			{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
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
			size_type _size;
			key_compare _key_compare;
			node *_root;
			node *_last; //pointer to the last elem of the tree
			allocator_type _pair_alloc;
			std::allocator<node> _node_alloc;

		public:
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _size(0), _key_compare(comp), _pair_alloc(alloc) {
				_root = make_node(value_type());
				_last = _root;
			}
			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
				 : _size(0), _key_compare(comp), _pair_alloc(alloc) {
				_root = make_node(value_type());
				_last = _root;
				insert(first, last);
			}
			map (const map& x) : _size(0), _key_compare(x._key_compare), _pair_alloc(x._pair_alloc), _node_alloc(x._node_alloc) {
				_root = make_node(value_type());
				_last = _root;
				insert(x.begin(), x.end());
			}

			~map() {
				//destroy
				//deallocate
			}//

			map& operator= (const map& x) {
				if (this != &x) {
					clear();
					_size = 0;
					_key_compare = x._key_compare;
					_pair_alloc = x._pair_alloc;
					_node_alloc = x._node_alloc;
					_root = make_node(value_type());
					_last = _root;
					insert(x.begin(), x.end());
				}
				return (*this);
			}

			//-----iterators-----//
			iterator begin() {
				node *tmp = _root;
				while (tmp && tmp->left) {
					tmp = tmp->left;
				}
				return (iterator(tmp));
			}
			const_iterator begin() const {
				node *tmp = _root;
				while (tmp && tmp->left) {
					tmp = tmp->left;
				}
				return (const_iterator(tmp));
			}
			iterator end() {
				return (iterator(_last));
			}
			const_iterator end() const {
				return (const_iterator(_last));
			}
			reverse_iterator rbegin() {return (reverse_iterator(end()));}
			const_reverse_iterator rbegin() const {return (const_reverse_iterator(end()));}
			reverse_iterator rend() {return (reverse_iterator(begin()));}
			const_reverse_iterator rend() const {return (const_reverse_iterator(begin()));}

			//-----capacity-----//
			bool empty() const {return (_size == 0);}
			size_type size() const {return (_size);}
			size_type max_size() const {return std::numeric_limits<difference_type>::max() / sizeof(value_type);}//

			//-----element access-----//
			mapped_type& operator[] (const key_type& k) { // insert 만 사용해도 원소가 있는지 없는지 확인 가능
				// k의 값이 존재하면 값 반환
				// k값이 없으면 키가 k인 새로운 노드를 추가하고 mapped value를 reference로 반환
				ft::pair<iterator, bool> p = insert(make_pair(k, mapped_type()));
				return (p.first->second);
			}

			//-----modifiers-----//
			pair<iterator,bool> insert (const value_type& val) {
				iterator it = find(val.first);
				if (it != end()) {
					return (ft::make_pair(it, false));
				}
				_size++;
				return (ft::make_pair(iterator(insert_node(val)), true));
			}
			iterator insert (iterator position, const value_type& val) {
				(void) position;
				return (insert(val).first);
			}
			template <class InputIterator>
			void insert (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) {//enable?
				// int i = 0;
				for (InputIterator it = first;it != last;++it) {
					// std::cout << i++ << std::endl;
					insert(*it);
				}
			}

			void erase (iterator position) {
				if (position == end()) {
					return ;
				}
				_size--;
				erase_node(position);
			}
			size_type erase (const key_type& k) {
				iterator it = find(k);
				if (it == end()) {
					return (0);
				}
				erase(it);
				return(1);
			}
			void erase (iterator first, iterator last) {
				for (iterator it = first;it != last;it++) {
					erase(it);
				}
			}

			void swap (map& x) {
				if (this == &x) {
					return ;
				}
				std::swap(_size, x._size);
				std::swap(_key_compare, x._key_compare);
				std::swap(_root, x._root);
				std::swap(_last, x._last);
				std::swap(_pair_alloc, x._pair_alloc);
				std::swap(_node_alloc, x._node_alloc);
				//std::swap?
				/*size_type _size;
				key_compare _key_compare;
				node *_root;
				node *_last;
				allocator_type _pair_alloc;
				node_allocator_type _node_alloc;
				_size = x._size;
				_key_compare = x._key_compare;
				_root = x._root;
				_last = x._last;
				_pair_alloc = x._pair_alloc;
				_node_alloc = x._node_alloc;*/
			}

			void clear() {
				while (_size) {
					erase(begin());
				}
			}

			//-----observers-----//
			key_compare key_comp() const {
				return (_key_compare);
			}
			value_compare value_comp() const {
				return (value_compare(_key_compare));
			}

			//-----operations-----//
			iterator find (const key_type& k) {
				node *tmp = _root;
				while (tmp && tmp != _last) {
					if (!_key_compare(tmp->_value.first, k) && !_key_compare(k, tmp->_value.first)) {
						return (iterator(tmp));
					} else if (key_comp()(tmp->_value.first, k)) {
						tmp = tmp->right;
					} else {
						tmp = tmp->left;
					}
				}
				return (end());
			}
			const_iterator find (const key_type& k) const {
				node *tmp = _root;
				while (tmp && tmp != _last) {
					if (!_key_compare(tmp->_value.first, k) && !_key_compare(k, tmp->_value.first)) {
						return (const_iterator(tmp));
					} else if (key_comp()(tmp->_value.first, k)) {
						tmp = tmp->right;
					} else {
						tmp = tmp->left;
					}
				}
				return (end());
			}

			size_type count (const key_type& k) const {
				node *tmp = _root;
				while (tmp && tmp != _last) {
					if (!_key_compare(tmp->_value.first, k) && !_key_compare(k, tmp->_value.first)) {
						return (1);
					} else if (_key_compare(tmp->_value.first, k)) {
						tmp = tmp->right;
					} else {
						tmp = tmp->left;
					}
				}
				return (0);
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
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}
			pair<iterator,iterator> equal_range (const key_type& k) {
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}

			//-----allocator-----//
			allocator_type get_allocator() const {return (_pair_alloc);}
		
		private:
			node *make_node(const value_type& value) {
				node *n = _node_alloc.allocate(1);
				_node_alloc.construct(n, node(value));
				return (n);
			}

			node *insert_node(const value_type& value) {
				// std::cout << "*********insert (" << value.first << ", " << value.second << ")*********" << std::endl;
				node *tmp = _root;
				node *newOne = make_node(value);
				while (tmp) {
					if (tmp == _last) {
						newOne->right = _last;
						newOne->parent = _last->parent;
						_last->parent = newOne;
						if (newOne->parent)
							newOne->parent->right = newOne;
						else
							_root = newOne;
						break;
					} else if (_key_compare(tmp->_value.first, value.first)) {
						if (!tmp->right) {
							tmp->right = newOne;
							newOne->parent = tmp;
							break ;
						}
						tmp = tmp->right;
					} else {
						if (!tmp->left) {
							tmp->left = newOne;
							newOne->parent = tmp;
							break;
						}
						tmp = tmp->left;
					}
				}
				balance(newOne);
				//display(_root);
				return (newOne);
			}

			node *max_node(node *n) {
				node *tmp = n;
				while (tmp->right) {
					tmp = tmp->right;
				}
				if (tmp->parent->left == tmp) {//tmp 왼쪽에 있는 것들 이어줌
					tmp->parent->left = tmp->left;
				} else {
					tmp->parent->right = tmp->left;
				}
				if (tmp->left)
					tmp->left->parent = tmp->parent;
				return (tmp);
			}

			void erase_one(node *n) {
				node *tmp = n;
				node *child;
				node *tmp_parent = 0;
				
				if (!tmp->left || !tmp->right) {
					tmp_parent = tmp->parent;
					child = tmp->left ? tmp->left : tmp->right;
					if (child)
						child->parent = tmp->parent;
				} else {
					//std::cout << "??" << std::endl;
					node *left_max = max_node(tmp->left);
					//std::cout << "^^" << std::endl;
					//std::cout << "left_max: " << left_max->_value.first << ", " << left_max->_value.second << std::endl;
					left_max->parent = tmp->parent;
					left_max->left = tmp->left;
					left_max->right = tmp->right;
					if (left_max->left)
						left_max->left->parent = left_max;
					if (left_max->right)
						left_max->right->parent = left_max;
					child = left_max;
					tmp_parent = child;
				}
				if (tmp->parent) {
					//std::cout << "have parent" << std::endl;
					if (tmp->parent->left == tmp) {
						tmp->parent->left = child;
					} else {
						tmp->parent->right = child;
					}
				}
				else {
					//std::cout << "no parent" << std::endl;
					_root = child;
				}
				_node_alloc.destroy(tmp);
				_node_alloc.deallocate(tmp, 1);		
				// balancing
				if (tmp_parent)
					balance(tmp_parent);
				//display(_root);
			}
			
			void erase_node(const iterator pos) {
				node *node = _root;
				while (node && node != _last) {
					if (!_key_compare(node->_value.first, pos->first) && !_key_compare(pos->first, node->_value.first)) break;
					else if (_key_compare(node->_value.first, pos->first)) node = node->right;
					else node = node->left;
				}
				// std::cout << "*********erase (" << node->_value.first << ", " << node->_value.second << ")*********" << std::endl;
				// if (node->parent)
				// 	std::cout << "parent: " << node->parent->_value.first << ", " << node->parent->_value.second << std::endl;
				erase_one(node);
			}

			node *l_rotate(node *n) {
				node *parent = n->parent;
				node *now = n;
				node *child = n->right;

				now->right = child->left;
				if (child->left) {
					child->left->parent = now;
				}
				child->left = now;
				now->parent = child;

				if (parent) {
					if (_key_compare(n->_value.first, parent->_value.first)) {
						parent->left = child;
					} else {
						parent->right = child;
					}
				}
				child->parent = parent;
				return (child);
			}
			node *r_rotate(node *n) {
				node *parent = n->parent;
				node *now = n;
				node *child = n->left;

				now->left = child->right;
				if (child->right) {
					child->right->parent = now;
				}
				child->right = now;
				now->parent = child;

				if (parent) {
					if (_key_compare(n->_value.first, parent->_value.first)) {
						parent->left = child;
					} else {
						parent->right = child;
					}
				}
				child->parent = parent;
				return (child);
			}
			
			int tree_height(node *node) {
				int height;
				int left = 0;
				int right = 0;

				if (!node || node == _last) {
					return (0);
				}
				left = tree_height(node->left);
				right = tree_height(node->right);
				height = left < right ? right + 1 : left + 1;
				return (height);
			}

			int balance_factor(node *node) {
				int left = tree_height(node->left);
				int right = tree_height(node->right);
				return (left - right);
			}

			void balance(node *n) {
				node *now = n;

				while (now && now != _last) {
					int bf = balance_factor(now);
					int diff;
					// std::cout << "bf: " << bf << " (" << now->_value.first << ", " << now->_value.second << ")" << std::endl;
					if (bf > 1) { // 왼쪽이 너무 큰 경우
						diff = balance_factor(now->left);
						// std::cout << "diff: " << diff << ", l";
						if (diff < 0) { // lr
							// std::cout << "r" << std::endl;
							now->left = l_rotate(now->left);
						} else {
							// std::cout << "l" << std::endl;
						}
						now = r_rotate(now);
					} else if (bf < -1) { // 오른쪽이 너무 큰 경우
						diff = balance_factor(now->right);
						//std::cout << "diff: " << diff << ", r";
						if (diff > 0) { // rl
							// std::cout << "l" << std::endl;
							now->right = r_rotate(now->right);
						} else {
							// std::cout << "r" << std::endl;
						}
						now = l_rotate(now);
					}
					if (now->parent == 0) {
						_root = now;
					}
					now = now->parent;
				}
			}

			void display(node *n) {
				return;
				if (n) {
					if (n == _last) {
						if (_last->parent)
							std::cout << "last --- " << _last->parent->_value.first << ", " << n->parent->_value.second << std::endl;
						return;
					}
					if (n == _root) {
						std::cout << "==display ";
						std::cout << "root: " << n->_value.first << ", " << n->_value.second << "==" << std::endl;
					}
					display(n->left);
					std::cout << n->_value.first << ", " << n->_value.second << " --- ";
					if(n->parent)
						std::cout << n->parent->_value.first << ", " << n->parent->_value.second << std::endl;
					else
						std::cout << "no parent" << std::endl;
					display(n->right);
				}
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