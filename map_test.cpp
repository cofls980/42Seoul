#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>

#ifdef FT_MODE
	#include "map/map.hpp"
	#include "vector/vector.hpp"
	#include "utils/utils.hpp"
#else
	#include <map>
	#include <vector>
	namespace ft = std;
#endif

int main() {
#ifdef FT_MODE
	std::cout << "ft_mode" << std::endl;
#else
	std::cout << "std_mode" << std::endl;
#endif
	
	ft::map<int,int> mp;
    clock_t start = clock(), end;
	for (int i = 0;i < 2000;i++) {
        int r = rand() % 2000;
		mp.insert(ft::make_pair(r, r));
        //mp.erase(mp.begin());
	}
    //std::cout << "//" << std::endl;
    for (int i = 0;i < 2000;i++) {
        int r = rand() % 2000;
        mp.find(r);
        //std::cout << i << std::endl;
        // int r = rand() % 2000;
        // mp.erase(r);
        //mp.erase(mp.begin());
	}
    // while (!mp.empty()) {
    //     mp.erase(mp.begin());
    // }
    end = clock();
    double result = (double)(end-start) / CLOCKS_PER_SEC;
    std::cout << "time diff: " << result << std::endl;
	
	// ft::pair<int, int> p;
	// p = ft::make_pair(10, 3);
	// ft::map<int, int> m1;    
	// m1.insert(ft::make_pair(10,3));
	// std::cout << "-----------" << std::endl;
	// m1.insert(ft::make_pair(15, 5));
	// std::cout << "-----------" << std::endl;
	// m1.insert(ft::make_pair(13, 5));
	// std::cout << "-----------" << std::endl;
	// m1.insert(ft::make_pair(1, 5));
	// std::cout << "-----------" << std::endl;
	// m1.insert(ft::make_pair(2, 5));
	// std::cout << "-----------" << std::endl;
	// m1.insert(ft::make_pair(3, 5));

	// std::cout << "==========================" << std::endl;

	// std::cout << m1.begin()->first << std::endl;

	// m1.erase(3);
	// m1.erase(10);
	// m1.erase(13);
	// std::cout << "1==========================" << std::endl;
	// ft::map<int, int>::iterator it = m1.end();
	//ft::map<int, int>::reverse_iterator rit(it);
	// std::cout << "2==========================" << std::endl;
	// std::cout << (*it).first << std::endl;
	// ++it;
	// std::cout << (*it).first << std::endl;
	// ++it;
	// std::cout << (*it).first << std::endl;
	// ++it;
	// std::cout << (*it).first << std::endl;
	// ++it;
	// std::cout << (*it).first << std::endl;
	// ++it;
	// std::cout << (*it).first << std::endl;
	// ++it;
	// std::cout << (*it).first << std::endl;
	// ++it;
	// std::cout << (*it).first << std::endl;
	// std::cout << "3==========================" << std::endl;
	// std::cout << (*it).first << std::endl;
	//std::cout << (*rit).first << std::endl;
	
	// std::cout << "==========================" << std::endl;

	// ft::map<int, int> m2 = m1;
	// for (ft::map<int, int>::iterator it2 = m2.begin();it2 != m2.end();it2++) {
	// 	std::cout << (*it2).first << std::endl;
	// }
	// std::cout << m1[12] << std::endl;
	// m1[12] = 3;
	// std::cout << m1[12] << std::endl;
	// m1.insert(ft::make_pair(12, 10));
	// std::cout << m1[12] << std::endl;

	// ft::map<int, int>::iterator it = m1.begin();
	// std::cout << (*it).first << std::endl;
	// std::cout << it->first << std::endl;
	// it++;
	// std::cout << it->first << std::endl;
	// it++;
	// std::cout << it->first << std::endl;
	// it++;
	// std::cout << it->first << std::endl;

	// ft::vector<int> v1, v2;
	// v1.resize(5, 3);
	// v2 = v1;
	// if (v1.begin() == v2.begin()) {
	// 	std::cout << "equals" << std::endl;
	// } else {
	// 	std::cout << "difference" << std::endl;
	// }

	// ft::map<char,int> mymap;

	// mymap['a']=10;
	// mymap['b']=20;
	// mymap['d']=30;

	// ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
	// ret = mymap.equal_range('b');

	// std::cout << "lower bound points to: ";
	// std::cout << ret.first->first << " => " << ret.first->second << '\n';

	// std::cout << "upper bound points to: ";
	// std::cout << ret.second->first << " => " << ret.second->second << '\n';

	// mymap.insert(mymap.begin(), ft::make_pair('e', 50));

	// ft::map<char, int>::iterator it6;
	// for (it6 = mymap.begin();it6 != mymap.end();it6++) {
	// 	std::cout << it6->first << ", " << it6->second << std::endl;
	// }
	// std::cout << mymap.erase('i') << std::endl;

	return (0);
} 