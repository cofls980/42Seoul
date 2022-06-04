#include "../includes/minishell.h"

int	builtin_command(char **command, t_info *info) // 명령어 추가
{
	if (ft_strcmp(command[0], "pwd") == 0)
		ft_pwd(command, info);
	else if (ft_strcmp(command[0], "unset") == 0)
		ft_unset(command, info);
	else if (ft_strcmp(command[0], "export") == 0)
		ft_export(command, info);
	else if (ft_strcmp(command[0], "echo") == 0)
		ft_echo(command, info);
	else if (ft_strcmp(command[0], "env") == 0)
		ft_env(info);//대충 만들었음
	else
		return (0);
	return (1);
}

pid_t	command_execute(char **command, t_info *info)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		printf("error\n");
	pid = fork();
	if (pid < 0)
		printf("error\n");
	else if (pid == 0)
	{
		close(fd[0]);
		info->output_file = fd[1];
		if (builtin_command(command, info))
		{
			close(fd[1]);
			exit(0);
		}
		else
		{
			set_redirection(info);
			close(fd[1]);
			execute(command, info->envp);
		}
	}
	close(fd[1]);
	if (info->input_file != 0)
		close(info->input_file);
	info->input_file = fd[0];
	return (pid);
}

pid_t	command(char **command, t_info *info)
{
	pid_t	pid;

	if (info->have_pipe)
	{
		if (info->pipe_count)
		{
			printf("\033[0;32m1. %s\033[0;37m\n", command[0]);
			pid = command_execute(command, info);
		}
		else //파이프의 마지막 문자열 실행 또는 파이프 없을 때
		{
			printf("\033[0;32m2. %s\033[0;37m\n", command[0]);
			pid = last_execute(command, info);
		}
	}
	else
	{
		if (!builtin_command(command, info))
			execute(command, info->envp);
	}
	return (pid);
}