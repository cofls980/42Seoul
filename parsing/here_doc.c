/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaekim <chaekim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 05:30:57 by chaekim           #+#    #+#             */
/*   Updated: 2022/06/10 05:30:57 by chaekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	chech_input(char *limit, char *input, int fd)
{
	if (ft_strcmp(limit, input) == 0)
	{
		free(input);
		return (0);
	}
	if (input[0] != '\0')
	{
		write(fd, input, ft_strlen(input));
		write(fd, "\n", 1);
	}
	free(input);
	return (1);
}

void	child_process(int *fd, char *limit)
{
	char	*input;

	close(fd[0]);
	while (1)
	{
		signal(SIGINT, ft_here_doc_sig);
		input = readline("> ");
		if (!input)
		{
			write(1, "\n", 1);
			break ;
		}
		else
		{
			if (!chech_input(limit, input, fd[1]))
				break ;
		}
	}
	exit(0);
}

int	here_doc(char *limit, t_info *info)
{
	int		fd[2];
	int		status;
	pid_t	pid;

	if (pipe(fd) == -1)
		free_exit(info);
	pid = fork();
	if (pid < 0)
	{
		close(fd[0]);
		close(fd[1]);
		free_exit(info);
	}
	else if (pid == 0)
	{
		child_process(fd, limit);
	}
	signal(SIGINT, ft_here_doc_sig_parent);
	close(fd[1]);
	waitpid(pid, &status, 0);
	g_exit_num = (status & 0xff00) >> 8;
	return (fd[0]);
}
