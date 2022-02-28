#include "push_swap.h"

void	swap(t_list **lst, char stack_name, int *cnt)
{
	t_list	*first;
	t_list	*second;

	first = stack_pop(lst);
	second = stack_pop(lst);
	if (first)
	{
		stack_push(lst, first);
		if (second)
		{
			stack_push(lst, second);
			display("s", stack_name);
			(*cnt)++;
		}
	}
}

void	push_ab(t_list **from, t_list **to, char stack_name, int *cnt)
{
	if (*from)
	{
		stack_push(to, stack_pop(from));
		display("p", stack_name);
		(*cnt)++;
	}
}

void	rotate(t_list **lst, char stack_name, int *cnt)
{
	if (*lst)
	{
		*lst = (*lst)->next;
		display("r", stack_name);
		(*cnt)++;
	}
}

void	reverse_rotate(t_list **lst, char stack_name, int *cnt)
{
	if (*lst)
	{
		*lst = (*lst)->prev;
		if (stack_name == 'a' || stack_name == 'b')
		{
			display("rr", stack_name);
			(*cnt)++;
		}
	}
}

void	rrr(t_list **a, t_list **b, t_info info, int *cnt)
{
	while (info.ra != 0 && info.rb != 0)
	{
		reverse_rotate(a, 't', cnt);
		reverse_rotate(b, 't', cnt);
		display("rr", 'r');
		info.ra--;
		info.rb--;
		(*cnt)++;
	}
	while (info.ra != 0)
	{
		reverse_rotate(a, 'a', cnt);
		info.ra--;
	}
	while (info.rb != 0)
	{
		reverse_rotate(b, 'b', cnt);
		info.rb--;
	}
}
