#include "push_swap.h"

t_list	*new_item(int val)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	res->value = val;
	res->next = NULL;
	res->prev = NULL;
	return (res);
}

void	delete_item(t_list *item)
{
	if (item)
	{
		free(item);
	}
}

void	stack_push(t_list **st, t_list *new)
{
	if (*st)
	{
		new->next = (*st);
		new->prev = (*st)->prev;
		(*st)->prev->next = new;
		(*st)->prev = new;
	}
	else
	{
		new->next = new;
		new->prev = new;
	}
	(*st) = new;
}

t_list	*stack_pop(t_list **st)
{
	t_list	*top;

	top = (*st);
	if (top)
	{
		if (top->next == top)
			(*st) = NULL;
		else
		{
			top->next->prev = top->prev;
			top->prev->next = top->next;
			(*st) = top->next;
		}
	}
	return (top);
}

int	is_empty(t_list **st)
{
	if (*st)
		return (0);
	return (1);
}
