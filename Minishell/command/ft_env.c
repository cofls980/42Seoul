#include "../includes/minishell.h"

int	ft_env(char **command, t_info *info)
{
	t_list	*tmp;

	tmp = info->env_list;
	if (command[1] != 0)
	{
		ft_print_error(command[0], command[1], "No such file or directory");
		return (127);
	}
	while (tmp)
	{
		if (tmp->print == 1)
		{
			ft_print(info, tmp->key);
			ft_print(info, "=");
			ft_print(info, tmp->value);
			ft_print(info, "\n");
		}
		tmp = tmp->next;
	}
	return (0);
}
