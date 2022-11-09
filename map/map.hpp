#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "map_iterator.hpp"
#include "../utils/reverse_iterator.hpp"
#include "../utils/utils.hpp"

namespace ft {
	template<class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map {
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef typename ft::pair<const key_type, mapped_type> value_type;
			typedef Compare key_compare;
			//template <class Key1, class T1, class Compare1, class Alloc1>
			class value_compare : binary_function<value_type,value_type,bool>
			{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
				friend class map;
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
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

			typedef typename ft::node<value_type> node_type;
			typedef typename std::allocator<node_type> node_allocator_type;

			typedef typename ft::map_iterator<node_type, value_type> iterator;
			typedef typename ft::map_iterator<const node_type, const value_type> const_iterator;
			typedef typename ft::reverse_iterator<iterator> reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;

			typedef node_type * node_pointer;

		private:
			size_type _size;
			key_compare _key_compare;
			node_pointer _root;
			node_pointer _last;
			allocator_type _pair_alloc;
			node_allocator_type _node_alloc;

		public:
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _size(0), _key_compare(comp), _root(0), _last(0), _pair_alloc(alloc) {
				/*_last = _node_alloc.allocate(1);
				_pair_alloc.construct(&(_root->_value), 0);
				_root = _last;*/
			}
			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) : _size(0), _key_compare(comp), _root(0), _last(0), _pair_alloc(alloc) {
				size_type dist = last - first;
				_size = dist;
			}//하나씩 다 복사가 필요한가
			map (const map& x) : _size(x._size), _key_compare(x._key_compare), _root(x._root), _pair_alloc(x._pair_alloc) {}//하나씩 다 복사가 필요한가

			~map() {}//

			map& operator= (const map& x) {
				if (this != &x) {
					_size = x._size;
					_key_compare = x._key_compare;
					//bfs로 넣기
					_root = x._root;//하나씩 다 복사가 필요한가
					_pair_alloc = x._pair_alloc;
				}
				return (*this);
			}

			//-----iterators-----//
			iterator begin() {
				node_pointer tmp = _root;
				while (tmp && tmp->left) {
					tmp = tmp->left;
				}
				return (iterator(tmp));
			}
			const_iterator begin() const {
				node_pointer tmp = _root;
				while (tmp && tmp->left) {
					tmp = tmp->left;
				}
				return (const_iterator(tmp));
			}
			iterator end() {// 수정
				node_pointer tmp = _root;
				while (tmp && tmp->left) {
					tmp = tmp->left;
				}
				return (iterator(tmp));
			}
			const_iterator end() const {// 수정
				node_pointer tmp = _root;
				while (tmp && tmp->left) {
					tmp = tmp->left;
				}
				return (iterator(tmp));
			}
			reverse_iterator rbegin() {return (reverse_iterator(end() - 1));}
			const_reverse_iterator rbegin() const {return (const_reverse_iterator(end() - 1));}
			reverse_iterator rend() {return (reverse_iterator(begin()));}
			const_reverse_iterator rend() const {return (const_reverse_iterator(begin()));}

			//-----capacity-----//
			bool empty() const {return (_size == 0);}
			size_type size() const {return (_size);}
			size_type max_size() const {return (allocator_type().max_size());}

			//-----element access-----//
			mapped_type& operator[] (const key_type& k) { // insert 만 사용해도 원소가 있는지 없는지 확인 가능
				// k의 값이 존재하면 값 반환
				// k값이 없으면 키가 k인 새로운 노드를 추가하고 mapped value를 reference로 반환
				// _size 늘림.
				iterator it = find(k);
				if (it != end()) {
					return (it->second);
				}
				return ((*((this->insert(make_pair(k,mapped_type()))).first)).second);
				/*tmp = _root;
				while (tmp) {
					if (tmp->_value.first == k) {
						return (tmp->_value.second);
					} else if (tmp->_value.first > k) {
						tmp = tmp->left;
					} else {
						tmp = tmp->right;
					}
				}
				return (mapped_type());*/
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
				for (InputIterator it = first;it != last;it++) {
					insert(it->first);
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
				size_type _size;
				key_compare _key_compare;
				node_pointer _root;
				node_pointer _last;
				allocator_type _pair_alloc;
				node_allocator_type _node_alloc;
				_size = x._size;
				_key_compare = x._key_compare;
				_root = x._root;
				_last = x._last;
				_pair_alloc = x._pair_alloc;
				_node_alloc = x._node_alloc;
			}

			void clear() {
				while (_size--) {
					erase(end() - 1);
				}
			}

			//-----observers-----//
			key_compare key_comp() const {
				return (_key_compare);
			}
			value_compare value_comp() const {
				return (value_compare());
			}

			//-----operations-----//
			iterator find (const key_type& k) { // key_compare
				node_pointer tmp = _root;
				while (tmp) {
					if (tmp->_value.first == k) {
						return (iterator(tmp));
					} else if (key_comp()(tmp->_value.first, k)) {
						tmp = tmp->right;
					} else {
						tmp = tmp->left;
					}
				}
				return (end());
			}
			const_iterator find (const key_type& k) const { // key_compare
				node_pointer tmp = _root;
				while (tmp) {
					if (tmp->_value.first == k) {
						return (iterator(tmp));
					} else if (key_comp()(tmp->_value.first, k)) {
						tmp = tmp->right;
					} else {
						tmp = tmp->left;
					}
				}
				return (end());
			}

			size_type count (const key_type& k) const { // key_compare
				node_pointer tmp = _root;
				while (tmp) {
					if (tmp->_value.first == k) {
						return (1);
					} else if (key_comp()(tmp->_value.first, k)) {
						tmp = tmp->right;
					} else {
						tmp = tmp->left;
					}
				}
				return (0);
			}

			iterator lower_bound (const key_type& k) {
				iterator it = find(k);
				if (it == end()) {
					it = begin();
					while (key_comp()(it->first, k)) {
						it++;
					}
				}
				return (it);
			}
			const_iterator lower_bound (const key_type& k) const {
				const_iterator it = find(k);
				if (it == end()) {
					it = begin();
					while (key_comp()(it->first, k)) {
						it++;
					}
				}
				return (it);
			}

			iterator upper_bound (const key_type& k) {
				iterator it = find(k);
				if (it == end()) {
					it = begin();
					while (key_comp()(it->first, k)) {
						it++;
					}
				} else {
					it++;
				}
				return (it);
			}
			const_iterator upper_bound (const key_type& k) const {
				const_iterator it = find(k);
				if (it == end()) {
					it = begin();
					while (key_comp()(it->first, k)) {
						it++;
					}
				} else {
					it++;
				}
				return (it);
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
			node_pointer insert_node(const value_type& value) {
				std::cout << "*********insert (" << value.first << ", " << value.second << ")*********" << std::endl;
				node_pointer tmp = _root;
				node_pointer newOne = _node_alloc.allocate(1);
				_pair_alloc.construct(&newOne->_value, value);
				if (_root == 0) {
					_root = newOne;
					display(_root);
					return (_root);
				}
				while (tmp) {//insert -> comp에 따라 달라지나?
					if (tmp->_value.first > value.first) {
						if (tmp->left == 0) {
							tmp->left = newOne;
							break;
						}
						tmp = tmp->left;
					} else {
						if (tmp->right == 0) {
							tmp->right = newOne;
							break;
						}
						tmp = tmp->right;
					}
				}
				newOne->parent = tmp;
				balance(newOne);
				display(_root);
				return (newOne);
			}

			void erase_one(node_pointer node) {
				node_pointer now = node;
				node_pointer child;
				
				if (now->left == 0 || now->right == 0) {
					if (now->left == 0 && now->right == 0) {// 1) leaf node
						std::cout << "1) ";
						child = now->left;
					} else {// 2) one child
						std::cout << "2) ";
						child = now->left ? now->left : now->right;
						child->parent = now->parent;
					}
				} else {// 3) two child
					std::cout << "3) ";
					node_pointer left_max = _root->left;
					while (left_max->right) {
						left_max = left_max->right;
					}
					if (left_max->parent->left == left_max) {
						left_max->parent->left = left_max->left;
					} else {
						left_max->parent->right = left_max->left;
					}
					std::cout << "left_max: " << left_max->_value.first << ", " << left_max->_value.second << std::endl;
					left_max->parent = now->parent;
					left_max->left = now->left;
					left_max->right = now->right;
					if (left_max->left)
						left_max->left->parent = left_max;
					if (left_max->right)
						left_max->right->parent = left_max;
					child = left_max;
				}
				if (now->parent) {
					std::cout << "have parent" << std::endl;
					if (now->parent->left == now) {
						now->parent->left = child;
					} else {
						now->parent->right = child;
					}
				}
				else {
					std::cout << "no parent" << std::endl;
					_root = child;
				}
				_pair_alloc.destroy(&now->_value);
				_node_alloc.deallocate(now, 1);
				
				// balancing
				display(_root);
			}
			// void erase_key(const key_type key) {
			// 	node_pointer node = _root;
			// 	while (node) {
			// 		if (node->_value.first == key) {
			// 			break;
			// 		}
			// 		if (node->_value.first > key) {
			// 			node = node->left;
			// 		} else {
			// 			node = node->right;
			// 		}
			// 	}
			// 	std::cout << "*********erase (" << node->_value.first << ", " << node->_value.second << ")*********" << std::endl;
			// 	if (node->parent)
			// 		std::cout << "parent: " << node->parent->_value.first << ", " << node->parent->_value.second << std::endl;
			// 	erase_node(node);
			// }
			
			void erase_node(const iterator pos) {
				node_pointer node = _root;
				while (node) {
					if (node->_value.first == pos->first) break ;
					else if (node->_value.first > pos->first) node = node->left;
					else node = node->right;
				}
				std::cout << "*********erase (" << node->_value.first << ", " << node->_value.second << ")*********" << std::endl;
				if (node->parent)
					std::cout << "parent: " << node->parent->_value.first << ", " << node->parent->_value.second << std::endl;
				erase_one(node);
			}

			node_pointer l_rotate(node_pointer node) {
				node_pointer parent = node->parent;
				node_pointer now = node;
				node_pointer child = node->right;

				now->right = child->left;
				if (child->left) {
					child->left->parent = now;
				}
				child->left = now;
				now->parent = child;

				if (parent) {
					if (parent->_value.first > node->_value.first) {
						parent->left = child;
					} else {
						parent->right = child;
					}
				}
				child->parent = parent;
				return (child);
			}
			node_pointer r_rotate(node_pointer node) {
				node_pointer parent = node->parent;
				node_pointer now = node;
				node_pointer child = node->left;

				now->left = child->right;
				if (child->right) {
					child->right->parent = now;
				}
				child->right = now;
				now->parent = child;

				if (parent) {
					if (parent->_value.first > node->_value.first) {
						parent->left = child;
					} else {
						parent->right = child;
					}
				}
				child->parent = parent;
				return (child);
			}
			
			int tree_height(node_pointer node) {
				int height;
				int left = 0;
				int right = 0;

				if (node == 0) {
					return (0);
				}
				left = tree_height(node->left);
				right = tree_height(node->right);
				height = left < right ? right + 1 : left + 1;
				return (height);
			}

			int balance_factor(node_pointer node) {
				int left = tree_height(node->left);
				int right = tree_height(node->right);
				return (left - right);
			}

			void balance(node_pointer node) {
				node_pointer now = node;

				while (now) {
					int bf = balance_factor(now);
					std::cout << "bf: " << bf << " (" << now->_value.first << ", " << now->_value.second << ")" << std::endl;
					int diff;
					if (bf > 1) { // 왼쪽이 너무 큰 경우
						diff = balance_factor(now->left);
						std::cout << "diff: " << diff << std::endl;
						if (diff < 0) { // lr
							std::cout << "lr" << std::endl;
							now->left = l_rotate(now->left);
						}
						std::cout << "ll" << std::endl;
						now = r_rotate(now);
					} else if (bf < -1) { // 오른쪽이 너무 큰 경우
						diff = balance_factor(now->right);
						std::cout << "diff: " << diff << std::endl;
						if (diff > 0) { // rl
							std::cout << "rl" << std::endl;
							now->right = r_rotate(now->right);
						}
						std::cout << "rr" << std::endl;
						now = l_rotate(now);
					}
					if (now->parent == 0) {
						_root = now;
					}
					now = now->parent;
				}
			}

			void display(node_pointer node) {
				if (node) {
					if (node == _root) {
						std::cout << "==display" << std::endl;
						std::cout << "root: " << node->_value.first << ", " << node->_value.second << std::endl;
					}
					display(node->left);
					std::cout << node->_value.first << ", " << node->_value.second << "----------";
					if(node->parent)
						std::cout << node->parent->_value.first << ", " << node->parent->_value.second << std::endl;
					else
						std::cout << "no parent" << std::endl;
					display(node->right);
				}
			}
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