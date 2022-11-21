/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaekim <chaekim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 01:15:45 by chaekim           #+#    #+#             */
/*   Updated: 2022/06/13 16:07:18 by chaekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

void	close_fd(int fd, t_info *info)
{
	if (fd != 1 && fd != 0)
	{
		if (close(fd) == -1)
		{
			free_exit(info);
		}
	}
}

void	duplicate(int fd1, int fd2, t_info *info)
{
	if (dup2(fd1, fd2) == -1)
	{
		free_exit(info);
	}
}

void	close_iofd(t_info *info)
{
	close_fd(info->output_fd, info);
	close_fd(info->input_fd, info);
}

void	words_free(char **parts, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->word_num)
	{
		if (parts[i])
			free(parts[i]);
		i++;
	}
	free(parts);
}

int	check_pid(int *i, int *e_num, t_info *info)
{
	if (info->pids[*i] == -2)
	{
		(*i)++;
		*e_num = -1;
		return (1);
	}
	return (0);
}
