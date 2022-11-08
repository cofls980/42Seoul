#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>
#include "../utils/utils.hpp"
#include "avl_iterator.hpp"

namespace ft {
	template<class Key, class T, class Compare = ft::less<T>, class Node = ft::node<T>, class Alloc = std::allocator<T>, class Node_alloc = std::allocator<Node> >
	class avl_tree {
		private:

		public:
			typedef Key key_type;
			typedef T value_type; // pair
			typedef Compare compare;
			typedef Node node_type;
			typedef Alloc allocator_type;
			typedef Node_alloc node_allocator_type;
			typedef Node * node_pointer;
			typedef typename ft::avl_iterator<value_type, compare, node_type> iterator;
			typedef typename ft::avl_iterator<const value_type, compare, node_type> const_iterator;
			
			node_allocator_type _node_alloc;
			allocator_type _alloc;
			node_pointer _root;
			compare _comp;

			avl_tree(const compare& comp, const node_allocator_type& node_alloc = node_allocator_type(), 
					const allocator_type& alloc = allocator_type()) {
				_node_alloc = node_alloc;
				_alloc = alloc;
				_root = 0;
				_comp = comp;
			}

			~avl_tree() {
				/*_node_alloc.destroy(_root);
				_node_alloc.deallocate(_root, 1);*/
			}

			node_pointer insert_node(const value_type& value) {//ft::pair<iterator, bool>
				std::cout << "*********insert (" << value.first << ", " << value.second << ")*********" << std::endl;
				//insert
				if (_root == 0) {
					//_root = newOne;
					_root = _node_alloc.allocate(1);
					_alloc.construct(&_root->_value, value);
					//_node_alloc.construct(_root, node_type(value));
				} else {
					node_pointer tmp = _root;
					bool l;
					while (tmp) {
						if (tmp->_value == value) {
							return (tmp);
							//return (ft::make_pair(iterator(tmp), false));
						}
						if (tmp->_value.first > value.first) {
							l = true;
							if (tmp->left == 0)  break;
							tmp = tmp->left;
						} else {
							l = false;
							if (tmp->right == 0)  break;
							tmp = tmp->right;
						}
					}
					//insert -> comp에 따라 달라지나?
					node_pointer newOne = _node_alloc.allocate(1);
					_alloc.construct(&newOne->_value, value);
					//_node_alloc.construct(newOne, node_type(value));
					if (l) {
						tmp->left = newOne;
					} else {
						tmp->right = newOne;
					}
					newOne->parent = tmp;
					balance(newOne);
					display(_root);
					return (newOne);
					//return (ft::make_pair(iterator(newOne), true));
				}
				display(_root);
				return (_root);
				//return (ft::make_pair(iterator(_root), true));
			}

			void erase_node(node_pointer now) {//iterator it
				node_pointer node = now;//it._now;
				node_pointer child;
				
				if (node->left == 0 || node->right == 0) {
					if (node->left == 0 && node->right == 0) {// 1) leaf node
						std::cout << "1) ";
						child = node->left;
					} else {// 2) one child
						std::cout << "2) ";
						child = node->left ? node->left : node->right;
						child->parent = node->parent;
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
					left_max->parent = node->parent;
					left_max->left = node->left;
					left_max->right = node->right;
					if (left_max->left)
						left_max->left->parent = left_max;
					if (left_max->right)
						left_max->right->parent = left_max;
					child = left_max;
				}
				if (node->parent) {
					std::cout << "have parent" << std::endl;
					if (node->parent->left == node) {
						node->parent->left = child;
					} else {
						node->parent->right = child;
					}
				}
				else {
					std::cout << "no parent" << std::endl;
					_root = child;
				}
				_alloc.destroy(&node->_value);
				_node_alloc.deallocate(node, 1);
				
				// balancing
				display(_root);
			}

			void erase_key(const key_type key) {
				node_pointer node = _root;
				while (node) {
					if (node->_value.first == key) {
						break;
					}
					if (node->_value.first > key) {
						node = node->left;
					} else {
						node = node->right;
					}
				}
				
				std::cout << "*********erase (" << node->_value.first << ", " << node->_value.second << ")*********" << std::endl;
				if (node->parent)
					std::cout << "parent: " << node->parent->_value.first << ", " << node->parent->_value.second << std::endl;
				erase_node(node);
			}
		
		private:
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
}

#endif