#include <iostream>
#include <string>
#include "stack/stack.hpp"
/*#include <stack>
namespace ft = std;*/

int main() {
    ft::stack<int> st;

    st.push(1);

    std::cout << st.top() << std::endl;
}