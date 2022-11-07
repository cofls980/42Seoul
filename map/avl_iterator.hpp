#ifndef AVL_ITERATOR_HPP
#define AVL_ITERATOR_HPP

#include "../utils/iterator_traits.hpp"
#include "../utils/utils.hpp"

namespace ft {// T=
    template<class T, class Comp, class Node>
	class avl_iterator {
        public:
			typedef typename ft::iterator_traits<T*>::value_type value_type;
			typedef typename ft::iterator_traits<T*>::pointer pointer;
			typedef typename ft::iterator_traits<T*>::reference reference;
			typedef typename ft::iterator_traits<T*>::difference_type difference_type;
			typedef typename ft::iterator_traits<T*>::iterator_category iterator_category;
			typedef Comp compare;
			typedef Node node_type;
			typedef Node * node_pointer;
		
		protected:
			node_pointer _now;
			compare _comp;

		public:
			avl_iterator() : _now() {}
			avl_iterator(const node_pointer p) : _now(p) {}
			avl_iterator(const avl_iterator& x) : _now(x._now) {}
			avl_iterator& operator= (const avl_iterator& x) {
				if (*this == x)
					return (*this);
				_now = x._now;
				return (*this);
			}
			~avl_iterator() {}

            reference operator*() const {return (_now->value);}
			pointer operator->() const {return (&(_now->value));}

            avl_iterator& operator++() {
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
			avl_iterator operator++(int) {
				avl_iterator it = *this;
				++_now;
				return (it);
			}
			avl_iterator& operator--() {
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
				_now--;
				return (*this);
			}
			avl_iterator operator--(int) {
				avl_iterator it = *this;
				--_now;
				return (it);
			}
    };
    /*template<class T1, class T2>
	bool operator==(const map_iterator<T1>& left, const map_iterator<T2>& right) {
		return (&(*left) == &(*right));
	}
	template<class T1, class T2>
	bool operator!=(const map_iterator<T1>& left, const map_iterator<T2>& right) {
		return (&(*left) != &(*right));
	}*/
}

#endif