#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

namespace ft {
	template <class Iterator> class reverse_iterator {
		public:
		typedef Iterator iterator_type;
		//typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer pointer;
		typedef typename ft::iterator_traits<Iterator>::reference reference;

		iterator_type _iter;

		// 생성자
		reverse_iterator() : _iter() {} // default
		explicit reverse_iterator (iterator_type it) : _iter(it) {} // initialization
		template <class Iter>  reverse_iterator (const reverse_iterator<Iter>& rev_it) {
			this->_iter = rev_it._iter;
		} // copy

		// base
		iterator_type base() const {
			return _iter;
		}

		// operator
		reference operator*() const {
			return _iter;
		}
		reverse_iterator operator+ (difference_type n) const {
			return this;
		}
		reverse_iterator& operator++() {
			return this;
		} // 전위
		reverse_iterator  operator++(int){
			return this;
		} // 후위
		reverse_iterator& operator+= (difference_type n) {
			return this;
		}
		reverse_iterator operator- (difference_type n) const {
			return this;
		}
		reverse_iterator& operator--() {
			return this;
		}
		reverse_iterator  operator--(int) {
			return this;
		}
		reverse_iterator& operator-= (difference_type n) {
			return this;
		}
		pointer operator->() const {
			return (0);
		}
		reference operator[] (difference_type n) const {
			return (0);
		}
		
		// non-member function overloads
		// relational-operators
		friend bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
			return (lhs == rhs);
		}
		friend bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
			return (lhs != rhs);
		}
		friend bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
			return (lhs < rhs);
		}
		friend bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
			return (lhs <= rhs);
		}
		friend bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
			return (lhs > rhs);
		}
		friend bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
			return (lhs >= rhs);
		}

		// operator+
		//template <class Iterator> reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it);

		// operator-
		//template <class Iterator> typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
	};
}

#endif