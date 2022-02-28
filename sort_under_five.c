#include "push_swap.h"

int is_middle_num(t_list *st, int mid)
{
    int min;
    int max;
    int j;

    min = 0;
    max = 0;
    j = 4;
    while (j--)
    {
        if (mid < st->value)
            max++;
        else if (mid > st->value)
            min++;
        st = st->next;
    }
    if (max == 2 && min == 2)
        return (1);
    return (0);
}

int find_middle_num(t_list **from)
{
    int i;
    int mid;
    t_list *tmp;

    tmp = (*from);
    i = 5;
    while (i--)
    {
        mid = tmp->value;
        if (is_middle_num(tmp->next, mid))
            return (mid);
        tmp = tmp->next;
    }
    return (0);
}

void    seperate(t_list **from, t_list **to, int *cnt, int *stack_info)
{
    int i;
    int idx;

    i = 0;
    idx = 5;
    while (idx--)
    {
        if (stack_info[1] == 'a' && (*from)->value < stack_info[0])
        {
            push_ab(from, to, 'b', cnt);
            i++;
        }
        else if (stack_info[1] == 'b' && (*from)->value > stack_info[0])
        {
            push_ab(from, to, 'a', cnt);
            i++;
        }
        else
        {
            rotate(from, stack_info[1], cnt);
        }
        if (i == 2)
            break;
    }
}

void    sorting_five(t_list **from, t_list **to, int *cnt, char stack_name)
{
    int i;
    int stack_info[2];

    stack_info[0] = find_middle_num(from);
    stack_info[1] = stack_name;
    seperate(from, to, cnt, stack_info);
    if (stack_name == 'a')
    {
        sorting_under_three_a(from, 3, cnt);
        sorting_under_three_b(to, 2, cnt);
        i = 2;
        while (i--)
            push_ab(to, from, 'a', cnt);
    }
    else
    {
        sorting_under_three_a(to, 2, cnt);
        sorting_under_three_b(from, 3, cnt);
        i = 3;
        while (i--)
            push_ab(from, to, 'a', cnt);
    }
}