#include <iostream>
#include <string>
#include <stdlib.h>

#ifdef FT_MODE
	#include "vector/vector.hpp"
	#include "utils/utils.hpp"
#else
	#include <vector>
	namespace ft = std;
#endif

int main() {
#ifdef FT_MODE
	std::cout << "ft_mode" << std::endl;
#else
	std::cout << "std_mode" << std::endl;
#endif
	
	ft::vector<int> v1;

	std::cout << "capacity: " << v1.capacity() << ", size: " << v1.size() << std::endl;

	v1.push_back(10);

	std::cout << "capacity: " << v1.capacity() << ", size: " << v1.size() << std::endl;

	v1.resize(3);

	std::cout << "capacity: " << v1.capacity() << ", size: " << v1.size() << std::endl;

	v1.resize(10);

	std::cout << "capacity: " << v1.capacity() << ", size: " << v1.size() << std::endl;

	v1.resize(5);

	std::cout << "capacity: " << v1.capacity() << ", size: " << v1.size() << std::endl;

	v1.resize(15);

	std::cout << "capacity: " << v1.capacity() << ", size: " << v1.size() << std::endl;

	v1.resize(20);

	std::cout << "capacity: " << v1.capacity() << ", size: " << v1.size() << std::endl;

	/*v1.push_back(10);

	std::cout << "capacity: " << v1.capacity() << ", size: " << v1.size() << std::endl;*/

	v1.insert(v1.begin(), 41, 10);

	std::cout << "capacity: " << v1.capacity() << ", size: " << v1.size() << std::endl;

	v1.clear();

	std::cout << "capacity: " << v1.capacity() << ", size: " << v1.size() << std::endl;

	v1.resize(62);

	std::cout << "capacity: " << v1.capacity() << ", size: " << v1.size() << std::endl;

	v1.assign(123,5);

	std::cout << "capacity: " << v1.capacity() << ", size: " << v1.size() << std::endl;

	ft::vector<float> ft_c0 (1000000, 42.21f);
	ft::vector<float> std_c0 (1000000, 42.21f);
	std::cout << "ft_c0 capacity: " << ft_c0.capacity() << ", size: " << ft_c0.size() << std::endl;
	std::cout << "std_c0 capacity: " << std_c0.capacity() << ", size: " << ft_c0.size() << std::endl;
	ft_c0.clear();
	std_c0.clear();
	std::cout << "ft_c0 capacity: " << ft_c0.capacity() << ", size: " << ft_c0.size() << std::endl;
	std::cout << "std_c0 capacity: " << std_c0.capacity() << ", size: " << ft_c0.size() << std::endl;
	ft::vector<float>().swap(ft_c0);
	ft::vector<float>().swap(std_c0);
	std::cout << "ft_c0 capacity: " << ft_c0.capacity() << ", size: " << ft_c0.size() << std::endl;
	std::cout << "std_c0 capacity: " << std_c0.capacity() << ", size: " << ft_c0.size() << std::endl;

	ft::vector<int> v2(v1.begin(), v1.end());
	std::cout << "capacity: " << v1.capacity() << ", size: " << v1.size() << std::endl;

	std::cout << v1.max_size() << std::endl;

	//v1.reserve(4611686018427387905);
	//v1.erase(v2.end());
	//v1.assign(v2.end(), v2.begin());
	v1.insert(v1.end(), 2);
	std::cout << "capacity: " << v1.capacity() << ", size: " << v1.size() << std::endl;

	std::cout << "max_size: " << v1.max_size() << std::endl;

	ft::vector<int> ve;
	std::cout << "empty: " << ve.empty() << std::endl;

	ve.push_back(1);
	std::cout << ve.front() << std::endl;

	ft::vector<int>::iterator it = ve.begin();
	*it = 10;
	std::cout << ve.front() << std::endl;
	ve.push_back(99);
	*it++;
	std::cout << *it << std::endl;
	ft::vector<int>::reverse_iterator r(it);
	r.base();

	return (0);
} 