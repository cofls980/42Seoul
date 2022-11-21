#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>

#ifdef FT_MODE
	#include "../vector/vector.hpp"
	#include "../stack/stack.hpp"
	#include "../map/map.hpp"
	#include "../utils/pair.hpp"
	#include "../utils/make_pair.hpp"
#else
	#include <vector>
	#include <stack>
	#include <map>
	namespace ft = std;
#endif

int main() {
#ifdef FT_MODE
	std::cout << "ft_mode" << std::endl;
#else
	std::cout << "std_mode" << std::endl;
#endif

	clock_t start = clock(), end;
	{
		std::cout << "//-------------push_back---------------//" << std::endl;
		ft::vector<int> vector_3(4);
		ft::vector<int> vector1 = vector_3;
		for (size_t i = 0;i < vector1.size();i++)
		{
			std::cout << vector1.at(i) << std::endl;
		}
		ft::vector<int> vector_int(5,2);
		for (unsigned int i = 0;i < vector_int.size();i++) {
			std::cout << vector_int[i] << std::endl;
		}
		std::cout << vector_int.size() << std::endl;
		std::cout << vector_int.capacity() << std::endl;

		for (int i = 0;i < 10;i++)
		{
			vector_int.push_back(i);
			std::cout << "i: " << i << ", cap: " << vector_int.capacity() << ", size: " << vector_int.size() << std::endl;
		}

		std::cout << "size: " << vector_int.size() << std::endl;
	}
	{
		std::cout << "//-------------reserve---------------//" << std::endl;
		ft::vector<int> vector_int(5,2);
		vector_int.reserve(12);
		for (size_t i = 0;i < vector_int.size();i++)
		{
			std::cout << "i: " << i << ", at: " << vector_int.at(i) << ", cap: " << vector_int.capacity() << std::endl;
		}
		int size = vector_int.size();
		for (int i = size;i < 30 + size;i++)
		{
			vector_int.push_back(i);
			std::cout << "i: " << i << ", cap: " << vector_int.capacity() << ", size: " << vector_int.size() << std::endl;
		}
	}
	{
		std::cout << "//-------------resize---------------//" << std::endl;
		ft::vector<int> vector_int(5,2);
		vector_int.resize(130,1);
		for (size_t i = 0;i < vector_int.size();i++)
		{
			std::cout << "i: " << i << ", at: " << vector_int.at(i) << ", cap: " << vector_int.capacity() << std::endl;
		}
		vector_int.reserve(259);
		int size = vector_int.size();
		for (int i = size;i < 30 * 2 + size;i++)
		{
			vector_int.push_back(i);
			std::cout << "i: " << i << ", cap: " << vector_int.capacity() << ", size: " << vector_int.size() << std::endl;
		}
	}
	{
		std::cout << "//-------------element access---------------//" << std::endl;
		ft::vector<int> vector_int(5,2);
		int idx = 3;
		std::cout << idx << " = " << vector_int[idx] << std::endl;
		std::cout << vector_int.front() << std::endl;
		ft::vector<int> v1;
		std::cout << vector_int.back() << std::endl;
	}
	{
		std::cout << "//-------------modifiers---------------//" << std::endl;
		ft::vector<int> vector_int(5,2);
		vector_int.assign(3, 3);
		for (size_t i = 0 ;i < vector_int.size();i++) {
			std::cout << vector_int[i] << std::endl;
		}
		std::cout << vector_int.capacity() << std::endl;
		std::cout << vector_int.size() << std::endl;
		std::cout <<"-----------------" << std::endl;
		ft::vector<int> v1;
		v1.reserve(2);
		std::cout << v1.capacity() << std::endl;
		v1.assign(3,3);
		for (size_t i = 0 ;i < v1.size();i++) {
			std::cout << v1[i] << std::endl;
		}
		std::cout << v1.capacity() << std::endl;
		std::cout << v1.size() << std::endl;
		std::cout << v1[0] << std::endl;
		std::cout <<"-------pop_back----------" << std::endl;
		ft::vector<int> v2;
		for (int i = 0;i < 10;i++) v2.push_back(i);
		std::cout << v2.size() << std::endl;
		v2.pop_back();
		std::cout << v2.size() << std::endl;
		for (int i = 0;i < 10;i++) std::cout << v2[i] << std::endl;
		std::cout <<"-------swap----------" << std::endl;
		ft::vector<int> v5;
		ft::vector<int> v6;
		for (int i = 0;i < 3;i++) v5.push_back(2);
		for (int i = 0;i < 8;i++) v6.push_back(i);
		std::cout << v5.size() << ", " << v5.capacity() << std::endl;
		std::cout << v6.size() << ", " << v6.capacity() << std::endl;
		v5.swap(v6);
		std::cout << v5.size() << ", " << v5.capacity() << std::endl;
		std::cout << v6.size() << ", " << v6.capacity() << std::endl;
		std::cout <<"-------clear----------" << std::endl;
		ft::vector<int> v4;
		for (int i = 0;i < 10;i++) v4.push_back(i);
		std::cout << v4.size() << ", " << v4.capacity() << std::endl;
		v4.clear();
		std::cout << v4.size() << ", " << v4.capacity() << std::endl;
		std::cout << v4[5] << std::endl;
	}
	{
		std::cout << "//-------------compare---------------//" << std::endl;
		int i1 = 3;
		int i2 = 3;
		ft::vector<int> foo;
		for (int i = 0;i < i1;i++) foo.push_back(2);
		ft::vector<int> bar;
		for (int i = 0;i < i2;i++) bar.push_back(3);

		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

		std::cout <<"-------swap----------" << std::endl;

		foo.swap(bar);
		for (int i = 0;i < i1;i++) std::cout << foo.at(i) << std::endl;
		for (int i = 0;i < i2;i++) std::cout << bar.at(i) << std::endl;
	}
	{
		std::cout << "//-------------iterators---------------//" << std::endl;
		int i1 = 3;
		int i2 = 10;
		ft::vector<int> foo;
		for (int i = 0;i < i1;i++) foo.push_back(2);
		ft::vector<int> bar;
		for (int i = 0;i < i2;i++) bar.push_back(i*2 + 1);
		std::cout << *bar.begin() << std::endl;
		std::cout << *(bar.end()-1) << std::endl;
		ft::vector<int>::iterator it(bar.begin());
		ft::vector<int>::iterator it1(bar.begin() + 1);
		if (it == it1)
		{
			std::cout << "same" << std::endl;
		}
		for (it = bar.begin();it != bar.end();++it)
			std::cout << *(it) << "\t";
		std::cout << std::endl;
	}
	{
		int i2 = 10;
		ft::vector<int> bar;
		for (int i = 0;i < i2;i++) bar.push_back(i*2 + 1);
		ft::vector<int>::iterator it(bar.begin());
		std::cout << it[4] << std::endl;
		std::cout << *it++ << std::endl;
		std::cout << *it++ << std::endl;
		std::cout << std::endl;
		ft::vector<int> foo(bar.begin(), bar.end());
		std::cout << foo.size() << ", " << foo.capacity() << std::endl;
	}
	{
		std::cout << "//-------------reverse iterators---------------//" << std::endl;
		ft::vector<int> ii;
		ft::vector<int> vector_int(ii);
		for (unsigned int i = 0;i < 10;i++) {
			vector_int.push_back(i);
		}
		ft::vector<int>::iterator it = vector_int.begin();
		ft::vector<int> vector_int2(5,2);
		ft::vector<int>::iterator it2 = vector_int2.begin();
		if (it == it2) std::cout << "true" << std::endl;
		std::cout << "-----------" << std::endl;
		std::cout << vector_int.size() << std::endl;
		std::cout << vector_int.capacity() << std::endl;
		ft::vector<int>::reverse_iterator it3(vector_int.rbegin());
		ft::vector<int>::reverse_iterator it4(vector_int.rend());
		std::cout << "-----------" << std::endl;
		std::cout << *(it3 + 1) << std::endl;
		std::cout << it3[5] << std::endl;
		std::cout << *(it4 - 5) << std::endl;
		std::cout << it4[-1] << std::endl;
	}
	{
		std::cout << "//-------------max_size---------------//" << std::endl;
		ft::vector<int> vector_int;
		for (unsigned int i = 0;i < 10;i++) {
			vector_int.push_back(i);
		}
		std::cout << vector_int.max_size() << std::endl;
	}
	{
		ft::vector<int> v1;
		std::cout << "capacity: " << v1.capacity() << ", size: " << v1.size() << std::endl;

		v1.push_back(10);
		std::cout << "capacity: " << v1.capacity() << ", size: " << v1.size() << std::endl;

		v1.resize(3);
		std::cout << "capacity: " << v1.capacity() << ", size: " << v1.size() << std::endl;

		v1.resize(4);
		std::cout << "capacity: " << v1.capacity() << ", size: " << v1.size() << std::endl;

		v1.resize(3);
		std::cout << "capacity: " << v1.capacity() << ", size: " << v1.size() << std::endl;

		v1.resize(7);
		std::cout << "capacity: " << v1.capacity() << ", size: " << v1.size() << std::endl;

		v1.resize(26);
		std::cout << "capacity: " << v1.capacity() << ", size: " << v1.size() << std::endl;

		v1.pop_back();
		v1.pop_back();

		std::cout << "capacity: " << v1.capacity() << ", size: " << v1.size() << std::endl;

		std::cout << v1.max_size() << std::endl;

		v1.resize(26);
		std::cout << "capacity: " << v1.capacity() << ", size: " << v1.size() << std::endl;

		for (int i = 0;i < 40;i++) {
			v1.insert(v1.begin(),3);
		}
		std::cout << "capacity: " << v1.capacity() << ", size: " << v1.size() << std::endl;

		v1.assign(67, 3);
		std::cout << "capacity: " << v1.capacity() << ", size: " << v1.size() << std::endl;

		ft::vector<int> v2(5, 3);
		std::cout << "capacity: " << v2.capacity() << ", size: " << v2.size() << std::endl;

		ft::vector<int> v3(v1.begin(), v1.end());
		std::cout << "capacity: " << v3.capacity() << ", size: " << v3.size() << std::endl;

		ft::vector<int> v4(v3);
		std::cout << "capacity: " << v4.capacity() << ", size: " << v4.size() << std::endl;

		v4.push_back(3);
		std::cout << "capacity: " << v4.capacity() << ", size: " << v4.size() << std::endl;

		v2 = v4;
		std::cout << "capacity: " << v2.capacity() << ", size: " << v2.size() << std::endl;

		for (int i = 0;i < 3;i++) {
			v2.erase(v2.begin());
		}
		
		std::cout << "capacity: " << v2.capacity() << ", size: " << v2.size() << std::endl;
	}
	end = clock();
	double result = (double)(end-start) / CLOCKS_PER_SEC;
	std::cout << "time diff: " << result << std::endl;
}