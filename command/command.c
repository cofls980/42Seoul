#include "../includes/minishell.h"

void	execute(char **command, t_info *info)
{
	char	*path;

	path = find_path(command[0], info->envp);
	if (execve(path, command, info->envp) == -1)
	{
		ft_print_error(command[0], 0, strerror(errno));
		free(path);
		free_all(info);
		free_str(info->bundles);
		//에러 num 종류에 따라 다른 숫자로 exit();
		exit(127);
	}
}

void	execute_command(char **command, t_info *info)
{
	int	status;

	set_input_fd(info);
	if (is_builtin(command[0]))
	{
		status = builtin_command(command, info);
		if (info->output_fd != 1)
			close(info->output_fd);
		free_all(info);
		free_str(info->bundles);
		exit(status);
	}
	else
	{
		set_output_fd(info);
		if (info->output_fd != 1)
		{
			dup2(info->output_fd, STDOUT_FILENO);
			close(info->output_fd);
		}
		execute(command, info);
	}
}

pid_t	last_command(char **command, t_info *info)//단순 실행
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
		ft_print_error(0, 0, strerror(errno));
	else if (pid == 0)
		execute_command(command, info);
	return (pid);
}

pid_t	commands(char **command, t_info *info)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
	{
		ft_print_error(0, 0, strerror(errno));
		return (-2);
	}
	pid = fork();
	if (pid < 0)
	{
		close(fd[0]);
		close(fd[1]);
		ft_print_error(0, 0, strerror(errno));
		return (-2);
	}
	else if (pid == 0)
	{
		close(fd[0]);
		info->output_fd = fd[1];
		execute_command(command, info);
	}
	close(fd[1]);
	info->input_fd = fd[0];
	return (pid);
}

pid_t	command(char **command, t_info *info)
{
	pid_t	pid;

	if (info->have_pipe)
	{
		if (info->pipe_num)
			pid = commands(command, info);
		else
			pid = last_command(command, info); //마지막 명령어는 exit 기록이 남는다.
	}
	else
	{
		if (is_builtin(command[0]))
		{
			builtin_command(command, info);
			pid = -2;
		}
		else
			pid = last_command(command, info);
	}
	return (pid);
}