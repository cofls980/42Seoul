/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaekim <chaekim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 01:15:45 by chaekim           #+#    #+#             */
/*   Updated: 2022/06/13 04:02:44 by chaekim          ###   ########.fr       */
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