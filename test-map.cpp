#include <iostream>
#include <string>
#include <stdlib.h>

#ifdef FT_MODE
	#include "map/map.hpp"
	#include "utils/utils.hpp"
#else
	#include <map>
	namespace ft = std;
#endif

int main() {
#ifdef FT_MODE
	std::cout << "ft_mode" << std::endl;
#else
	std::cout << "std_mode" << std::endl;
#endif
	
	// ft::pair<int, int> p;
	// p = ft::make_pair(10, 3);
	ft::map<int, int> m1;
	m1.insert(ft::make_pair(10,3));
	std::cout << "-----------" << std::endl;
	m1.insert(ft::make_pair(15, 5));
	std::cout << "-----------" << std::endl;
	m1.insert(ft::make_pair(13, 5));
	std::cout << "-----------" << std::endl;
	m1.insert(ft::make_pair(1, 5));
	std::cout << "-----------" << std::endl;
	m1.insert(ft::make_pair(2, 5));
	std::cout << "-----------" << std::endl;
	m1.insert(ft::make_pair(3, 5));
	std::cout << "-----------" << std::endl;
	//m1.insert(ft::make_pair(12, 5));

	std::cout << "==========================" << std::endl;

	m1.erase(3);
	//m1.erase(13);
	// m1.erase(10);
	
	/*std::cout << m1[12] << std::endl;
	m1[12] = 3;
	std::cout << m1[12] << std::endl;
	m1.insert(ft::make_pair(12, 10));
	std::cout << m1[12] << std::endl;*/

	return (0);
} 