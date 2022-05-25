#include "./includes/minishell.h"

void	check_command(char **command, t_info *info)
{
	/* 리다이렉션 포함시켜야함. */
	if (ft_strcmp(command[0], "pwd") == 0)
		ft_pwd(command, info);
	else if (ft_strcmp(command[0], "unset") == 0)
		ft_unset(command, info);
	else if (ft_strcmp(command[0], "export") == 0)
		ft_export(command, info);
	else if (ft_strcmp(command[0], "echo") == 0)
		ft_echo(command);
	else if (ft_strcmp(command[0], "env") == 0)
		ft_env(info);//대충 만들었음
	else
		running_execute(command, info);
}