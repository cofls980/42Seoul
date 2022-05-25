#include "./includes/minishell.h"

void	ft_env(t_info *info)
{
	t_list	*tmp;

	tmp = info->list;
	while (tmp)
	{
		if (tmp->print)
			printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}