#include "../includes/minishell.h"

int	check_command(char **command, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->command_null)
	{
		if (command[i])
			break ;
		i++;
	}
	if (!command[i])
	{
		g_exit_num = 0;
		return (-2);
	}
	return (i);
}

void	check_execute_command(char **command, t_info *info)
{
	if (ft_strcmp(command[0], "") == 0)
	{
		ft_print_error(command[0], 0, "command not found");
		free_all(info);
		exit(127);
	}
	if (ft_strlen(command[0]) >= 2)
	{
		if (command[0][0] == '.' && command[0][1] == '/')
		{
			ft_print_error(command[0], 0, "is a directory");
			free_all(info);
			exit(126);
		}
		if (ft_strlen(command[0]) >= 3)
		{
			if (command[0][0] == '.' && command[0][1] == '.' \
			&& command[0][2] == '/')
			{
				ft_print_error(command[0], 0, "is a directory");
				free_all(info);
				exit(126);
			}
		}
	}
}
