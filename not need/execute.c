#include "../includes/minishell.h"

void	execute(char **command, t_info *info)
{
	char	*path;

	path = find_path(command[0], info->envp);
	if (execve(path, command, info->envp) == -1)
	{
		ft_error_print("minishell: ");
		ft_error_print(command[0]);
		ft_error_print(":command not found\n");
		free(path); //free 필요
		exit(EXIT_FAILURE);//error mssg
	}
}

void	execute_command(char **command, t_info *info)
{
	set_input_fd(info);
	if (!builtin_command(command, info))
	{
		if (info->output_fd != 1)
		{
			dup2(info->output_fd, STDOUT_FILENO);
			close(info->output_fd);
		}
		execute(command, info);
	}
	else
	{
		close(info->output_fd);
		exit(0);
	}
}

pid_t	last_command(char **command, t_info *info)//단순 실행
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		printf("error\n");// 에러처리 제대로
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execute_command(command, info);
	}
	return (pid);
}