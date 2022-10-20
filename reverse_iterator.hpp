#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

namespace ft {
	template <class Iterator> class reverse_iterator {
		public:
		typedef Iterator iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer pointer;
		typedef typename ft::iterator_traits<Iterator>::reference reference;

		// 생성자
		reverse_iterator(); // default
		explicit reverse_iterator (iterator_type it); // initialization
		template <class Iter>  reverse_iterator (const reverse_iterator<Iter>& rev_it); // copy

		// base
		iterator_type base() const;

		// operator
		reference operator*() const;
		reverse_iterator operator+ (difference_type n) const;
		reverse_iterator& operator++(); // 전위
		reverse_iterator  operator++(int); // 후위
		reverse_iterator& operator+= (difference_type n);
		reverse_iterator operator- (difference_type n) const;
		reverse_iterator& operator--();
		reverse_iterator  operator--(int);
		reverse_iterator& operator-= (difference_type n);
		pointer operator->() const;
		reference operator[] (difference_type n) const;
		
		// non-member function overloads
		// relational-operators
		template <class Iterator> bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
			return (lhs == rhs);
		}
		template <class Iterator> bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
			return (lhs != rhs);
		}
		template <class Iterator> bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
			return (lhs < rhs);
		}
		template <class Iterator> bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
			return (lhs <= rhs);
		}
		template <class Iterator> bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
			return (lhs > rhs);
		}
		template <class Iterator> bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
			return (lhs >= rhs);
		}

		// operator+
		template <class Iterator> reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it);

		// operator-
		template <class Iterator> typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
	};
}

#endif