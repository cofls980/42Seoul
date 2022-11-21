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
		std::cout << "[top, push, pop]" << std::endl;
		ft::stack<int, ft::vector<int> > st;

		st.push(3);
		std::cout << st.top() << std::endl;
		st.push(1);
		std::cout << st.top() << std::endl;
		st.pop();
		std::cout << st.top() << std::endl;
	}
	{
		std::cout << "[size, empty]" << std::endl;
		ft::stack<int, ft::vector<int> > st;

		st.push(3);
		std::cout << st.top() << std::endl;
		st.push(1);
		std::cout << st.top() << std::endl;
		std::cout << st.size() << std::endl;
		st.pop();
		std::cout << st.top() << std::endl;
		std::cout << st.size() << std::endl;
		std::cout << st.empty() << std::endl;
		st.pop();
		std::cout << st.empty() << std::endl;
	}
	{
		std::cout << "[compare]" << std::endl;
		ft::stack<int, ft::vector<int> > st1;
		ft::stack<int, ft::vector<int> > st2;

		st1.push(1);
		st1.push(1);
		st1.push(1);

		st2.push(2);
		st2.push(2);
		st2.push(2);

		if (st1==st2) std::cout << "st1 and st2 are equal\n";
		if (st1!=st2) std::cout << "st1 and st2 are not equal\n";
		if (st1< st2) std::cout << "st1 is less than st2\n";
		if (st1> st2) std::cout << "st1 is greater than st2\n";
		if (st1<=st2) std::cout << "st1 is less than or equal to st2\n";
		if (st1>=st2) std::cout << "st1 is greater than or equal to st2\n";
	}
	end = clock();
	double result = (double)(end-start) / CLOCKS_PER_SEC;
	std::cout << "time diff: " << result << std::endl;
}