#include "push_swap.h"

long long	make_number(char *str)
{
	long long	res;
	int			i;
	int			minus;

	res = 0;
	i = 0;
	minus = 1;
	while (str[i])
	{
		if (str[i] == '-')
		{
			minus = -1;
		}
		else
		{
			res *= 10;
			res += (str[i] - '0');
		}
		i++;
	}
	res *= minus;
	return (res);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!(0 <= (str[i] - '0') && (str[i] - '0') <= 9))
			return (0);
		i++;
	}
	return (1);
}

int	ft_cnt(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_sorted(t_list **st, int n)
{
	t_list	*tmp;

	tmp = (*st);
	while (--n)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_duplicated(t_list **st)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = (*st);
	if (tmp->next == (*st))
		return (0);
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp2 == (*st))
				break ;
			if (tmp->value == tmp2->value)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
		if (tmp == (*st))
			break ;
	}
	return (0);
}
