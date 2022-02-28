#include "push_swap.h"

void	free_stack(t_list **a, t_list **b)
{
	while (!is_empty(a))
	{
		delete_item(stack_pop(a));
	}
	while (!is_empty(b))
	{
		delete_item(stack_pop(b));
	}
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
