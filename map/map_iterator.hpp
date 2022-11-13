#ifndef AVL_ITERATOR_HPP
#define AVL_ITERATOR_HPP

#include "../utils/iterator_traits.hpp"
#include "../utils/utils.hpp"

namespace ft {
    template<class Node, class Pair>//, class Comp
	class map_iterator {
        public:
			typedef Pair value_type;
			typedef Pair * pointer;
			typedef Pair & reference;
			typedef std::ptrdiff_t difference_type;
			typedef std::bidirectional_iterator_tag iterator_category;
		
		private:
			typedef Node * node_pointer;
			node_pointer _now;
			// compare _comp;

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

			map_iterator& operator++() { // map 범위를 넘어갈 경우
				if (_now->right) {
					_now = _now->right;
					while (_now && _now->left) {
						_now = _now->left;
					}
				} else {
					node_pointer tmp = _now;
					_now = _now->parent;
					while (_now && _now->right == tmp) {
						tmp = _now;
						_now = _now->parent;
					}
				}
				return (*this);
			}
			map_iterator operator++(int) {
				map_iterator it = *this;
				++(*this);
				return (it);
			}
			map_iterator& operator--() { // map 범위를 넘어갈 경우
				if (_now->left) {
					_now = _now->left;
					while (_now && _now->right) {
						_now = _now->right;
					}
				} else {
					node_pointer tmp = _now;
					_now = _now->parent;
					while (_now && _now->left == tmp) {
						tmp = _now;
						_now = _now->parent;
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