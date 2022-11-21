#include "push_swap.h"

void	display(char *command, char stack_name)
{
	int	i;

	i = 0;
	while (command[i])
	{
		write(1, &command[i], 1);
		i++;
	}
	if (stack_name)
		write(1, &stack_name, 1);
	write(1, "\n", 1);
}

int	is_valid(char **argv, t_list **st, int argc)
{
	char		**str;
	int			j;
	long long	num;

	while (--argc > 0)
	{
		str = ft_split(argv[argc], ' ');
		j = ft_cnt(str);
		while (--j >= 0)
		{
			if (!is_number(str[j]))
				break ;
			num = make_number(str[j]);
			if (num > 2147483647 || num < -2147483648)
				break ;
			stack_push(st, new_item(num));
		}
		free_str(str);
		if (j != -1)
			break ;
	}
	if (argc == 0)
		return (1);
	return (0);
}

int	count_params(t_list **st)
{
	t_list	*tmp;
	int		cnt;

	cnt = 0;
	tmp = (*st);
	while (tmp)
	{
		cnt++;
		tmp = tmp->next;
		if (tmp == (*st))
			break ;
	}
	return (cnt);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		count_param;
	int		cnt;

	if (argc == 1)
		return (0);
	a = NULL;
	b = NULL;
	if (!is_valid(argv, &a, argc) || is_duplicated(&a))
	{
		display("Error", 0);
		free_stack(&a, &b);
		exit(1);
	}
	cnt = 0;
	count_param = count_params(&a);
	atob(&a, &b, count_param, &cnt);
	free_stack(&a, &b);
	return (0);
}
