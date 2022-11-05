#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

namespace ft {
    template<class T>
	class map_iterator {
        public:
			typedef typename ft::iterator_traits<T*>::value_type value_type;
			typedef typename ft::iterator_traits<T*>::pointer pointer;
			typedef typename ft::iterator_traits<T*>::reference reference;
			typedef typename ft::iterator_traits<T*>::difference_type difference_type;
			typedef typename ft::iterator_traits<T*>::iterator_category iterator_category;
		
		protected:
			pointer _ptr;

		public:
			map_iterator() : _ptr(0) {}
			map_iterator(const pointer& p) : _ptr(p) {}
			map_iterator(const map_iterator& x) : _ptr(x._ptr) {}
			map_iterator& operator= (const map_iterator& x) {
				if (*this == x)
					return (*this);
				_ptr = x._ptr;
				return (*this);
			}
			~map_iterator() {}

            reference operator*() const {return (*_ptr);}
			pointer operator->() const {return (_ptr);}

            map_iterator& operator++() {
				_ptr++;
				return (*this);
			}
			map_iterator operator++(int) {
				map_iterator it(*this);
				_ptr++;
				return (it);
			}
			map_iterator& operator--() {
				_ptr--;
				return (*this);
			}
			map_iterator operator--(int) {
				map_iterator it(*this);
				_ptr--;
				return (it);
			}
    };
    template<class T1, class T2>
	bool operator==(const map_iterator<T1>& left, const map_iterator<T2>& right) {
		return (&(*left) == &(*right));
	}
	template<class T1, class T2>
	bool operator!=(const map_iterator<T1>& left, const map_iterator<T2>& right) {
		return (&(*left) != &(*right));
	}
}

#endif