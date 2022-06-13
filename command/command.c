/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaekim <chaekim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:52:16 by chaekim           #+#    #+#             */
/*   Updated: 2022/06/13 15:40:59 by chaekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	execute(char **command, t_info *info)
{
	char	*path;
	int		status;

	check_execute_command(command, info);
	path = find_path(command[0], info->envp);
	if (execve(path, command, info->envp) == -1)
	{
		if (ft_strcmp(command[0], path) == 0)
		{
			ft_print_error(command[0], 0, "command not found");
			free(path);
			free_all(info);
			exit(127);
		}
		ft_print_error(command[0], 0, strerror(errno));
		status = 1;
		free(path);
		free_all(info);
		exit(status);
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
			close_fd(info->output_fd, info);
		free_all(info);
		exit(status);
	}
	else
	{
		set_output_fd(info);
		if (info->output_fd != 1)
		{
			duplicate(info->output_fd, STDOUT_FILENO, info);
			close_fd(info->output_fd, info);
		}
		execute(command, info);
	}
}

pid_t	last_command(char **command, t_info *info)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		ft_print_error(0, 0, strerror(errno));
		free_all(info);
		exit(1);
	}
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
		free_exit(info);
	}
	pid = fork();
	if (pid < 0)
	{
		close_fd(fd[0], info);
		close_fd(fd[1], info);
		ft_print_error(0, 0, strerror(errno));
		free_exit(info);
	}
	else if (pid == 0)
	{
		close_fd(fd[0], info);
		info->output_fd = fd[1];
		execute_command(command, info);
	}
	close_fd(fd[1], info);
	info->input_fd = fd[0];
	return (pid);
}

pid_t	command(char **command, t_info *info)
{
	pid_t	pid;
	int		i;

	i = check_command(command, info);
	if (i == -2)
		return (i);
	command = command + i;
	if (info->have_pipe)
	{
		if (info->pipe_num)
			pid = commands(command, info);
		else
			pid = last_command(command, info);
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
