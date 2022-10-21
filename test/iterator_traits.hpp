#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

namespace ft {
	template <class Iterator> class iterator_traits {
		public:
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::iterator_category	iterator_category;
	};
	template <class T> class iterator_traits<T*>;
	template <class T> class iterator_traits<const T*>;
}

#endif

//cplusplus
template <class Iterator> class iterator_traits;
template <class T> class iterator_traits<T*>;
template <class T> class iterator_traits<const T*>;

//cppreference
template< class Iter > struct iterator_traits {
	public:
		typedef typename Iter::difference_type difference_type;
		typedef typename Iter::value_type value_type;
		typedef typename Iter::pointer pointer;
		typedef typename Iter::reference reference;
		//typedef typename Iter::iterator_category iterator_category;

}
//template< class T > struct iterator_traits<T*>;
//template< class T > struct iterator_traits<const T*>;