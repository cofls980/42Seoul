#include <iostream>
#include <string>

#ifdef FT_MODE
#include "vector/vector.hpp"
#else
#include <vector>
namespace ft = std;
#endif
#include <stdlib.h>

#define COUNT 100

int main() {
#ifdef FT_MODE
	std::cout << "ft_mode" << std::endl;
#else
	std::cout << "std_mode" << std::endl;
#endif
	ft::vector<int> ii;
	ft::vector<int> vector_int(ii);
	for (unsigned int i = 0;i < 10;i++) {
		vector_int.push_back(i);
	}
	std::cout << vector_int.size() << std::endl;
	std::cout << vector_int.capacity() << std::endl;
	for (unsigned int i = 0;i < 10;i++) {
		std::cout << vector_int.at(i) << " ";
	}
	std::cout << std::endl;
	vector_int.resize(18, 8);
	std::cout << vector_int.size() << std::endl;
	std::cout << vector_int.capacity() << std::endl;
	for (unsigned int i = 0;i < vector_int.size();i++) {
		std::cout << vector_int.at(i) << " ";
	}
	std::cout << std::endl;
	vector_int.assign(21, 10);
	std::cout << vector_int.size() << std::endl;
	std::cout << vector_int.capacity() << std::endl;
	for (unsigned int i = 0;i < vector_int.size();i++) {
		std::cout << vector_int.at(i) << " ";
	}
	std::cout << std::endl;
	vector_int.clear();
	for (int i = 0 ;i < 10;i++) {
		vector_int.push_back(i+1);
	}
	std::cout << vector_int.size() << std::endl;
	std::cout << vector_int.capacity() << std::endl;
	std::cout << "-----------" << std::endl;
	ft::vector<int>::iterator it = vector_int.begin();
	ft::vector<int> vector_int2(5,2);
	ft::vector<int>::iterator it2 = vector_int2.begin();
	if (it == it2) std::cout << "true" << std::endl;
	std::cout << "-----------" << std::endl;
	std::cout << vector_int.size() << std::endl;
	std::cout << vector_int.capacity() << std::endl;
	ft::vector<int>::reverse_iterator it3(vector_int.end());
	ft::vector<int>::reverse_iterator it4(vector_int.begin());
	std::cout << "-----------" << std::endl;
	std::cout << *(it3 + 1) << std::endl;
	std::cout << it3[5] << std::endl;
	std::cout << *(it4 - 5) << std::endl;
	std::cout << it4[-1] << std::endl;

	std::cout << "-----------" << std::endl;
	ft::vector<int> aa;
	for (int i = 0 ;i < 10;i++) {
		aa.push_back(i+1);
	}
	aa.assign(5, 3);
	for (size_t i = 0 ;i < aa.capacity();i++) {
		std::cout << aa[i] << std::endl;
	}

	std::allocator<int> alloc = std::allocator<int>();
	std::allocator<int>::pointer begin = alloc.allocate(10);

	std::cout << "-----------" << std::endl;
	/*
	for (int i = 0; i < 10; i++) {
		alloc.construct(begin + i, i);
	} 
	for (int i =0; i < 10; i++) 
		std::cout << *(begin + i) << std::endl;*/

	for (int i =0; i < 10; i++) 
		std::cout << *(begin + i) << std::endl;
	ft::vector<int> c1;
	c1.pop_back();
	std::cout << c1.size() << std::endl;

	/*std::cout << c1.front() << std::endl;
	std::cout << c1.back() << std::endl;*/

	return (0);
} 