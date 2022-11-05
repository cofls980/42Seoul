#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

namespace ft {
    template<class T_key, class T_value>
    class avl_tree {
        avl_tree *left;
        avl_tree *right;
        avl_tree *parent;
        T_key key; //값 비교에 사용
        T_value value;
    };
}

#endif