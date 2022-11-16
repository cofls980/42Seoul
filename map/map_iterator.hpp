#ifndef AVL_ITERATOR_HPP
#define AVL_ITERATOR_HPP

#include "../utils/iterator_traits.hpp"

namespace ft {
	template<class Node, class Pair>
	class map_iterator {
		public:
			typedef Pair value_type;
			typedef Pair * pointer;
			typedef Pair & reference;
			typedef std::ptrdiff_t difference_type;
			typedef ft::bidirectional_iterator_tag iterator_category;
		
		private:
			typedef Node * node_pointer;
			node_pointer _now;

		public:
			map_iterator(const node_pointer p = node_pointer()) : _now(p) {}
			map_iterator(const map_iterator& x) : _now(x._now) {}
			~map_iterator() {}
			map_iterator& operator= (const map_iterator& x) {
				if (this != &x) {
					_now = x._now;
				}
				return (*this);
			}

			reference operator*() const {return (_now->_value);}
			pointer operator->() const {return &(_now->_value);}

			map_iterator& operator++() {
				if (_now->is_nil) {
					return (*this);
				}
				if (_now->right && !_now->right->is_nil) {
					_now = _now->right;
					while (_now && !_now->left->is_nil) {
						_now = _now->left;
					}
				} else {
					node_pointer curr = _now;
					node_pointer tmp = _now;
					_now = _now->parent;
					if (!_now) {
						_now = curr->right;
					} else {
						while (_now && _now->right == tmp) {
							if (!_now->parent) {
								_now = curr->right;
								break ;
							}
							tmp = _now;
							_now = _now->parent;
						}
					}
				}
				return (*this);
			}
			map_iterator operator++(int) {
				map_iterator it = *this;
				++(*this);
				return (it);
			}
			map_iterator& operator--() {
				if (_now->is_nil) {
					_now = _now->parent;
					return (*this);
				}
				if (_now->left && !_now->left->is_nil) {
					_now = _now->left;
					while (_now && !_now->right->is_nil) {
						_now = _now->right;
					}
				} else {
					node_pointer curr = _now;
					node_pointer tmp = _now;
					_now = _now->parent;
					if (!_now) {
						_now = curr;
					} else {
						while (_now && _now->left == tmp) {
							if (!_now->parent) {
								_now = curr;
								break ;
							}
							tmp = _now;
							_now = _now->parent;
						}
					}
				}
				return (*this);
			}
			map_iterator operator--(int) {
				map_iterator it = *this;
				--(*this);
				return (it);
			}
			friend bool operator==(const map_iterator& left, const map_iterator& right) {return (left._now == right._now);}
			friend bool operator!=(const map_iterator& left, const map_iterator& right) {return (left._now != right._now);}
	};
}

#endif