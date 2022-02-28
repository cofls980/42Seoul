#include "push_swap.h"

void    sorting_three_a(t_list **st, int *num, int *cnt)
{
    if (num[0] < num[1] && num[0] < num[2] && num[1] > num[2]) //1 3 2
    {
        swap(st, 'a', cnt);
        rotate(st, 'a', cnt);
    }
    else if (num[0] > num[1] && num[0] < num[2] && num[1] < num[2]) //2 1 3
    {
        swap(st, 'a', cnt);
    }
    else if (num[0] < num[1] && num[0] > num[2] && num[1] > num[2]) //2 3 1
    {
        reverse_rotate(st, 'a', cnt);
    }
    else if (num[0] > num[1] && num[0] > num[2] && num[1] < num[2]) //3 1 2
    {
        rotate(st, 'a', cnt);
    }
    else if (num[0] > num[1] && num[0] > num[2] && num[1] > num[2]) //3 2 1
    {
        swap(st, 'a', cnt);
        reverse_rotate(st, 'a', cnt);
    }
}

void    sorting_three_b(t_list **st, int *num, int *cnt)
{
    if (num[0] < num[1] && num[0] < num[2] && num[1] < num[2]) //1 2 3
    {
        swap(st, 'b', cnt);
        reverse_rotate(st, 'b', cnt);
    }
    else if (num[0] < num[1] && num[0] < num[2] && num[1] > num[2]) //1 3 2
    {
        rotate(st, 'b', cnt);
    }
    else if (num[0] > num[1] && num[0] < num[2] && num[1] < num[2]) //2 1 3
    {
        reverse_rotate(st, 'b', cnt);
    }
    else if (num[0] < num[1] && num[0] > num[2] && num[1] > num[2]) //2 3 1
    {
        swap(st, 'b', cnt);
    }
    else if (num[0] > num[1] && num[0] > num[2] && num[1] < num[2]) //3 1 2
    {
        swap(st, 'b', cnt);
        rotate(st, 'b', cnt);
    }
}

void    sorting_under_three_a(t_list **st, int n, int *cnt)
{
    int num[3];

    if (n == 2)
    {
        if ((*st)->value > (*st)->next->value)
            sort_2(st, cnt, 'a');
    }
    else if (n == 3)
    {
        num[0] = (*st)->value;
        num[1] = (*st)->next->value;
        num[2] = (*st)->next->next->value;
        if ((*st)->next->next->next == (*st))
            sorting_three_a(st, num, cnt);
        else if (num[0] < num[1] && num[0] < num[2] && num[1] > num[2]) //1 3 2
            sort_1(st, cnt, 'a');
        else if (num[0] > num[1] && num[0] < num[2] && num[1] < num[2]) //2 1 3
            sort_2(st, cnt, 'a');
        else if (num[0] < num[1] && num[0] > num[2] && num[1] > num[2]) //2 3 1
            sort_3(st, cnt, 'a');
        else if (num[0] > num[1] && num[0] > num[2] && num[1] < num[2]) //3 1 2
            sort_4(st, cnt, 'a');
        else if (num[0] > num[1] && num[0] > num[2] && num[1] > num[2]) //3 2 1
            sort_5(st, cnt, 'a');
    }
}

void    sorting_under_three_b(t_list **st, int n, int *cnt)
{
    int num[3];

    if (n == 2)
    {
        if ((*st)->value < (*st)->next->value)
            sort_2(st, cnt, 'b');
    }
    else if (n == 3)
    {
        num[0] = (*st)->value;
        num[1] = (*st)->next->value;
        num[2] = (*st)->next->next->value;
        if ((*st)->next->next->next == (*st))
            sorting_three_b(st, num, cnt);
        else if (num[0] < num[1] && num[0] < num[2] && num[1] < num[2]) //1 2 3
            sort_5(st, cnt, 'b');
        else if (num[0] < num[1] && num[0] < num[2] && num[1] > num[2]) //1 3 2
            sort_4(st, cnt, 'b');
        else if (num[0] > num[1] && num[0] < num[2] && num[1] < num[2]) //2 1 3
            sort_3(st, cnt, 'b');
        else if (num[0] < num[1] && num[0] > num[2] && num[1] > num[2]) //2 3 1
            sort_2(st, cnt, 'b');
        else if (num[0] > num[1] && num[0] > num[2] && num[1] < num[2]) //3 1 2
            sort_1(st, cnt, 'b');
    }
}