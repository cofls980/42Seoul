#include "./includes/minishell.h"

void	free_str(char **strs)
{
	int	i;

	i = 0;
	if (strs)
	{
		while (strs[i])
		{
			free(strs[i]);
			i++;
		}
		free(strs);
	}
}

void	init_str(char **strs, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		strs[i] = 0;
		i++;
	}
}

void	free_list(t_list **list)
{
	t_list	*item;

	if (*list)
	{
		while (*list)
		{
			item = *list;
			*list = (*list)->next;
			delete_item(item);
		}
		free(*list);
	}
}

void	free_all(t_info *info)
{
	if (info->home)
		free(info->home);
	if (info->pwd)
		free(info->pwd);
	free_list(&(info->env_list));
}