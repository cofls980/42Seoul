#include <iostream>
#include <string>
#include "vector/vector.hpp"
/*#include <vector>
namespace ft = std;*/

#include <stdlib.h>

#define COUNT 100

int main(int argc, char** argv) {
	(void) argc;
	(void) argv;
	ft::vector<int> vector_int(5,2);
	for (unsigned int i = 0;i < vector_int.size();i++) {
		std::cout << vector_int[i] << std::endl;
	}
	std::cout << vector_int.size() << std::endl;
	std::cout << vector_int.capacity() << std::endl;
	
	/*ft::vector<int> vector_3(4);
	ft::vector<int> vector1 = vector_3;
	for (int i = 0;i < vector1.size();i++)
	{
		std::cout << vector1.at(i) << std::endl;
	}*/

	/*for (int i = 0;i < COUNT;i++)
	{
		vector_int.push_back(i);
		std::cout << "i: " << i << ", cap: " << vector_int.capacity() << ", size: " << vector_int.size() << std::endl;
	}

	std::cout << "size: " << vector_int.size() << std::endl;*/

	/*{//-------------reserve---------------//
		vector_int.reserve(12);
		for (int i = 0;i < vector_int.size();i++)
		{
			std::cout << "i: " << i << ", at: " << vector_int.at(i) << ", cap: " << vector_int.capacity() << std::endl;
		}
		int size = vector_int.size();
		for (int i = size;i < COUNT + size;i++)
		{
			vector_int.push_back(i);
			std::cout << "i: " << i << ", cap: " << vector_int.capacity() << ", size: " << vector_int.size() << std::endl;
		}
	}*/
	/*{//-------------resize---------------//
		vector_int.resize(130,1);
		for (int i = 0;i < vector_int.size();i++)
		{
			std::cout << "i: " << i << ", at: " << vector_int.at(i) << ", cap: " << vector_int.capacity() << std::endl;
		}
		vector_int.reserve(259);
		int size = vector_int.size();
		for (int i = size;i < COUNT * 2 + size;i++)
		{
			vector_int.push_back(i);
			std::cout << "i: " << i << ", cap: " << vector_int.capacity() << ", size: " << vector_int.size() << std::endl;
		}
	}*/
	/*{//-------------element access---------------//
		int idx = 800;
		std::cout << idx << " = " << vector_int[idx] << std::endl;
		std::cout << vector_int.front() << std::endl;
		ft::vector<int> v1;
		//std::cout << v1.front() << std::endl;
		std::cout << vector_int.back() << std::endl;
		std::cout << v1.back() << std::endl;
	}*/
	/*{//-------------modifiers---------------//
		vector_int.assign(3, 3);
		for (int i = 0 ;i < vector_int.size();i++) {
			std::cout << vector_int[i] << std::endl;
		}
		std::cout << vector_int.capacity() << std::endl;
		std::cout << vector_int.size() << std::endl;
		std::cout <<"-----------------" << std::endl;
		ft::vector<int> v1;
		v1.reserve(2);
		std::cout << v1.capacity() << std::endl;
		v1.assign(3,3);
		for (int i = 0 ;i < v1.size();i++) {
			std::cout << v1[i] << std::endl;
		}
		std::cout << v1.capacity() << std::endl;
		std::cout << v1.size() << std::endl;
		std::cout << v1[100] << std::endl;
		std::cout <<"-------pop_back----------" << std::endl;
		ft::vector<int> v2;
		for (int i = 0;i < 10;i++) v2.push_back(i);
		v2.pop_back();
		for (int i = 0;i < 10;i++) std::cout << v2[i] << std::endl;
		ft::vector<int> v3;
		std::cout <<"-----------------" << std::endl;
		std::cout << v3.size() << std::endl;
		v3.pop_back();
		std::cout << v3.size() << std::endl;
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
	}*/
	/*{//-------------allocator---------------//
		ft::vector<int> myvector;
		int * p;
		unsigned int i;

		// allocate an array with space for 5 elements using vector's allocator:
		p = myvector.get_allocator().allocate(5);

		// construct values in-place on the array:
		for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

		std::cout << "The allocated array contains:";
		for (i=0; i<5; i++) std::cout << ' ' << p[i];
		std::cout << '\n';

		// destroy and deallocate:
		for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
		myvector.get_allocator().deallocate(p,5);
	}*/
	/*{//-------------non-member function overloads---------------//
		int i1 = 3;
		int i2 = 3;
		ft::vector<int> foo;   // three ints with a value of 100
		for (int i = 0;i < i1;i++) foo.push_back(2);
		ft::vector<int> bar;   // two ints with a value of 200
		for (int i = 0;i < i2;i++) bar.push_back(3);
		//bar.reserve(5);

		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

		std::cout <<"-------swap----------" << std::endl;

		foo.swap(bar);
	}*/
	{//-------------iterators---------------//
		int i1 = 3;
		int i2 = 10;
		ft::vector<int> foo;   // three ints with a value of 100
		for (int i = 0;i < i1;i++) foo.push_back(2);
		ft::vector<int> bar;   // two ints with a value of 200
		for (int i = 0;i < i2;i++) bar.push_back(i*2 + 1);
		std::cout << *(bar.begin()) << std::endl;
		std::cout << *(bar.end()) << std::endl;
		ft::vector<int>::iterator it(bar.begin());
		ft::vector<int>::iterator it1(bar.begin() + 1);
		if (it == it1)
		{
			std::cout << "??" << std::endl;
		}
		for (it = bar.begin();it != bar.end();++it)
			std::cout << *(it) << "\t";
		std::cout << std::endl;
	}
	{
		int i2 = 10;
		ft::vector<int> bar;   // two ints with a value of 200
		for (int i = 0;i < i2;i++) bar.push_back(i*2 + 1);
		ft::vector<int>::iterator it(bar.begin());
		std::cout << it[4] << std::endl;
		std::cout << *it++ << std::endl;
		std::cout << *it++ << std::endl;
	}
	{
		int i2 = 10;
		ft::vector<int> bar;   // two ints with a value of 200
		for (int i = 0;i < i2;i++) bar.push_back(i*2 + 1);
		ft::vector<int>::iterator it(bar.begin());
		std::cout << it[4] << std::endl;
		std::cout << *it++ << std::endl;
		std::cout << *it++ << std::endl;
		std::cout << std::endl;
		ft::vector<int> foo(bar.begin(), bar.end());
		std::cout << foo.size() << ", " << foo.capacity() << std::endl;
	}

	//std::cout << "max_size: " << vector_int.max_size() << std::endl;

	//system("leaks containers");
	return (0);
}