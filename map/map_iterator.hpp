#ifndef AVL_ITERATOR_HPP
#define AVL_ITERATOR_HPP

#include "../utils/iterator_traits.hpp"
#include "../utils/utils.hpp"

namespace ft {
    template<class Node, class Pair>//, class Comp
	class map_iterator {
        public:
			typedef typename ft::iterator_traits<Node*>::value_type value_type;
			typedef typename ft::iterator_traits<Node*>::pointer pointer;
			typedef typename ft::iterator_traits<Node*>::reference reference;
			typedef typename ft::iterator_traits<Node*>::difference_type difference_type;
			typedef typename ft::iterator_traits<Node*>::iterator_category iterator_category;
			typedef Pair pair_type;
			typedef Pair * pair_pointer;
			typedef Pair & pair_reference;
		
		private:
			pointer _now;
			// compare _comp;

		public:
			map_iterator(const pointer p = pointer()) : _now(p) {}
			map_iterator(const map_iterator& x) : _now(x._now) {}
			~map_iterator() {}
			map_iterator& operator= (const map_iterator& x) {
				if (this != &x) {
					_now = x._now;
				}
				return (*this);
			}

			pair_reference operator*() const {return (_now->_value);}
			pair_pointer operator->() const {return &(_now->_value);}

			map_iterator& operator++() { // map 범위를 넘어갈 경우
				if (_now->right) {
					_now = _now->right;
					while (_now && _now->left) {
						_now = _now->left;
					}
				} else {
					pointer tmp = _now;
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
					pointer tmp = _now;
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