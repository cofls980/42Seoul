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
		std::cout << "[insert, erase]1" << std::endl;
		ft::map<int, int> m1;
		ft::pair<int, int> p;
		p = ft::make_pair(10, 3);
		m1.insert(p);
		m1.insert(ft::make_pair(15, 5));
		m1.insert(ft::make_pair(13, 5));
		m1.insert(ft::make_pair(1, 5));
		m1.insert(ft::make_pair(2, 5));
		m1.insert(ft::make_pair(3, 5));
		std::cout << m1.size() << std::endl;
		m1.erase(3);
		m1.erase(10);
		m1.erase(14);
		std::cout << m1.size() << std::endl;
	}
	{
		std::cout << "[insert, erase]2" << std::endl;
		ft::map<int,int> mp;
		for (int i = 0;i < 20;i++) {
			mp.insert(ft::make_pair(i, i));
		}
		for (int i = 0;i < 20;i++) {
			mp.find(i);
		}
		while (!mp.empty()) {
			mp.erase(mp.begin());
		}
	}
	{
		std::cout << "[iterator + reverse]" << std::endl;
		ft::map<int, int> m1;
		ft::pair<int, int> p;
		p = ft::make_pair(10, 3);
		m1.insert(p);
		m1.insert(ft::make_pair(15, 5));
		m1.insert(ft::make_pair(13, 5));
		m1.insert(ft::make_pair(1, 5));
		m1.insert(ft::make_pair(2, 5));
		m1.insert(ft::make_pair(3, 5));
		std::cout << m1.size() << std::endl;
		m1.erase(3);
		m1.erase(10);
		m1.erase(14);
		std::cout << m1.size() << std::endl;
		ft::map<int, int>::iterator it = m1.begin();
		ft::map<int, int>::reverse_iterator rit(m1.rbegin());
		std::cout << (*it).first << std::endl;++it;
		std::cout << (*it).first << std::endl;
		std::cout << (*rit).first << std::endl;++rit;
		std::cout << (*rit).first << std::endl;

		ft::map<int, int> m2 = m1;
		for (ft::map<int, int>::iterator it2 = m2.begin();it2 != m2.end();it2++) {
			std::cout << (*it2).first << std::endl;
		}
		std::cout << m1[12] << std::endl;
		m1[12] = 3;
		std::cout << m1[12] << std::endl;
		m1.insert(ft::make_pair(12, 10));
		std::cout << m1[12] << std::endl;

		ft::map<int, int>::iterator it3 = m1.begin();
		std::cout << (*it3).first << std::endl;
		std::cout << it3->first << std::endl;
		it3++;
		std::cout << it3->first << std::endl;
	}
	{
		std::cout << "[swap]" << std::endl;
		ft::map<int, int> m1;
		ft::pair<int, int> p;
		p = ft::make_pair(10, 3);
		m1.insert(p);
		m1.insert(ft::make_pair(15, 5));
		m1.insert(ft::make_pair(13, 5));
		m1.insert(ft::make_pair(1, 5));
		m1.insert(ft::make_pair(2, 5));
		m1.insert(ft::make_pair(3, 5));
		std::cout << m1.size() << std::endl;
		m1.erase(3);
		m1.erase(10);
		m1.erase(14);
		std::cout << m1.size() << std::endl;
		ft::map<int, int> m2;
		m2[5] = 10;
		m2[4] = 3;
		m1.swap(m2);
		std::cout << m1.size() << std::endl;
		std::cout << m2.size() << std::endl;
	}
	{
		std::cout << "[clear]" << std::endl;
		ft::map<int, int> m1;
		ft::pair<int, int> p;
		p = ft::make_pair(10, 3);
		m1.insert(p);
		m1.insert(ft::make_pair(15, 5));
		m1.insert(ft::make_pair(13, 5));
		m1.insert(ft::make_pair(1, 5));
		m1.insert(ft::make_pair(2, 5));
		m1.insert(ft::make_pair(3, 5));
		std::cout << m1.size() << std::endl;
		m1.erase(3);
		m1.erase(10);
		m1.erase(14);
		std::cout << m1.size() << std::endl;
		m1.clear();
		std::cout << m1.size() << std::endl;
		m1[4] = 4;
		std::cout << m1.size() << std::endl;
	}
	{
		std::cout << "[find count]" << std::endl;
		ft::map<int, int> m1;
		ft::pair<int, int> p;
		p = ft::make_pair(10, 3);
		m1.insert(p);
		m1.insert(ft::make_pair(15, 5));
		m1.insert(ft::make_pair(13, 5));
		m1.insert(ft::make_pair(1, 5));
		m1.insert(ft::make_pair(2, 5));
		m1.insert(ft::make_pair(3, 5));
		std::cout << m1.size() << std::endl;
		m1.erase(3);
		m1.erase(10);
		m1.erase(14);
		std::cout << m1.size() << std::endl;
		if (m1.find(3) != m1.end())
			std::cout << "have" << std::endl;
		else
			std::cout << "not have" << std::endl;
		if (m1.count(3) != 0)
			std::cout << "have" << std::endl;
		else
			std::cout << "not have" << std::endl;
	}
	{
		std::cout << "[lower upper bound, equal_range]" << std::endl;
		ft::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['d']=30;
		ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
		ret = mymap.equal_range('b');

		std::cout << "lower bound points to: ";
		std::cout << ret.first->first << " => " << ret.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << ret.second->first << " => " << ret.second->second << '\n';

		ret = mymap.equal_range('c');

		std::cout << "lower bound points to: ";
		std::cout << ret.first->first << " => " << ret.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << ret.second->first << " => " << ret.second->second << '\n';
	}
	{
		std::cout << "[max_size]" << std::endl;
		ft::map<int, int> m1;
		ft::pair<int, int> p;
		p = ft::make_pair(10, 3);
		m1.insert(p);
		m1.insert(ft::make_pair(15, 5));
		m1.insert(ft::make_pair(13, 5));
		m1.insert(ft::make_pair(1, 5));
		m1.insert(ft::make_pair(2, 5));
		m1.insert(ft::make_pair(3, 5));
		std::cout << m1.size() << std::endl;
		m1.erase(3);
		m1.erase(10);
		m1.erase(14);
		std::cout << m1.size() << std::endl;
		std::cout << m1.max_size() << std::endl;
	}
	{
		std::cout << "[compare]" << std::endl;
		int i1 = 3;
		int i2 = 3;
		ft::map<int, int> foo;
		for (int i = 0;i < i1;i++) foo.insert(ft::make_pair(i, i));
		ft::map<int, int> bar;
		for (int i = 0;i < i2;i++) bar.insert(ft::make_pair(i + 1, i));

		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	}
	end = clock();
	double result = (double)(end-start) / CLOCKS_PER_SEC;
	std::cout << "time diff: " << result << std::endl;
}