#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP


#include <cstddef>

namespace ft{
	template <class T, bool v>
	struct integral_constant {
		static const bool value = v;
		typedef T value_type;
		typedef integral_constant<T,value> type;
		operator value_type() const { return value; }
	};
	template< class T > struct is_integral : public integral_constant<T, false> {};
	template<> struct is_integral<bool> : public integral_constant<bool, true> {};
	template<> struct is_integral<char> : public integral_constant<char, true> {};
	template<> struct is_integral<wchar_t> : public integral_constant<wchar_t, true> {};
	template<> struct is_integral<signed char> : public integral_constant<signed char, true> {};
	template<> struct is_integral<short> : public integral_constant<short int, true> {};
	template<> struct is_integral<int> : public integral_constant<int, true> {};
	template<> struct is_integral<long> : public integral_constant<long int, true> {};
	template<> struct is_integral<long long> : public integral_constant<long long int, true> {};
	template<> struct is_integral<unsigned char> : public integral_constant<unsigned char, true> {};
	template<> struct is_integral<unsigned short> : public integral_constant<unsigned short int, true> {};
	template<> struct is_integral<unsigned int> : public integral_constant<unsigned int, true> {};
	template<> struct is_integral<unsigned long> : public integral_constant<unsigned long int, true> {};
	template<> struct is_integral<unsigned long long> : public integral_constant<unsigned long long int, true> {};

}

#endif