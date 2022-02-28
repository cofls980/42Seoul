#include "push_swap.h"

void    sort_1(t_list **st, int *cnt, char stack_name) //a: 1 3 2, b: 3 1 2
{
    rotate(st, stack_name, cnt);
    swap(st, stack_name, cnt);
    reverse_rotate(st, stack_name, cnt);
}

void    sort_2(t_list **st, int *cnt, char stack_name) //a: 2 1 3, b: 2 3 1
{
    swap(st, stack_name, cnt);
}

void    sort_3(t_list **st, int *cnt, char stack_name) //a: 2 3 1, b: 2 1 3
{
    rotate(st, stack_name, cnt);
    swap(st, stack_name, cnt);
    reverse_rotate(st, stack_name, cnt);
    swap(st, stack_name, cnt);
}

void    sort_4(t_list **st, int *cnt, char stack_name) //a: 3 1 2, b: 1 3 2
{
    swap(st, stack_name, cnt);
    rotate(st, stack_name, cnt);
    swap(st, stack_name, cnt);
    reverse_rotate(st, stack_name, cnt);
}

void    sort_5(t_list **st, int *cnt, char stack_name) //a: 3 2 1, b: 1 2 3
{
    swap(st, stack_name, cnt);
    rotate(st, stack_name, cnt);
    swap(st, stack_name, cnt);
    reverse_rotate(st, stack_name, cnt);
    swap(st, stack_name, cnt);
}