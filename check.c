#include "push_swap.h"

int	find_max(t_list **st, int n)
{
	t_list	*tmp;
	int		num;

	tmp = (*st);
	num = -2147483648;
	while (n--)
	{
		if (num < tmp->value)
			num = tmp->value;
		tmp = tmp->next;
	}
	return (num);
}

int	find_min(t_list **st, int n)
{
	t_list	*tmp;
	int		num;

	tmp = (*st);
	num = 2147483647;
	while (n--)
	{
		if (num > tmp->value)
			num = tmp->value;
		tmp = tmp->next;
	}
	return (num);
}

int	find_pivot(int min, int max, double op)
{
	return ((int)((max - min + 1) * op) + min);
}

int	check_atob(t_list **st1, t_list **st2, int n, int *cnt)
{
	if (is_sorted(st1, n))
		return (1);
	if (n <= 3)
	{
		sorting_under_three_a(st1, n, cnt);
		return (1);
	}
	if (n == 5 && (*st1)->next->next->next->next->next == (*st1))
	{
		sorting_five(st1, st2, cnt, 'a');
		return (1);
	}
	return (0);
}

int	check_btoa(t_list **st1, t_list **st2, int n, int *cnt)
{
	if (n <= 3)
	{
		sorting_under_three_b(st1, n, cnt);
		while (n--)
			push_ab(st1, st2, 'a', cnt);
		return (1);
	}
	if (n == 5 && (*st1)->next->next->next->next->next == (*st1))
	{
		sorting_five(st1, st2, cnt, 'b');
		return (1);
	}
	return (0);
}
